/*! @file front-end.cpp
*   @brief A source file for the presentation layer.
*/

#include "front-end.h"
#include "back-end.h"
#include "logs.h"

/**
 * @brief A struct for every option of the menu.
*/
struct MenuOptions
{
	std::string name; /*!< The name of the option*/
	Operation opt; /*!< A pointer to function that will be called whenever this option is selected */
};

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
 * @brief A function that get the output handle.
 * @return HANDLE
*/
HANDLE getOutputHandle()
{
	return GetStdHandle(STD_OUTPUT_HANDLE);
}

/**
 * @brief Check if the output that was returned from getOutputHandle() is INVALID_HANDLE_VALUE.
 * @return bool
*/
bool checkForInvalidHandle()
{
	return getOutputHandle() == INVALID_HANDLE_VALUE;
}

/**
 * @brief Function that sets the console foreground color.
 * @param color The code of the color.
*/
void setConsoleColorTo(int color)
{
	HANDLE STD_OUTPUT = getOutputHandle();
	if (SetConsoleTextAttribute(STD_OUTPUT, color) == 0)
	{
		showError("front-end.cpp", "setConsoleColorTo -> SetConsoleTextAttribute", GetLastError(), "Failed to set console text attributes");
	}
}

/**
 * @brief A function that displays error and logs it to the browser.
 * @param fileName The name of the file.
 * @param functionName The name of the function.
 * @param errorCode The error code.
 * @param msg The message shown by the error.
*/
void showError(std::string fileName, std::string functionName, DWORD errorCode, std::string msg)
{
	Logger logger;
	logger.err("File: " + fileName + ", Function: " + functionName + ", Error code: " + std::to_string(errorCode) + ", Message: " + msg);

	clearConsole();
	std::cout << msg + "\nThe program is going to close itself!\nSee the log file for more information";
	
	exit(1);
}

/**
 * @brief A function that clears the console.
*/
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

/**
 * @brief A function that puts the cursor to a specific position.
 * @param x A x coordinate.
 * @param y A y coordinate.
*/
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

/**
 * @brief A function that print the option from the vector, passed as parameter, and ask the user to choose a option.
 * @param menuOptions A vector that holds all the options.
 * @param selectedOption A int variable that represent the selected function.
 * @param opt A pointer to function.
*/
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

/**
 * @brief A function to start the game.
 * @param selectedOption The number of selected option.
 * @param printLogo Should the logo be printed? 
*/
void startGame(int selectedOption, bool printLogo)
{
	//clearConsole();
	//drawBoard();	
	move();
	//exit(0);
}

/**
 * @brief A function to load the game.
 * @param selectedOption The number of selected option.
 * @param printLogo Should the logo be printed?
*/
void loadGame(int selectedOption, bool printLogo)
{
	std::cout << "Load old game";
}

/**
 * @brief function that prints the settings logo.
*/
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

/**
 * @brief function that print the settings.
 * @param selectedOption The number of selected option.
 * @param printLogo Should the logo be printed?
*/
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
	
	//Initialise a vector that holds all of the options for this menu
	const std::vector<MenuOptions> menuOptions
	{
		{
			"Setting 1", loadGame
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

/**
 * @brief function that prints the how to play logo.
*/
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

/**
 * @brief Function that print the How to play section.
 * @param selectedOption The number of selected option.
 * @param printLogo Should the logo be printed?
*/
void printHowToPlay(int selectedOption, bool printLogo)
{
	if (printLogo)
	{
		//Clear the screen
		clearConsole();

		printHowToPlayLogo();
	}
	else
	{
		//Skip the logo printing
		goToXY(0, 16);
	}

	std::cout << "    Lorem ipsum" << std::endl << std::endl;

	//Initialise a vector that holds all of the options for this menu
	const std::vector<MenuOptions> menuOptions
	{
		{
			"Back to main menu", printMainMenu
		}
	};

	printOptions(menuOptions, selectedOption, printHowToPlay);
}

/**
 * @brief Function that print About Us logo.
*/
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

/**
 * @brief Function that print the About Us section.
 * @param selectedOption The number of selected option.
 * @param printLogo Should the logo be printed?
*/
void printAboutUs(int selectedOption, bool printLogo)
{
	if (printLogo)
	{
		//Clear the screen
		clearConsole();
		
		printAboutUsLogo();
	}
	else
	{
		//Skip the logo printing
		goToXY(0, 11);
	}

	std::cout << "    Lorem ipsum" << std::endl << std::endl;

	//Initialise a vector that holds all of the options for this menu
	const std::vector<MenuOptions> menuOptions
	{
		{
			"Back to main menu", printMainMenu
		}
	};

	printOptions(menuOptions, selectedOption, printAboutUs);
}

/**
 * @brief Function that prints the main logo.
*/
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

/**
 * @brief Function that exit the app.
 * @param selectedOption The number of selected option.
 * @param printLogo Should the logo be printed?
*/
void exitApp(int selectedOption, bool printLogo)
{
	exit(0);
}

/**
 * @brief Function that print the main menu.
 * @param selectedOption The number of selected option.
 * @param printLogo Should the logo be printed?
*/
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

	//Initialise a vector that holds all of the options for this menu
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
			"Exit", exitApp
		}
	};

	printOptions(menuOptions, selectedOption, printMainMenu);
}

