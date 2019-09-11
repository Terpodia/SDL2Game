#ifndef GameObjects_hpp
#define GameObjects_hpp

#include "Game.hpp"

class GameObjects
{
public:
    GameObjects();
    GameObjects(const char* texturesheet, SDL_Renderer* ren, int x, int y);
    ~GameObjects();
    void update();
    void renderer();

private:
    int xpos;
    int ypos;
    SDL_Texture* objTexture;
    SDL_Rect destR;
    SDL_Renderer* render;
    
};

#endif /* GameObjects_hpp */
