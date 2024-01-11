#include "Display_Disk.h"
#include <thread>

char rod[] = { 'S', 'A', 'D' };
int rods[1000][10000];
int top[3] = { -1, -1, -1 }; // To keep track of the top of each rod

int x, y, z;

//This function change the place of the disks if the conditions are true
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

        }
        else if (rod[a] == 'D' && rod[b] == 'S')
        {
            x++;
            disk_1[x] = disk_3[z];
            disk_3[z] = 0;
            z--;
        }
        else if (rod[a] == 'S' && rod[b] == 'A')
        {
            y++;
            disk_2[y] = disk_1[x];
            disk_1[x] = 0;
            x--;
        }
        else if (rod[a] == 'A' && rod[b] == 'S')
        {
            x++;
            disk_1[x] = disk_2[y];
            disk_2[y] = 0;
            y--;
        }
        else if (rod[a] == 'D' && rod[b] == 'A')
        {
            y++;
            disk_2[y] = disk_3[z];
            disk_3[z] = 0;
            z--;
        }
        else if (rod[a] == 'A' && rod[b] == 'D')
        {
            z++;
            disk_3[z] = disk_2[y];
            disk_2[y] = 0;
            y--;
        }
        rods[b][++top[b]] = rods[a][top[a]--];
    }
    else
    {
        moveDisk(b, a);
    }
}

//Reinitialization of the vars
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
/*1. Calculate the total number of moves required i.e. "pow(2, n) - 1" here n is number of disks.
2. If number of disks(i.e.n) is even then interchange destination
pole and auxiliary pole.
3. for i = 1 to total number of moves :
if i % 3 == 1 :
    legal movement of top disk between source pole and destination pole
if i % 3 == 2 :
       legal movement top disk between source pole and auxiliary pole
if i % 3 == 0 :
       legal movement top disk between auxiliary pole
       and destination pole
*/
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
            this_thread::sleep_for(chrono::milliseconds(400)); //delay of 400 miliseconds
        }
        else if (i % 3 == 1)
        {
            moveDisk(src, dest);
            Display_Towers(n); 
            this_thread::sleep_for(chrono::milliseconds(400)); //delay of 400 miliseconds
        }
        else
        {
            moveDisk(src, aux);
            Display_Towers(n);
            this_thread::sleep_for(chrono::milliseconds(400)); //delay of 400 miliseconds
        }
    }
}
