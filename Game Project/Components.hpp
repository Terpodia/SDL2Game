#ifndef Components_hpp
#define Components_hpp

#include "ECS.HPP"

class PositionComponent : public Component
{
private:
    int xpos;
    int ypos;
    
public:
    int x(){return xpos;}
    int y(){return ypos;}
    
    void setPosition(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    
    void init() override
    {
        xpos = 0;
        ypos = 0;
    }
    
    void update() override
    {
        xpos++;
        ypos++;
    }
};

#endif /* Components_hpp */
