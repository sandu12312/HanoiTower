#include "Display_Disk.h"



void Disk_Initialization(int number_of_discs)
{
    int i;

    int counter = number_of_discs + 1;
    for (i = 1; i <= number_of_discs; i++)
    {
        counter--;
        disk_1[i] = counter;

    }
   
}

char tower_forms[10][50]{ "        |        ",
                           "        *        ",
                           "       ***       ",
                           "      *****      ",
                           "     *******     ",
                           "    *********    ",
                           "   ***********   ",
                           "  *************  ",
                           " *************** "
};






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