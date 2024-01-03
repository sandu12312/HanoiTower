#include <iostream>
#include <fstream>
#include <string>
#include "Tower_Of_Hanoi.h"


using namespace std;



int disk_1[10], disk_2[10], disk_3[10];
int disk_number;
int ok = 0;
int i1, i2, i3;


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
    cout << "Cititi numarul de disk - uri:";
    cin >> disk_number;
    Disk_Initialization(disk_number);
   // Display_Towers(disk_number);
    change_disk(1, 2);
    cout << "\n";
    Display_Towers(disk_number);
    change_disk(1, 3);
    cout << "\n";
    Display_Towers(disk_number);
    change_disk(2, 3);
    cout << "\n";
    Display_Towers(disk_number);



  
 
    int opt;
    
    

    for (i = 1; i <= 8; i++)
    {
       
        cout<<disk_2[i]<<"\n";

    }
    return 0;
}


