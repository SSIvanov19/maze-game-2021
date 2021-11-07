/*! @file back-end.cpp
*   @brief A source file for the logic layer.
*/


#include "back-end.h"

/**
 * @brief A struct for room.
*/

/*
#include <iostream>
#include <Windows.h>
#include <stdio.h>    
#include <stdlib.h>   
#include <time.h> 

using namespace std;

int rowRoom = 41, colRoom = 17; // size of the rooms
int rowMap = 45, colMap = 21; // size of the map
int right = 0, left = 0, down = 0, up = 0;
int level = 0, nextLevel = 0, nextRoom = 0;
int MapX = 0, MapY = 0, MapRoom, ChoiseShopX[2], ChoiseShopY[2], showShop = 0;
bool levelUp = false;
char** board;
int rowPlayer = 2, colPlayer = 2, moves = 0;
int randomSizeOfEnemies, tempE = 0;
int* tempX = new int[randomSizeOfEnemies];
int* tempY = new int[randomSizeOfEnemies];
int randomSpawnX, randomSpawnY;
int counterDead = 0;
int* deadList = new int[randomSizeOfEnemies];
int counterOfEnemies, levelOfEnemies1, levelOfEnemies2;

/* ART 

char uSword = 179;
char dSword = 216;
char key = 12;
char healthShop = 3;
char armorShop = 233;
char wizard = 30;
char money = 36;
char firstMonster = 254;
char secondMonster = 4;
char fPartThirdMonster = 203;
char sPartThirdMonster = 176;
char fPartFourthMonster = 209;
char sPartFourthMonster = 177;
char bossFPart = 206;
char bossSPart = 178;
char bossTPart = 201;
char bossFoPart = 184;
char chest = 127;

HANDLE rhnd = GetStdHandle(STD_INPUT_HANDLE);  // handle to read console

DWORD Events = 0;     // Event count
DWORD EventsRead = 0; // Events read from console

bool Running = true;


struct Data
{
	char person;
	short health;
	short armor;
	short attack;
	short money;
	short keys;
};


void stats(Data** role, Data* item, int idEnemies) {

	cout << "Counter of Enemies - " << tempE << endl;
	//for (int i = 0; i < randomSizeOfEnemies; i++) {
		//cout << "Cordinates of element - " << i << " = " << tempX[i] << " " << tempY[i] << endl;
	//}
	for (int i = 0; i < 2; i++) {
		cout << "Shops are in - row = " << ChoiseShopX[i] << " col = " << ChoiseShopY[i] << endl;
	}
	//cout << "Cordinates of element this enemie " << " = row - " << tempX[idEnemies] << " col - " << tempY[idEnemies] << endl;
	cout << "Map - row = " << MapX << " col = " << MapY << endl;
	//cout << "idEnemies = " << idEnemies << endl;
	//cout << "tempE = " << tempE << endl;
	cout << "ShowShop = " << showShop << endl;
	cout << "Level = " << level << endl;
	cout << "nextLevel = " << nextLevel << endl;
	cout << "Counter of Deads - " << counterDead << endl << endl;

	cout << "Player" << endl;
	cout << "health: " << role[0][0].health << endl;
	cout << "attack: " << role[0][0].attack << endl;
	cout << "Armor: " << role[0][0].armor << endl;
	cout << "Money: " << role[0][0].money << endl;
	cout << "Keys: " << role[0][0].keys << endl << endl;
	/*
	if (tempX[idEnemies] < 22 && tempX[idEnemies] > 0) {
		cout << "Enemie" << endl;
		cout << "health: " << role[1][idEnemies].health << endl;
		cout << "attack: " << role[1][idEnemies].attack << endl;
		cout << "Money: " << role[1][idEnemies].money << endl;
	}
	
}

char** room(Data** role, Data* item) {
	char** room = new char* [rowMap];
	for (int i = 0; i < rowMap; i++)
		room[i] = new char[colMap];

	for (int i = 0; i < rowMap; i++) {
		for (int j = 0; j < colMap; j++) {
			room[i][j] = ' ';
		}
	}
	// |-
	if (MapX == 0 && MapY == 0) {
		MapRoom = 1;
		for (int i = 0; i < rowRoom; i++) {
			for (int j = 0; j < colRoom; j++) {
				if (i > 1 && j > 1 && i < rowRoom - 1 && j < colRoom - 1) {
					room[i][j] = ' ';
				}
				else {
					room[i][j] = '#';
				}
			}
		}
		int hall = 0;
		int temp2 = -2, help = 2;
		do {
			for (int x = 0; x < rowMap; x++) {
				for (int y = 0; y < colMap; y++) {
					// right
					if (x == rowRoom && y == (colRoom - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// down
					if (x == (rowRoom - 1) / 2 + temp2 * 2 && y == colRoom) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
				}
			}
			temp2 = 2;
			help--;
		} while (help);
	}

	// | <-
	if (MapX == 0 && (MapY == 1 || MapY == 2)) {
		MapRoom = 2;
		for (int i = 0; i < rowRoom; i++) {
			for (int j = 0; j < colRoom; j++) {
				if (i > 1 && j > 1 && i < rowRoom - 1 && j < colRoom - 1) {
					room[i][j] = ' ';
				}
				else {
					if (j == 0)
						room[i][j] = ' ';
					else
						room[i][j] = '#';
				}
			}
		}
		int hall = 0;
		int temp2 = -2, help = 2;
		do {
			for (int x = 0; x < rowMap; x++) {
				for (int y = 0; y < colMap; y++) {
					if (x == rowRoom && y == (colRoom - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					if (x == (rowRoom - 1) / 2 + temp2 * 2 && y == colRoom) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					if (x == (rowRoom - 1) / 2 + temp2 * 2 && y == 0) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;

				}
			}
			temp2 = 2;
			help--;
		} while (help);
	}

	// |_
	if (MapX == 0 && MapY == 3) {
		MapRoom = 2;
		for (int i = 0; i < rowRoom; i++) {
			for (int j = 0; j < colRoom; j++) {
				if (i > 1 && j > 1 && i < rowRoom - 1 && j < colRoom) {
					if (j == colRoom - 2 || j == colRoom - 1)
						room[i][j] = '#';
					else
						room[i][j] = ' ';
				}
				else {
					if (j == 0)
						room[i][j] = ' ';
					else
						room[i][j] = '#';
				}
			}
		}
		int hall = 0;
		int temp2 = -2, help = 2;
		do {
			for (int x = 0; x < rowMap; x++) {
				for (int y = 0; y < colMap; y++) {
					if (x == rowRoom && y == (colRoom - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					if (x == (rowRoom - 1) / 2 + temp2 * 2 && y == 0) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
				}
			}
			temp2 = 2;
			help--;
		} while (help);
	}

	// -
	if ((MapX == 1 || MapX == 2) && MapY == 0) {
		MapRoom = 4;
		for (int i = 0; i < rowRoom; i++) {
			for (int j = 0; j < colRoom; j++) {
				if (i > 1 && j > 1 && i < rowRoom - 1 && j < colRoom - 1) {
					room[i][j] = ' ';
				}
				else {
					if (i == 0)
						room[i][j] = ' ';
					else
						room[i][j] = '#';
				}
			}
		}
		int hall = 0;
		int temp2 = -2, help = 2;
		do {
			for (int x = 0; x < rowMap; x++) {
				for (int y = 0; y < colMap; y++) {
					// right
					if (x == rowRoom && y == (colRoom - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// down
					if (x == (rowRoom - 1) / 2 + temp2 * 2 && y == colRoom) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// left 
					if (x == 0 && y == (colRoom - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
				}
			}
			temp2 = 2;
			help--;
		} while (help);
	}

	// -|
	if (MapX == 3 && MapY == 0) {
		MapRoom = 5;
		for (int i = 0; i < rowRoom; i++) {
			for (int j = 0; j < colRoom; j++) {
				if (i > 1 && j > 1 && i < rowRoom - 1 && j < colRoom - 1) {
					if (i == rowRoom - 2)
						room[i][j] = '#';
					else
						room[i][j] = ' ';
				}
				else {
					if (i == 0)
						room[i][j] = ' ';
					else
						room[i][j] = '#';
				}
			}
		}
		int hall = 0;
		int temp2 = -2, help = 2;
		do {
			for (int x = 0; x < rowMap; x++) {
				for (int y = 0; y < colMap; y++) {
					// down
					if (x == (rowRoom - 1) / 2 + temp2 * 2 && y == colRoom) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// left 
					if (x == 0 && y == (colRoom - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
				}
			}
			temp2 = 2;
			help--;
		} while (help);
	}

	// -> | 
	if (MapX == 3 && (MapY == 1 || MapY == 2)) {
		MapRoom = 6;
		for (int i = 0; i < rowRoom; i++) {
			for (int j = 0; j < colRoom; j++) {
				if (i > 1 && j > 1 && i < rowRoom - 1 && j < colRoom - 1) {
					if (i == rowRoom - 2)
						room[i][j] = '#';
					else
						room[i][j] = ' ';
				}
				else {
					if (i == 0 || j == 0)
						room[i][j] = ' ';
					else
						room[i][j] = '#';
				}
			}
		}
		int hall = 0;
		int temp2 = -2, help = 2;
		do {
			for (int x = 0; x < rowMap; x++) {
				for (int y = 0; y < colMap; y++) {
					// down
					if (x == (rowRoom - 1) / 2 + temp2 * 2 && y == colRoom) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// left 
					if (x == 0 && y == (colRoom - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// up 
					if (x == (rowRoom - 1) / 2 + temp2 * 2 && y == 0) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
				}
			}
			temp2 = 2;
			help--;
		} while (help);
	}

	// _|
	if (MapX == 3 && MapY == 3) {
		MapRoom = 7;
		for (int i = 0; i < rowRoom; i++) {
			for (int j = 0; j < colRoom; j++) {
				if (i > 1 && j > 1 && i < rowRoom - 1 && j < colRoom - 1) {
					if (i == rowRoom - 2 || j == colRoom - 2)
						room[i][j] = '#';
					else
						room[i][j] = ' ';
				}
				else {
					if (i == 0 || j == 0)
						room[i][j] = ' ';
					else
						room[i][j] = '#';
				}
			}
		}
		int hall = 0;
		int temp2 = -2, help = 2;
		do {
			for (int x = 0; x < rowMap; x++) {
				for (int y = 0; y < colMap; y++) {
					// left 
					if (x == 0 && y == (colRoom - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// up 
					if (x == (rowRoom - 1) / 2 + temp2 * 2 && y == 0) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
				}
			}
			temp2 = 2;
			help--;
		} while (help);
	}

	// _
	if ((MapX == 1 || MapX == 2) && MapY == 3) {
		MapRoom = 8;
		for (int i = 0; i < rowRoom; i++) {
			for (int j = 0; j < colRoom; j++) {
				if (i > 1 && j > 1 && i < rowRoom - 1 && j < colRoom - 1) {
					if (j == colRoom - 2)
						room[i][j] = '#';
					else
						room[i][j] = ' ';
				}
				else {
					if (i == 0 || j == 0)
						room[i][j] = ' ';
					else
						room[i][j] = '#';
				}
			}
		}
		int hall = 0;
		int temp2 = -2, help = 2;
		do {
			for (int x = 0; x < rowMap; x++) {
				for (int y = 0; y < colMap; y++) {
					// right
					if (x == rowRoom && y == (colRoom - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// left 
					if (x == 0 && y == (colRoom - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// up 
					if (x == (rowRoom - 1) / 2 + temp2 * 2 && y == 0) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
				}
			}
			temp2 = 2;
			help--;
		} while (help);
	}

	// all
	if (MapX >= 1 && MapX < 3 && MapY >= 1 && MapY < 3) {
		MapRoom = 9;
		for (int i = 0; i < rowRoom; i++) {
			for (int j = 0; j < colRoom; j++) {
				if (i > 1 && j > 1 && i < rowRoom - 1 && j < colRoom - 1) {
					room[i][j] = ' ';
				}
				else {
					if (i == 0 || j == 0)
						room[i][j] = ' ';
					else
						room[i][j] = '#';
				}
			}
		}
		int hall = 0;
		int temp2 = -2, help = 2;
		do {
			for (int x = 0; x < rowMap; x++) {
				for (int y = 0; y < colMap; y++) {
					// right
					if (x == rowRoom && y == (colRoom - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// down
					if (x == (rowRoom - 1) / 2 + temp2 * 2 && y == colRoom) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// left 
					if (x == 0 && y == (colRoom - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// up 
					if (x == (rowRoom - 1) / 2 + temp2 * 2 && y == 0) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
				}
			}
			temp2 = 2;
			help--;
		} while (help);
	}


	if (level == nextLevel) {
		srand(time(NULL));
		if (MapX == 0 && MapY == 0) {
			room[20][8] = wizard;
			nextLevel++;
			bool readyShop = false;
			for (int i = 0; i < 2; i++) {
				do {
					readyShop = false;
					ChoiseShopX[i] = rand() % 4;
					ChoiseShopY[i] = rand() % 4;
					if (ChoiseShopX[i] == ChoiseShopX[i - 1] || ChoiseShopY[i] == ChoiseShopY[i - 1])
						readyShop = true;
					if (ChoiseShopX[i] == 0 && ChoiseShopY[i] == 0)
						readyShop = true;
					if (ChoiseShopX[i] == 3 && ChoiseShopY[i] == 3)
						readyShop = true;
				} while (readyShop);
			}
		}
		else {
			if (((MapX == ChoiseShopX[0] && MapY == ChoiseShopY[0]) || (MapX == ChoiseShopX[1] && MapY == ChoiseShopY[1]))) {
				room[20][7] = wizard;
				room[13][9] = '2';
				room[14][9] = '0';
				room[15][9] = '$';
				room[14][10] = healthShop;
				room[19][9] = '1';
				room[20][9] = '0';
				room[21][9] = '$';
				room[20][10] = armorShop;
				room[25][9] = '5';
				room[26][9] = '$';
				room[25][10] = uSword;
				room[25][11] = dSword;
				if (showShop == 0) {
					showShop++;
				}
				room[4][6] = '1';
				for (int i = 0; i < 4; i++) {
					if (role[1][i].person == 'D') {
						role[1][i].person = 'F';
						role[1][i].health = 15;
					}
				}
			}
			else {
				randomSizeOfEnemies = 1; // rand() % 4 + 1;
				tempE += randomSizeOfEnemies;
				bool ready;
				room[4][4] = '2';
				if (showShop > 0) {
					room[4][5] = '3';
					nextLevel++;
					showShop = 0;
				}
				nextLevel++;
				for (counterOfEnemies = 0; counterOfEnemies < randomSizeOfEnemies; counterOfEnemies++) {
					do {
						ready = false;
						tempX[counterOfEnemies] = rand() % rowRoom + 1;
						tempY[counterOfEnemies] = rand() % colRoom + 1;

						if (tempX[counterOfEnemies] >= rowRoom - 5)
							ready = true;
						if (tempY[counterOfEnemies] >= colRoom - 5)
							ready = true;
						if (room[tempX[counterOfEnemies]][tempY[counterOfEnemies]] == '#') {
							ready = true;
						}
						if (tempX[counterOfEnemies] == tempX[counterOfEnemies - 1] && tempY[counterOfEnemies] == tempY[counterOfEnemies - 1])
							ready = true;

					} while (ready);
				}

				for (int i = 0; i < 4; i++) {
					if (role[1][i].person == 'D') {
						role[1][i].person = 'F';
						role[1][i].health = 15;
					}
				}

				/* RULES */
				/*
				if (role[0][0].attack <= 15) {
				  levelOfEnemies1 = 1;
				}
				else {
				  if (role[0][0].attack <= 15) {
					levelOfEnemies1 = 1;
				}

				*
			}
		}
	}
	if ((!(MapX == ChoiseShopX[0] && MapY == ChoiseShopY[0]) || !(MapX == ChoiseShopX[1] && MapY == ChoiseShopY[1])) && showShop > 0) {
		nextLevel++;
	}
	for (int i = 0; i < randomSizeOfEnemies; i++) {
		if (showShop == 0)
			room[tempX[i]][tempY[i]] = role[1][i].person;
	}

	if (counterDead == tempE) {
		switch (MapRoom) {
		case 1:
			// down door
			for (int i = 17; i < 24; i++) {
				room[i][16] = ' ';
			}
			// right door
			for (int i = 7; i < 10; i++) {
				room[40][i] = ' ';
			}
			break;
		case 2:
			// down door
			for (int i = 17; i < 24; i++) {
				room[i][16] = ' ';
			}
			// right door
			for (int i = 7; i < 10; i++) {
				room[40][i] = ' ';
			}
			// up door
			for (int i = 17; i < 24; i++) {
				room[i][1] = ' ';
			}
			break;
		case 3:
			// right door
			for (int i = 7; i < 10; i++) {
				room[40][i] = ' ';
			}
			// up door
			for (int i = 17; i < 24; i++) {
				room[i][1] = ' ';
			}
			break;
		case 4:
			// down door
			for (int i = 17; i < 24; i++) {
				room[i][16] = ' ';
			}
			// right door
			for (int i = 7; i < 10; i++) {
				room[40][i] = ' ';
			}
			// left door
			for (int i = 7; i < 10; i++) {
				room[1][i] = ' ';
			}
			break;
		case 5:
			// left door
			for (int i = 7; i < 10; i++) {
				room[1][i] = ' ';
			}
			// down door
			for (int i = 17; i < 24; i++) {
				room[i][16] = ' ';
			}
			break;
		case 6:
			// down door
			for (int i = 17; i < 24; i++) {
				room[i][16] = ' ';
			}
			// up door
			for (int i = 17; i < 24; i++) {
				room[i][1] = ' ';
			}
			// left door
			for (int i = 7; i < 10; i++) {
				room[1][i] = ' ';
			}
			break;
		case 7:
			// up door
			for (int i = 17; i < 24; i++) {
				room[i][1] = ' ';
			}
			// left door
			for (int i = 7; i < 10; i++) {
				room[1][i] = ' ';
			}
			break;
		case 8:
			// right door
			for (int i = 7; i < 10; i++) {
				room[40][i] = ' ';
			}
			// up door
			for (int i = 17; i < 24; i++) {
				room[i][1] = ' ';
			}
			// left door
			for (int i = 7; i < 10; i++) {
				room[1][i] = ' ';
			}
			break;
		case 9:
			// down door
			for (int i = 17; i < 24; i++) {
				room[i][16] = ' ';
			}
			// right door
			for (int i = 7; i < 10; i++) {
				room[40][i] = ' ';
			}
			// up door
			for (int i = 17; i < 24; i++) {
				room[i][1] = ' ';
			}
			// left door
			for (int i = 7; i < 10; i++) {
				room[1][i] = ' ';
			}
			break;
		}
		// down door
	}

	return room;
}

void freeRoom(char** room) {
	for (int i = 0; i < rowRoom; i++) {
		delete[] room[i];
	}
	delete[] room;
}

void attack(Data** role, short index, bool game, int idEnemies) {
	if (role[index][idEnemies].person != 'D') {

		role[index][idEnemies].health -= role[0][0].attack;
		if (role[index][idEnemies].health <= 0) {
			role[0][0].money += role[index][idEnemies].money;
			role[index][idEnemies].person = 'D';
			counterDead++;
		}

		if (role[index][idEnemies].person != ' ' && role[index][idEnemies].person != 'D') {
			if (role[0][0].armor > 0) {
				role[0][0].armor -= role[index][idEnemies].attack;
				if (role[0][0].armor < 0) {
					role[0][0].health += role[0][0].armor;
					role[0][0].armor = 0;
				}
			}
			else {
				role[0][0].health -= role[index][idEnemies].attack;
				if (role[0][0].health <= 0)
					game = false;
			}
		}
	}
}

void shop(Data** role, Data* item, short index) {
	switch (index) {
	case 0:
		// health
		if (role[0][0].money >= item[0].money) {
			role[0][0].money -= item[0].money;
			role[0][0].health = 100;
		}
		break;
	case 1:
		// Sword
		if (role[0][0].money >= item[1].money) {
			role[0][0].money -= item[1].money;
			role[0][0].attack += 5;
		}
		break;
	case 2:
		// Armor
		if (role[0][0].money >= item[2].money) {
			role[0][0].money -= item[2].money;
			role[0][0].armor += 10;
		}
		break;
	case 3:
		// Key
		if (role[0][0].money >= item[3].money) {
			role[0][0].money -= item[3].money;
			role[0][0].keys += 1;
		}
		break;
	default:
		break;
	}
}

void gotoxy(short x, short y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

/*
void teleport(Data** role, short row, short col) {
	if (board[row][col] == role[0][0].person) {
		gotoxy(1, 1);

	}
}
*

bool movePosible(short row, short col, Data** role, Data* item, bool game) {
	int idEnemies;
	for (idEnemies = 0; idEnemies < tempE; idEnemies++) {
		if (row == tempX[idEnemies] && col == tempY[idEnemies]) {
			attack(role, 1, game, idEnemies);
			break;
		}
	}

	board = room(role, item);

	for (int i = 0; i < 4; i++) {
		if (board[row][col] == item[i].person)
			shop(role, item, i);
	}

	stats(role, item, idEnemies);

	for (int i = 17; i < 24; i++) {
		if (row == i && col == 17) {
			//teleport(role, row, col);
			level++;
			levelUp = true;
			MapY++;
			return false;
		}
	}

	for (int i = 7; i < 10; i++) {
		if (row == 41 && col == i) {
			//teleport(role, row, col);
			level++;
			levelUp = true;
			MapX++;
			return false;
		}
	}

	for (int i = 17; i < 24; i++) {
		if (row == i && col == 0) {
			//teleport(role, row, col);
			level++;
			levelUp = true;
			MapY--;
			return false;
		}
	}

	for (int i = 7; i < 10; i++) {
		if (row == 0 && col == i) {
			//teleport(role, row, col);
			level++;
			levelUp = true;
			MapX--;
			return false;
		}
	}

	if (row == -1 || col == -1)
		return false;

	if (board[row][col] != ' ')
		return false;
	return true;
}

void draw(Data** role, Data* item, int level) {
	board = room(role, item);
	for (int i = 0; i < rowMap; i++) {
		for (int j = 0; j < colMap; j++) {
			gotoxy(i, j);
			cout << board[i][j];
		}
		cout << endl;
	}
}


void clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

void move(Data** role, Data* item) {
	//programs main loop
	while (Running) {
		// gets the systems current "event" count
		GetNumberOfConsoleInputEvents(rhnd, &Events);

		if (Events != 0) { // if something happened we will handle the events we want
		  // create event buffer the size of how many Events
			INPUT_RECORD* eventBuffer = new INPUT_RECORD[Events];

			// fills the event buffer with the events and saves count in EventsRead
			ReadConsoleInput(rhnd, eventBuffer, Events, &EventsRead);

			// loop through the event buffer using the saved count
			for (DWORD i = 0; i < EventsRead; ++i) {
				// check if event[i] is a key event && if so is a press not a release
				if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown) {

					if (moves > 0) {
						clear();
					}
					draw(role, item, level);
					moves++;
					// check if the key press was an arrow key

					switch (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode) {
					case VK_LEFT:
						rowPlayer--;
						if (!movePosible(rowPlayer, colPlayer, role, item, Running))
							rowPlayer++;
						gotoxy(rowPlayer, colPlayer);
						cout << "x";
						break;
					case VK_RIGHT:
						rowPlayer++;
						if (!movePosible(rowPlayer, colPlayer, role, item, Running))
							rowPlayer--;
						gotoxy(rowPlayer, colPlayer);
						cout << "x";
						break;
					case VK_UP:
						colPlayer--;
						if (!movePosible(rowPlayer, colPlayer, role, item, Running))
							colPlayer++;
						gotoxy(rowPlayer, colPlayer);
						cout << "x";
						break;
					case VK_DOWN:
						colPlayer++;
						if (!movePosible(rowPlayer, colPlayer, role, item, Running))
							colPlayer--;
						gotoxy(rowPlayer, colPlayer);
						cout << "x";
						break;

						// if any arrow key was pressed go to these cordinates
					case VK_ESCAPE: // if escape key was pressed end program loop
						Running = false;
						break;

					default:        // no handled cases where pressed 
						break;
					}
				}

			} // end EventsRead loop

		} // end of events

	} // end program loop
}

void GameRules(Data** role, Data* item) {

	// player
	role[0][0].person = 'x';
	role[0][0].health = 100;
	role[0][0].armor = 10;
	role[0][0].attack = 10;
	role[0][0].money = 200;
	role[0][0].keys = 0;

	// first type enemie | counter of enemy
	for (int i = 0; i < 4; i++) {
		role[1][i].person = 'F';
		role[1][i].health = 15;
		role[1][i].attack = 15;
		role[1][i].money = 1;
	}

	// second enemie
	for (int i = 0; i < 4; i++) {
		role[2][i].person = 248;
		role[2][i].health = 25;
		role[2][i].attack = 10;
		role[2][i].money = 3;
	}

	// third enemie
	for (int i = 0; i < 4; i++) {
		role[3][i].person = 176;
		role[3][i].health = 50;
		role[3][i].attack = 20;
		role[3][i].money = 6;
	}

	// fourth enemie
	for (int i = 0; i < 4; i++) {
		role[4][i].person = 177;
		role[4][i].health = 75;
		role[4][i].attack = 25;
		role[4][i].money = 10;
	}

	// boss

	role[5][0].person = 201;
	role[5][0].health = 500;
	role[5][0].attack = 0;

	// heart recovers
	item[0].person = healthShop;
	item[0].health = 0;
	item[0].money = 20;

	// sword
	item[1].person = dSword;
	item[1].attack = 5;
	item[1].money = 10;

	// armor
	item[2].person = armorShop;
	item[2].armor = 10;
	item[2].money = 15;

}

int main() {
	Data** role = new Data * [6];
	for (int i = 0; i < 6; i++) {
		role[i] = new Data[100];
	}
	Data* item = new Data[3];
	GameRules(role, item);
	move(role, item);
}
*/
struct Room
{
	bool visited;
	bool top;
	bool bot;
	bool left;
	bool right;
	char show;
};

