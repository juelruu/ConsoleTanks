#ifndef MAP_H
#include <vector>
#include <string>
#define MAP_H


class Map
{
    public:
        Map();
        virtual ~Map();

        std::vector<std::string> GetMap();

    private:
        std::vector<std::string> GeneratedMap;
        void GenerateMap();
};

#endif // MAP_H
