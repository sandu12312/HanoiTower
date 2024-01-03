#include "Manual_Game_Mode.h"

int ok=0;
int i1, i2, i3;


int Check_GameStatus(void)
{

}

void change_disk(int x, int y)
{

    if (ok == 0)
    {
        i1 = ReturnDiskNumbers(), i2 = 0, i3 = 0;
        ok = 1;
    }
    disk_2[0] = 99;
    disk_3[0] = 99;
    if (x == 1 && y == 2)
    {
        if (disk_2[i2] > disk_1[i1])
        {
            disk_2[i2 + 1] = disk_1[i1];
            disk_1[i1] = 0;
            i2++;
            i1--;
        }
        else
        {
            cout << "Invalid move" << "\n\n";
        }
    }
    else if (x == 1 && y == 3)
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