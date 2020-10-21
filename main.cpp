#include <iostream>
using namespace std;

const int empty = 0;
const int   x   = 1;
const int   o   = 2;

int gameboard[3][3] = {{empty, empty, empty},
                       {empty, empty, empty},
                       {empty, empty, empty}};

void draw_board()
{
    cout << '\n';

    for(int i = 0; i < 3; ++i){
        cout << gameboard[0][i];
        if(i != 2){
            cout << " | ";
        }
        else{
            cout << " ";
        }
    }

    cout << '\n' << "----------" << '\n';

    for(int i = 0; i < 3; ++i){
        cout << gameboard[1][i];
        if(i != 2){
            cout << " | ";
        }
        else{
            cout << " ";
        }
    }

    cout << '\n' << "----------" << '\n';

    for(int i = 0; i < 3; ++i){
        cout << gameboard[2][i];
        if(i != 2){
            cout << " | ";
        }
        else{
            cout << " ";
        }
    }

    cout << "\n\n";
}

int main()
{
    draw_board();
}