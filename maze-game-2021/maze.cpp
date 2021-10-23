#include "stdafx.h" // VS header
#include "maze.h"

int main() {

	/*
	Room** Maze = new Room* [LENGTH];
	for (int i = 0; i < LENGTH; ++i)
		Maze[i] = new Room[LENGTH];
	*/

	Room Maze[LENGTH][LENGTH];
	bool playing = false;
	while (!playing) {
		system("cls");
		Set(Maze);
		Draw(Maze);
		Generator(Maze);

		char input;
		std::cout << "Close? (Y): ";
		std::cin >> input;

		if ((input != 'y') && (input != 'Y'))
			std::cout << "Invalid option" << std::endl;
		else if ((input == 'Y') || (input == 'y')) {
			std::cout << "Good bye!" << std::endl;
			break;
		}
	}

	return 0;
}

void Set(Room Maze[][LENGTH]) {
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			Maze[i][j].show = '#';
			Maze[i][j].visited = false;
			Maze[i][j].top = true;
			Maze[i][j].bot = true;
			Maze[i][j].left = true;
			Maze[i][j].right = true;
		}
	}
	for (int i = 1; i < LENGTH - 1; i++) {
		for (int j = 1; j < LENGTH - 1; j++) {
			// Border Cells have fewer accessible walls
			Maze[1][j].top = false;
			Maze[LENGTH - 2][j].bot = false;
			Maze[i][1].left = false;
			Maze[i][LENGTH - 2].right = false;
		}
	}
}

void Clear()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void Draw(Room Maze[][LENGTH]) {
	for (int i = 0; i < LENGTH; i++) {
		std::cout << std::endl;
		for (int j = 0; j < LENGTH; j++)
			std::cout << " " << Maze[i][j].show;
	}
}

void Generator(Room Maze[][LENGTH]) {
	srand((unsigned)time(NULL));				        					// Pick random start cell
	int random = 0;
	int times = 0;
	int row = ((2 * rand()) + 1) % (LENGTH - 1);						// Generate a random odd number between 1 and LENGTH
	int col = ((2 * rand()) + 1) % (LENGTH - 1);						// Generate a random odd number between 1 and LENGTH
	int visitedCells = 1;
	int totalCells = ((LENGTH - 1) / 2) * ((LENGTH - 1) / 2);
	int percent = 0;
	std::stack<int> back_trackX, back_trackY; 						// Stack is used to trace the reverse path
	if (times == 0) {
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
			if ((random == 1) && (col > 1)) {
				if (Maze[col - 2][row].visited == false) {	// If not visited
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
			else if ((random == 2) && (col < LENGTH - 2)) {
				if (Maze[col + 2][row].visited == false) {	// If not visited
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
			else if ((random == 3) && (row > 1)) {
				if (Maze[col][row - 2].visited == false) {	// If not visited
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
			else if ((random == 4) && (row < LENGTH - 2)) {
				if (Maze[col][row + 2].visited == false) {	// If not visited
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

			percent = (visitedCells * 100 / totalCells * 100) / 100;		// Progress in percentage
			std::cout << std::endl << "	Generating a Random Maze... " << percent << "%" << std::endl;
		}
		else {
			row = back_trackX.top();
			back_trackX.pop();

			col = back_trackY.top();
			back_trackY.pop();
		}

		Clear();
		Draw(Maze);
	}

	Maze[LENGTH - 2][LENGTH - 2].show = 'E';
	system("cls");
	Clear();
	Draw(Maze);
}

