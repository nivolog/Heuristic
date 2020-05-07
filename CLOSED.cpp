//
// Created by what_is_love on 14.04.2020.
//

#include "CLOSED.h"

void CLOSED::insertNode(NODE &node) {
    CLOSED.insert(std::make_pair(node.id, node));
}

std::unordered_map <int, class NODE>::iterator  CLOSED::findNode(int id) {
    return CLOSED.find(id);
}

void CLOSED::output(){
    std::cout << "CLOSED IS: ";
    if (CLOSED.empty()) std::cout << "EMPTY" << std::endl;
    for (auto it : CLOSED)
    {
        std::cout << "(" << it.second.x_coordinate << ", " << it.second.y_coordinate << ") ";
    }
    std::cout << std::endl;
}