//
// Created by what_is_love on 14.04.2020.
//

#include "A_search.h"

A_search::A_search(double e, double chosenOne) : _e(e), _chosenOne(chosenOne) {}

void A_search::search(NODE &start, NODE &goal, MAP &occupancyMap) {
    iterations = 0;
    NODE successor_node;
    std::list <NODE> successors;
    NODE *pred;
    open.insertNode(start);
    while (ok()) {
        successor_node = open.pop();
        if (successor_node == goal) {
            iterations++;
            goal_is_not_reached = false;
            closed.insertNode(successor_node);
            address_of_goal_node = closed.findNode(successor_node.getId());
            continue;
        }

        std::cout << "Currently working on :  " << successor_node.x_coordinate << "  " << successor_node.y_coordinate << std::endl;
        closed.insertNode(successor_node);
        pred = &closed.findNode(successor_node.getId())->second;                                                       //Maybe better return NODE or *NODE

        successors = getSuccessors(pred, goal, occupancyMap);

        for (auto & successor : successors){
            //open.insertId(successor.getId());
            open.updateOpen(successor, pred);
        }

        iterations++;
    }
}

bool A_search::ok() {
    return (goal_is_not_reached || (open.size() == 0));
}


std::list<NODE> A_search::getSuccessors(NODE *current, NODE &goal, MAP &occupancyMap) {
    int x = (*current).x_coordinate;
    int y = (*current).y_coordinate;

    std::list <NODE> successors;


    for (int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if (!occupancyMap.getOccupancy(std::make_pair <int, int> (x - 1 + i, y - 1 + j))){
                NODE tmp = NODE(x-1+i, y-1+j, occupancyMap.size_x);
                if(closed.find(tmp.getId()) == closed.end()) {
                    tmp.setH(hCalc(tmp, goal));
                    tmp.setG(gCalc(*current,tmp));
                    tmp.setF(fCalc(tmp.getG(), tmp.getH()));
                    tmp.PRED = current;
                    successors.push_back(tmp);
                }
            }
        }
    }
    return successors;

}

double A_search::computeCost(NODE &one, NODE &two) {                                                                    //distance between two nodes
    int dx = one.x_coordinate - two.x_coordinate;
    int dy = one.y_coordinate - two.y_coordinate;
    int dd = std::abs(dx*dy);
    if (dd > 0) return sqrt(2);                                                                                      //sqrt(2) in case of diagonal transition
    else return 1;                                                                                                      //1 in case of horizontal/vertical transition
}

double A_search::gCalc(NODE &predecessor, NODE &successor) {
    return  predecessor.getG() + computeCost(predecessor, successor);
}

double A_search::hCalc(NODE &cur, NODE &goal) {
    switch (_chosenOne){
        case 1:
            return _e * hypot(abs(cur.x_coordinate - goal.x_coordinate), abs(cur.y_coordinate - goal.y_coordinate));
        case 2:
            return _e *(abs(cur.x_coordinate - goal.x_coordinate) + abs(cur.y_coordinate - goal.y_coordinate) + (sqrt(2) - 2)*fmin(abs(cur.x_coordinate - goal.x_coordinate),abs(cur.y_coordinate - goal.y_coordinate)));
        case 3:
            return _e * fmax(abs(cur.x_coordinate - goal.x_coordinate), abs(cur.y_coordinate - goal.y_coordinate));
        default:
            return 0;
    }
}

double A_search::fCalc(double const &g, double const &h) {
    return g+h;
}



void A_search::create_path(NODE &start) {
    NODE path_node = (*address_of_goal_node).second;
    NODE path_node_next;
    path.add_node(path_node);
    bool path_not_complite = true;


    while(path_not_complite){
        path_node_next = *(path_node.PRED);
        if (path_node_next ==  start){
            path_not_complite = false;
            path.add_node(start);
            continue;
        }
        else{
            path.add_node(path_node_next);
            path_node = path_node_next;
        }
    }

}

void A_search::extract_path(const std::string& path_file) {
    path.extract_path(path_file);
}
