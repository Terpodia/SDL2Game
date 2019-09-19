#ifndef Collider_h
#define Collider_h

#include <SDL2/SDL.h>
#include "ColliderComponent.hpp"

class Collision
{
    
public:
   
   //The meaning of "c" is: the weight and the height of the hitbox
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB, float c)
    {
        return (recA.x - c) + (recA.w - c) >= recB.x &&
        (recB.x - c) + (recB.w - c) >= recA.x &&
        (recA.y - c) + (recA.h - c) >= recB.y &&
        (recB.y - c) + (recB.h - c) >= recA.y;
    }
    
    static bool AABB(const ColliderComponent colA, const ColliderComponent colB)
    {
        if(AABB(colA.collider, colB.collider, 5.0f))
        {
            std::cout << colA.tag << " Hit: " << colB.tag << std::endl;
            return true;
        }
    
        return false;
    }
};

#endif /* Collider_h */
