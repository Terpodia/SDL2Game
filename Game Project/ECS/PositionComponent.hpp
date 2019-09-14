#ifndef PositionComponent_hpp
#define PositionComponent_hpp

#include "Components.hpp"

class PositionComponent : public Component
{
private:
    int xpos;
    int ypos;
    
public:
    
    PositionComponent()
    {
        xpos = 0;
        ypos = 0;
    }
    
    PositionComponent(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    
    int x(){return xpos;}
    int y(){return ypos;}
    
    void setPosition(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    
    void update() override
    {
        xpos++;
        ypos++;
    }
};


#endif /* PositionComponent_hpp */
