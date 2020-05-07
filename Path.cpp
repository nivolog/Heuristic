//
// Created by what_is_love on 16.04.2020.
//

#include "Path.h"

void PATH::add_node(NODE &node) {
    _PATH.push(node);
}

void PATH::extract_path(const std::string& path_file) {
    std::ofstream path;
    path.open(path_file);
    int x_path, y_path;
    int range = _PATH.size();
    for (int i = 0; i < range; ++i){
        x_path = _PATH.top().x_coordinate;
        y_path = _PATH.top().y_coordinate;
        PATH.pop();
        path <<  x_path << " " << y_path << "\n";
    }
    path.close();

}
