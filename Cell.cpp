#include "Cell.hpp"

Cell::Cell() {
    C = Color::white;
}

void Cell::next_color() {
    if (C == Color::white) {
        C = Color::black;
    } else {
        C = Color::white;
    }
}

Cell::Color Cell::get_color (){
    return C;
}
