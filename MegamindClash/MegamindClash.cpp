//libraries
#include <iostream>
#include <conio.h>
#include <cmath>
#include <iomanip>

using namespace std;

bool gOver;
int x, y;
int doorX1, doorY1;
int doorX2, doorY2;
int doorX3, doorY3;
int keyX1, keyY1;
int keyX2, keyY2;
int keyX3, keyY3;
char temp;
int counter = 0;
bool key = 0;
bool doorR = 0;


//map size
char map[20][41] = {
    "----------------------------------------",
    "|       |D                     |       |",
    "|       |      _____           |       |",
    "|       |      |B1 |___________|       |",
    "|       |      |___|___________|_______|",
    "|       |                              |",
    "|_______|              _________       |",
    "|                      |    |D3|       |",
    "|                H     |    |__|  D    |",
    "|__________            |       |       |",
    "|          |           |_______|       |",
    "|__________|                           |",
    "|D                                     |",
    "|                  _____________       |",
    "|       ____       |C2   |     |       |",
    "|       |A5|       |     |_____|       |",
    "|       |  |       |     |             |",
    "|       |  |       |     |             |",
    "|       |  |       |     |             |",
    "----------------------------------------",
    
};


//setting up the coordinates for the keys and doors.
void Setup()
{
    gOver = false;
}

//printing the map on screen
void Map()
{
    system("cls");
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 41; j++)
        {
            if (map[i][j] == 'H')
            {
                x = j;
                y = i;
            }
            else if (map[i][j] == 'D' && counter == 0)
            {
                doorX1 = j;
                doorY1 = i;
                counter++;
            }
            else if (map[i][j] == 'D' && counter == 1)
            {
                doorX2 = j;
                doorY2 = i;
                counter++;
            }
            else if (map[i][j] == 'D' && counter == 2)
            {
                doorX3 = j;
                doorY3 = i;
                counter++;
            }

            cout << map[i][j];
        }
        cout << endl;
    }
}


//keybinds for movement
void Input()
{
    if (_kbhit()) //clicking a character on the keyboard
    {
        switch (_getch()) //obtaining the clicked character
        {	
	//movement		
        case 'a':
            if (x - 1 >= 0 && map[y][x - 1] == ' ')
            {
                temp = map[y][x - 1];
                map[y][x - 1] = map[y][x];
                map[y][x] = temp;
                x--;
            }

            break;
        case 'd':
            if (x + 1 <= 40 && map[y][x + 1] == ' ')
            {
                temp = map[y][x + 1];
                map[y][x + 1] = map[y][x];
                map[y][x] = temp;
                x++;
            }

            break;
        case 'w':
            if (y - 1 >= 0 && map[y - 1][x] == ' ')
            {
                temp = map[y - 1][x];
                map[y - 1][x] = map[y][x];
                map[y][x] = temp;
                y--;
            }


            break;
        case 's':
            if (y + 1 <= 19 && map[y + 1][x] == ' ')
            {
                temp = map[y + 1][x];
                map[y + 1][x] = map[y][x];
                map[y][x] = temp;
                x--;
            }

            break;
        case 'x':
            gOver = true;
            break;
        }
    }
}

//getting keys
void KeyObtain()
{
    if (x == keyX1 && y == keyY1)
    {
        key = 1;
    }
    if (key == 1)
    {
        cout << "You found a Key!";
    }
}


//opening the doors
void door()
{
    if (x == doorX1 && y == doorY1 && key == 1)
    {
	 //the door opens and the key dissapears
        doorR = 1;
        key = 0;
    }
    if (doorR == 1)
    {
        gOver = true;
        cout << " ";
    }
}


//ending the game
void GameO()
{
    if (gOver == true)
    {
        system("cls");
        cout << setw(50) << "GAME OVER";
    }
}

//setting up the game
int main()
{
    Setup();

    while (gOver == false)
    {
        Map();
        Input();
        KeyObtain();
        door();
        GameO();
    }
    return 0;
}
