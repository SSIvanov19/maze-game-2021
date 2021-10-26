/*! @file back-end.cpp
*   @brief A source file for the logic layer.
*/


#include "back-end.h"

/**
 * @brief A struct for room.
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
	srand((unsigned)time(NULL)); 
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

	// Set S as the start cell
	Maze[col][row].show = 'S';
	// Set start cell as visited;
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
bool isMovePossible(Room **board, short row, short col) 
{
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
