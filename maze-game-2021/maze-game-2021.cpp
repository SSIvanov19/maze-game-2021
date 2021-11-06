/*! @file maze-game-2021.cpp
*   @brief The main source file of the program.
*/

#include "front-end.h"
#include "back-end.h"
#include "logs.h"

/**
 * @brief Function that initializes the game.
*/
void initializeTheGame()
{
	system("chcp 437");

	Logger logger;
	logger.log("The game is initializeing");

	//Set the console output to the main color (White)
	setConsoleColorTo(COLOR_MAIN);
}

int main()
{
	bool runing = true;
	initializeTheGame();

	while (runing)
	{
		printMainMenu(1, true);
	}
}