#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include <vector>

#ifndef Game_hpp
#define Game_hpp

using namespace std;

class ColliderComponent;

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

  static void addTile(int ID, int x, int y);
  static SDL_Renderer* renderer;
  static SDL_Event event;
  static std::vector<ColliderComponent*> colliders;
  static bool isRunning;
  static SDL_Rect camera;
private:
  SDL_Window *window;
};

#endif /* Game_hpp */
