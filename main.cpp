#include <iostream>
using namespace std;

/*
    Board Layout

     1 | 2 | 3
     ---------
     4 | 5 | 6
     ---------
     7 | 8 | 9
    
*/

//Global vars for access to all functions
int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0;

int main()
{
    
}

int player_turn()
{
    int temp_var;
    cout << "Which Square? ";
    cin >> temp_var;
    return temp_var;
}

int enemy_turn()
{
    int temp_var = rand() % 11 + 1;
    return temp_var;
}

void check_square(int x)
{
    switch (x)
    {
    case 1:
        one += 1;
        break;

    case 2:
        two += 1;
        break;

    case 3:
        three += 1;
        break;

    case 4:
        four += 1;
        break;
        
    case 5:
        five += 1;
        break;
        
    case 6:
        six += 1;
        break;
        
    case 7:
        seven += 1;
        break;
        
    case 8:
        eight += 1;
        break;
        
    case 9:
        nine += 1;
        break;
    
    default:
        cerr << "Invalid entry!";
        break;
    }
}