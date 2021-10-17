#include "front-end.h"

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

void printOptions(std::vector<MenuOptions> menuOptions, int selectedOption, Operation opt)
{
	//Output the names of the functions 
	for (unsigned int i = 0; i < menuOptions.size(); i++)
	{
		std::cout << " ";
		(i + 1 == selectedOption) ? std::cout << "-> " : std::cout << "   ";
		std::cout << menuOptions[i].name << std::endl << std::endl;
	}

	//Get the input from user
	char input = _getch();

	//Check the input
	if (input == 'w' || input == 'W' || input == ARROW_UP)
	{
		//Go one option up
		selectedOption == 1 ? opt(menuOptions.size()) : opt(selectedOption - 1);
	}
	else if (input == 's' || input == 'S' || input == ARROW_DOWN)
	{
		//Go one option down
		selectedOption == menuOptions.size() ? opt(1) : opt(selectedOption + 1);
	}
	else if (input == KEY_ENTER)
	{
		//Call the corresponding function
		menuOptions[selectedOption - 1].opt(1);
	}
	else
	{
		opt(selectedOption);
	}
}

void startGame(int selectedOption)
{
	std::cout << "New game goes here";
}

void loadGame(int selectedOption)
{
	std::cout << "Load old game";
}

void printSettingsLogo()
{
	std::cout << "    ===========================================================" << std::endl;
	std::cout << "       _____ ______ _______ _______ _____ _   _  _____  _____" << std::endl;
	std::cout << "      / ____| ____ |__   __|__   __|_   _| \\ | |/ ____|/ ____|" << std::endl;
	std::cout << "     | (___ | |__     | |     | |    | | |  \\| | |  __| (___" << std::endl;
	std::cout << R"(      \___ \|  __|    | |     | |    | | | . ` | | |_ |\___ \)" << std::endl;
	std::cout << "      ____) | |____   | |     | |   _| |_| |\\  | |__| |____) |" << std::endl;
	std::cout << "     |_____/|______|  |_|     |_|  |_____|_| \\_|\\_____|_____/" << std::endl << std::endl;
	std::cout << "    ===========================================================" << std::endl << std::endl << std::endl;
}

void printSettings(int selectedOption)
{
	//Clear the console
	system("CLS");

	printSettingsLogo();
	
	//Intialise a vector that holds all of the options for this menu
	const std::vector<MenuOptions> menuOptions
	{
		{
			"Setting 1", startGame
		},
		{
			"Setting 2", loadGame
		},
		{
			"Back to menu", printMainMenu
		}
	};

	printOptions(menuOptions, selectedOption, printSettings);
}

void printHowToPlayLogo()
{
	std::cout << "    ==================================================" << std::endl;
	std::cout << "	 _    _  ______          __  _______ ____" << std::endl;
	std::cout << "	| |  | |/ __ \\ \\        / / |__   __/ __ \\" << std::endl;
	std::cout << "	| |__| | |  | \\ \\  /\\  / /     | | | |  | |" << std::endl;
	std::cout << "	|  __  | |  | |\\ \\/  \\/ /      | | | |  | |" << std::endl;
	std::cout << "	| |  | | |__| | \\  /\\  /       | | | |__| |" << std::endl;
	std::cout << "	|_|  |_|\\____/   \\/  \\/   _    |_|  \\____/ " << std::endl;
	std::cout << "	     |  __ \\| |        /\\\\ \\   / /" << std::endl;
	std::cout << "	     | |__) | |       /  \\\\ \\_/ /" << std::endl;
	std::cout << "	     |  ___/| |      / /\\ \\\\   /" << std::endl;
	std::cout << "	     | |    | |____ / ____ \\| |" << std::endl;
	std::cout << "	     |_|    |______/_/    \\_\\_|" << std::endl << std::endl;
	std::cout << "    ==================================================" << std::endl << std::endl << std::endl;
}

void printHowToPlay(int selectedOption)
{
	system("CLS");

	printHowToPlayLogo();

	std::cout << "    Lorem ipsum" << std::endl << std::endl;

	//Intialise a vector that holds all of the options for this menu
	const std::vector<MenuOptions> menuOptions
	{
		{
			"Back to main menu", printMainMenu
		}
	};

	printOptions(menuOptions, selectedOption, printHowToPlay);
}

void printAboutUsLogo()
{
	std::cout << "    ==========================================" << std::endl;
	std::cout << "                ____   ____  _    _ _______" << std::endl;
	std::cout << "          /\\   |  _ \\ / __ \\| |  | |__   __|" << std::endl;
	std::cout << "         /  \\  | |_) | |  | | |  | |  | |" << std::endl;
	std::cout << "        / /\\ \\ |  _ <| |  | | |  | |  | |   " << std::endl;
	std::cout << "       / ____ \\| |_) | |__| | |__| |  | |" << std::endl;
	std::cout << "      /_/    \\_\\____/ \\____/ \\____/   |_|" << std::endl << std::endl;
	std::cout << "    ==========================================" << std::endl << std::endl << std::endl;
}

void printAboutUs(int selectedOption)
{
	system("CLS");

	printAboutUsLogo();

	std::cout << "    Lorem ipsum" << std::endl << std::endl;

	//Intialise a vector that holds all of the options for this menu
	const std::vector<MenuOptions> menuOptions
	{
		{
			"Back to main menu", printMainMenu
		}
	};

	printOptions(menuOptions, selectedOption, printAboutUs);
}

void printLogo()
{
	std::cout << R"(    ============================================)" << std::endl;
	std::cout << R"(      ____  _____       __      ________ _   _)" << std::endl;
	std::cout << R"(     |  _ \|  __ \     /\ \    / /  ____| \ | |)" << std::endl;
	std::cout << R"(     | |_) | |__) |   /  \ \  / /| |__  |  \| |)" << std::endl;
	std::cout << R"(     |  _ <|  _  /   / /\ \ \/ / |  __| | . ` |)" << std::endl;
	std::cout << R"(     | |_) | | \ \  / ____ \  /  | |____| |\  |)" << std::endl;
	std::cout << R"(     |____/|_|  \_\/_/    \_\/   |______|_| \_|)" << std::endl << std::endl;
	std::cout << R"(    ============================================)" << std::endl << std::endl << std::endl;
}

void printMainMenu(int selectedOption)
{
	//Clear the screen
	system("cls");

	//Set the console output to the main color (White)
	setConsoleColorTo(COLOR_MAIN);

	//Intialise a vector that holds all of the options for this menu
	const std::vector<MenuOptions> menuOptions
	{
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
		}
	};

	//TODO: Find a way to print only once
	printLogo();

	printOptions(menuOptions, selectedOption, printMainMenu);
}