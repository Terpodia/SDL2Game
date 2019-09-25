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
            
            Game::addTile(atoi(&tile), j * 64, i * 64);
        }
    }
    
    mapFile.close();
}

void Map::loadColliders(std::string path, int sizeX, int sizeY)
{
    char col;
    std::fstream mapCollidersFile;
    
    mapCollidersFile.open(path);
    
    for(int i = 0; i < sizeX; i++){
        for(int j = 0; j < sizeY; j++){
            
            mapCollidersFile.get(col);
            mapCollidersFile.ignore();
            
            if (atoi(&col) == 1){
                Game::addCol(2, j * 64, i * 64);
            }
        }
    }
    
    mapCollidersFile.close();
}




