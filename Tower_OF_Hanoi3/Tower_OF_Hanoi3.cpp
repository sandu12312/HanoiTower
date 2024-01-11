#include <iostream>
#include <fstream>
#include <string>
#include "Tower_Of_Hanoi.h"
#include "math.h"

using namespace std;

int disk_1[10], disk_2[10], disk_3[10];
int disk_number;
int game_over = 0, steps_number;

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
            cout << "-------------------------------------------------------------------------------------------------\n";
            cout << "                                           The rules\n";
            cout << "-------------------------------------------------------------------------------------------------\n";
            cout << "The mission is to move all the disks to third tower without violating the sequence of arrangement\n";
            cout << "1. Only one disk can be moved among the towers at any given time." << "\n";
            cout << "2. Only the \"top\" disk can be removed." << "\n";
            cout << "3. No large disk can sit over a small disk." << "\n";
            cout << "-------------------------------------------------------------------------------------------------\n";
            cout << "For Manual game you have to introduce 2 integers that means from which disk to which disk to move.\n";
            cout << "For Exemple:\nINPUT:1 2 -> you will move from the top first tower a disk to the top of second tower\n";
            cout << "-------------------------------------------------------------------------------------------------\n";
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

