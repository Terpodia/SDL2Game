#include "Map.hpp"
#include "TextureManager.hpp"

int lvl1 [20][26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,3,0,3,0,
                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,0,
                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,0,
                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,0,
                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,0,
                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,0,
                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,0,
                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,0,
                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,0,
                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,0,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
                     4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};
    
Map::Map()
{
    brick = TextureManager::loadTexture("media/brick.png");
    grass = TextureManager::loadTexture("media/grass.png");
    water = TextureManager::loadTexture("media/water.png");
    ground = TextureManager::loadTexture("media/ground.png");
    sky = TextureManager::loadTexture("media/sky.png");

    loadMap(lvl1);
    
    destR.x = destR.y = 0;
    destR.w = destR.h = 30;
}

Map::~Map()
{}

void Map::loadMap(int array [20][26])
{
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 26; j++){
            map[i][j] = array[i][j];
        }
      }
    }

void Map::drawMap()
{
    int type = 0;
    
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 26; j++){
            type = map[i][j];
            
            destR.x = j * 30;
            destR.y = i * 30;
            
            switch (type) {
                case 1:
                    TextureManager::Draw(grass, destR);

                    break;
                case 2:
                    TextureManager::Draw(water, destR);
                    break;
                case 3:
                    TextureManager::Draw(brick, destR);
                    break;
                    
                case 4:
                    TextureManager::Draw(ground, destR);
                    break;
                default:
                    TextureManager::Draw(sky, destR);
                    break;
            }
        }
    }
}

