#include <iostream>
#include <fstream>
#include <string>
#include "Tower_Of_Hanoi.h"


using namespace std;



int disk_1[10], disk_2[10], disk_3[10];
int disk_number;


int game_over = 0;


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
         
            
                


           
            break;
        default:
            cout << "--------------------\n";
            cout << "Optiune invalida"<<"\n";
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

