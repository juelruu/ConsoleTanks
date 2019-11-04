#include "Map.h"

Map::Map()
{
    GenerateMap();
}

Map::~Map()
{
    //dtor
}

std::vector<std::string> Map::GetMap()
{
    return GeneratedMap;
}

void Map::GenerateMap()
{
    GeneratedMap.push_back("+---+----------------------------+");
    GeneratedMap.push_back("+   +                            +");
    GeneratedMap.push_back("+   +   +----+   +----+   +--+   +");
    GeneratedMap.push_back("+   +   ++++++   ++++++   ++++   +");
    GeneratedMap.push_back("+   +   ++++++   +----+   ++++   +");
    GeneratedMap.push_back("+   +   ++++++            ++++   +");
    GeneratedMap.push_back("+   +   +----+   +----+   +--+   +");
    GeneratedMap.push_back("+                ++++++          +");
    GeneratedMap.push_back("+                +----+      +---+");
    GeneratedMap.push_back("+   +------+                     +");
    GeneratedMap.push_back("+   ++++++++     +----+          +");
    GeneratedMap.push_back("+   ++++++++     +               +");
    GeneratedMap.push_back("+   +------+     +    +------+   +");
    GeneratedMap.push_back("+                +    ++++++++   +");
    GeneratedMap.push_back("+   +------+     +    +------+   +");
    GeneratedMap.push_back("+          +     +               +");
    GeneratedMap.push_back("+   +--+   +     +    +------+   +");
    GeneratedMap.push_back("+   +  +   +     +    ++++++++   +");
    GeneratedMap.push_back("+   +  +   +-----+    ++++++++   +");
    GeneratedMap.push_back("+   +  +              ++++++++   +");
    GeneratedMap.push_back("+   +--+   +-----+    +------+   +");
    GeneratedMap.push_back("+                                +");
    GeneratedMap.push_back("+--------------------------------+");
}
