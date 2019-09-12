#ifndef Map_hpp
#define Map_hpp

#include "Game.hpp"

class Map{

public:
    Map();
    ~Map();
    void loadMap(int array[20][26]);
    void drawMap();
    
private:
    SDL_Rect destR;
    
    SDL_Texture* grass;
    SDL_Texture* water;
    SDL_Texture* brick;
    SDL_Texture* ground;
    SDL_Texture* sky;

    int map [20][26];

};

#endif /* Map_hpp */
