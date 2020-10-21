#include <iostream>
using namespace std;

void draw_board(int a[3][3])
{
    cout << '\n';

    for(int i = 0; i < 3; ++i){
        cout << a[0][i];
        if(i != 2){
            cout << " | ";
        }
        else{
            cout << " ";
        }
    }

    cout << '\n' << "----------" << '\n';

    for(int i = 0; i < 3; ++i){
        cout << a[1][i];
        if(i != 2){
            cout << " | ";
        }
        else{
            cout << " ";
        }
    }

    cout << '\n' << "----------" << '\n';

    for(int i = 0; i < 3; ++i){
        cout << a[2][i];
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
    const int empty = 0;
    const int   x   = 1;
    const int   o   = 2;

    int gameboard[3][3] = {{empty, empty, empty},
                           {empty, empty, empty},
                           {empty, empty, empty}};
    draw_board(gameboard);
}