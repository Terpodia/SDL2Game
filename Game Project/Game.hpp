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

  static SDL_Renderer* renderer;
  static SDL_Event event;

private:
  bool isRunning = true;
  SDL_Window *window;
};

#endif /* Game_hpp */
