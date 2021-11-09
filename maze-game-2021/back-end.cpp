/*! @file back-end.cpp
*   @brief A source file for the logic layer.
*/
#include "back-end.h"
#include "front-end.h"

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
char bossFoPart = 187;
char chest = 219;
char bush = 157;
char rock = 240;
char holegl = 201;
char holegd = 187;
char holedl = 200;
char holedd = 188;
char holesr1 = 205;
char holesr2 = 186;

int times = 0;

#define LENGTH 17 // length of maze

/**
 * @brief A function for settign up the maze
 * @param Maze The maze
*/
void setMaze(Room** Maze)
{
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			Maze[i][j].show = '#';
			Maze[i][j].visited = false;
			Maze[i][j].top = true;
			Maze[i][j].bot = true;
			Maze[i][j].left = true;
			Maze[i][j].right = true;
		}
	}

	for (int i = 1; i < LENGTH - 1; i++)
	{
		for (int j = 1; j < LENGTH - 1; j++)
		{
			// Border Cells have fewer accessible walls
			Maze[1][j].top = false;
			Maze[LENGTH - 2][j].bot = false;
			Maze[i][1].left = false;
			Maze[i][LENGTH - 2].right = false;
		}
	}
}

/**
 * @brief Generate a maze
 * @param maze The maze
*/
void generateMaze(Room** maze)
{
	Room Maze[LENGTH][LENGTH];

	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			Maze[i][j] = maze[i][j];
		}
	}

	srand((unsigned)time(NULL)); // Pick random start cell
	int random = 0;
	int times = 0;
	int row = ((2 * rand()) + 1) % (LENGTH - 1); // Generate a random odd number between 1 and LENGTH
	int col = ((2 * rand()) + 1) % (LENGTH - 1); // Generate a random odd number between 1 and LENGTH
	int visitedCells = 1;
	int totalCells = ((LENGTH - 1) / 2) * ((LENGTH - 1) / 2);
	int percent = 0;
	std::stack<int> back_trackX, back_trackY; 						// Stack is used to trace the reverse path
	if (times == 0)
	{
		times++;
		col = 1;
		row = 1;
	}
	Maze[col][row].show = 'S';						// Set S as the start cell
	Maze[col][row].visited = true;						// Set start cell as visited;

	while (visitedCells < totalCells)
	{
		if (((Maze[col - 2][row].visited == false) && (Maze[col][row].top == true && Maze[col - 2][row].bot == true)) ||
			((Maze[col + 2][row].visited == false) && (Maze[col][row].bot == true && Maze[col + 2][row].top == true)) ||
			((Maze[col][row - 2].visited == false) && (Maze[col][row].left == true && Maze[col][row - 2].right == true)) ||
			((Maze[col][row + 2].visited == false) && (Maze[col][row].right == true && Maze[col][row + 2].left == true)))
		{
			random = (rand() % 4) + 1;		// Pick a random wall 1-4 to knock down

			 // GO UP
			if ((random == 1) && (col > 1))
			{
				if (Maze[col - 2][row].visited == false)
				{	// If not visited
					Maze[col - 1][row].show = ' ';	// Delete show
					Maze[col - 1][row].visited = true;	// Mark cell as visited
					Maze[col][row].top = false;	// Knock down wall

					back_trackX.push(row); 			// Push X for back track
					back_trackY.push(col);			// Push Y for back track

					col -= 2;					// Move to next cell
					Maze[col][row].visited = true;		// Mark cell moved to as visited
					Maze[col][row].show = ' ';		// Update path
					Maze[col][row].bot = false;	// Knock down wall
					visitedCells++;					// Increase visitedCells counter
				}
				else
					continue;
			}

			// GO DOWN
			else if ((random == 2) && (col < LENGTH - 2))
			{
				if (Maze[col + 2][row].visited == false)
				{	// If not visited
					Maze[col + 1][row].show = ' ';	// Delete show
					Maze[col + 1][row].visited = true;	// Mark cell as visited
					Maze[col][row].bot = false;	// Knock down wall

					back_trackX.push(row); 			// Push X for back track
					back_trackY.push(col);			// Push Y for back track

					col += 2;					// Move to next cell
					Maze[col][row].visited = true;		// Mark cell moved to as visited
					Maze[col][row].show = ' ';		// Update path
					Maze[col][row].top = false;	// Knock down wall
					visitedCells++;					// Increase visitedCells counter
				}
				else
					continue;
			}

			// GO LEFT
			else if ((random == 3) && (row > 1))
			{
				if (Maze[col][row - 2].visited == false)
				{	// If not visited
					Maze[col][row - 1].show = ' ';	// Delete show
					Maze[col][row - 1].visited = true;	// Mark cell as visited
					Maze[col][row].left = false;	// Knock down wall

					back_trackX.push(row); 			// Push X for back track
					back_trackY.push(col);			// Push Y for back track

					row -= 2;					// Move to next cell
					Maze[col][row].visited = true;		// Mark cell moved to as visited
					Maze[col][row].show = ' ';		// Update path
					Maze[col][row].right = false;	// Knock down wall
					visitedCells++;					// Increase visitedCells counter
				}
				else
					continue;
			}

			// GO RIGHT
			else if ((random == 4) && (row < LENGTH - 2))
			{
				if (Maze[col][row + 2].visited == false)
				{	// If not visited
					Maze[col][row + 1].show = ' ';	// Delete show
					Maze[col][row + 1].visited = true;	// Mark cell as visited
					Maze[col][row].right = false;	// Knock down wall

					back_trackX.push(row); 			// Push X for back track
					back_trackY.push(col);			// Push Y for back track

					row += 2;					// Move to next cell
					Maze[col][row].visited = true;		// Mark cell moved to as visited
					Maze[col][row].show = ' ';		// Update path
					Maze[col][row].left = false;	// Knock down wall
					visitedCells++;					// Increase visitedCells counter
				}
				else
					continue;
			}

			/*
			percent = (visitedCells * 100 / totalCells * 100) / 100;		// Progress in percentage
			std::cout << std::endl << "	Generating a Random Maze... " << percent << "%" << std::endl;
			*/
		}
		else {
			row = back_trackX.top();
			back_trackX.pop();

			col = back_trackY.top();
			back_trackY.pop();
		}
	}

	Maze[LENGTH - 2][LENGTH - 2].show = chest;

	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			maze[i][j] = Maze[i][j];
		}
	}
}

