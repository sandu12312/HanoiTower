#include "Display_Disk.h"


//Disk_Initialization makes the full first tower and empty second and third tower
void Disk_Initialization(int number_of_discs)
{
    int i;

    int counter = number_of_discs + 1;
    for (i = 1; i <= number_of_discs; i++)
    {
        counter--;
        disk_1[i] = counter;

    }
    for (i = 1; i <= number_of_discs; i++)
    {
        disk_2[i] = 0;
        disk_3[i] = 0;
    }
   
}

char tower_forms[10][50]{  "        |        ", 
                           "        *        ",
                           "       ***       ",
                           "      *****      ",
                           "     *******     ",
                           "    *********    ",
                           "   ***********   ",
                           "  *************  ",
                           " *************** "
};





//Display the towers
void Display_Towers(int number_of_discs)
{
    int i, j;
    for (i = number_of_discs; i >= 1; i--)
    {
        if (disk_1[i] != 0)
        {
            cout << tower_forms[disk_1[i]];
        }
        else
        {
            cout << "        |        ";
        }
        if (disk_2[i] != 0)
        {
            cout << tower_forms[disk_2[i]];
        }
        else
        {
            cout << "        |        ";
        }
        if (disk_3[i] != 0)
        {
            cout << tower_forms[disk_3[i]];
        }
        else
        {
            cout << "        |        ";
        }

        cout << "\n";
    }
}