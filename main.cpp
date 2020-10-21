#include <iostream>
using namespace std;

void draw_board(int a[3][3])
{
    cout << '\n';

    for(int y = 0; y < 3; ++y){
        for(int x = 0; x < 3; ++x){
            cout << a[y][x];
            if(x != 2){
                cout << " | ";
            }
            else{
                cout << " ";
            }
        }
        if(y != 2){
            cout << '\n' << "----------" << '\n';
        }
        else{
            cout << '\n';
        }
    }

    cout << '\n';
}

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