/**
 * @brief A function for checking if a move is possible
 * @param board The maze
 * @param row The row coordinate
 * @param col The column coordinate
 * @return bool value
*/
bool isMovePossible(Room** board, short row, short col, bool &isChest)
{
	isChest = false;

	if (board[col][row].show == chest)
	{
		isChest = true;
	}

	if (row == -1 || col == -1)
	{
		return false;
	}

	if (board[col][row].show == '#')
	{
		return false;
	}

	return true;
}

char** room(Data** role, Data* item, int* tempE, int* level, int* tempX, int* tempY, int* counterDead, int* mapY, int* mapX, int &keyChest)
{
	static int mapRoom;
	static int drawArt;
	static int randomSizeOfEnemies;
	static int counterOfEnemies;
	static int nextLevel = 0;
	static int openChests = 0;
	static int choiseShopX[2];
	static int choiseShopY[2];
	static int choiseMazeX[4]; 
	static int choiseMazeY[4];
	static int levelOfEnemies1;
	static int levelOfEnemies2;
	static int levelSize;
	static bool BossIshere = false;
	static bool shopIsHere = false;
	static bool mazeIsHere = false;
	static int indexOfMaze;
	static bool wizardTalking = false;
	static bool haveKey = false;

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
		if (*mapX == 3 && *mapY == 3 && haveKey) {
			role[0][0].keys--;
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

			// BOSS IS HERE
			tempX[0] = 19;
			tempY[0] = 9;
			*tempE = 1;
			room[20][8] = bossFPart;
			room[20][9] = bossSPart;
			room[19][9] = bossTPart;
			room[21][9] = bossFoPart;
		}
		else { 
			if (*mapX == 0 && *mapY == 0 && !wizardTalking) {
				wizardTalking = true;
				room[20][8] = wizard;
				nextLevel++;
				bool notReadyCordinates = false;
				for (int i = 0; i < 2; i++) {
					do {
						notReadyCordinates = false;
						choiseShopX[i] = rand() % 4;
						choiseShopY[i] = rand() % 4;
						if (choiseShopX[i] == choiseShopX[i - 1] || choiseShopY[i] == choiseShopY[i - 1])
							notReadyCordinates = true;
						if (choiseShopX[i] == 0 && choiseShopY[i] == 0)
							notReadyCordinates = true;
						if (choiseShopX[i] == 3 && choiseShopY[i] == 3)
							notReadyCordinates = true;
						if (choiseShopX[i] == 2 && choiseShopY[i] == 3)
							notReadyCordinates = true;
						if (choiseShopX[i] == 3 && choiseShopY[i] == 2)
							notReadyCordinates = true;
					} while (notReadyCordinates);
				}
				do {
					for (int i = 0; i < 4; i++) {
						do {
							notReadyCordinates = false;
							choiseMazeX[i] = rand() % 4;
							choiseMazeY[i] = rand() % 4;
							if (choiseMazeX[i] == 0 && choiseMazeY[i] == 0)
								notReadyCordinates = true;
							if (choiseMazeX[i] == 3 && choiseMazeY[i] == 3)
								notReadyCordinates = true;
							for (int j = 0; j < 2; j++) {
								if (choiseMazeX[i] == choiseShopX[j] && choiseMazeY[i] == choiseShopY[j])
									notReadyCordinates = true;
							}
						} while (notReadyCordinates);
					}
					int i, j, k = 1;
					for (i = 0; i < 4; i++, k++) {
						for (j = k; j < 4; j++) {
							if (choiseMazeX[i] == choiseMazeX[j] || choiseMazeY[i] == choiseMazeY[j])
								notReadyCordinates = true;
						}
					}
				} while (notReadyCordinates);
			}
			else {
				for (int i = 0; i < 4; i++) {
					if ((*mapX == choiseMazeX[i] && *mapY == choiseMazeY[i])) {
						mazeIsHere = true;
						indexOfMaze = i;
					}
				}
				if (!mazeIsHere) {
					if (((*mapX == choiseShopX[0] && *mapY == choiseShopY[0]) || (*mapX == choiseShopX[1] && *mapY == choiseShopY[1]))) {
						shopIsHere = true;
					}
					else {
						shopIsHere = false;
					}
					randomSizeOfEnemies = rand() % 4 + 1;
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
				else {
					moveInMaze(false);
					nextLevel++;
					openChests++;
					choiseMazeX[indexOfMaze] = 5;
					choiseMazeY[indexOfMaze] = 5;
					
					if (openChests == keyChest)
					{
						role[0][0].keys++;
						haveKey = true;
					}
					else
					{
						role[0][0].money += 15;
					}

					mazeIsHere = false;
					printPlayerData(role);
				}
			}
		}
	}

	if (!BossIshere) {
		if (!mazeIsHere) {
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
		} // mazeIsHere
		  /*
		else {
			for (int i = 0; i < 37; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					room[i][j] = maze[i][j].show;
				}
			}
		}
		*/
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
		case 7: // Boss is here
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

void attack(Data** role, int index, bool &game, int idEnemies, int* counterDead, bool* showBoard, bool& bossIsDead)
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
				*showBoard = true;
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
					if (role[0][0].health <= 0) {
						bossIsDead = false;
						game = false;
					}
				}
			}
			else {
				bossIsDead = true;
				game = false;
			}
		}
		else {
			bossIsDead = true;
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

	printPlayerData(role);
}

