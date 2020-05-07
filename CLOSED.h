//
// Created by what_is_love on 14.04.2020.
//

#ifndef HEURISTIC_CLOSED_H
#define HEURISTIC_CLOSED_H

#include <unordered_map>
#include <iostream>
#include "NODE.h"

class CLOSED {
private:
    std::unordered_map <int, NODE> CLOSED;
public:
    void insertNode(NODE &node);
    std::unordered_map <int, NODE>::iterator findNode(int id);
    void output();
};


#endif //HEURISTIC_CLOSED_H
