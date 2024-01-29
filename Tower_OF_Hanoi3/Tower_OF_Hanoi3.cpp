#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <cmath>

using namespace std;

char rod[] = { 'S', 'A', 'D' };
int rods[1000][10000];
int top[3] = { -1, -1, -1 };
int x, y, z;

int disk_1[10], disk_2[10], disk_3[10];
int disk_number;
int game_over = 0, tries = 0;
int i1, i2, i3, ok, verify[10], check, counts;

// Function declarations
void moveDisk(int a, int b);
void initialize_vars(int disks);
void automated_game(int n);
void Disk_Initialization(int number_of_discs);
void Display_Towers(int number_of_discs);
int Check_GameStatus();
void change_disk(int move_from, int move_to);
int ReturnDiskNumbers();

int main()
{
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
            // Display rules
            cout << "-------------------------------------------------------------------------------------------------\n";
            cout << "                                           The rules\n";
            cout << "-------------------------------------------------------------------------------------------------\n";
            cout << "The mission is to move all the disks to the third tower without violating the sequence of arrangement\n";
            cout << "1. Only one disk can be moved among the towers at any given time." << "\n";
            cout << "2. Only the \"top\" disk can be removed." << "\n";
            cout << "3. No large disk can sit over a small disk." << "\n";
            cout << "-------------------------------------------------------------------------------------------------\n";
            cout << "For the Manual game, introduce 2 integers indicating from which disk to which disk to move.\n";
            cout << "For Example:\nINPUT: 1 2 -> you will move from the top of the first tower to the top of the second tower\n";
            cout << "-------------------------------------------------------------------------------------------------\n";
            break;

        case 2:
            // Play manual game
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
                        game_over = 1;
                    }
                }
            }
            break;

        case 3:
            // Play automated game
            cout << "\nRead the number of disks for the bot to play:";
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
            }
            break;

        default:
            cout << "--------------------\n";
            cout << "INVALID OPTION" << "\n";
            cout << "--------------------\n";
            return 0;
            break;
        }
    }
    return 0;
}

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
int ReturnDiskNumbers()
{
    // The ReturnDiskNumbers function implementation as provided in the original code
    return disk_number;
}