void GameRules(Data** role, Data* item) 
{

	// player
	role[0][0].person = 'x';
	role[0][0].health = 100;
	role[0][0].armor = 10;
	role[0][0].attack = 15;
	role[0][0].money = 200;
	role[0][0].keys = 3;

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

bool isMovePossible(bool* showBoard, short* row, short* col, Data** role, Data* item, bool& game, bool& bossIsDead, int* tempE, int* level, int* tempX, int* tempY, int* counterDead, int* mapY, int* mapX, int &keyChest)
{
	static bool levelUp = false;

	int idEnemies, indexOfEnemie = 0;
	char** board = room(role, item, tempE, level, tempX, tempY, counterDead, mapY, mapX, keyChest);
	*showBoard = false;
	for (idEnemies = 0; idEnemies < *tempE; idEnemies++) {
		if (*row == tempX[idEnemies] && *col == tempY[idEnemies]) {
			if (board[*row][*col] == firstMonster)
				indexOfEnemie = 1;
			if (board[*row][*col] == secondMonster)
				indexOfEnemie = 2;
			if ((board[*row][*col] == sPartThirdMonster) || (board[*row][*col] == fPartThirdMonster))
				indexOfEnemie = 3;
			if ((board[*row][*col] == sPartFourthMonster) || (board[*row][*col] == fPartFourthMonster))
				indexOfEnemie = 4;
			//if (bossIsHere)
			if (board[*row][*col] == bossTPart) {
				indexOfEnemie = 5;
				idEnemies = 0;
				*showBoard = true;
				printPlayerData(role);
			}
			if (board[*row][*col] != 'D')
			{
				attack(role, indexOfEnemie, game, idEnemies, counterDead, showBoard, bossIsDead);
				printPlayerData(role);
			}
			break;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (board[*row][*col] == item[i].person)
			shop(role, item, i);
	}

	//stats(role, item, idEnemies);
	for (int i = 17; i < 24; i++) {
		if (*row == i && *col == 17) {
			teleport(role, board, row, col, 3);
			(*level)++;
			levelUp = true;
			(*mapY)++;
			*showBoard = true;
			return false;
		}
	}
	for (int i = 7; i < 10; i++) {
		if (*row == 41 && *col == i) {
			teleport(role, board, row, col, 2);
			(*level)++;
			levelUp = true;
			(*mapX)++;
			*showBoard = true;
			return false;
		}
	}
	for (int i = 17; i < 24; i++) {
		if (*row == i && *col == 0) {
			teleport(role, board, row, col, 1);
			(*level)++;
			levelUp = true;
			(*mapY)--;
			*showBoard = true;
			return false;
		}
	}
	for (int i = 7; i < 10; i++) {
		if (*row == 0 && *col == i) {
			teleport(role, board, row, col, 4);
			(*level)++;
			levelUp = true;
			(*mapX)--;
			*showBoard = true;
			return false;
		}
	}
	if (*row == -1 || *col == -1)
		return false;
	if (board[*row][*col] != ' ')
		return false;
	return true;
}

