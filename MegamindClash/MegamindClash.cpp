//libraries
#include <iostream>
#include <conio.h>
#include <cmath>
#include <iomanip>

using namespace std;

bool gOver;
int x, y, keyX, keyY, doorX, doorY;
bool key = 0;
bool doorR = 0;
enum eDirecton { STOP = 1, LEFT, RIGHT, UP, DOWN };
eDirecton dir;

//map size
char map[20][41] = {
    "----------------------------------------",
    "|       |                      |       |",
    "|       |      _____           |       |",
    "|_______|      |B1 |___________|       |",
    "|              |___|___________|_______|",
    "|                                      |",
    "|                      _________       |",
    "|                      |    |D3|       |",
    "|                           |--|       |",
    "|----------|           |       |       |",
    "|          |           |_______|       |",
    "|----------|                           |",
    "|                                      |",
    "|                  _____________       |",
    "|       ____       |C2   |     |       |",
    "|       |A5|       |     |--- -|       |",
    "|       |  |       |     |             |",
    "|       |  |       |     |             |",
    "|       |  |       |     |             |",
    "----------------------------------------",
    
};


//setting up the coordinates for the keys and doors.
void Setup()
{
    gOver = false;
    dir = STOP;
    x = (32 / 2) - 1;
    y = 18 - 1;

    keyX = 32 - 1;
    keyY = (18 / 2) - 1;

    doorX = 0;
    doorY = 0;
}

//printing the map on screen
void Map()
{
	for (int i = 0; i < 18; i++) 
    {
		printf("%s\n", map[i]);
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
            dir = LEFT;

            break;
        case 'd':
            dir = RIGHT;

            break;
        case 'w':
            dir = UP;

            break;
        case 's':
            dir = DOWN;

            break;
        case 'x':
            gOver = true;
            break;
        }
    }

    switch (dir)
    {
    case LEFT:
        x--;
        dir = STOP;
        break;
    case RIGHT:
        x++;
        dir = STOP;
        break;
    case UP:
        y--;
        dir = STOP;
        break;
    case DOWN:
        y++;
        dir = STOP;
        break;
    }
}

//getting keys
void KeyObtain()
{
    if (x == keyX && y == keyY)
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
    if (x == doorX && y == doorY && key == 1)
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
    Map();
    while (gOver == false)
    {
        Input();
        KeyObtain();
        door();
        GameO();
    }
    return 0;
}
