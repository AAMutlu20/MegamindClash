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
int counter2 = 0;
int key = 0;
int doorR = 0;


//map size
char map[20][41] = {
    "----------------------------------------",
    "|       |D                    K|       |",
    "|       |      _____           |       |",
    "|       |      |B1 |___________|       |",
    "|       |      |___|___________|_______|",
    "|_______|                              |",
    "|                      _________       |",
    "|                      |    |D3|       |",
    "|                H     |    |__|  D    |",
    "|__________            |       |       |",
    "|          |           |_______|       |",
    "|________  |                           |",
    "|D      |__|                           |",
    "|                  _____________       |",
    "|       ____       |C2   |     |       |",
    "|       |A5|       |     |_____|       |",
    "|       |  |       |     |K            |",
    "|       |  |       |     |             |",
    "|       |  |K      |     |             |",
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
            if (map[i][j] == 'H') //player
            {
                x = j;
                y = i;
            }
            else if (map[i][j] == 'D' && counter == 0) //door1
            {
                doorX1 = j;
                doorY1 = i;
                counter++;
            }
            else if (map[i][j] == 'D' && counter == 1) //door2
            {
                doorX2 = j;
                doorY2 = i;
                counter++;
            }
            else if (map[i][j] == 'D' && counter == 2) //door3
            {
                doorX3 = j;
                doorY3 = i;
                counter++;
            }
            else if (map[i][j] == 'K' && counter2 == 0) //key1
            {
                keyX1 = j;
                keyY1 = i;
                counter++;
            }
            else if (map[i][j] == 'K' && counter2 == 1) //key2
            {
                keyX2 = j;
                keyY2 = i;
                counter++;
            }
            else if (map[i][j] == 'K' && counter2 == 2) //key3
            {
                keyX3 = j;
                keyY3 = i;
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
        case 'a': //move left
            if (x - 1 >= 0 && map[y][x - 1] == ' ')
            {
                temp = map[y][x - 1];
                map[y][x - 1] = map[y][x];
                map[y][x] = temp;
                x--;
            }

            break;
        case 'A': //move left
            if (x - 1 >= 0 && map[y][x - 1] == ' ')
            {
                temp = map[y][x - 1];
                map[y][x - 1] = map[y][x];
                map[y][x] = temp;
                x--;
            }

            break;
        case 'd': //move right
            if (x + 1 <= 40 && map[y][x + 1] == ' ')
            {
                temp = map[y][x + 1];
                map[y][x + 1] = map[y][x];
                map[y][x] = temp;
                x++;
            }

            break;
        case 'D': //move right
            if (x + 1 <= 40 && map[y][x + 1] == ' ')
            {
                temp = map[y][x + 1];
                map[y][x + 1] = map[y][x];
                map[y][x] = temp;
                x++;
            }

            break;
        case 'w': //move up
            if (y - 1 >= 0 && map[y - 1][x] == ' ')
            {
                temp = map[y - 1][x];
                map[y - 1][x] = map[y][x];
                map[y][x] = temp;
                y--;
            }


            break;
        case 'W': //move up
            if (y - 1 >= 0 && map[y - 1][x] == ' ')
            {
                temp = map[y - 1][x];
                map[y - 1][x] = map[y][x];
                map[y][x] = temp;
                y--;
            }


            break;
        case 's': //move down
            if (y + 1 <= 19 && map[y + 1][x] == ' ')
            {
                temp = map[y + 1][x];
                map[y + 1][x] = map[y][x];
                map[y][x] = temp;
                x--;
            }

            break;
        case 'S': //move down
            if (y + 1 <= 19 && map[y + 1][x] == ' ')
            {
                temp = map[y + 1][x];
                map[y + 1][x] = map[y][x];
                map[y][x] = temp;
            }

            break;
        case 'x': //end game character
            gOver = true;
            break;
        }
    }
}

//getting keys
void KeyObtain()
{
    if (x == keyX1 && y == keyY1) //player going into the key coordinates
    {
        key++;
        map[keyX1][keyY1] = ' ';
    }
    else if (x == keyX2 && y == keyY2)
    {
        key++;
        map[keyX2][keyY2] = ' ';
    }
    else if (x == keyX3 && y == keyY3)
    {
        key++;
        map[keyX3][keyY3] = ' ';
    }
}


//opening the doors
void door()
{
    if (x == doorX1 && y == doorY1 && key >= 1)
    {
	 //the door opens and the key dissapears
        doorR++;
        key--;
        map[doorX1][doorY1] = ' ';
    }
    else if (x == doorX2 && y == doorY2 && key >= 1)
    {
        
        doorR++;
        key--;
        map[doorX2][doorY2] = ' ';
    }
    else if (x == doorX3 && y == doorY3 && key >= 1)
    {
        
        doorR++;
        key--;
        map[doorX3][doorY3] = ' ';
    }
    else if (doorR == 3)
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
