/* 
Terminal Tac Toe - v0.5
Pranav Tripathi

TODO:
- Stop cycle when board is full, declare tie
- Declare winner when three in a row
- Fix invalid choice error - multiple calls of draw_board()
- Whole thing needs a rework - redundant stuff and passing
the array around between functions is stupid
*/

#include <iostream>
#include <vector>
using namespace std;

//Declare functions to be called
void draw_board(char (&a)[3][3]);
void player_turn(char (&a)[3][3]);
void cpu_turn(char (&a)[3][3]);
void cpu_random(char (&a)[3][3]);

//Draw board
void draw_board(char (&a)[3][3])
{
    cout << a[0][0] << " | " << a[0][1] << " | " << a[0][2]
    << '\n' << "----------"
    << '\n' << a[1][0] << " | " << a[1][1] << " | " << a[1][2]
    << '\n' << "----------"
    << '\n' << a[2][0] << " | " << a[2][1] << " | " << a[2][2]
    << '\n';
}

void player_turn(char (&a)[3][3])
{
    //Get player choice, fill in associated square
    int choice = 0;
    cout << "Enter square number: "; cin >> choice;
    switch(choice){
        case 1: a[0][0] = 'x'; break; case 2: a[0][1] = 'x'; break;
        case 3: a[0][2] = 'x'; break; case 4: a[1][0] = 'x'; break;
        case 5: a[1][1] = 'x'; break; case 6: a[1][2] = 'x'; break;
        case 7: a[2][0] = 'x'; break; case 8: a[2][1] = 'x'; break;
        case 9: a[2][2] = 'x'; break; 
        default: 
            cout << "Invalid entry!\n";
            break;
    }
    cout << '\n';
}

int scan_row(const char (&a)[3][3], int x)
{
    int n1 = 0, n2 = 0;
    for(int i = 0; i < 3; ++i){
        if(a[x][i] == 'x') ++n1;
        if(a[x][i] == 'o') ++n2;
    }
    if(n2 == 2){
        for(int i = 0; i < 3; ++i){
        if(a[x][i] == ' ') return i;
        }
    } 
    else if(n1 == 2){
        for(int i = 0; i < 3; ++i){
        if(a[x][i] == ' ') return i;
        }
    } 
    return 999;
}

int scan_col(const char (&a)[3][3], int y)
{
    int n1 = 0, n2 = 0;
    for(int i = 0; i < 3; ++i){
        if(a[i][y] == 'x') ++n1;
        if(a[i][y] == 'o') ++n2;
    }
    if(n2 == 2){
        for(int i = 0; i < 3; ++i){
        if(a[i][y] == ' ') return i;
        }
    }
    else if(n1 == 2){
        for(int i = 0; i < 3; ++i){
        if(a[i][y] == ' ') return i;
        }
    }
    return 999;
}

pair<int, int> scan_diag1(const char (&a)[3][3])
{
    int n1 = 0, n2 = 0;
    for(int x = 0, y = 0; x < 3 && y < 3; ++x, ++y){
        if(a[x][y] == 'x') ++n1;
        if(a[x][y] == 'o') ++n2;
    }
    if(n2 == 2){
        for(int x = 0, y = 0; x < 3 && y < 3; ++x, ++y){
            if(a[x][y] == ' ') return make_pair(x, y);
        }
    }
    else if(n1 == 2){
        for(int x = 0, y = 0; x < 3 && y < 3; ++x, ++y){
            if(a[x][y] == ' ') return make_pair(x, y);
        }
    }
    return make_pair(999, 999);
}

pair<int, int> scan_diag2(const char (&a)[3][3])
{
    int n1 = 0, n2 = 0;
    for(int x = 0, y = 2; x < 3 && y < 3; ++x, --y){
        if(a[x][y] == 'x') ++n1;
        if(a[x][y] == 'o') ++n2;
    }
    if(n2 == 2){
        for(int x = 0, y = 2; x < 3 && y < 3; ++x, --y){
            if(a[x][y] == ' ') return make_pair(x, y);
        }
    }
    else if(n1 == 2){
        for(int x = 0, y = 2; x < 3 && y < 3; ++x, --y){
            if(a[x][y] == ' ') return make_pair(x, y);
        }
    }
    return make_pair(999, 999);
}

pair<int, int> random_square(const char (&a)[3][3])
{
    int x = rand() % 3;
    int y = rand() % 3;
    if(a[x][y] == ' ') return make_pair(x, y);
    else{random_square(a);}
}

void cpu_turn(char (&a)[3][3])
{
    for(int x = 0; x < 3; ++x){
        int y = scan_row(a, x);
        if(y != 999){
            a[x][y] = 'o';
            return;
        }
    }
    for(int y = 0; y < 3; ++y){
        int x = scan_col(a, y);
        if(x != 999){
            a[x][y] = 'o';
            return;
        }
    }
    pair<int, int> dia1 = scan_diag1(a);
    if(dia1.first != 999 && dia1.second != 999){
        a[dia1.first][dia1.second] = 'o';
        return;
    }
    pair<int, int> dia2 = scan_diag2(a);
    if(dia2.first != 999 && dia2.second != 999){
        a[dia2.first][dia2.second] = 'o';
        return;
    }

    pair<int, int> random = random_square(a);
    a[random.first][random.second] = 'o';
    return;
}

//Initialize array, pass to function
int main()
{
    //Greeting + selection instructions
    cout << "\nTerminal Tac Toe v0.3 - Pranav Tripathi\n\n";
    cout << "Squares are numbered as follows:\n" <<
    "1 | 2 | 3\n" << "----------\n" << "4 | 5 | 6\n" <<
    "----------\n" << "7 | 8 | 9\n\n";
    cout << "Press ENTER to begin.";
    cin.ignore();
    cout << "\n\n";
    
    //Create array
    char gameboard[3][3] = {{' ', ' ', ' '},
                           {' ', ' ', ' '},
                           {' ', ' ', ' '}};
}