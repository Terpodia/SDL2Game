#ifndef PositionComponent_hpp
#define PositionComponent_hpp

#include "Components.hpp"
#include "../Vector2D.hpp"

class PositionComponent : public Component
{
public:

    Vector2D position;
    
    PositionComponent()
    {
        position.x = 0.0f;
        position.y = 0.0f;
    }
    
    PositionComponent(float x, float y)
    {
        position.x = x;
        position.x = y;
    }
    
    
    void setPosition(float x, float y)
    {
        position.x = x;
        position.y = y;
    }
    
    void update() override
    {
       
        
    }
};


#endif /* PositionComponent_hpp */
