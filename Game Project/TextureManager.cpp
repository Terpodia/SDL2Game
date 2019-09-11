#include "textureManager.hpp"


SDL_Texture* TextureManager::loadTexture(const char* textureRoute, SDL_Renderer* ren)
{
    SDL_Surface* tmpSurface = IMG_Load(textureRoute);
    
    if (tmpSurface == NULL){
        printf ("La imagen %s no puedo ser encontrada", textureRoute);
    }
    
    SDL_SetColorKey(tmpSurface, SDL_TRUE, SDL_MapRGB(tmpSurface->format,0xFF, 0xFF, 0xFF));
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    
    return tex;
}
