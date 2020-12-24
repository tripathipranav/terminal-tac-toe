/* 
Terminal Tac Toe - v0.3
Pranav Tripathi

TODO:
- Add logic to CPU's turn
- Add # labels to grid
- Main turn loop
- Stop cycle when board is full, declare tie
- Declare winner when three in a row
*/

#include <iostream>
using namespace std;

//Declare funcs - can be called universally
void draw_board(char a[3][3]);
void player_turn(char a[3][3]);

//Draw grid and pass array to player func
void draw_board(char a[3][3])
{
    cout << a[0][0] << " | " << a[0][1] << " | " << a[0][2]
    << '\n' << "----------"
    << '\n' << a[1][0] << " | " << a[1][1] << " | " << a[1][2]
    << '\n' << "----------"
    << '\n' << a[2][0] << " | " << a[2][1] << " | " << a[2][2]
    << '\n';
}

//Get square from player, add x to array
void player_turn(char a[3][3])
{
    cout << "Enter square number: "; int choice; cin >> choice;
    switch(choice){
        case 1: a[0][0] = 'x'; break; case 2: a[0][1] = 'x'; break;
        case 3: a[0][2] = 'x'; break; case 4: a[1][0] = 'x'; break;
        case 5: a[1][1] = 'x'; break; case 6: a[1][2] = 'x'; break;
        case 7: a[2][0] = 'x'; break; case 8: a[2][1] = 'x'; break;
        case 9: a[2][2] = 'x'; break; 
        
        default: 
            cout << "Invalid entry!\n";
            player_turn(a);
            break;
    }
    draw_board(a);
}

//Initialize array, pass to function
int main()
{
    //Greeting + selection instructions
    cout << "Terminal Tac Toe v0.3 - Pranav Tripathi\n\n";
    cout << "Squares are numbered as follows:\n" <<
    "1 | 2 | 3\n" << "----------\n" << "4 | 5 | 6\n" <<
    "----------\n" << "7 | 8 | 9\n\n";
    cout << "Press ENTER to begin.";
    cin.ignore();
    cout << "\n\n";

    char gameboard[3][3] = {{' ', ' ', ' '},
                           {' ', ' ', ' '},
                           {' ', ' ', ' '}};
    draw_board(gameboard);
    player_turn(gameboard);
}