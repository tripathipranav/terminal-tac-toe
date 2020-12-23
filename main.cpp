#include <iostream>
using namespace std;

void cycle(char a[3][3]);
void draw_board(char a[3][3])
{
    cout << '\n';
    for(int y = 0; y < 3; ++y){
        for(int x = 0; x < 3; ++x){
            cout << a[y][x];
            if(x != 2){cout << " | ";}
            else{cout << " ";}
        }
        if(y != 2){cout << '\n' << "----------" << '\n';}
        else{cout << '\n';}
    }
    cout << '\n';
    cycle(a);
}

void cpu_turn(char a[3][3])
{
    int x = rand() % 3, y = rand() % 3;
    if(a[x][y] == ' '){a[x][y] = 'o'; draw_board(a);}
    else{cpu_turn(a);}
}

void player_turn(char a[3][3])
{
    int x, y;
    cout << "Which square? ";
    cin >> x >> y;
    if(a[x][y] == ' ' && x < 3 && x > -1 && y < 3 && y > -1){a[x][y] = 'x';}
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

int main()
{
    char gameboard[3][3] = {{' ', ' ', ' '},
                           {' ', ' ', ' '},
                           {' ', ' ', ' '}};
    cycle(gameboard);
}
