//libraries
#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
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
int KeyCollectionCounter = 0;
int KeyCollectionCounter2 = 0;
int KeyCollectionCounter3 = 0;
int DoorPassCounter1 = 0;
int DoorPassCounter2 = 0;
int DoorPassCounter3 = 0;
string PhysicsQ;
string PhysicsQ2;
string PhysicsQ3;
int key = 0;
int doorR = 0;


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
    "|               H      |    |__|  D    |",
    "|__________            |       |       |",
    "|          |           |_______|       |",
    "|__________|                           |",
    "|D                                     |",
    "|                  _____________       |",
    "|       ____       |           |       |",
    "|       |A5|       |C2    _____|       |",
    "|       |  |       |     |             |",
    "|       |  |       |     |             |",
    "|       |  |       |     |             |",
    "----------------------------------------",
    
};


//setting up the coordinates for the keys and doors.
void Setup()
{
    gOver = false;
    keyX1 = 30;
    keyX2 = 26;
    keyX3 = 12;
    keyY1 = 1;
    keyY2 = 16;
    keyY3 = 18;
    doorX1 = 10;
    doorX2 = 33;
    doorX3 = 2;
    doorY1 = 1;
    doorY2 = 8;
    doorY3 = 12;

     
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

            cout << map[i][j];
        }
        cout << endl;
    }
//Artefacts and Coords menu
    cout << "Coords: " << x << "/" << y << endl;
    cout << "Artefact Parts: " << doorR << "/" << "3" << endl;
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
        case 'x': //end game
            gOver = true;
            break;
	case 'X': //end game
            gOver = true;
            break;
        }
    }
}

//getting keys
void KeyObtain()
{
    if (x == keyX1 && y == keyY1 && KeyCollectionCounter == 0)
    {
	    //Physic Question 1
        cout << "Can a fire have a shadow?\nYes/No" << endl;
        cin >> PhysicsQ;

        if (PhysicsQ == "Yes" || PhysicsQ == "yes")
        {
		//If the answer is right the player obtains 1 key.
            key++;
            KeyCollectionCounter++;
        }
        else
        {
		//If the answer is wrong the game ends.
            gOver = true;
        }
    }
    else if (x == keyX2 && y == keyY2 && KeyCollectionCounter2 == 0)
    {
	    //Physic Question 2
        cout << "Can light bend around corners?\nYes/No" << endl;
        cin >> PhysicsQ2;

        if (PhysicsQ2 == "Yes" || PhysicsQ2 == "yes")
        {
            key++;
            KeyCollectionCounter2++;
        }
        else
        {
            gOver = true;
        }
    }
    else if (x == keyX3 && y == keyY3 && KeyCollectionCounter3 == 0)
    {
	    //Physic Question 3
        cout << "As light from a star spreads out and weakens, do gaps form between the photons?\nYes/No" << endl;
        cin >> PhysicsQ3;

        if (PhysicsQ3 == "No" || PhysicsQ3 == "no")
        {
            key++;
            KeyCollectionCounter3++;
        }
        else
        {
            gOver = true;
        }
    }

    cout << "Keys: " << key;
}


//opening the doors
void door()
{
    if (x == doorX1 && y == doorY1 && key >= 1 && DoorPassCounter1 == 0)
    {
	 //the door opens and the key dissapears
        doorR++;
        key--;
	    //Gives one artefact part
        DoorPassCounter1++;
    }
    else if (x == doorX2 && y == doorY2 && key >= 1 && DoorPassCounter2 == 0)
    {
        //the door opens and the key dissapears
        doorR++;
        key--;
	    //Gives one artefact part
        DoorPassCounter2++;
    }
    else if (x == doorX3 && y == doorY3 && key >= 1 && DoorPassCounter3 == 0)
    {
        //the door opens and the key dissapears
        doorR++;
        key--;
	    //Gives one artefact part
        DoorPassCounter3++;
    }
    else if (doorR == 3)
    {
	   //If all artefact parts are collected the game ends
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
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
        cout << setw(60) << "GAME OVER";
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
    }
}

//setting up the game
int main()
{
    Setup();

    while (gOver == false)
    {
	    //Building the game
        Map();
        Input();
        KeyObtain();
        door();
        GameO();
    }
    return 0;
}