//In progress
/**
 * @brief A function for drawing the UI of the game
*/
void drawBoard()
{
	//First row
	std::cout << char(218);
	for (int i = 0; i < 8; i++)
	{
		std::cout << char(196);
	}
	std::cout << char(194);
	for (int i = 0; i < 43; i++)
	{
		std::cout << char(196);
	}
	std::cout << char(191) << std::endl;
	
	//End First row
	//Second, Fifth, Seventh, Tenth, Twelfth, fifteenth, Seventeenth, Twentieth Row
	for (int i = 0; i < 19; i++)
	{
		std::cout << char(179);
		for (int i = 0; i < 8; i++)
		{
			std::cout << ' ';
		}
		std::cout << char(179);
		for (int i = 0; i < 43; i++)
		{
			std::cout << ' ';
		}
		std::cout << char(179) << std::endl;

	}
}

/**
 * @brief Spawn a player in a room and allow the user to move the player. 
*/
void move()
{
	char input;
	bool playing = false;
	short rowPlayer = 1, colPlayer = 1, moves = 0;

	Room** Maze = new Room* [LENGTH];

	for (int i = 0; i < LENGTH; ++i)
	{
		Maze[i] = new Room[LENGTH];
	}

	clearConsole();
	set(Maze);
	generator(Maze);
	drawRoom(Maze);
	
	goToXY(rowPlayer, colPlayer);
	std::cout << "x";
	
	while (!playing) 
	{
		switch ((input = _getch()))
		{
			case ARROW_LEFT:
			case 'a':
			case 'A':
				if (isMovePossible(Maze, rowPlayer - 1, colPlayer))
				{
					goToXY(rowPlayer, colPlayer);
					std::cout << " ";

					rowPlayer--;

					goToXY(rowPlayer, colPlayer);
					std::cout << "x";
				}

				break;
			case ARROW_RIGHT:
			case 'd':
			case 'D':
				if (isMovePossible(Maze, rowPlayer + 1, colPlayer))
				{
					goToXY(rowPlayer, colPlayer);
					std::cout << " ";

					rowPlayer++;

					goToXY(rowPlayer, colPlayer);
					std::cout << "x";
				}

				break;
			case ARROW_UP:
			case 'w':
			case 'W':
				if (isMovePossible(Maze, rowPlayer, colPlayer - 1))
				{
					goToXY(rowPlayer, colPlayer);
					std::cout << " ";

					colPlayer--;

					goToXY(rowPlayer, colPlayer);
					std::cout << "x";
				}

				break;
			case ARROW_DOWN:
			case 's':
			case 'S':
				if (isMovePossible(Maze, rowPlayer, colPlayer + 1))
				{
					goToXY(rowPlayer, colPlayer);
					std::cout << " ";

					colPlayer++;
					
					goToXY(rowPlayer, colPlayer);
					std::cout << "x";
				}

				break;
				// if any arrow key was pressed go to these cordinates
			case ESCAPE_BUTTON: // if escape key was pressed end program loop
				playing = false;
				break;
			default:  // no handled cases where pressed 
				break;
		}
	}
} 

/**
 * @brief A function that print a room on the screen.
 * @param board A pointer to dynamic two-dimensional array of strings.
 * @param rowRoom The number of rows.
 * @param colRoom The number of columns.
*/
void drawRoom(Room** Maze)
{
	for (int i = 0; i < LENGTH; i++) 
	{
		for (int j = 0; j < LENGTH; j++)
		{
			std::cout << Maze[i][j].show;
		}
		std::cout << std::endl;
	}
}
