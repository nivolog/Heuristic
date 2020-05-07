//
// Created by what_is_love on 14.04.2020.
//

#ifndef HEURISTIC_MAP_H
#define HEURISTIC_MAP_H

#include <string>
#include <vector>
#include <fstream>
#include <list>
#include "NODE.h"
#include "CLOSED.h"


class MAP {//Map
private:
    std::vector <std::vector <bool> > occupancyGrid;

public:
    MAP(const std::string &address);
    int size_x, size_y; //add getters
    bool getOccupancy(std::pair<int, int> const &coordinates);

};


#endif //HEURISTIC_MAP_H
