#include "funcs.hpp"

int main()
{
    const int empty = 0;
    const int   x   = 1;
    const int   o   = 2;

    int gameboard[3][3] = {{empty, empty, empty},
                           {empty, empty, empty},
                           {empty, empty, empty}};
    draw_board(gameboard);
}