#include <iostream>
using namespace std;

void cycle(char a[3][3]);
void draw_board(char a[3][3])
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
    cycle(a);
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
    draw_board(a);
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
    cpu_turn(a);
}

void cycle(char a[3][3])
{
    int i = 0;
    for(int y = 0; y < 3; ++y){
        for(int x = 0; x < 3; ++x){
            if(a[x][y] == ' '){
                i++;
            }
        }
    }
    if(i > 0){player_turn(a);}
    else if(i == 0){ draw_board(a); cout << "Game over!"; }
}
