#include "Game.hpp"

Game *game = nullptr;

int main(int argc, const char *argv[]) {

  game = new Game();

  game->init("Game 2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 780,
             600, false);
    
  game->start();
  
  const int fps = 60;
  const int frameDelay = 1000/fps;
  Uint32 frameStart;
  int frameTime;

  while (game->running()) {
    
    frameStart = SDL_GetTicks();
    
    game->handleEvents();
    game->render();
    game->update();
    
    frameTime = SDL_GetTicks() - frameStart;
    if(frameDelay > frameTime)
    {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  game->clean();

  return 0;
}
