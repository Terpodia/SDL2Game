#include "Game.hpp"
#include "textureManager.hpp"
#include "Map.hpp"
#include "ECS/Components.hpp"
#include "ECS/Collider.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
std::vector<ColliderComponent*>  Game::colliders;

Manager manager;

auto& player (manager.addEntity());
auto& wall (manager.addEntity());

SDL_Rect destR;

enum groupLabels : size_t
{
  groupMap,
  groupPlayers,
  groupEnemies,
  groupColliders
};

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

SDL_Texture* TileComponent::grass = NULL;
SDL_Texture* TileComponent::water = NULL;
SDL_Texture* TileComponent::brick = NULL;
SDL_Texture* TileComponent::ground = NULL;
SDL_Texture* TileComponent::sky = NULL;

void Game::start(){
  
  //ECS Implementation
  
  TileComponent::PreLoadTextures();
  
  Map::loadMap("media/Map.txt", 20, 26);
  
  wall.addComponent<TransformComponent>();
  wall.addComponent<TransformComponent>(300.0f, 390.0f, 120, 120, 1);
  wall.addComponent<SpriteComponent>("media/Tiles/Original/brick.png");
  wall.addComponent<ColliderComponent>("wall");
  
  
  player.addComponent<TransformComponent>(0.0f, 0.0f, 64, 64, 1);
  player.addComponent<SpriteComponent>("media/Characters/player.png");
  player.addComponent<KeyboardController>();
  player.addComponent<ColliderComponent>("player");
  player.addGroup(groupPlayers);
  wall.addGroup(groupMap);
}

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));

void Game::render() {
  
  SDL_RenderClear(renderer);
  for(auto& t : tiles)
  {
    t->draw();
  }

  for(auto& p : players)
  {
    p->draw();
  }

  for(auto& e : enemies)
  {
    e->draw();
  }

  
  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  cout << "Game Cleaned" << endl;
}

void Game::handleEvents() {
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
  
  manager.refresh();
  manager.update();
  
  for(auto cc : colliders)
  {
    
    if(cc->tag != "player")
    {
      if(Collision::AABB(player.getComponent<ColliderComponent>(), *cc))
        player.getComponent<TransformComponent>().velocity * -1.5f;
    }
    
      //cout << "Wall hit" << endl;
  }
  
  SDL_UpdateWindowSurface(window);
}

void Game::addTile(int ID, int x, int y)
{
  auto& tile(manager.addEntity());
  tile.addComponent<TileComponent>(x, y, 32, 32, ID);
  tile.addGroup(groupMap);
}



