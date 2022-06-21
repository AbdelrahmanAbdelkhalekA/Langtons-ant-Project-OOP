
#include "Gary.hpp"



Gary::Gary(unsigned int Boardsize){ //intialize the intial point
        x = Boardsize / 2; // x and y acts as my snail loction that i will update each iteration
        y = Boardsize / 2;
        t = orientation::up;
        z = t;
        size = Boardsize;
    }


     orientation Gary::get_orientation(){
    return t;
     }
    //just for testing purpose -  i will add the algortihim later
    void Gary::move(Cell* v) {
        g = x;
        k = y;
        if (v->get_color() == Cell::black){
            switch (t){
                case orientation::up:
                    t = orientation::left;
                    x--;
                    g--;
                    break;
                case orientation::right:
                    t = orientation::up;
                    y--;
                    k--;
                    break;
                case orientation::down:
                    t = orientation::right;
                    x++;
                    break;
                case orientation::left:
                    t = orientation::down;
                    y++;
                    break;
            }
        }
        else if (v->get_color() == Cell::white){
            switch (t){
                case orientation::up:
                    t = orientation::right;
                    x++;
                    break;
                case orientation::right:
                    t = orientation::down;
                    y++;
                    break;
                case orientation::down:
                    t = orientation::left;
                    x--;
                    g--;
                    break;
                case orientation::left:
                    t = orientation::up;
                    y--;
                    k--;
                    break;
            }
        }
        z = t;
        if ((g<0) || (k<0)){
            if (g < 0){
                x = (size-1);
            }
            else {
                y = (size-1);
            }
        } else if ((x>(size-1) || (y>(size-1)))){
            if (x>(size-1)){
                x = 0;
            }else{
                y = 0;
            }
        }
        v->next_color();
    }

        std::tuple<int, int> Gary::get_location(){
        location = std::make_tuple(y,x);
        return location;
    }

    std::tuple<int, int> Gary::get_locatio(){
        location = std::make_tuple(x,y);
        return location;
    }

