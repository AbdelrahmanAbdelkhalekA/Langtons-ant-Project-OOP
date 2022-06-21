

#include "Cell.hpp"
#include "Gary.hpp"
#include "Board.hpp"
int main(int argc, char* argv[]){
    Cell temp;
    unsigned int boardSize = atoi(argv[1]);
    unsigned int numberSteps = atoi(argv[2]);
    Board B(boardSize);
    if (argc == 4){
    char outputFilename[40];
    strcpy(outputFilename,argv[3]);
    B.setOutputFilename(outputFilename);
    }
    B.move_gary(numberSteps); 
    return 0;
}
