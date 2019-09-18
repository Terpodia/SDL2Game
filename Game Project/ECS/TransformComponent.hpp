#ifndef TransformComponent_hpp
#define TransformComponent_hpp

#include "Components.hpp"
#include "../Vector2D.hpp"

class TransformComponent : public Component
{
public:

    Vector2D position;
    Vector2D velocity;
    
    int speed = 3;
    
    int height = 32;
    int width = 32;
    int scale = 1;
    
    TransformComponent()
    {
        position.zero();
    }

    TransformComponent(float x, float y, int h, int w, int scl)
    {
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = scl;
    }
    
    void setPosition(float x, float y)
    {
        position.x = x;
        position.y = y;
    }
    
    void init() override
    {
        velocity.zero();
    }
    
    void update() override
    {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }
};


#endif /* TransformComponent_hpp */
