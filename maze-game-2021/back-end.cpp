/*! @file back-end.cpp
*   @brief A source file for the logic layer.
*/


#include "back-end.h"

/**
 * @brief A struct for room.
*/

/* Data for size of room, cordinates of enemies
int rowRoom = 22, colRoom = 11; // size of the rooms
int level = 0;
char** board;
int rowPlayer = 1, colPlayer = 1, moves = 0;
int randomSizeOfEnemies, tempE;
int* tempX = new int[randomSizeOfEnemies];
int* tempY = new int[randomSizeOfEnemies];
int cTemp = 0;
int randomSpawnX, randomSpawnY;
int counterDead = 0;
int counterOfEnemies;
*/

/* Fuction for front end about statistic of game
void stats(Data** role, Data* item, int idEnemies) {
	cout << endl;
	cout << "Counter of Enemies - " << tempE << endl;
	for (int i = 0; i < randomSizeOfEnemies; i++) {
	   cout << "Cordinates of element - " << i << " = " << tempX[i] << " " << tempY[i] << endl;
	}
	cout << "Cordinates of element this enemie " << " = row - " << tempX[idEnemies] << " col - " << tempY[idEnemies] << endl;
	cout << "idEnemies = " << idEnemies << endl;
	cout << "Level = " << level << endl;
	cout << "Counter of Deads - " << counterDead << endl << endl;
	cout << "Player" << endl;
	cout << "Healt: " << role[0][0].healt << endl;
	cout << "Atack: " << role[0][0].atack << endl;
	cout << "Armor: " << role[0][0].armor << endl;
	cout << "Money: " << role[0][0].money << endl;
	cout << "Keys: " << role[0][0].keys << endl << endl;

	if (tempX[idEnemies] < 22) {
		cout << "Enemie" << endl;
		cout << "Healt: " << role[1][idEnemies].healt << endl;
		cout << "Atack: " << role[1][idEnemies].atack << endl;
		cout << "Money: " << role[1][idEnemies].money << endl;
	}
}
*/

/* Create normal room with enemies
char** room(Data** role, Data* item) {
	char** room = new char * [rowRoom];
	for (int i = 0; i < rowRoom; i++)
		room[i] = new char[colRoom];

	for (int i = 0; i < rowRoom; i++) {
		for (int j = 0; j < colRoom; j++) {
			if ((i == 0 && j == 0) || (i == 0 && j != 0) || (j == 0 && i != 0) || (j == colRoom - 1 && i != rowRoom - 1) || (i == rowRoom - 1 && j != 0)) {
				room[i][j] = '#';
			}
			else {
				room[i][j] = ' ';
			}
		}
	}

	if (level == 0) {
		srand(time(NULL));
		randomSizeOfEnemies = 3;//rand() % 4 + 1;
		tempE = randomSizeOfEnemies;
		for (counterOfEnemies = 0; counterOfEnemies < randomSizeOfEnemies; counterOfEnemies++) {
			do {
				tempX[counterOfEnemies] = rand() % rowRoom + 3;
				tempY[counterOfEnemies] = rand() % colRoom + 3;
			} while (tempX[counterOfEnemies] >= rowRoom - 1 || tempY[counterOfEnemies] >= colRoom - 1 || room[tempX[counterOfEnemies]][tempY[counterOfEnemies]] != ' ');
		}
		level++;
	}
		for (int i = 0; i < tempE; i++) {
			room[tempX[i]][tempY[i]] = role[1][i].person;
		}

				for (int k = 0; k < tempE; k++) {
					if (role[1][k].person == 'D') {
						counterDead++;
						if (counterDead >= tempE) {
							room[rowRoom - 1][(colRoom - 3) / 2] = ' ';
							room[rowRoom - 1][((colRoom - 3) / 2) + 1] = ' ';
							room[rowRoom - 1][((colRoom - 3) / 2) + 2] = ' ';
							level++;
						}
					}
				}
				counterDead = 0;

	return room;
}
*/

/* Fuction for fighting and dead body
void atack(Data** role, short index, bool game, short row, short col, int idEnemies) {
	if (role[index][idEnemies].person != 'D') {
		role[index][idEnemies].healt -= role[0][0].atack;
		if (role[index][idEnemies].healt <= 0) {
			role[0][0].money += role[index][idEnemies].money;
			role[index][idEnemies].person = 'D';
		}

		if (role[index][idEnemies].person != ' ' && role[index][idEnemies].person != 'D') {
			role[0][0].healt -= role[index][idEnemies].atack;
			if (role[0][0].healt <= 0)
				game = false;
		}
	}
}
*/

/* Shop
void shop(Data** role, Data* item, short index) {
	switch (index) {
	case 0:
		// Healt
		if (role[0][0].money >= item[0].money) {
			role[0][0].money -= item[0].money;
			role[0][0].healt = 100;
		}
		break;
	case 1:
		// Sword
		if (role[0][0].money >= item[1].money) {
			role[0][0].money -= item[1].money;
			role[0][0].atack += 5;
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
*/

/* Fuction if the player finds a enemie or item or place where he can't be
bool movePosible(short row, short col, Data** role, Data* item, bool game) {
	int idEnemies;
	for (idEnemies = 0; idEnemies < tempE; idEnemies++) {
		if (row == tempX[idEnemies] && col == tempY[idEnemies]) {
			atack(role, 1, game, row, col, idEnemies);
			break;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (board[row][col] == item[i].person)
			shop(role, item, i);
	}

	stats(role, item, idEnemies);
	if (row == -1 || col == -1)
		return false;
	board = room(role, item);
	if (board[row][col] != ' ')
		return false;
	return true;
}
*/

/* Draw room
void draw(Data **role, Data* item) {
	board = room(role, item);
	for (int i = 0; i < rowRoom; i++) {
		for (int j = 0; j < colRoom; j++) {
				gotoxy(i, j);
				cout << board[i][j];
		}
		cout << endl;
	}
}
*/

/* Game Rules about player, enemies and items
void GameRules(Data **role, Data *item) {

	// player
	role[0][0].person = 'x';
	role[0][0].healt = 100;
	role[0][0].armor = 0;
	role[0][0].atack = 10;
	role[0][0].money = 200;
	role[0][0].keys = 0;

	// first type enemie | counter of enemy
	for (int i = 0; i < 10; i++) {
		role[1][i].person = 'F';
		role[1][i].healt = 15;
		role[1][i].atack = 5;
		role[1][i].money = 1;
	}

	/*
	// second enemie
	role[2].person = 248;
	role[2].healt = 25;
	role[2].atack = 10;
	role[2].money = 3;

	// third enemie
	role[3].person = 176;
	role[3].healt = 50;
	role[3].atack = 20;
	role[3].money = 6;

	// fourth enemie
	role[4].person = 177;
	role[4].healt = 75;
	role[4].atack = 25;
	role[4].money = 10;

	// boss
	role[5].person = 201;
	role[5].healt = 500;
	role[5].atack = 0;
	
	// heart recovers
item[0].person = 3;
item[0].healt = 0;
item[0].money = 20;

// sword
item[1].person = 'S';
item[1].atack = 5;
item[1].money = 10;

// armor
item[2].person = 'A';
item[2].armor = 10;
item[2].money = 15;

// key
item[3].person = 'K';
item[3].keys = 1;
item[3].money = 100;
*/

/* This is for "int main()"
	Data** role = new Data*[6];
	for (int i = 0; i < 6; i++) {
		role[i] = new Data[100];
	}
	Data* item = new Data[4];
	GameRules(role, item);
	move(role, item);
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
