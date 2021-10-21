#include "front-end.h"
#include "back-end.h"
#include "logs.h"

void initializeTheGame()
{
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