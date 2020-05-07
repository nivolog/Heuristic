//
// Created by what_is_love on 14.04.2020.
//

//#include <vector>
#include "Map.h"



MAP::MAP(const std::string &address) {

    std::ifstream maze;                                                                                                 //Text file with map
    maze.open(address);
    maze >> size_x >> size_y;
    occupancyGrid = std::vector <std::vector <bool> > (size_x, std::vector <bool> (size_y));
    int x, y, b;
    for (int i = 0; i < size_x; ++i){                                                                                   //coordinates and states of nodes
        for(int j = 0; j < size_y; ++j){
            maze >> x >> y >> b;
            occupancyGrid[x-1][y-1] = bool(b);
        };
    };
    maze.close();
}

bool MAP::getOccupancy(std::pair<int, int> const &coordinates) {
    return occupancyGrid[coordinates.first][coordinates.second];
}


