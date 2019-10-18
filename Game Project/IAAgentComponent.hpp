#ifndef IAAgentComponent_hpp
#define IAAgentComponent_hpp

#include "Components.hpp"
#include "Vector2D.hpp"
#include "ECS.hpp"

#include <SDL2/SDL.h>
#include "TextureManager.hpp"

class IAAgentComponent : public Component
{
public:
    
    Vector2D position;
    int height = 32;
    int width = 32;
    int scale = 2;
    
    IAAgentComponent(Vector2D position, Vector2D* target, const float sp, const char* path, int beha): maxSpeed(sp), behavior(beha)
    {
        this->position = position;
        this->target = target;
        
        scrRect.w = 32;
        scrRect.h = 32;
        setTexture(path);
    }
    
    ~IAAgentComponent()
    {
        SDL_DestroyTexture(texture);
    }
    
    
    Vector2D flee()
    {
        Vector2D direction;
        direction.x = position.x - target->x;
        direction.y = position.y - target->y;
        direction = direction * (1/direction.magnitude());
        
        return direction;
    }

    Vector2D seek()
    {
        Vector2D direction;
        direction.x = target->x - position.x;
        direction.y = target->y - position.y;
        direction = direction * (1/direction.magnitude());
        
        return direction;
    }

    
    void update() override
    {
        if(behavior == 1)
        velocity = flee() * maxSpeed;
        
        else if(behavior == 2)
            velocity = seek() * maxSpeed;
        
        position.x += velocity.x;
        position.y += velocity.y;
        
        destRect.x = static_cast<int>(position.x) - Game::camera.x;
        destRect.y = static_cast<int>(position.y) - Game::camera.y;
        destRect.w = width * scale;
        destRect.h = height * scale;
    }
    
    //Load Textures
    
    void setTexture(const char* path)
    {
        texture = TextureManager::loadTexture(path);
    }
    
    void draw() override
    {
        TextureManager::Draw(texture, destRect);
    }
    
private:
    
    Vector2D velocity;
    Vector2D* target;
    int behavior;
    
    const float maxSpeed;
    
    
    SDL_Texture *texture;
    SDL_Rect destRect;
    SDL_Rect scrRect;
};

#endif /* IAAgentComponent_hpp */
