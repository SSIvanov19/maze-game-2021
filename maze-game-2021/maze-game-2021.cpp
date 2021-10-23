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

	if (checkForInvalidHandle())
	{
		showError("maze-game.cpp", "initializeTheGame -> checkForInvalidHandle", GetLastError(), "Failed to get STD_OUTPUT_HANDLE!");
	}

	//Set the console output to the main color (White)
	setConsoleColorTo(COLOR_MAIN);
}

int main()
{
	initializeTheGame();

	while (true)
	{
		printMainMenu(1, true);
	}
}