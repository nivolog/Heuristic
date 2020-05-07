//
// Created by what_is_love on 14.04.2020.
//

#ifndef HEURISTIC_NODE_H
#define HEURISTIC_NODE_H


#include <cmath>
#include <list>

#include "Map.h"

class NODE {
private:
    int id{};

    //distance to the start node
    double g{};
    //heuristic distance to the goal node
    double h{};
    //summ of g and h
    double f{};



public:
    int x_coordinate;                                                                                                   //X position of NODE
    int y_coordinate;                                                                                                   //Y position of NODE

    double getF() const;

    void setF(double f);

    double getG() const;

    void setG(double g);

    double getH() const;

    void setH(double h);

    int getId() const;

    NODE();                                                                                                             //constructors
    NODE(int x, int y, int size_x);
    NODE *PRED{};                                                                                                       //link to the predecessor
    bool operator==(const NODE &rhs) const;

    void id_c(int size_x);

    void check_g (double const &new_g);



};


#endif //HEURISTIC_NODE_H
