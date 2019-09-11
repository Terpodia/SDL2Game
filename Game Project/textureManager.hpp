#include "game.hpp"

#ifndef TextureManager_hpp
#define TextureManager_hpp

class TextureManager{

public:
    static SDL_Texture* loadTexture(const char* textureRoute, SDL_Renderer* render);
};

#endif /* TextureManager_hpp */
