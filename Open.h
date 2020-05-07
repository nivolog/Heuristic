//
// Created by what_is_love on 14.04.2020.
//

#ifndef HEURISTIC_OPEN_H
#define HEURISTIC_OPEN_H

#include "set"
#include "unordered_set"
#include "Node.h"
#include <iostream>

struct comparator{
    using is_transparent = int;

    bool operator()(const NODE& m, const NODE& n) const{
        if (m.getF() < n.getF()){
            return true;
        }else if(m.getF() > n.getF()){
            return false;
        }else if(m.getG() < n.getG()){
            return true;
        }else if(m.getG() > n.getG()){
            return false;
        }else if(m.x_coordinate < n.x_coordinate){
            return true;
        }else if(m.x_coordinate > n.x_coordinate){
            return false;
        }else return m.y_coordinate < n.y_coordinate;
    }
};

class OPEN {
private:
    std::set <class NODE, comparator> OPEN;
    std::unordered_set <int> OPEN_ID;

public:
    //дай ноду, возьми ноду
    void insertNode(NODE &node);
    void erase_node(std::set <class NODE>::iterator it);
    NODE pop();
    void insertId(int id);
    void output();
    void updateOpen(NODE &new_node, NODE *Pred);

    int size();
};


#endif //HEURISTIC_OPEN_H
