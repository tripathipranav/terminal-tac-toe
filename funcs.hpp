#include <iostream>
using namespace std;

void draw_board(const int (&a)[3][3])
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

void player_turn(int a[3][3])
{
    int temp_var = 0;
    cout << "Which square? ";
    cin >> temp_var;

    switch(temp_var){
        case 1:
            if (a[0][0] == 0){
                a[0][0] += 1;
            }
            break;

        case 2:
            if (a[0][1] == 0){
                a[0][1] += 1;
            }
            break;

        case 3:
            if (a[0][2] == 0){
                a[0][2] += 1;
            }
            break;

        case 4:
            if (a[1][0] == 0){
                a[1][0] += 1;
            }
            break;

        case 5:
            if (a[1][1] == 0){
                a[1][1] += 1;
            }
            break;

        case 6:
            if (a[1][2] == 0){
                a[1][2] += 1;
            }
            break;

        case 7:
            if (a[2][0] == 0){
                a[2][0] += 1;
            }
            break;

        case 8:
            if (a[2][1] == 0){
                a[2][1] += 1;
            }
            break;

        case 9:
            if (a[2][2] == 0){
                a[2][2] += 1;
            }
            break;

        default:
            cout << "invalid entry!";
            player_turn(a);
            break;
    }
}

void cpu_turn(int (&a)[3][3])
{
    int temp_var = rand() % 9 + 1;

    switch(temp_var){
        case 1:
            if (a[0][0] == 0){
                a[0][0] += 2;
            }
            else {cpu_turn(a);}
            break;

        case 2:
            if (a[0][1] == 0){
                a[0][1] += 2;
            }
            else {cpu_turn(a);}
            break;

        case 3:
            if (a[0][2] == 0){
                a[0][2] += 2;
            }
            else {cpu_turn(a);}
            break;

        case 4:
            if (a[1][0] == 0){
                a[1][0] += 2;
            }
            else {cpu_turn(a);}
            break;

        case 5:
            if (a[1][1] == 0){
                a[1][1] += 2;
            }
            else {cpu_turn(a);}
            break;

        case 6:
            if (a[1][2] == 0){
                a[1][2] += 2;
            }
            else {cpu_turn(a);}
            break;

        case 7:
            if (a[2][0] == 0){
                a[2][0] += 2;
            }
            else {cpu_turn(a);}
            break;

        case 8:
            if (a[2][1] == 0){
                a[2][1] += 2;
            }
            else {cpu_turn(a);}
            break;

        case 9:
            if (a[2][2] == 0){
                a[2][2] += 2;
            }
            else {cpu_turn(a);}
            break;
    }
}