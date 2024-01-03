#include <iostream>
#include <fstream>
#include <string>
#include "Tower_Of_Hanoi.h"


using namespace std;



int disk_1[10], disk_2[10], disk_3[10];
int disk_number;
int ok = 0;
int i1, i2, i3;
int game_over = 0;

void change_disk(int x, int y)
{
    
    if (ok == 0)
    {
         i1 = disk_number, i2 = 0, i3 = 0;
        ok = 1;
    }
    disk_2[0] = 99;
    disk_3[0] = 99;
       if (x == 1 && y == 2)
        {
            if (disk_2[i2] > disk_1[i1])
            {
                disk_2[i2+1] = disk_1[i1];
                disk_1[i1] = 0;
                i2++;
                i1--;
            }
            else
            {
                cout << "Invalid move"<<"\n\n";
            }
        }
       else if (x==1 && y==3)
       {
           if (disk_3[i3] > disk_1[i1])
           {
               disk_3[i3 + 1] = disk_1[i1];
               disk_1[i1] = 0;
               i3++;
               i1--;
           }
           else
           {
               cout << "Invalid move" << "\n\n";
           }

       }
       else if (x == 2 && y == 3)
       {
           if (disk_3[i3] > disk_2[i2])
           {
               disk_3[i3 + 1] = disk_2[i2];
               disk_2[i2] = 0;
               i3++;
               i2--;
           }
           else
           {
               cout << "Invalid move" << "\n\n";
           }

       }
       else if (x == 2 && y == 1)
       {
           if (disk_1[i1] > disk_2[i2])
           {
               disk_1[i1 + 1] = disk_2[i2];
               disk_2[i2] = 0;
               i1++;
               i2--;
           }
           else
           {
               cout << "Invalid move" << "\n\n";
           }

       }
       else if (x == 3 && y == 1)
       {
           if (disk_1[i1] > disk_3[i3])
           {
               disk_1[i1 + 1] = disk_3[i3];
               disk_3[i3] = 0;
               i1++;
               i3--;
           }
           else
           {
               cout << "Invalid move" << "\n\n";
           }

       }
       else if (x == 3 && y == 2)
       {
           if (disk_2[i2] > disk_3[i3])
           {
               disk_2[i2 + 1] = disk_3[i3];
               disk_3[i3] = 0;
               i2++;
               i3--;
           }
           else
           {
               cout << "Invalid move" << "\n\n";
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
            Disk_Initialization(disk_number);
            Display_Towers(disk_number);
            
            while (game_over != 1) 
            {
                cout << "\nRead from what tower to what tower you want to make the move:";
                cin >> move_from >> move_to;
                change_disk(move_from, move_to);
                Display_Towers(disk_number);
            }
         
            
                


           
            break;
        default:
            cout << "--------------------\n";
            cout << "Optiune invalida"<<"\n";
            cout << "--------------------\n";
            break;
        }

    }

    

    for (i = 1; i <= 8; i++)
    {
       
        cout<<disk_2[i]<<"\n";

    }
    return 0;
}


