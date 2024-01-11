#include "Display_Disk.h"
#include <thread>
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
