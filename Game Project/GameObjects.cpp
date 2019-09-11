#include "GameObjects.hpp"
#include "textureManager.hpp"

GameObjects::GameObjects(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{
    render = ren;
    objTexture = TextureManager::loadTexture(texturesheet, ren);
    
    xpos = x;
    ypos = y;

}

GameObjects::~GameObjects(){}


void GameObjects::update()
{
    destR.x = xpos;
    destR.y = ypos;
    
    destR.w = 64;
    destR.h = 64;
    
    xpos++;
    ypos++;
}

void GameObjects::renderer()
{
    if (SDL_RenderCopy(render, objTexture, NULL, &destR) != 0)
        printf("Ocurrio un error en la mierda esa, %s ", SDL_GetError());
}
