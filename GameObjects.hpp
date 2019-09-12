#ifndef GameObjects_hpp
#define GameObjects_hpp

#include "Game.hpp"

class GameObjects
{
public:
    GameObjects();
    GameObjects(const char* texturesheet, int x, int y);
    ~GameObjects();
    void update();
    void renderer();

private:
    int xpos;
    int ypos;
    SDL_Texture* objTexture;
    SDL_Rect destR;
    
};

#endif /* GameObjects_hpp */
