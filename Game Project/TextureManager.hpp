#include "game.hpp"

#ifndef TextureManager_hpp
#define TextureManager_hpp

class TextureManager{

public:
    static SDL_Texture* loadTexture(const char* textureRoute);
    static void Draw(SDL_Texture* tex, SDL_Rect destR);
    static void Draw(SDL_Texture* tex, SDL_Rect scrR, SDL_Rect destR, SDL_RendererFlip flip);

    ~TextureManager();

};

#endif /* TextureManager_hpp */
