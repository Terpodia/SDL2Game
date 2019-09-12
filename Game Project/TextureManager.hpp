#include "game.hpp"

#ifndef TextureManager_hpp
#define TextureManager_hpp

class TextureManager{

public:
    static SDL_Texture* loadTexture(const char* textureRoute);
    static void Draw(SDL_Texture* tex, SDL_Rect destR);
};

#endif /* TextureManager_hpp */
