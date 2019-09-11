#include "Game.hpp"
#include "textureManager.hpp"
#include "GameObjects.hpp"

GameObjects* player;
GameObjects* enemy;

int cnt = 0;

SDL_Rect destR;
Game::Game() {}
Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height,
                bool fullScreen) {


  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    cout << "The iniciatilize is fine!" << endl;

    window = SDL_CreateWindow(title, xpos, ypos, width, height, fullScreen? SDL_WINDOW_FULLSCREEN : 0);

    if (window) {
      cout << "Window Created!" << endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer) {
      SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
      cout << "Renderer Created!" << endl;
      isRunning = true;
    }
  } else {
    isRunning = false;
  }
}

void Game::start(){
  player = new GameObjects("media/player.png", renderer, 0, 0);
  enemy = new GameObjects("media/enemy.png", renderer, 50, 50);
}

void Game::render() {
  SDL_RenderClear(renderer);
  player->renderer();
  enemy->renderer();
  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  cout << "Game Cleaned" << endl;
}

void Game::handleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
  case SDL_QUIT:
    isRunning = false;
    break;

  default:
    break;
  }
}

bool Game::running() { return isRunning; }

void Game::update() {
  player->update();
  enemy->update();
  SDL_UpdateWindowSurface(window);
}
