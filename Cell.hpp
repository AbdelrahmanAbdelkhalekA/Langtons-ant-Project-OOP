//
// Created by 2002a on 4/10/2022.
//

#ifndef UNTITLED33_CELL_H
#define UNTITLED33_CELL_H

#include <iostream>
#include <cstdio> // std::sscanf
#include <cstring> // std::strcmp
#include <tuple>
#include <fstream>

enum class orientation {up = 0, right , down , left}; //static_cast
class Cell {
public:
    enum Color { white, black}; //public
    Color C;
    Cell();
    void next_color();
    Color get_color ();
};
#endif //UNTITLED33_CELL_H
