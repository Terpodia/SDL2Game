#include "Map.hpp"
#include "Game.hpp"
#include <fstream>

Map::Map()
{
    
}

Map::~Map()
{
    
}

void Map::loadMap(std::string path, int sizeX, int sizeY)
{
    char tile;
    std::fstream mapFile;
    
    mapFile.open(path);
    
    for(int i = 0; i < sizeX; i++){
        for(int j = 0; j < sizeY; j++){
            
            mapFile.get(tile);
            mapFile.ignore();
            
            Game::addTile(atoi(&tile), j * 32, i * 32);
        }
    }
    
    mapFile.close();
}
    


