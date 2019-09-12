#include "GameObjects.hpp"
#include "TextureManager.hpp"

GameObjects::GameObjects(const char* texturesheet, int x, int y)
{
    objTexture = TextureManager::loadTexture(texturesheet);
    
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
    if (SDL_RenderCopy(Game::renderer, objTexture, NULL, &destR) != 0)
        printf("Ocurrio un error, %s ", SDL_GetError());
}
