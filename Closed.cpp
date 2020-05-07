//
// Created by what_is_love on 14.04.2020.
//

#include "Closed.h"

void CLOSED::insertNode(NODE &node) {
    closed.insert(std::make_pair(node.getId(), node));
}

std::unordered_map <int, NODE>::iterator  CLOSED::findNode(int id) {
    return closed.find(id);
}

void CLOSED::output(){
    std::cout << "closed is: ";
    if (closed.empty()) std::cout << "EMPTY" << std::endl;
    for (auto it : closed)
    {
        std::cout << "(" << it.second.x_coordinate << ", " << it.second.y_coordinate << ") ";
    }
    std::cout << std::endl;
}