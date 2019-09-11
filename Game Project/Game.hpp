#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>

#ifndef Game_hpp
#define Game_hpp

using namespace std;

class Game {
public:
  Game();
  ~Game();
  void start();
  void init(const char *title, int xpos, int ypos, int width, int height,
            bool fullScreen);
  void update();
  void render();
  void clean();
  void handleEvents();
  bool running();



private:
  bool isRunning = true;
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *player;

};

#endif /* Game_hpp */
