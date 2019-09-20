#ifndef GameSprite_hpp
#define GameSprite_hpp

#include "Components.hpp"
#include <SDL2/SDL.h>
#include "../TextureManager.hpp"

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
    SpriteComponent() = default;
    
    SpriteComponent(const char* path)
    {
        setTexture(path);
    }
    
    SpriteComponent(const char* path, int mFrames, int mSpeed, int width, int height)
    {
        animated = true;
        frames = mFrames;
        speed = mSpeed;
        
        scrRect.x = 0;
        scrRect.y = 0;
        scrRect.w = width;
        scrRect.h = height;
        
        setTexture(path);
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
        transform = &entity->getComponent<TransformComponent>();
        
        if (transform == NULL){
            cout << "Transform Component has not found" << endl;
        }
            
    }
    
    void update() override
    {
        if(animated)
        {
            scrRect.x = scrRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
        }
        
        destRect.x = static_cast<int>(transform->position.x);
        destRect.y = static_cast<int>(transform->position.y);
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }
    
    void draw() override
    {
        if (!animated)
            TextureManager::Draw(texture, destRect);
        else
            TextureManager::Draw(texture, scrRect, destRect);
    }
};


#endif /* GameSprite_hpp */
