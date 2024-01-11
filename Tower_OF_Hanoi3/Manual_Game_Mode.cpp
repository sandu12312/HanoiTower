#include "Manual_Game_Mode.h"

int ok=0;
int i1, i2, i3;
int check;
int verify[10], counts, tries=0;


//the function that validate on every iteration if third tower is complete or n0;
void verify_array(void)
{
    int i, n;
    n = ReturnDiskNumbers();
    counts = n+1;
    for (i = 1; i <= n; i++)
    {
        counts--;
        verify[i] = counts;
    }
 
}

//if third array is complete the function Check_GameStatus will return 1 if the game is over
//and 0 if the game continues
int Check_GameStatus(void)
{
    int i, n;
    
    check = 0;
    n = ReturnDiskNumbers();
    verify_array();
  
    for (i = 1; i <= n; i++)
    {
        if (verify[i] == disk_3[i])
        {
            check = 1;
        }
        else
        {
            check = 0;
            break;
        }

    }
    if (check == 1)
    {
        return 1;
    }
    else
        return 0;
}


//the logic behind every valid move
void change_disk(int x, int y)
{

    if (ok == 0)
    {
        i1 = ReturnDiskNumbers(), i2 = 0, i3 = 0;
        ok = 1;
    }
    disk_1[0] = 99;
    disk_2[0] = 99;
    disk_3[0] = 99;
    if (x == 1 && y == 2) //if the input is 1 2
    {
        if (disk_2[i2] > disk_1[i1]) //verify is a valid move
        {
            tries++; //the counter for number of tries of moves you are doing
            disk_2[i2 + 1] = disk_1[i1]; //the top disk from tower 1 is moving on the top of the tower 2
            disk_1[i1] = 0; //making the top disk from tower 1 = 0 because i moved it to tower 2
            i2++; //incrementing the index for tower 2
            i1--; //decrimenting the index for tower 1
        }
        else
        {
            tries++; 
            cout << "Invalid move" << "\n\n";
        }
    }
    //the same logic is for every else if behind
    else if (x == 1 && y == 3)
    {
        if (disk_3[i3] > disk_1[i1])
        {
            tries++;
            disk_3[i3 + 1] = disk_1[i1];
            disk_1[i1] = 0;
            i3++;
            i1--;
        }
        else
        {
            tries++;
            cout << "Invalid move" << "\n\n";
        }

    }
    else if (x == 2 && y == 3)
    {
        if (disk_3[i3] > disk_2[i2])
        {
            tries++;
            disk_3[i3 + 1] = disk_2[i2];
            disk_2[i2] = 0;
            i3++;
            i2--;
        }
        else
        {
            tries++;
            cout << "Invalid move" << "\n\n";
        }

    }
    else if (x == 2 && y == 1)
    {
        if (disk_1[i1] > disk_2[i2])
        {
            tries++;
            disk_1[i1 + 1] = disk_2[i2];
            disk_2[i2] = 0;
            i1++;
            i2--;
        }
        else
        {
            tries++;
            cout << "Invalid move" << "\n\n";
        }

    }
    else if (x == 3 && y == 1)
    {
        if (disk_1[i1] > disk_3[i3])
        {
            tries++;
            disk_1[i1 + 1] = disk_3[i3];
            disk_3[i3] = 0;
            i1++;
            i3--;
        }
        else
        {
            tries++;
            cout << "Invalid move" << "\n\n";
        }

    }
    else if (x == 3 && y == 2)
    {
        if (disk_2[i2] > disk_3[i3])
        {
            tries++;
            disk_2[i2 + 1] = disk_3[i3];
            disk_3[i3] = 0;
            i2++;
            i3--;
        }
        else
        {
            tries++;
            cout << "Invalid move" << "\n\n";
        }

    }
}