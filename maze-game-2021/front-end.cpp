#include "front-end.h"
#include "back-end.h"
#include "logs.h"

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
	if (SetConsoleTextAttribute(STD_OUTPUT, color) == 0)
	{
		showError("front-end.cpp", "setConsoleColorTo -> SetConsoleTextAttribute", GetLastError(), "Failed to set console text attributes");
	}
}

void showError(std::string fileName, std::string fucntionName, DWORD errorCode, std::string msg)
{
	Logger logger;
	logger.err("File: " + fileName + ", Function: " + fucntionName + ", Error code: " + std::to_string(errorCode) + ", Message: " + msg);

	clearConsole();
	std::cout << msg + "\nThe program is going to close itself!\nSee the log file for more information";
	
	exit(1);
}

void clearConsole()
{
	COORD topLeft = { 0, 0 };
	HANDLE console = getOutputHandle();
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	if (GetConsoleScreenBufferInfo(console, &screen) == 0)
	{
		showError("front-end.cpp", "clearConsole -> GetConsoleScreenBufferInfo", GetLastError(), "Failed to get console screen buffer info");
	}

	if (FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	) == 0)
	{
		showError("front-end.cpp", "clearConsole -> FillConsoleOutputCharacterA", GetLastError(), "Failed to writes a character to the console screen buffer");
	}

	if (FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	) == 0)
	{
		showError("front-end.cpp", "clearConsole -> FillConsoleOutputAttribute", GetLastError(), "Failed to set the character attributes");
	}

	goToXY(topLeft.X, topLeft.Y);
}

void goToXY(short x, short y)
{
	HANDLE STD_OUTPUT = getOutputHandle();
	COORD cords;
	cords.X = x;
	cords.Y = y;

	if (SetConsoleCursorPosition(STD_OUTPUT, cords) == 0)
	{
		showError("front-end.cpp", "goToXY -> SetConsoleCursorPosition", GetLastError(), "Can't set cursor position");
	}
}

void printOptions(std::vector<MenuOptions> menuOptions, int selectedOption, Operation opt)
{
	//Output the names of the functions 
	for (size_t i = 0; i < menuOptions.size(); i++)
	{
		std::cout << " ";
		(i + 1 == selectedOption) ? std::cout << "-> " : std::cout << "   ";
		std::cout << menuOptions[i].name << std::endl << std::endl;
	}

	//Get the input from user
	char input = _getch();

	//Check the input
	switch (input)
	{
		case 'w':
		case 'W':
		case ARROW_UP:
			selectedOption == 1 ? opt(int(menuOptions.size()), false) : opt(selectedOption - 1, false);
			break;
		case 's':
		case 'S':
		case ARROW_DOWN:
			selectedOption == menuOptions.size() ? opt(1, false) : opt(selectedOption + 1, false);
			break;
		case KEY_ENTER:
			menuOptions[selectedOption - 1].opt(1, true);
			break;
		default:
			opt(selectedOption, false);
			break;
	}
}

void startGame(int selectedOption, bool printLogo)
{
	std::cout << "New game goes here";
}

void loadGame(int selectedOption, bool printLogo)
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

void printSettings(int selectedOption, bool printLogo)
{

	if (printLogo)
	{
		//Clear the screen
		clearConsole();

		//TODO: Find a way to print only once
		printSettingsLogo();
	}
	else
	{
		//Skip the logo printing
		goToXY(0, 11);
	}
	
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

void printHowToPlay(int selectedOption, bool printLogo)
{
	if (printLogo)
	{
		//Clear the screen
		clearConsole();

		//TODO: Find a way to print only once
		printHowToPlayLogo();
	}
	else
	{
		//Skip the logo printing
		goToXY(0, 16);
	}

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

void printAboutUs(int selectedOption, bool printLogo)
{
	if (printLogo)
	{
		//Clear the screen
		clearConsole();

		//TODO: Find a way to print only once
		printAboutUsLogo();
	}
	else
	{
		//Skip the logo printing
		goToXY(0, 11);
	}

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

void printMainLogo()
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

void exitApp(int selectedOption, bool printLogo)
{
	exit(0);
}

void printMainMenu(int selectedOption, bool printLogo)
{
	if (printLogo)
	{
		//Clear the screen
		clearConsole();
		
		//Print the logo
		printMainLogo();
	}
	else
	{
		//Skip the logo printing
		goToXY(0, 11);
	}

	//Intialise a vector that holds all of the options for this menu
	const std::vector<MenuOptions> menuOptions
	{
		{
			"New game", move
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
			"Exit", exitApp
		}
	};

	printOptions(menuOptions, selectedOption, printMainMenu);
}

void move(int selectedOption, bool printLogo)
{
	short rowPlayer = 1, colPlayer = 1, moves = 0;
	char input;
	bool running = true;
	short rowRoom = 22, colRoom = 11; // size of the rooms
	std::string **board = generateRoom(rowRoom, colRoom);
	
	clearConsole();

	drawRoom(board, rowRoom, colRoom);

	//programs main loop
	while (running)
	{
		goToXY(rowPlayer, colPlayer);
		std::cout << "x";

		switch ((input = _getch()))
		{
			case ARROW_LEFT:
			case 'a':
			case 'A':
				rowPlayer--;

				if (!isMovePossible(board, rowPlayer, colPlayer))
				{
					rowPlayer++;
				}

				goToXY(rowPlayer + 1, colPlayer);
				std::cout << " ";

				goToXY(rowPlayer, colPlayer);
				std::cout << "x";

				break;
			case ARROW_RIGHT:
			case 'd':
			case 'D':
				rowPlayer++;

				if (!isMovePossible(board, rowPlayer, colPlayer))
				{
					rowPlayer--;
				}

				goToXY(rowPlayer - 1, colPlayer);
				std::cout << " ";

				goToXY(rowPlayer, colPlayer);
				std::cout << "x";

				break;
			case ARROW_UP:
			case 'w':
			case 'W':
				colPlayer--;

				if (!isMovePossible(board, rowPlayer, colPlayer))
				{
					colPlayer++;
				}

				goToXY(rowPlayer, colPlayer + 1);
				std::cout << " ";

				goToXY(rowPlayer, colPlayer);
				std::cout << "x";

				break;
			case ARROW_DOWN:
			case 's':
			case 'S':
				colPlayer++;

				if (!isMovePossible(board, rowPlayer, colPlayer))
				{
					colPlayer--;
				}

				goToXY(rowPlayer, colPlayer - 1);
				std::cout << " ";

				goToXY(rowPlayer, colPlayer);
				std::cout << "x";

				break;
			// if any arrow key was pressed go to these cordinates
			case ESCAPE_BUTTON: // if escape key was pressed end program loop
				//cout << " escape key pressed.\n";
				running = false;
				break;
			default:  // no handled cases where pressed 
				//cout << "dont press other buttons.\n";
				break;
		}
	}
} 

void drawRoom(std::string** board, short rowRoom, short colRoom)
{
	for (int i = 0; i < rowRoom; i++)
	{
		for (int j = 0; j < colRoom; j++)
		{
			if (board[i][j] == "#")
			{
				goToXY(i, j);
				std::cout << "#";
			}
		}
		std::cout << std::endl;
	}
}
