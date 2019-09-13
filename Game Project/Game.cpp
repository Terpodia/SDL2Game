#include "Game.hpp"
#include "textureManager.hpp"
#include "GameObjects.hpp"
#include "Map.hpp"
#include "ECS.hpp"
#include "Components.hpp"

GameObjects* player;
GameObjects* enemy;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer (manager.addEntity());

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
  player = new GameObjects("media/player.png", 0, 0);
  enemy = new GameObjects("media/enemy.png", 50, 50);
  map = new Map();
  
  newPlayer.addComponent<PositionComponent>();
  newPlayer.getComponent<PositionComponent>().setPosition(500, 500);
}

void Game::render() {
  SDL_RenderClear(renderer);
  map->drawMap();
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
  manager.update();
  
  cout << newPlayer.getComponent<PositionComponent>().x() << "," << newPlayer.getComponent<PositionComponent>().y() << endl;
  
  SDL_UpdateWindowSurface(window);
}
