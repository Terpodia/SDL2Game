#include "AssetManager.hpp"

AssetManager::AssetManager(Manager* man) : manager(man)
{
}

AssetManager::~AssetManager()
{
}

void AssetManager::addTexture(std::string ID, const char* path)
{
    textures.emplace(ID, TextureManager::loadTexture(path));
}

SDL_Texture* AssetManager::getTexture(std::string ID)
{
    return textures[ID];
}

void AssetManager::CreateProjectile(Vector2D pos, const char* path)
{
    auto& projectile(manager->addEntity());
    projectile.addComponent<TransformComponent>(pos.x, pos.y, 32, 32, 1);
    projectile.addComponent<SpriteComponent>(path);
    projectile.addComponent<ColliderComponent>("projectile");
    
    projectile.addComponent<ProjectileComponent>(1000, 2, Vector2D(1, 1));
    projectile.addGroup(Game::groupProjectiles);
    
    
}
