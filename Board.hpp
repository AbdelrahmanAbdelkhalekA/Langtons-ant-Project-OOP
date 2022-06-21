//
// Created by 2002a on 4/10/2022.
//

#ifndef UNTITLED33_BOARD_H
#define UNTITLED33_BOARD_H
#include "Cell.hpp"
#include "Gary.hpp"
class Board {
public:
    char filename[40];
    Board();
    Board(unsigned int size);
    void setOutputFilename(char d[]);
    void move_gary (unsigned int steps);
private:
    int sizee, d = 0;
};
#endif //UNTITLED33_BOARD_H


