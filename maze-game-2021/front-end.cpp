#include "front-end.h"

HANDLE getOutputHandle()
{
	return GetStdHandle(STD_OUTPUT_HANDLE);
}

bool checkForInvalidHandle()
{
	return getOutputHandle() == INVALID_HANDLE_VALUE;
}

void SetConsoleColorTo(int color)
{
	HANDLE STD_OUTPUT = getOutputHandle();
	SetConsoleTextAttribute(STD_OUTPUT, color);
}

void printMenu(int selectedOption)
{
	system("cls");

	SetConsoleColorTo(COLOR_MAIN);

	const std::string menuOptions[4] = {
		"Play the game",
		"How to play",
		"About us",
		"Exit"
	};
	
	std::cout << std::endl << "Main Menu" << std::endl << std::endl;

	for (int i = 0; i < 4; i++)
	{
		std::cout << " ";
		(i + 1 == selectedOption) ? std::cout << "-> " : std::cout << "   ";
		std::cout << menuOptions[i] << std::endl << std::endl;
	}

	char input = _getch();

	if (input == 'w' || input == 'W' || input == ARROW_UP)
	{
		selectedOption == 1 ? printMenu(4) : printMenu(selectedOption - 1);
	}
	else if (input == 's' || input == 'S' || input == ARROW_DOWN)
	{
		selectedOption == 4 ? printMenu(1) : printMenu(selectedOption + 1);
	}
	else
	{
		printMenu(selectedOption);
	}
}