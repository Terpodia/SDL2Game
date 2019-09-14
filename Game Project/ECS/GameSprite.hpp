#ifndef GameSprite_hpp
#define GameSprite_hpp

#include "Components.hpp"
#include <SDL2/SDL.h>
#include "TextureManager.hpp"

class SpriteComponent : public Component
{
private:
    PositionComponent *position;
    SDL_Texture *texture;
    SDL_Rect destRect;
    
public:
    SpriteComponent() = default;
    SpriteComponent(const char* path)
    {
        setTexture(path);
    }
    
    void setTexture(const char* path)
    {
        texture = TextureManager::loadTexture(path);
    }
    
    void init() override
    {
        position = &entity->getComponent<PositionComponent>();
        
        destRect.w = destRect.h = 64;
        destRect.x = destRect.y = 0;
    }
    
    void update() override
    {
        destRect.x = (int)position->position.x;
        destRect.y = (int)position->position.y;
    }
    
    void draw() override
    {
        TextureManager::Draw(texture, destRect);
    }
};


#endif /* GameSprite_hpp */
