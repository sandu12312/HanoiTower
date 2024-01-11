

#include <iostream>
#include <fstream>
#include <string>
#include "Tower_Of_Hanoi.h"
#include "math.h"
#include <thread>

using namespace std;



int disk_1[10], disk_2[10], disk_3[10];
int disk_number;
int game_over = 0, steps_number;

char rod[] = { 'S', 'A', 'D' };
int rods[1000][10000]; // Assuming a maximum of 10 disks for each rod
int top[3] = { -1, -1, -1 }; // To keep track of the top of each rod

int x, y, z;
void moveDisk(int a, int b)
{
    if (top[b] == -1 || (top[a] != -1 && rods[a][top[a]] < rods[b][top[b]]))
    {
        cout << "Move disk " << rods[a][top[a]] << " from rod " << rod[a] << " to rod " << rod[b] << "\n";
        if (rod[a] == 'S' && rod[b] == 'D')
        {
            z++;
            disk_3[z] = disk_1[x];
            disk_1[x] = 0; 
            x--;
            cout << x << " " << y << " " << z << "\n";
            
        }
        else if (rod[a] == 'D' && rod[b] == 'S')
        {
            x++;
            disk_1[x] = disk_3[z];
            disk_3[z] = 0;      
            z--;
            cout << x << " " << y << " " << z << "\n";
        }
        else if (rod[a] == 'S' && rod[b] == 'A')
        {
            y++;
            disk_2[y] = disk_1[x];
            disk_1[x] = 0;
            x--;
            cout << x << " " << y << " " << z << "\n";
        }
        else if (rod[a] == 'A' && rod[b] == 'S')
        {
            x++;
            disk_1[x] = disk_2[y];
            disk_2[y] = 0;
            y--;
            cout << x << " " << y << " " << z << "\n";
        }
        else if (rod[a] == 'D' && rod[b] == 'A')
        {
            y++;
            disk_2[y] = disk_3[z];
            disk_3[z] = 0;
            z--;
            cout << x << " " << y << " " << z << "\n";
        }
        else if (rod[a] == 'A' && rod[b] == 'D')
        {
            z++;
            disk_3[z] = disk_2[y];
            disk_2[y] = 0;
            y--;
            cout << x << " " << y << " " << z << "\n";
        }
        rods[b][++top[b]] = rods[a][top[a]--];
    }
    else
    {
        moveDisk(b, a);
    }
}

void initialize_vars(int disks) 
{
    for (int i = 0; i < 3; i++)
    {
        top[i] = -1;
    }
    x = disks;
    y = 0;
    z = 0;
}

void automated_game(int n)
{
   
    cout << "Tower of Hanoi for " << n << " disks:\n";
    initialize_vars(n);
    int src = 0, aux = 1, dest = 2;
    for (int i = n; i > 0; i--)
        rods[src][++top[src]] = i;

    int totalMoves = (1 << n) - 1;
    if (n % 2 == 0)
        swap(aux, dest);

    for (int i = 1; i <= totalMoves; i++)
    {
        if (i % 3 == 0)
        {
            moveDisk(aux, dest);
            Display_Towers(n);
            this_thread::sleep_for(chrono::milliseconds(400));
        }
        else if (i % 3 == 1)
        {
            moveDisk(src, dest);
            Display_Towers(n);
            this_thread::sleep_for(chrono::milliseconds(400));
        }
        else
        {
            moveDisk(src, aux);
            Display_Towers(n);
            this_thread::sleep_for(chrono::milliseconds(400));
        }
    }
}


int main()
{


    int i;
    int move_from, move_to;
    

 
    int game_mode, opt;
    
    cout << "Welcome to play Tower of Hanoi!!!" << "\n";

    
    while (1)
    {
        cout << "1.Rules of the game." << "\n";
        cout << "2.Play the manual game" << "\n";
        cout << "3.Let the game play for you" << "\n";

        cout << "Please read an option from below:";
        cin >> game_mode;

        switch (game_mode)
        {
        case 1:
            cout << "--------------------\n";
            cout << "The rules\n";
            cout << "--------------------\n";
            break;
        case 2:
           
            cout << "\nRead the number of disks you want to play:";
            cin >> disk_number;
            if (disk_number > 8) 
            {
                cout << "----------------\n";
                cout << "Overflow\n";
                cout << "----------------\n";
            }
            else
            {

                game_over = 0;

                Disk_Initialization(disk_number);
                Display_Towers(disk_number);

                while (game_over != 1)
                {



                    cout << "\nRead from what tower to what tower you want to make the move:";
                    cin >> move_from >> move_to;
                    change_disk(move_from, move_to);
                    Display_Towers(disk_number);
                    if (Check_GameStatus() == 1)
                    {

                        cout << "\n" << "--------------------------\n";
                        cout << "Congrats, you won the game!!!";
                        cout << "\nYou finished in " << tries << " moves";
                        cout << "\n" << "--------------------------\n";
                        Disk_Initialization(disk_number);
                        ok = 0;
                        game_over = 1;
                    }
                }
            }
            break;
        case 3:
            cout << "\nRead the number of disks the bot to play:";
            cin >> disk_number;
            if (disk_number > 8)
            {
                cout << "----------------\n";
                cout << "Overflow\n";
                cout << "----------------\n";
            }
            else
            {
                Disk_Initialization(disk_number);
                automated_game(disk_number);
                cout << "-----------------------------------------------------\n";
                cout << "The Computer Finished the game in " << (1 << disk_number) - 1 << " moves" << "\n";
                cout << "-----------------------------------------------------\n";
                break;
            }
        default:
            cout << "--------------------\n";
            cout << "INVALIDE OPTION"<<"\n";
            cout << "--------------------\n";
            break;
        }

    }



    return 0;
}

int ReturnDiskNumbers(void)
{
    return disk_number;
}

