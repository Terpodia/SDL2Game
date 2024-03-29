#ifndef SpriteComponent_hpp
#define SpriteComponent_hpp

#include "Components.hpp"
#include <SDL2/SDL.h>
#include "../TextureManager.hpp"
#include "Animation.h"
#include <map>


class SpriteComponent : public Component
{
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect destRect;
    SDL_Rect scrRect;
    
    bool animated = false;
    int frames = 0  ;
    int speed = 100;
    
public:
    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
        
    int animIndex = 0;
    
    std::map<const char*, Animation> animations;
    
    
    SpriteComponent() = default;
    
    SpriteComponent(const char* path)
    {
        setTexture(path);
    }
    
    SpriteComponent(map<const char*, Animation> anims)
    {
        animated = true;
        animations = anims;
        
        scrRect.w = 32;
        scrRect.h = 32;
    
        play("Idle");
    }
    
    
    SpriteComponent(SDL_Texture* texture)
    {
        setTexture(texture);
    }
    
    ~SpriteComponent()
    {
        SDL_DestroyTexture(texture);
    }
    
    void setTexture(const char* path)
    {
        texture = TextureManager::loadTexture(path);
    }
    
    void setTexture(SDL_Texture* texture)
    {
        this->texture = texture;
    }
    
    void init() override
    {
        if (entity->hasComponent<TransformComponent>()){
            transform = &entity->getComponent<TransformComponent>();
        }
    }
    
    void update() override
    {
        if(animated)
            scrRect.x = scrRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
        
        if (entity->hasComponent<TransformComponent>()){
            destRect.x = static_cast<int>(transform->position.x) - Game::camera.x;
            destRect.y = static_cast<int>(transform->position.y) - Game::camera.y;
            destRect.w = transform->width * transform->scale;
            destRect.h = transform->height * transform->scale;
        }
    }
    
    void draw() override
    {
        if (!animated)
            TextureManager::Draw(texture, destRect);
        else
            TextureManager::Draw(texture, scrRect, destRect, spriteFlip);
    }
            
    void play(const char* animName)
    {
        frames = animations[animName].frames;
        speed = animations[animName].speed;
        scrRect.w = animations[animName].width;
        scrRect.h = animations[animName].height;
        texture = animations[animName].sprite;
    }
};


#endif /* SpriteComponent_hpp */
