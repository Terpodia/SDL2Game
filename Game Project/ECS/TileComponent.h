#ifndef TileComponent_h
#define TileComponent_h

#include "ECS.hpp"
#include "TransformComponent.hpp"
#include "GameSprite.hpp"
#include <SDL2/SDL.h>
#include "../TextureManager.hpp"

class TileComponent : public Component
{
public:
    
    static SDL_Texture* grass;
    static SDL_Texture* water;
    static SDL_Texture* brick;
    static SDL_Texture* ground;
    static SDL_Texture* sky;
    
    SDL_Texture* texture;
    
    TransformComponent *transform;
    SpriteComponent *sprite;
    
    SDL_Rect tileRect;
    int tileID;
    
    static void PreLoadTextures(){
        grass = TextureManager::loadTexture("media/grass.png");
        water = TextureManager::loadTexture("media/water.png");
        brick = TextureManager::loadTexture("media/brick.png");
        ground = TextureManager::loadTexture("media/ground.png");
        sky = TextureManager::loadTexture("media/sky.png");
    }
    
    TileComponent() = default;
    
    TileComponent(int x, int y, int w, int h, int ID)
    {
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;
        tileID = ID;
        
        switch(tileID)
        {
            case 1:
                texture = grass;
                break;
                
            case 2:
                texture = water;
                break;
                
            case 3:
                texture = brick;
                break;
                
            case 4:
                texture = ground;
                break;
                
            default:
                texture = sky;
                break;
        }
    }
    
    
    void init() override
    {
        entity->addComponent<TransformComponent>(tileRect.x, tileRect.y, tileRect.w, tileRect.h, 1);
        
        transform = &entity->getComponent<TransformComponent>();
        
        entity->addComponent<SpriteComponent>(texture);
        sprite = &entity->getComponent<SpriteComponent>();
    }
    
};

#endif /* TileComponent_h */
