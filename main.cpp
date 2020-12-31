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

//Check lines and attempt to win
void cpu_turn(char (&a)[3][3])
{
    vector<int> winning_xcoords;
    vector<int> winning_ycoords;
    vector<int> losing_xcoords;
    vector<int> losing_ycoords;

    for(int x = 0; x < 3; ++x){
        int Os = 0;
        int Xs = 0;
        for(int y = 0; y < 3; ++y){
            if(a[x][y] == 'o'){
                ++Os;
            }
            else if(a[x][y] == 'x'){
                ++Xs;
            }
        }
        if(Os > 1){winning_xcoords.push_back(x);}
        if(Xs > 1){losing_xcoords.push_back(x);}
    }

    for(int y = 0; y < 3; ++y){
        int Os = 0;
        int Xs = 0;
        for(int x = 0; x < 3; ++x){
                if(a[x][y] == 'o'){
                ++Os;
            }
            else if(a[x][y] == 'x'){
                ++Xs;
            }
        }
        if(Os == 1){winning_ycoords.push_back(y);}
        if(Xs == 1){losing_ycoords.push_back(y);}
    }

    if(winning_xcoords.size() != 0){
        int coord = winning_xcoords[0];
        for(int y = 0; y < 3; ++y){
            if(a[winning_xcoords[0]][y] == ' '){a[winning_xcoords[0]][y] = 'o';}
        }
    }
    else if(winning_ycoords.size() != 0){
        int coord = winning_ycoords[0];
        for(int x = 0; x < 3; ++x){
            if(a[x][winning_ycoords[0]] == ' '){a[x][winning_ycoords[0]] = 'o';}
        }
    }
    else if(losing_xcoords.size() != 0){
        int coord = losing_xcoords[0];
        for(int y = 0; y < 3; ++y){
            if(a[losing_xcoords[0]][y] == ' '){a[losing_xcoords[0]][y] = 'o';}
        }
    }
    else if(losing_ycoords.size() != 0){
        int coord = losing_ycoords[0];
        for(int x = 0; x < 3; ++x){
            if(a[x][losing_ycoords[0]] == ' '){a[x][losing_ycoords[0]] = 'o';}
        }
    }
    else if(winning_xcoords.size() == 0 && winning_ycoords.size() == 0 
    && losing_xcoords.size() == 0 && losing_ycoords.size() == 0){
        cout << "no good moves";
    }
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