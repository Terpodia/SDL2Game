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
    
public:
    SpriteComponent() = default;
    SpriteComponent(const char* path)
    {
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
        destRect.x = static_cast<int>(transform->position.x);
        destRect.y = static_cast<int>(transform->position.y);
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;

    }
    
    void draw() override
    {
        TextureManager::Draw(texture, destRect);
    }
};


#endif /* GameSprite_hpp */
