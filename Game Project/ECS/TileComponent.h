#ifndef TileComponent_h
#define TileComponent_h

#include "ECS.hpp"
#include "TransformComponent.hpp"
#include "GameSprite.hpp"
#include <SDL2/SDL.h>

class TileComponent : public Component
{
public:
    
    char *path;
    TransformComponent *transform;
    SpriteComponent *sprite;
    
    SDL_Rect tileRect;
    int tileID;
    
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
                path = "media/grass.png";
                break;
                
            case 2:
                path = "media/water.png";
                break;
                
            case 3:
                path = "media/brick.png";
                break;
                
            case 4:
                path = "media/ground.png";
                break;
                
            default:
                path = "media/sky.png";
                break;
        }
    }
    
    
    void init() override
    {
        entity->addComponent<TransformComponent>(tileRect.x, tileRect.y, tileRect.w, tileRect.h, 1);
        
        transform = &entity->getComponent<TransformComponent>();
        
        entity->addComponent<SpriteComponent>(path);
        
        sprite = &entity->getComponent<SpriteComponent>();
    }
    
};















#endif /* TileComponent_h */
