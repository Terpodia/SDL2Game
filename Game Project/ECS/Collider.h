#ifndef Collider_h
#define Collider_h

#include <SDL2/SDL.h>

class Collision
{
    
public:
   
    /**
     * Crearte a hitbox.
     *
     * @param c Container whose values are summed.

     * @return true if the condition of collision is valid or false if not.
     */

    
    
    
    //The meaning of "c" is: the weight and the height of the hitbox
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB, float c)
    {
        return (recA.x - c) + (recA.w - c) >= recB.x &&
        (recB.x - c) + (recB.w - c) >= recA.x &&
        (recA.y - c) + (recA.h - c) >= recB.y &&
        (recB.y - c) + (recB.h - c) >= recA.y;
    }
};

#endif /* Collider_h */
