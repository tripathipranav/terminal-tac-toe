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
    if(a[x_choice][y_choice] == ' '){
        a[x_choice][y_choice] = 'x';
    }
    else{
        cout << "Square already in use! Please try again.\n\n";
        player_turn(a);
    }
}