#include "Game.hpp"
#include "textureManager.hpp"
#include "Map.hpp"
#include "ECS/Components.hpp"
#include "ECS/Collider.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
std::vector<ColliderComponent*>  Game::colliders;

bool Game::isRunning = true;

SDL_Rect Game:: camera = {0, 0, 780, 600};

Manager manager;

auto& player (manager.addEntity());
auto& wall (manager.addEntity());

SDL_Rect destR;
const int offset = 200;

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
  Map::loadColliders("media/Colliders.txt", 20, 26);

//  wall.addComponent<TransformComponent>(0.0f, 1089.0f, 32, 1640, 1);
//  // wall.addComponent<SpriteComponent>("media/Tiles/Original/brick.png");
//  wall.addComponent<ColliderComponent>("wall");
//  wall.addGroup(groupMap);

  player.addComponent<TransformComponent>(500.0f, 1033.0f, 64, 64, 1);
  Animation idle = Animation(74, 74, 3, 400, "media/Characters/wizard/idle.png");
  Animation walk = Animation(78, 74, 4, 300, "media/Characters/wizard/walk.png");
  map<const char*, Animation> playerAnims;
  playerAnims.emplace("Idle", idle);
  playerAnims.emplace("Walk", walk);
  
  player.addComponent<SpriteComponent>(playerAnims);
  player.addComponent<KeyboardController>();
  player.addComponent<ColliderComponent>("player");
  player.addGroup(groupPlayers);
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
  
  Vector2D playerPos = player.getComponent<TransformComponent>().position;

  manager.refresh();
  manager.update();
  
  for(auto cc : colliders)
  {
    
    if(cc->tag != "player")
    {
      if(Collision::AABB(player.getComponent<ColliderComponent>(), *cc))
        player.getComponent<TransformComponent>().position = playerPos;
    }
    
    //cout << "Wall hit" << endl;
  }
  
  camera.x = player.getComponent<TransformComponent>().position.x - offset;
  camera.y = player.getComponent<TransformComponent>().position.y - offset;
  
  if(camera.x < 0)
  {
    camera.x = 0;
  }
  
  if(camera.y < 0)
  {
    camera.y = 0;
  }
  
  if(camera.x > camera.w)
  {
    camera.x = camera.w;
  }
  
  if(camera.y > camera.h)
  {
    camera.y = camera.h;
  }
  
  
  SDL_UpdateWindowSurface(window);
}

void Game::addTile(int ID, int x, int y)
{
  auto& tile(manager.addEntity());
  tile.addComponent<TileComponent>(x, y, 64, 64, ID);
  tile.addGroup(groupMap);
}

void Game::addCol(int ID, int x, int y)
{
  auto& col(manager.addEntity());
  col.addComponent<TransformComponent>(x, y, 64, 64, ID);
  col.addComponent<ColliderComponent>("Collider");
  col.addGroup(groupColliders);

}

