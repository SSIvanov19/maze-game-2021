/*! @file maze-game-2021.cpp
*   @brief The main source file of the program.
*/

#include "front-end.h"
#include "back-end.h"
#include "logs.h"
#include "Bulgarify.h"

/**
 * @brief Function that initializes the game.
*/
void initializeTheGame()
{

	system("chcp 437");

	Logger logger;
	logger.log("The game is initializeing");

	setCursor(false);

	//Set the console output to the main color (White)
	setConsoleColorTo(COLOR_MAIN);
}

//Wild Bulgarian starts here
целочислен_тип главен()
{
	булев_тип игратаВърви е вярно;
	инцилизирайИгра();

	докато (игратаВърви е_равно_на вярно)
	{
		изпечатайГлавноМеню(1, вярно);
	}
}

/*
int main()
{
	bool running = true;
	initializeTheGame();

	while (running)
	{
		printMainMenu(1, true);
	}
}
*/