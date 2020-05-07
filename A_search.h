//
// Created by what_is_love on 14.04.2020.
//

#ifndef HEURISTIC_A_SEARCH_H
#define HEURISTIC_A_SEARCH_H

#include "NODE.h"
#include "OPEN.h"
#include "CLOSED.h"
#include "MAP.h"
#include "PATH.h"

class A_search {
private:
    double _e;
    int _chosenOne;
    CLOSED closed;
    OPEN open;
    bool goal_is_not_reached = true;
    PATH path;
    //logs
    int iterations = 0;
    //time TODO
    std::unordered_map <int, class NODE>::iterator address_of_goal_node;
public:
    A_search(double e, double chosenOne);
    double computeCost(NODE& one, NODE& two);
    double hCalc(NODE &cur, NODE &goal);
    double gCalc(NODE &predecessor, NODE &successor);
    double fCalc(double const &g, double const &h);

    std::list<NODE> getSuccessors(NODE* current, NODE &goal, MAP &occupancyMap);
    void search(NODE &start, NODE &goal, MAP &occupancyMap);
    bool ok();
    void create_path(NODE &start);
    void extract_path(const std::string& path_file);

};


#endif //HEURISTIC_A_SEARCH_H
