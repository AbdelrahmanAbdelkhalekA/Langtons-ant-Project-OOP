# Langtons-ant-Project-OOB


Gary the snail exists on a Board which consists of an N by N grid of Cells. The program functions using three main classes: Board, Gary, and Cell. The Board class drives the program in that it parameterizes the Gary class and issues K commands for Gary to move. On each step, Gary moves based on the Cell he currently occupies (passed by the Board class). Gary is responsible for the Board's wrapping boundary conditions. We will track the overall state of the program (all Cell colors and Gary's orientation) via formatted output either to standard output or to a file. Note that this output may be used to create a visualization if desired as the code also save the snail moves in an a two-dimensional array that can be easily printed out.


A N by N square grid is intialized where N is always an odd number where also the Cell class outputs if the cells are either white or black. The ant start at the center of the grid with an orientation initially intialized with an up orientation. The number of steps the ant preforms is decided by the user.
 
    1.If Gary is on a white square turn 90 deg clockwise, flip the color of the square, and move forward one unit. 
    2.If Gary is on a black square turn 90 deg counterclockwise, flip the color of the square, and move forward one unit. 
 
 
## Main Funtion:
 
The main function is compiled into an executable named FindGary. The main function shall accept two (2) or three (3) command line arguments and will be called either as ./FindGary BoardSize Steps or ./FindGary BoardSize Steps OutputFilename where BoardSize and Steps will be unsigned integer values and OutputFilename will be a char array. The main program should construct a Board object, optionally sets the output filename if given as a command line argument, and shall execute Gary's movement through Board's member function.
 
## Board Class:

The Board class shall be constructed given an unsigned integer parameter that defines the number of rows and columns, i.e., 'N' in the N by N board. Note that N must be odd. If N is given as even, students shall display a message (only to std::cout and not to any file argument!) stating "Board dimension must be an odd number!! Got {N} and adding 1 to equal {N+1}" (note that parameters within { } must be printed as their values and the { } should not be printed) and shall add 1 to N to satisfy the requirement that N must be odd. Note that this message must be printed only to the console, i.e., should not be printed to the output file.


Gary shall move around the board when the Board::move_gary(unsigned int steps) function is called. Each step shall be one step of Langton's ant as defined above, i.e., change Gary's orientation based on the Cell input, change the cell color, and move Gary forward one unit. The board class shall print the state of the board at every step. See the below example with a boardSize input of 5 for 10 steps:

    [Gary Location] {2, 2} [Gary Orientation] up [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 0 0 0 [Row 3] 0 0 0 0 0 [Row 4] 0 0 0 0 0
    [Gary Location] {2, 3} [Gary Orientation] right [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 1 0 0 [Row 3] 0 0 0 0 0 [Row 4] 0 0 0 0 0
    [Gary Location] {3, 3} [Gary Orientation] down [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 1 1 0 [Row 3] 0 0 0 0 0 [Row 4] 0 0 0 0 0
    [Gary Location] {3, 2} [Gary Orientation] left [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 1 1 0 [Row 3] 0 0 0 1 0 [Row 4] 0 0 0 0 0
    [Gary Location] {2, 2} [Gary Orientation] up [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 1 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
    [Gary Location] {2, 1} [Gary Orientation] left [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 0 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
    [Gary Location] {1, 1} [Gary Orientation] up [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 1 0 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
    [Gary Location] {1, 2} [Gary Orientation] right [Row 0] 0 0 0 0 0 [Row 1] 0 1 0 0 0 [Row 2] 0 1 0 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
    [Gary Location] {2, 2} [Gary Orientation] down [Row 0] 0 0 0 0 0 [Row 1] 0 1 1 0 0 [Row 2] 0 1 0 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
    [Gary Location] {2, 1} [Gary Orientation] left [Row 0] 0 0 0 0 0 [Row 1] 0 1 1 0 0 [Row 2] 0 1 1 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
    [Gary Location] {3, 1} [Gary Orientation] down [Row 0] 0 0 0 0 0 [Row 1] 0 1 1 0 0 [Row 2] 0 0 1 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0


the format is given by [Gary Location] {(row), (col)} (orientation) [Row 0] (col 0 color) (col 1 color) ... (col N-1 color) [Row 1] ... [Row (N-1)] ... (col N-1 color) where values within ( ) are to be filled in with program values. (col i color) shall be either "0" for "white" or "1" for "black". This output will either be to standard output, i.e., std::cout, if a filename command line argument is not provided or will be printed to the filename given in the argument (students should use the ofstream object for file output. Note that C's fprintf will also be okay). The filename shall be set with the void Board::setOutputFilename(std::string) member function.

## Cell Class

This class will be used to define the N by N board in the final solution (there will be N 2 Cell objects which define the board). You are to program the Cell class according to the following design criteria:

The Cell class shall define a public unscoped enumeration member type Color, i.e., Cell::Color where the enumeration is declared within the class scope, with values white and black. This enumeration type is used to determine the "color" of the Cell and therefore how Gary change's his orientation.
The Cell class shall be constructed using the default constructor, i.e., will not accept any arguments. The constructor shall set color to white upon construction.
The Cell class shall contain a public member function named next_color to toggle the Color-type member. I.e., if the color is currently set to white, calling next_color() will change color to black and vise versa. The member function next_color will return type void and will accept no input parameters.
The Cell class shall have a "getter" function to return the Color named get_color() which returns the Cell's current color.

This class is the "Ant" in "Langton's Ant". Gary moves around the grid of cells and changes orientation based on the current cell he occupies. You are to program Gary to the following criteria:

## Gary Class:

Gary is constructed with a parameterized constructor accepting an unsigned integer input parameter representing the size of the board (denote here as BoardSize). Gary shall initialize his position to be the middle cell of the board, e.g., if the BoardSize is given as 5 Gary would be initialized at index (2,2). The Gary constructor should assume the parameter given is odd (and therefore you should make sure the parameter is odd before constructing the Gary-type member of Board)

Gary is an disallowed default construction, i.e., Gary() = delete;. Note this means you will either have to allocate in the Board class via dynamic memory allocation or construct the Gary-type member via the Board constructor's member initialization list (the ternary operator is how I constructed Gary in the member initialization list).

Gary contains a public member function get_location which accepts no input and returns a std::tuple<unsigned int, unsigned int> type where the 0th element denotes the row and the 1st element denotes the column Gary current occupies.

Gary contains a public member function which returns type void and accepts a Cell pointer called Gary::move(Cell*) which shall (a) alter Gary's orientation based on the Cell's color (b) change the Cell's color (c) move Gary one unit forward in the new orientation.

Gary wraps around the board when moving out of bounds, e.g., from the top row to the bottom row. 

Gary contains a public member function which returns type orientation which is a scoped enumeration type, i.e., enum class orientation, which has values (in order) "up, right, down, left".
