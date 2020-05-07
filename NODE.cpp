//
// Created by what_is_love on 14.04.2020.
//

#include "NODE.h"

NODE::NODE() {
    g = 0;
}

NODE::NODE(int x, int y, int size_x) {
    x_coordinate = x;
    y_coordinate = y;
    id_c(size_x);
}

void NODE::id_c(int size_x) {
    id = y_coordinate*size_x + x_coordinate;
}



void NODE::check_g(double const &new_g) {
    g = fmin(g, new_g);
}


bool NODE::operator==(const NODE &rhs) const {
    return x_coordinate == rhs.x_coordinate &&
           y_coordinate == rhs.y_coordinate;
}

int NODE::getId() const {
    return id;
}

double NODE::getF() const {
    return f;
}

void NODE::setF(double f) {
    NODE::f = f;
}

double NODE::getG() const {
    return g;
}

void NODE::setG(double g) {
    NODE::g = g;
}

double NODE::getH() const {
    return h;
}

void NODE::setH(double h) {
    NODE::h = h;
}
