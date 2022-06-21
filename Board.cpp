#include "Board.hpp"

    Board::Board() {

    }
    void Board::setOutputFilename(char d[]){
    strcpy(filename, d);
}
    Board::Board(unsigned int size){
        if (size % 2 == 0){
            std::cout << "Board dimension must be an odd number!! Got " << size << " and adding 1 to equal " << (size+1) << std::endl;
            size++;
        }
        sizee = size;
    }

    void Board::move_gary (unsigned int steps){
        std::ofstream f;
        f.open(filename);
        Cell c;
        Gary temp(sizee);
        int board[sizee][sizee];
        if (d == 0) { // intialize all the grid to 0 (white)
            for (int i = 0; i < sizee; i++) {
                for (int j = 0; j < sizee; j++) {
                    board[i][j] = 0;
                }
            }
        }

        int x, y, printx, printy;
        std::tuple<int, int> location1 = temp.get_locatio(); //32
        printy = std::get<0>(location1);
        printx = std::get<1>(location1);
        //[Gary Location] {2, 2} [Gary Orientation] up [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 0 0 0 [Row 3] 0 0 0 0 0 [Row 4] 0 0 0 0 0
        for (unsigned int g = 0; g <= steps; g++) {
            if (d != 0)
            {
                std::cout << std::endl;

                f << std::endl;
            }
            d++; 
            f << "[Gary Location] ";
            std::cout << "[Gary Location] ";
            std::cout  << "{" << printx << ", " << printy << "} ";
            f  << "{" << printx << ", " << printy << "} ";
            std::cout << "[Gary Orientation] ";
            f << "[Gary Orientation] ";
            switch (temp.z){
                case orientation::up:
                    std::cout << "up ";
                    f << "up ";
                    break;
                case orientation::right:
                    std::cout << "right ";
                    f << "right ";
                    break;
                case orientation::down:
                    std::cout << "down ";
                    f << "down ";
                    break;
                case orientation::left:
                    std::cout << "left ";
                    f << "left ";
                    break;
            }
                for (int i = 0; i < sizee; i++) { //the cell information is shared between gary  and booard to keep up with the color
                    std::cout << "[Row " << i << "]";
                    f << "[Row " << i << "]";
                    for (int j = 0; j < sizee; j++) {
                        std::cout << " " << board[i][j];
                        f << " " << board[i][j];
                    }
                    std::cout << " ";
                    f << " ";
                }
            std::tuple<int, int> location1 = temp.get_locatio(); //32
            y = std::get<0>(location1);
            x = std::get<1>(location1);
            if ((board[x][y] == 1) && (c.get_color() == Cell::white)){ //22
                c.next_color();
            }
            else if ((board[x][y] == 0) && (c.get_color() == Cell::black)){
                c.next_color();
            }
            temp.move(&c); //will return 22
             c.next_color();
            if ((board[x][y] == 0) && (c.get_color() == Cell::white)) {
                c.next_color();
            }
            else if ((board[x][y] == 1) && (c.get_color() == Cell::black)){
                c.next_color();
            }

            if (c.get_color() == Cell::black){ //2/2 (white)
                board[x][y] = 1;
            }
            else {
                board[x][y] = 0;
            }
            std::tuple<int, int> location = temp.get_locatio(); //32
            printy = std::get<0>(location);
            printx = std::get<1>(location);
        }
    }

