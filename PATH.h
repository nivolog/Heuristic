//
// Created by what_is_love on 16.04.2020.
//

#ifndef HEURISTIC_PATH_H
#define HEURISTIC_PATH_H

#include "NODE.h"
#include <stack>
#include <fstream>
#include <string>

class PATH {
private:
    std::stack  <NODE> _PATH;
public:
    void add_node(NODE &node);
    void extract_path(const std::string& path_file);
};


#endif //HEURISTIC_PATH_H
