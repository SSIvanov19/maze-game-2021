/*! @file back-end.cpp
*   @brief A source file for the logic layer.
*/
#include "back-end.h"


struct Room
{
	bool visited;
	bool top;
	bool bot;
	bool left;
	bool right;
	char show;
};

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
char sPartFourthMonster = 215;
char bossFPart = 206;
char bossSPart = 178;
char bossTPart = 201;
char bossFoPart = 184;
char chest = 127;
char bush = 157;
char rock = 240;
char holegl = 201;
char holegd = 187;
char holedl = 200;
char holedd = 188;
char holesr1 = 205;
char holesr2 = 186;

char** room(Data** role, Data* item, int* tempE, int* level, int* tempX, int* tempY, int* counterDead, int* mapY, int* mapX)
{
	static int mapRoom;
	static int drawArt;
	static int randomSizeOfEnemies;
	static int counterOfEnemies;
	static int nextLevel = 0;
	static int ChoiseShopX[2];
	static int ChoiseShopY[2];
	static int levelOfEnemies1;
	static int levelOfEnemies2;
	static int levelSize;
	static bool BossIshere = false;
	static bool shopIsHere = false;

	char** room = new char * [ROW_ROOM + 4];

	for (int i = 0; i < ROW_ROOM + 4; i++)
	{
		room[i] = new char[COL_ROOM + 4];
	}

	for (int i = 0; i < ROW_ROOM + 4; i++) {
		for (int j = 0; j < COL_ROOM + 4; j++) {
			room[i][j] = ' ';
		}
	}

	drawArt = rand() % 2;

	// |-
	if (*mapX == 0 && *mapY == 0) {
		mapRoom = 1;
		for (int i = 0; i < ROW_ROOM; i++) {
			for (int j = 0; j < COL_ROOM; j++) {
				if (i > 1 && j > 1 && i < ROW_ROOM - 1 && j < COL_ROOM - 1) {
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
			for (int x = 0; x < ROW_ROOM + 4; x++) {
				for (int y = 0; y < COL_ROOM + 4; y++) {
					// right
					if (x == ROW_ROOM && y == (COL_ROOM - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// down
					if (x == (ROW_ROOM - 1) / 2 + temp2 * 2 && y == COL_ROOM) {
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
	if (*mapX == 0 && (*mapY == 1 || *mapY == 2)) {
		mapRoom = 2;
		for (int i = 0; i < ROW_ROOM; i++) {
			for (int j = 0; j < COL_ROOM; j++) {
				if (i > 1 && j > 1 && i < ROW_ROOM - 1 && j < COL_ROOM - 1) {
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
			for (int x = 0; x < ROW_ROOM + 4; x++) {
				for (int y = 0; y < COL_ROOM + 4; y++) {
					if (x == ROW_ROOM && y == (COL_ROOM - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					if (x == (ROW_ROOM - 1) / 2 + temp2 * 2 && y == COL_ROOM) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					if (x == (ROW_ROOM - 1) / 2 + temp2 * 2 && y == 0) {
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

		//drawArtRoom(drawArt, role, item);
	}

	// |_
	if (*mapX == 0 && *mapY == 3) {
		mapRoom = 2;
		for (int i = 0; i < ROW_ROOM; i++) {
			for (int j = 0; j < COL_ROOM; j++) {
				if (i > 1 && j > 1 && i < ROW_ROOM - 1 && j < COL_ROOM) {
					if (j == COL_ROOM - 2 || j == COL_ROOM - 1)
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
			for (int x = 0; x < ROW_ROOM + 4; x++) {
				for (int y = 0; y < COL_ROOM + 4; y++) {
					if (x == ROW_ROOM && y == (COL_ROOM - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					if (x == (ROW_ROOM - 1) / 2 + temp2 * 2 && y == 0) {
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
		//drawArtRoom(drawArt, role, item);
	}

	// -
	if ((*mapX == 1 || *mapX == 2) && *mapY == 0) {
		mapRoom = 4;
		for (int i = 0; i < ROW_ROOM; i++) {
			for (int j = 0; j < COL_ROOM; j++) {
				if (i > 1 && j > 1 && i < ROW_ROOM - 1 && j < COL_ROOM - 1) {
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
			for (int x = 0; x < ROW_ROOM + 4; x++) {
				for (int y = 0; y < COL_ROOM + 4; y++) {
					// right
					if (x == ROW_ROOM && y == (COL_ROOM - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// down
					if (x == (ROW_ROOM - 1) / 2 + temp2 * 2 && y == COL_ROOM) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// left 
					if (x == 0 && y == (COL_ROOM - 1) / 2 + temp2) {
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
		//drawArtRoom(drawArt, role, item);
	}

	// -|
	if (*mapX == 3 && *mapY == 0) {
		mapRoom = 5;
		for (int i = 0; i < ROW_ROOM; i++) {
			for (int j = 0; j < COL_ROOM; j++) {
				if (i > 1 && j > 1 && i < ROW_ROOM - 1 && j < COL_ROOM - 1) {
					if (i == ROW_ROOM - 2)
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
			for (int x = 0; x < ROW_ROOM + 4; x++) {
				for (int y = 0; y < COL_ROOM + 4; y++) {
					// down
					if (x == (ROW_ROOM - 1) / 2 + temp2 * 2 && y == COL_ROOM) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// left 
					if (x == 0 && y == (COL_ROOM - 1) / 2 + temp2) {
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
		//drawArtRoom(drawArt, role, item);
	}

	// -> | 
	if (*mapX == 3 && (*mapY == 1 || *mapY == 2)) {
		mapRoom = 6;
		for (int i = 0; i < ROW_ROOM; i++) {
			for (int j = 0; j < COL_ROOM; j++) {
				if (i > 1 && j > 1 && i < ROW_ROOM - 1 && j < COL_ROOM - 1) {
					if (i == ROW_ROOM - 2)
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
			for (int x = 0; x < ROW_ROOM + 4; x++) {
				for (int y = 0; y < COL_ROOM + 4; y++) {
					// down
					if (x == (ROW_ROOM - 1) / 2 + temp2 * 2 && y == COL_ROOM) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// left 
					if (x == 0 && y == (COL_ROOM - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// up 
					if (x == (ROW_ROOM - 1) / 2 + temp2 * 2 && y == 0) {
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
		//drawArtRoom(drawArt, role, item);
	}

	// _|
	if (*mapX == 3 && *mapY == 3) {
		mapRoom = 7;
		for (int i = 0; i < ROW_ROOM; i++) {
			for (int j = 0; j < COL_ROOM; j++) {
				if (i > 1 && j > 1 && i < ROW_ROOM - 1 && j < COL_ROOM - 1) {
					if (i == ROW_ROOM - 2 || j == COL_ROOM - 2)
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
			for (int x = 0; x < ROW_ROOM + 4; x++) {
				for (int y = 0; y < COL_ROOM + 4; y++) {
					// left 
					if (x == 0 && y == (COL_ROOM - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// up 
					if (x == (ROW_ROOM - 1) / 2 + temp2 * 2 && y == 0) {
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
	if ((*mapX == 1 || *mapX == 2) && *mapY == 3) {
		mapRoom = 8;
		for (int i = 0; i < ROW_ROOM; i++) {
			for (int j = 0; j < COL_ROOM; j++) {
				if (i > 1 && j > 1 && i < ROW_ROOM - 1 && j < COL_ROOM - 1) {
					if (j == COL_ROOM - 2)
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
			for (int x = 0; x < ROW_ROOM + 4; x++) {
				for (int y = 0; y < COL_ROOM + 4; y++) {
					// right
					if (x == ROW_ROOM && y == (COL_ROOM - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// left 
					if (x == 0 && y == (COL_ROOM - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// up 
					if (x == (ROW_ROOM - 1) / 2 + temp2 * 2 && y == 0) {
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
		//drawArtRoom(drawArt, role, item);
	}

	// all
	if (*mapX >= 1 && *mapX < 3 && *mapY >= 1 && *mapY < 3) {
		mapRoom = 9;
		for (int i = 0; i < ROW_ROOM; i++) {
			for (int j = 0; j < COL_ROOM; j++) {
				if (i > 1 && j > 1 && i < ROW_ROOM - 1 && j < COL_ROOM - 1) {
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
			for (int x = 0; x < ROW_ROOM + 4; x++) {
				for (int y = 0; y < COL_ROOM + 4; y++) {
					// right
					if (x == ROW_ROOM && y == (COL_ROOM - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// down
					if (x == (ROW_ROOM - 1) / 2 + temp2 * 2 && y == COL_ROOM) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// left 
					if (x == 0 && y == (COL_ROOM - 1) / 2 + temp2) {
						room[x][y] = '#';
						hall++;
					}
					if (hall == 5)
						hall = 0;
					// up 
					if (x == (ROW_ROOM - 1) / 2 + temp2 * 2 && y == 0) {
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
		//drawArtRoom(drawArt, role, item);
	}


	if (*level == nextLevel) {
		srand(time(NULL));
		if (*mapX != 3 && *mapY != 3) {
			if (*mapX == 0 && *mapY == 0) {
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
				if (((*mapX == ChoiseShopX[0] && *mapY == ChoiseShopY[0]) || (*mapX == ChoiseShopX[1] && *mapY == ChoiseShopY[1]))) {
					shopIsHere = true;
				}
				else {
					shopIsHere = false;
				}
				randomSizeOfEnemies = 1; rand() % 4 + 1;
				*tempE += randomSizeOfEnemies;
				bool ready;
				nextLevel++;
				for (counterOfEnemies = 0; counterOfEnemies < randomSizeOfEnemies; counterOfEnemies++) {
					do {
						ready = false;
						tempX[counterOfEnemies] = rand() % ROW_ROOM + 1;
						tempY[counterOfEnemies] = rand() % COL_ROOM + 1;

						if (shopIsHere) {
							for (int i = 0; i < ROW_ROOM; i++) {
								for (int j = 0; j < COL_ROOM; j++) {
									if (tempX[counterOfEnemies] >= 12 && tempX[counterOfEnemies] <= 27)
										if (tempY[counterOfEnemies] >= 5 && tempY[counterOfEnemies] <= 14)
											ready = true;
								}
							}
						}
						if (tempX[counterOfEnemies] >= ROW_ROOM - 10 || tempX[counterOfEnemies] < 2)
							ready = true;
						if (tempY[counterOfEnemies] >= COL_ROOM - 6 || tempY[counterOfEnemies] < 2)
							ready = true;
						if (room[tempX[counterOfEnemies]][tempY[counterOfEnemies]] == '#') {
							ready = true;
						}
						if (tempX[counterOfEnemies] == tempX[counterOfEnemies - 1] && tempY[counterOfEnemies] == tempY[counterOfEnemies - 1])
							ready = true;

					} while (ready);
				}

				for (int i = 0; i < 4; i++) {
					for (int j = 1; j <= 4; j++) {
						if (role[j][i].person == 'D') {
							if (j == 1) {
								role[j][i].person = firstMonster;
								role[j][i].health = 15;
								role[j][i].money = 1;
							}
							if (j == 2) {
								role[j][i].person = secondMonster;
								role[j][i].health = 25;
								role[j][i].money = 3;
							}
							if (j == 3) {
								role[j][i].person = sPartThirdMonster;
								role[j][i].health = 50;
								role[j][i].money = 6;
							}
							if (j == 4) {
								role[j][i].person = sPartFourthMonster;
								role[j][i].health = 75;
								role[j][i].money = 10;
							}
						}
					}
				}

				/* RULES */
				// before 15
				if (role[0][0].attack < 15) {
					levelSize = 4;
					levelOfEnemies1 = 1;
					levelOfEnemies2 = 1;
				}
				// after 15 and before 20
				else if (role[0][0].attack == 15) {
					levelSize = 1;
					levelOfEnemies1 = 1;
					levelOfEnemies2 = 2;
				}
				// after 20 and before 25
				else if (role[0][0].attack == 20) {
					levelSize = 3;
					levelOfEnemies1 = 1;
					levelOfEnemies2 = 2;
				}
				// after 25 and before 45
				else if (role[0][0].attack >= 25 && role[0][0].attack < 45) {
					levelSize = 1;
					levelOfEnemies1 = 2;
					levelOfEnemies2 = 3;
				}
				// after 45 and before 60
				else if (role[0][0].attack >= 45 && role[0][0].attack < 60) {
					levelSize = 3;
					levelOfEnemies1 = 2;
					levelOfEnemies2 = 3;
				}
				// after 60 and before 75
				else if (role[0][0].attack >= 60 && role[0][0].attack < 75) {
					levelSize = 2;
					levelOfEnemies1 = 3;
					levelOfEnemies2 = 4;
				}
				// after 75
				else if (role[0][0].attack >= 75) {
					levelSize = 4;
					levelOfEnemies1 = 4;
					levelOfEnemies2 = 4;
				}

			}
		}
		else { // BOSS IS HERE
			room[20][8] = bossFPart;
			room[20][9] = bossSPart;
			room[19][9] = bossTPart;
			room[21][9] = bossFoPart;
		}
	}

	if (!BossIshere) {
		for (int i = 0; i < randomSizeOfEnemies; i++) {
			if (shopIsHere) {
				// shop
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

				// block
				if (*counterDead != *tempE) {
					// up
					for (int i1 = 12; i1 < 28; i1++) {
						room[i1][5] = holesr1;
					}
					// down
					for (int i1 = 12; i1 < 28; i1++) {
						room[i1][13] = holesr1;
					}
					// ->
					for (int i1 = 6; i1 < 13; i1++) {
						room[28][i1] = holesr2;
					}
					// <-
					for (int i1 = 6; i1 < 13; i1++) {
						room[11][i1] = holesr2;
					}
					room[11][5] = holegl; // |-
					room[28][5] = holegd; // -|
					room[11][13] = holedl; // |_
					room[28][13] = holedd; // _|
				}
				else {
					// up
					for (int i1 = 12; i1 < 28; i1++) {
						room[i1][5] = ' ';
					}
					// down
					for (int i1 = 12; i1 < 28; i1++) {
						room[i1][13] = ' ';
					}
					// ->
					for (int i1 = 6; i1 < 13; i1++) {
						room[28][i1] = ' ';
					}
					// <-
					for (int i1 = 6; i1 < 13; i1++) {
						room[11][i1] = ' ';
					}
					room[11][5] = ' '; // |-
					room[28][5] = ' '; // -|
					room[11][13] = ' '; // |_
					room[28][13] = ' '; // _|
				}
			}
			if (i < levelSize) {
				if (levelOfEnemies2 == 3) {
					room[tempX[i]][tempY[i] - 1] = fPartThirdMonster;
					room[tempX[i]][tempY[i]] = role[levelOfEnemies2][i].person;
				}
				else if (levelOfEnemies2 == 4) {
					room[tempX[i]][tempY[i] - 1] = fPartFourthMonster;
					room[tempX[i]][tempY[i]] = role[levelOfEnemies2][i].person;
				}
				else {
					room[tempX[i]][tempY[i]] = role[levelOfEnemies2][i].person;
				}
			}
			else if (i >= levelSize) {
				if (levelOfEnemies1 == 3) {
					room[tempX[i]][tempY[i] - 1] = fPartThirdMonster;
					room[tempX[i]][tempY[i]] = role[levelOfEnemies1][i].person;
				}
				else if (levelOfEnemies1 == 4) {
					room[tempX[i]][tempY[i] - 1] = fPartFourthMonster;
					room[tempX[i]][tempY[i]] = role[levelOfEnemies1][i].person;
				}
				else {
					room[tempX[i]][tempY[i]] = role[levelOfEnemies1][i].person;
				}
			}
		}
	}
	else { // BOSS IS HERE

	}

	if (*counterDead == *tempE) 
	{
		switch (mapRoom) {
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

void attack(Data** role, int index, bool game, int idEnemies, int* counterDead) 
{
	if (index != 5) 
	{
		if (role[index][idEnemies].person != 'D') 
		{
			role[index][idEnemies].health -= role[0][0].attack;

			if (role[index][idEnemies].health <= 0)
			{
				role[0][0].money += role[index][idEnemies].money;
				role[index][idEnemies].money = 0;
				role[index][idEnemies].person = 'D';
				(*counterDead)++;
			}

			if (role[index][idEnemies].person != ' ' && role[index][idEnemies].person != 'D') 
			{
				if (role[0][0].armor > 0) 
				{
					role[0][0].armor -= role[index][idEnemies].attack;

					if (role[0][0].armor < 0) 
					{
						role[0][0].health += role[0][0].armor;
						role[0][0].armor = 0;
					}
				}
				else 
				{
					role[0][0].health -= role[index][idEnemies].attack;

					if (role[0][0].health <= 0)
					{
						game = false;
					}
				}
			}
		}
	}
	else { // BOSS IS HERE
		if (role[index][idEnemies].health > 0) {
			role[index][idEnemies].health -= role[0][0].attack;
			if (role[index][idEnemies].health > 0) {
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
			else {
				game = false;
			}
		}
		else {
			game = false;
		}
	}
}

void shop(Data** role, Data* item, short index) {
	switch (index) 
	{
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

void GameRules(Data** role, Data* item) 
{

	// player
	role[0][0].person = 'x';
	role[0][0].health = 100;
	role[0][0].armor = 10;
	role[0][0].attack = 15;
	role[0][0].money = 200;
	role[0][0].keys = 0;

	// first type enemie | counter of enemy
	for (int i = 0; i < 4; i++) {
		role[1][i].person = firstMonster;
		role[1][i].health = 15;
		role[1][i].attack = 15;
		role[1][i].money = 1;
	}

	// second enemie
	for (int i = 0; i < 4; i++) {
		role[2][i].person = secondMonster;
		role[2][i].health = 25;
		role[2][i].attack = 10;
		role[2][i].money = 3;
	}

	// third enemie
	for (int i = 0; i < 4; i++) {
		role[3][i].person = sPartThirdMonster;
		role[3][i].health = 50;
		role[3][i].attack = 20;
		role[3][i].money = 6;
	}

	// fourth enemie
	for (int i = 0; i < 4; i++) {
		role[4][i].person = sPartFourthMonster;
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

/* TODO: Make isMovePossible to return vector of two bools:
* first one - Show if the move is possible
* second one - Show if the board needs to be cleared and printed again
*/
bool isMovePosible(short row, short col, Data** role, Data* item, bool game, int* tempE, int* level, int* tempX, int* tempY, int* counterDead, int* mapY, int* mapX)
{
	static bool levelUp = false;

	int idEnemies, indexOfEnemie = 0;
	char** board = room(role, item, tempE, level, tempX, tempY, counterDead, mapY, mapX);

	for (idEnemies = 0; idEnemies < *tempE; idEnemies++) {
		if (row == tempX[idEnemies] && col == tempY[idEnemies]) {
			if (board[row][col] == firstMonster)
				indexOfEnemie = 1;
			if (board[row][col] == secondMonster)
				indexOfEnemie = 2;
			if ((board[row][col] == sPartThirdMonster) || (board[row][col] == fPartThirdMonster))
				indexOfEnemie = 3;
			if ((board[row][col] == sPartFourthMonster) || (board[row][col] == fPartFourthMonster))
				indexOfEnemie = 4;
			if (board[row][col] != 'D')
				attack(role, indexOfEnemie, game, idEnemies, counterDead);
			break;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (board[row][col] == item[i].person)
			shop(role, item, i);
	}
	if ((board[row][col] == bossFPart) || (board[row][col] == bossSPart) || (board[row][col] == bossTPart) || (board[row][col] == bossFoPart)) {
		indexOfEnemie = 5;
		idEnemies = 0;
		attack(role, indexOfEnemie, game, idEnemies, counterDead);
	}
	//stats(role, item, idEnemies);
	for (int i = 17; i < 24; i++) {
		if (row == i && col == 17) {
			//teleport(role, row, col);
			(*level)++;
			levelUp = true;
			(*mapY)++;
			return false;
		}
	}
	for (int i = 7; i < 10; i++) {
		if (row == 41 && col == i) {
			//teleport(role, row, col);
			(*level)++;
			levelUp = true;
			(*mapX)++;
			return false;
		}
	}
	for (int i = 17; i < 24; i++) {
		if (row == i && col == 0) {
			//teleport(role, row, col);
			(*level)++;
			levelUp = true;
			(*mapY)--;
			return false;
		}
	}
	for (int i = 7; i < 10; i++) {
		if (row == 0 && col == i) {
			//teleport(role, row, col);
			(*level)++;
			levelUp = true;
			(*mapX)--;
			return false;
		}
	}
	if (row == -1 || col == -1)
		return false;
	if (board[row][col] != ' ')
		return false;
	return true;
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
bool isMazeMovePossible(Room **board, short row, short col/*, Data* role, Data* item, , bool game*/)
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