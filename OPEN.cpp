//
// Created by what_is_love on 14.04.2020.
//

#include <fcntl.h>
#include "OPEN.h"
#include "NODE.h"


void OPEN::insertNode(NODE &node) {
    OPEN.insert(node);

}

void OPEN::erase_node(std::set<class NODE>::iterator it) {
    OPEN.erase(it);
}

void OPEN::insertId(int id) {
    OPEN_ID.insert(id);
}

void OPEN::output() {
    if (OPEN.empty()) std::cout << "EMPTY" << std::endl;
    for (auto n: OPEN) {
        std::cout << "(" << n.x_coordinate << ", " << n.y_coordinate << ") ";
    }
    std::cout << std::endl << std::endl;
}

void OPEN::updateOpen(NODE &new_node, NODE *Pred) {
    auto open_iterator = OPEN.begin();

    auto is_inside_open = OPEN_ID.find(new_node.getId());
    if (is_inside_open != OPEN_ID.end()) {
        while (((*open_iterator).getId() != new_node.getId()) && (open_iterator != OPEN.end())) {
            ++open_iterator;
        }
    } else open_iterator = OPEN.end();
    insertId(new_node.getId());

    if (open_iterator != OPEN.end()) {
        NODE tmp = *open_iterator;
        OPEN.erase(open_iterator);

        if (tmp.PRED->getG() > (*Pred).getG()) {
            tmp.PRED = Pred;
        }
        tmp.check_g(new_node.getG());
        OPEN.insert(tmp);
    } else {
        //remove new
        new_node.PRED = new NODE;
        new_node.PRED = Pred;
        OPEN.insert(new_node);
    }

}

int OPEN::size() {
    return OPEN.size();
}

NODE OPEN::pop() {
    NODE tmp = (*OPEN.begin());
    OPEN.erase(OPEN.begin());
    return tmp;
}


