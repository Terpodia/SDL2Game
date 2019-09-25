#ifndef Map_hpp
#define Map_hpp

#include <string>

class Map{

public:
    Map();
    ~Map();
    static void loadMap(std::string path, int sizeX, int sizeY);
    static void loadColliders(std::string path, int sizeX, int sizeY);

};

#endif /* Map_hpp */
