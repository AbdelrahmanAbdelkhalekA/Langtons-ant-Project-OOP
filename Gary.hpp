//
// Created by 2002a on 4/10/2022.
//

#ifndef UNTITLED33_GARY_H
#define UNTITLED33_GARY_H

#define GARY_TEST_VERBOSE

#include "Cell.hpp"
class Gary {
public:
orientation t;
std::tuple<int, int> get_locatio();
    unsigned int x, y, size;
    int g, k; // enum class orientation {up = 0, right , down , left}; //static_cast
    orientation z;
    orientation get_orientation();
    Gary(unsigned int Boardsize); //just for testing purpose -  i will add the algortihim later
    std::tuple<int, int> location;
    std::tuple<int, int> get_location();
    void move(Cell* v);
};
#endif //UNTITLED33_GARY_H
