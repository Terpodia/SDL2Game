#ifndef ProjectileComponent_hpp
#define ProjectileComponent_hpp

#include "ECS.hpp"
#include "Components.hpp"
#include "TextureManager.hpp"
#include "Vector2D.hpp"
#include "Game.hpp"

class ProjectileComponent : public Component
{
public:
    
    ~ProjectileComponent(){}
    
    ProjectileComponent(int rng, int sp, Vector2D vec) : range(rng), speed(sp), vector(vec)
    {

    }
    
    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();
       //transform->vector = vector;
    }
    
    void update() override
    {
        distance += speed;
        
        if(distance > range)
        {
            entity->destroy();
        }
        
//        else if(transform->position.x > Game::camera.x + Game::camera.w ||
//                transform->position.x < Game::camera.x ||
//                transform->position.y > Game::camera.y + Game::camera.h ||
//                transform->position.y < Game::camera.y)
//        {
//            entity->destroy();
//        }
      
    }
    
    
    
private:
    int range = 0;
    int speed = 0;
    int distance = 0;
    SDL_Texture* tex;
    Manager* manager;
    Vector2D vector;
    TransformComponent* transform;
};

#endif /* ProjectileComponent_hpp */
