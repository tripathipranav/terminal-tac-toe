#include <iostream>
using namespace std;

void draw_board(const char (&a)[3][3])
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

void player_turn(char a[3][3])
{
    int x_choice, y_choice;
    cout << "Which square? ";
    cin >> x_choice >> y_choice;
    if(a[x_choice][y_choice] == ' ' && x_choice < 3
    && x_choice > -1 && y_choice < 3 && y_choice > -1){
        a[x_choice][y_choice] = 'x';
    }
    else{
        cout << "Square already in use! Please try again.\n";
        player_turn(a);
    }
}

void cpu_turn(char a[3][3])
{
    int x_choice = rand() % 2 + 0;
    int y_choice = rand() % 2 + 0;
    if(a[x_choice][y_choice] == ' ' && x_choice < 3
    && x_choice > -1 && y_choice < 3 && y_choice > -1){
        a[x_choice][y_choice] = 'o';
    }
    else{cpu_turn(a);}
}

int main()
{
    char gameboard[3][3] = {{' ', ' ', ' '},
                           {' ', ' ', ' '},
                           {' ', ' ', ' '}};
}   