struct Data
{
	char person;
	short healt;
	short armor;
	short atack;
	short money;
	short keys;
};

/**
 * @brief A function for settign up the maze
 * @param Maze The maze
 * @param 
*/
void set(Room** Maze, int length)
{
	for (int i = 0; i < length; i++) 
	{
		for (int j = 0; j < length; j++) 
		{
			Maze[i][j].show = '#';
			Maze[i][j].visited = false;
			Maze[i][j].top = true;
			Maze[i][j].bot = true;
			Maze[i][j].left = true;
			Maze[i][j].right = true;
		}
	}

	for (int i = 1; i < length - 1; i++) 
	{
		for (int j = 1; j < length - 1; j++) 
		{
			// Border Cells have fewer accessible walls
			Maze[1][j].top = false;
			Maze[length - 2][j].bot = false;
			Maze[i][1].left = false;
			Maze[i][length - 2].right = false;
		}
	}

}


/**
 * @brief Generate a maze
 * @param length The length of the maze
*/
Room** generator(int length)
{
	Room Maze[100][100];

	Room** maze = new Room * [length];

	for (int i = 0; i < length; ++i)
	{
		maze[i] = new Room[length];
	}

	set(maze, length);

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			Maze[i][j] = maze[i][j];
		}
	}

	// Pick random start cell
	srand(time_t(NULL)); 
	int random = 0;
	int times = 0;
	// Generate a random odd number between 1 and length
	int row = ((2 * rand()) + 1) % (length - 1); 
	// Generate a random odd number between 1 and length
	int col = ((2 * rand()) + 1) % (length - 1); 
	int visitedCells = 1;
	int totalCells = ((length - 1) / 2) * ((length - 1) / 2);
	// Stack is used to trace the reverse path
	std::stack<int> back_trackX, back_trackY;

	if (times == 0) 
	{
		times++;
		col = 1;
		row = 1;
	}						

	Maze[col][row].visited = true;

	while (visitedCells < totalCells)
	{
		if (((!Maze[col - 2][row].visited) && (Maze[col][row].top && Maze[col - 2][row].bot)) ||
			((!Maze[col + 2][row].visited) && (Maze[col][row].bot && Maze[col + 2][row].top)) ||
			((!Maze[col][row - 2].visited) && (Maze[col][row].left && Maze[col][row - 2].right)) ||
			((!Maze[col][row + 2].visited) && (Maze[col][row].right && Maze[col][row + 2].left)))
		{
			// Pick a random wall 1-4 to knock down
			random = (rand() % 4) + 1;		

			 // GO UP
			if ((random == 1) && (col > 1)) 
			{
				// If not visited
				if (Maze[col - 2][row].visited == false) 
				{	
					// Delete show
					Maze[col - 1][row].show = ' ';	
					// Mark cell as visited
					Maze[col - 1][row].visited = true;	
					// Knock down wall
					Maze[col][row].top = false;	

					// Push X for back track
					back_trackX.push(row); 			
					// Push Y for back track
					back_trackY.push(col);			

					// Move to next cell
					col -= 2;				
					// Mark cell moved to as visited
					Maze[col][row].visited = true;		
					// Update path
					Maze[col][row].show = ' ';	
					// Knock down wall
					Maze[col][row].bot = false;	
					// Increase visitedCells counter
					visitedCells++;					
				}
				else
					continue;
			}

			// GO DOWN
			else if ((random == 2) && (col < length - 2)) 
			{
				// If not visited
				if (Maze[col + 2][row].visited == false) 
				{	
					// Delete show
					Maze[col + 1][row].show = ' ';	
					// Mark cell as visited
					Maze[col + 1][row].visited = true;	
					// Knock down wall
					Maze[col][row].bot = false;	

					// Push X for back track
					back_trackX.push(row); 	
					// Push Y for back track
					back_trackY.push(col);			

					// Move to next cell
					col += 2;					
					// Mark cell moved to as visited
					Maze[col][row].visited = true;		
					// Update path
					Maze[col][row].show = ' ';		
					// Knock down wall
					Maze[col][row].top = false;	
					// Increase visitedCells counter
					visitedCells++;					
				}
				else
					continue;
			}

			// GO LEFT
			else if ((random == 3) && (row > 1)) 
			{
				// If not visited
				if (Maze[col][row - 2].visited == false) 
				{	
					// Delete show
					Maze[col][row - 1].show = ' ';	
					// Mark cell as visited
					Maze[col][row - 1].visited = true;	
					// Knock down wall
					Maze[col][row].left = false;	

					// Push X for back track
					back_trackX.push(row); 			
					// Push Y for back track
					back_trackY.push(col);			

					// Move to next cell
					row -= 2;					
					// Mark cell moved to as visited
					Maze[col][row].visited = true;		
					// Update path
					Maze[col][row].show = ' ';		
					// Knock down wall
					Maze[col][row].right = false;
					// Increase visitedCells counter
					visitedCells++;					
				}
				else
					continue;
			}

			// GO RIGHT
			else if ((random == 4) && (row < length - 2)) 
			{
				// If not visited
				if (Maze[col][row + 2].visited == false) 
				{	
					// Delete show
					Maze[col][row + 1].show = ' ';	
					// Mark cell as visited
					Maze[col][row + 1].visited = true;	
					// Knock down wall
					Maze[col][row].right = false;

					// Push X for back track
					back_trackX.push(row); 	
					// Push Y for back track
					back_trackY.push(col);			

					// Move to next cell
					row += 2;					
					// Mark cell moved to as visited
					Maze[col][row].visited = true;		
					// Update path
					Maze[col][row].show = ' ';	
					// Knock down wall
					Maze[col][row].left = false;	
					// Increase visitedCells counter
					visitedCells++;					
				}
				else
					continue;
			}
		}
		else {
			row = back_trackX.top();
			back_trackX.pop();

			col = back_trackY.top();
			back_trackY.pop();
		}
	}

	Maze[length - 2][length - 2].show = 'E';

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			maze[i][j] = Maze[i][j];
		}
	}

	return maze;
}

