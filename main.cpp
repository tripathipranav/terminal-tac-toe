#include "funcs.hpp"

int main()
{
    const char empty = ' ';
    const char   x   = 'x';
    const char   o   = 'o';
    char gameboard[3][3] = {{empty, empty, empty},
                           {empty, empty, empty},
                           {empty, empty, empty}};
    draw_board(gameboard);
    player_turn(gameboard);
    draw_board(gameboard);
}