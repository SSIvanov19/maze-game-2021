#include "front-end.h"

typedef void (*Operation);

struct MenuOptions
{
	std::string name;
	Operation opt;
};

HANDLE getOutputHandle()
{
	return GetStdHandle(STD_OUTPUT_HANDLE);
}

bool checkForInvalidHandle()
{
	return getOutputHandle() == INVALID_HANDLE_VALUE;
}

void setConsoleColorTo(int color)
{
	HANDLE STD_OUTPUT = getOutputHandle();
	SetConsoleTextAttribute(STD_OUTPUT, color);
}

void startGame()
{
	std::cout << "New game goes here";
}

void loadGame()
{
	std::cout << "Load old game";
}

void printSettings()
{
	std::cout << "Settings";
}

void printHowToPlay()
{
	std::cout << "How to play";
}

void printAboutUs()
{
	std::cout << "About Us";
}

void printMenu(int selectedOption)
{
	//Clear the screen
	system("cls");

	//Set the console output to the main color (White)
	setConsoleColorTo(COLOR_MAIN);

	int size = 6;
	const MenuOptions menuOptions[6] = {
		{
			"New game", startGame
		},
		{
			"Resume game", loadGame
		},
		{
			"Settings", printSettings
		},
		{
			"How to play", printHowToPlay
		},
		{
			"About us", printAboutUs
		},
		{
			"Exit", exit
		},
	};
	
	std::cout << std::endl << "Main Menu" << std::endl << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << " ";
		(i + 1 == selectedOption) ? std::cout << "-> " : std::cout << "   ";
		std::cout << menuOptions[i].name << std::endl << std::endl;
	}

	char input = _getch();

	if (input == 'w' || input == 'W' || input == ARROW_UP)
	{
		selectedOption == 1 ? printMenu(size) : printMenu(selectedOption - 1);
	}
	else if (input == 's' || input == 'S' || input == ARROW_DOWN)
	{
		selectedOption == size ? printMenu(1) : printMenu(selectedOption + 1);
	}
	else if (input == KEY_ENTER)
	{
		menuOptions[selectedOption - 1].opt;
	}
	else
	{
		printMenu(selectedOption);
	}
}