/**
 * @brief A function for checking if a move is possible
 * @param board The maze
 * @param row The row coordinate
 * @param col The column coordinate
 * @return bool value
*/
bool isMovePossible(Room **board, short row, short col/*, Data* role, Data* item, , bool game*/)
{
	/*
	for (int i = 0; i < 6; i++) {
		if (board[row][col] == role[i].person)
			atack(role, i, game);
	}
	for (int i = 0; i < 4; i++) {
		if (board[row][col] == item[i].person)
			shop(role, item, i);
	}
	*/
	if (board[col][row].show == '#')
	{
		return false;
	}

    return true;
}

void GameRules() {
	Data role[6];
	Data item[4];
	// player
	role[0].person = 'x';
	role[0].healt = 100;
	role[0].armor = 0;
	role[0].atack = 10;
	role[0].money = 0;
	role[0].keys = 0;

	// first enemie
	//role[1].person = 253;
	role[1].healt = 15;
	role[1].atack = 5;
	role[1].money = 1;

	// second enemie
	//role[2].person = 248;
	role[2].healt = 25;
	role[2].atack = 10;
	role[2].money = 3;

	// third enemie
	//role[3].person = 176;
	role[3].healt = 50;
	role[3].atack = 20;
	role[2].money = 6;

	// fourth enemie
	//role[4].person = 177;
	role[4].healt = 75;
	role[4].atack = 25;
	role[2].money = 10;

	// boss
	//role[5].person = 201;
	role[5].healt = 500;
	role[5].atack = 0;

	// heart recovers
	//item[0].person = 3;
	item[0].healt = 0;
	item[0].money = 20;

	// sword
	//item[1].person = 216;
	item[1].atack = 5;
	item[1].money = 10;

	// armor
	//item[2].person = 1;
	item[2].armor = 10;
	item[2].money = 15;

	// key
	//item[3].person = 12;
	item[3].keys = 1;
	item[3].money = 100;
}
