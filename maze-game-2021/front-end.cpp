/*! @file front-end.cpp
*   @brief A source file for the presentation layer.
*/

#include "front-end.h"
#include "back-end.h"
#include "logs.h"
#include "dialogue.h"

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
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (checkForInvalidHandle(handle))
	{
		showError("maze-game.cpp", "initializeTheGame -> checkForInvalidHandle", GetLastError(), GetLastErrorAsString(GetLastError()));
	}

	return handle;
}

/**
 * @brief Function for showing/hideing the cursor
 * @param shown bool show/hide
*/
void setCursor(bool shown)
{
	HANDLE consoleHandle = getOutputHandle();
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = shown;
	
	if (SetConsoleCursorInfo(consoleHandle, &info) == 0)
	{
		showError("front-end.cpp", "setCursor -> SetConsoleCursorInfo", GetLastError(), GetLastErrorAsString(GetLastError()));
	}
}

/**
 * @brief Check if the output that was returned from getOutputHandle() is INVALID_HANDLE_VALUE.
 * @param handle 
 * @return bool
*/
bool checkForInvalidHandle(HANDLE handle)
{
	return handle == INVALID_HANDLE_VALUE;
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
		showError("front-end.cpp", "setConsoleColorTo -> SetConsoleTextAttribute", GetLastError(), GetLastErrorAsString(GetLastError()));
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
		showError("front-end.cpp", "clearConsole -> GetConsoleScreenBufferInfo", GetLastError(), GetLastErrorAsString(GetLastError()));
	}

	if (FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	) == 0)
	{
		showError("front-end.cpp", "clearConsole -> FillConsoleOutputCharacterA", GetLastError(), GetLastErrorAsString(GetLastError()));
	}

	if (FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	) == 0)
	{
		showError("front-end.cpp", "clearConsole -> FillConsoleOutputAttribute", GetLastError(), GetLastErrorAsString(GetLastError()));
	}

	goToXY(topLeft.X, topLeft.Y);
}

/**
 * @brief Function for getting current coordiantes of Cursor
 * @return COORD The coordinates of the cursor
*/
COORD GetConsoleCursorPosition()
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(getOutputHandle(), &cbsi))
	{
		return cbsi.dwCursorPosition;
	}
	else
	{
		showError("front-end.cpp", "GetConsoleCursorPosition -> GetConsoleScreenBufferInfo", GetLastError(), GetLastErrorAsString(GetLastError()));
		COORD invalid = { 0, 0 };
		return invalid;
	}
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
		showError("front-end.cpp", "goToXY -> SetConsoleCursorPosition", GetLastError(), GetLastErrorAsString(GetLastError()));
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
	setConsoleColorTo(COLOR_MAIN);

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
			menuOptions[--selectedOption].opt(1, true);
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
	clearConsole();
	drawBoard();	
	printPlayerData();
	//Data role[6];
	//Data item[4];
	//GameRules();
	printMessage("");
	game(/*role, item*/);
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

		//Print the logo
		printSettingsLogo();

		//Print the boss art
		printBossOnMenu();
	}

	goToXY(0, 11);
	
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

		//Print logo
		printHowToPlayLogo();

		//Print the boss art
		printBossOnMenu();
	}

	goToXY(0, 16);

	std::cout << "    Movement:" << std::endl;
	std::cout << "      Primary:" << std::endl;
	std::cout << "         W - Go up" << std::endl;
	std::cout << "         A - Go left" << std::endl;
	std::cout << "         S - Go down" << std::endl;
	std::cout << "         D - Go right" << std::endl;
	std::cout << "      Secnodary:" << std::endl;
	std::cout << "         Arrow up - Go up" << std::endl;
	std::cout << "         Arrow left - Go left" << std::endl;
	std::cout << "         Arrow down - Go down" << std::endl;
	std::cout << "         Arrow right - Go right\n" << std::endl;
	
	std::cout << "    Dialogue:" << std::endl;
	std::cout << "      Space - Next dialogue\n" << std::endl;

	std::cout << "    Fighting:" << std::endl;
	std::cout << "      Bump into enemies to deal damage.\n" << std::endl;

	std::cout << "    Menu:" << std::endl;
	std::cout << "      Esc - Open menu" << std::endl;
	std::cout << "      Arrow up / down - Go up / down menu item" << std::endl;
	std::cout << "      Enter - Select menu item\n\n" << std::endl;

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
		
		//Print the logo
		printAboutUsLogo();

		//Print the boss art
		printBossOnMenu();
	}
	

	goToXY(0, 11);

	std::cout << "     Braven is a dungeon crawler rogue-like game, where you navigate \n     trough rooms and mazes, killing enemies while helping wizard.\n" << std::endl;
	std::cout << "     Team: " << std::endl;
	std::cout << "       Stoyan Ivanov - Scrum trainer" << std::endl;
	std::cout << "       Stas Uzunov - Back-end Developer" << std::endl;
	std::cout << "       Viktor Kirov - Front-end Developer" << std::endl;
	std::cout << "       Teodor Karchev - QA Engineer\n\n" << std::endl;

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
 * @brief Print the boss art that shows at the menu of the game
*/
void printBossOnMenu()
{
	std::vector<std::string> boss = 
	{
		"                       ||  ||",
		"                       ||  ||",
		"                       ||  ||",
		"               ========||  ||========",
		"                                     ",
		"               ========||  ||========",
		"                       ||  ||",
		"                       ||  ||",
		"                       ||  ||",
		"               ______________________",
		"               ||  ||  ||  ||  ||  ||",
		"               ______________________",
		"               ||  ||  ||  ||  ||  ||",
		"===============______________________===============",
		"||=============||  ||  ||  ||  ||  ||=============||",
		"||             ______________________             ||",
		"||             ||  ||  ||  ||  ||  ||             ||",
		"||       ======______________________======       ||",
		"||       ||====||  ||  ||  ||  ||  ||====||       ||",
		"||       ||    ______________________    ||       ||",
		"||       ||    ||  ||  ||  ||  ||  ||    ||       ||",
		"||       ||    ______________________    ||       ||"
	};

	for (size_t i = 0; i < boss.size(); i++)
	{
		goToXY(61, short(i));
		std::cout << boss[i] << std::endl;
	}
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

		//Print the boss art
		printBossOnMenu();
	}
	
	goToXY(0, 11);

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

void printRow(int firstCornerElement, int secondCornerElement, int thirdCornerElement, int fillElements, int secondfillElements = 32)
{
	std::cout << char(firstCornerElement);
	for (int i = 0; i < 8; i++)
	{
		std::cout << char(fillElements);
	}
	std::cout << char(secondCornerElement);
	for (int i = 0; i < 43; i++)
	{
		std::cout << char(secondfillElements);
	}

	std::cout << char(thirdCornerElement) << std::endl;
}
/**
 * @brief A function for drawing the UI of the game
*/
void drawBoard()
{
	for (int i = 1; i <= 30; i++)
	{
		if (i < 22 || i == 30)
		{
			switch (i)
			{
				case 1:
					printRow(UPPER_LEFT_CORNER, HORIZONTAL_DOWN_LINE, UPPER_RIGHT_CORNER, HORIZONTAL_LINE, HORIZONTAL_LINE);
					break;
				case 6: 
				case 11:
				case 16:
					printRow(VERTICAL_RIGHT_LINE, VERTICAL_LEFT_LINE, VERTICAL_LINE, HORIZONTAL_LINE, SPACE);
					break;
				case 21:
					printRow(VERTICAL_RIGHT_LINE, HORIZONTAL_UP_LINE, VERTICAL_LEFT_LINE, HORIZONTAL_LINE, HORIZONTAL_LINE);
					break;
				case 30:
					printRow(LOWER_LEFT_CORNER, HORIZONTAL_LINE, LOWER_RIGHT_CORNER, HORIZONTAL_LINE, HORIZONTAL_LINE);
					break;
				default:
					printRow(VERTICAL_LINE, VERTICAL_LINE, VERTICAL_LINE, SPACE, SPACE);
					break;
			}
		}
		else
		{
			printRow(VERTICAL_LINE, SPACE, VERTICAL_LINE, SPACE, SPACE);
		}
	}
}

/**
 * @brief Function for printing player information (Helath, Armour, etc) on the board
*/
void printPlayerData()
{
	struct PLAYER_DATA 
	{
		int health;
		int armour;
		int keys;
		int money;
	};

	PLAYER_DATA playerData = { 100, 100, 100, 100 };

	int counter = 0;
	for (int i = 0; i < 8;i++)
	{
		switch (i)
		{
			case 0:
				goToXY(2, 2);
				std::cout << "Health";
				break;
			case 1:
				goToXY(3, 3);
				std::cout << playerData.health;
				break;
			case 2:
				goToXY(2, 7);
				std::cout << "Armour";
				break;
			case 3:
				goToXY(3, 8);
				std::cout << playerData.armour;
				break;
			case 4:
				goToXY(3, 12);
				std::cout << "Keys";
				break;
			case 5:
				goToXY(3, 13);
				std::cout << playerData.keys;
				break;
			case 6:
				goToXY(2, 17);
				std::cout << "$Money";
				break;
			case 7:
				goToXY(3, 18);
				std::cout << playerData.money;
				break;
		}
	}
}

/**
 * @brief Function for showing message on the console;
 * @param msg The message to be shown
*/
void printMessage(std::string msg)
{
	int row = 1;
	int index = 0;

	goToXY(2, 22);
	
	for (size_t i = 0; i < msg.size(); i++)
	{
		if (msg[i] == '[')
		{
			msg.erase(i, 1);
			msg.insert(i, getBossName());
		}

		if (index == 51 || msg[i] == '\n')
		{
			goToXY(2, 22 + row);
			row++;
			index = 1;

			if (msg[i] == '\n')
			{
				continue;
			}
		}

		index++;


		std::cout << msg[i];
	}
}

/**
 * @brief Function for clearing message from the console;
 * @param msg The message to be cleared
*/
void clearMessage(std::string msg)
{
	int row = 1;
	int index = 0;

	goToXY(2, 22);

	for (size_t i = 0; i < msg.size(); i++)
	{
		if (msg[i] == '[')
		{
			msg.erase(i, 1);
			msg.insert(i, getBossName());
		}

		if (index == 51 || msg[i] == '\n')
		{
			goToXY(2, 22 + row);
			row++;
			index = 1;

			if (msg[i] == '\n')
			{
				continue;
			}
		}

		index++;


		std::cout << " ";
	}
}

/**
 * @brief Spawn a player in a room and allow the user to move the player. 
*/
void game(/*Data* role, Data* item*/)
{
	char input;
	bool playing = true;
	short rowPlayer = 2, colPlayer = 2, moves = 0;
	int mazeSize = 17;	

	Dialogue dialogueAtStart = 
	{
		{
			{
				"Wizard", "Hello brave adventurer!"
			},
			{
				"You", "What happened???"
			},
			{
				"Wizard", "That is not important! The important part is that you are here, welcome to the wilderness of the Djamal Sehdi Albadas Pethi III!!!"
			},
			{
				"You", "Wait, isn't that a little long name?"
			},
			{
				"Wizard", "Yes it is, so how we should call him?", askForBossName
			},
			{
				"Wizard", "So we would call him [, I like it!"
			},
			{
				"Wizard", "Your task is to defeat [ and save the middle earth!"
			},
			{
				"Yes", "Oh so we are in the Lord of the ring!"
			},
			{
				"Wizard", "No, this is the real life! So where was I, ah yes so you need to save the middle earth! To do this you need to level up your gear. Now take this woden sword!"
			},
			{
				"Wizard", "Now try to move with WASD."
			},
			{
				"You", "What is WASD?"
			},
			{
				"Wizard", "You will figure it out!"
			}
		}
	};


	//Generate normal room
	//drawBoard(role, item);
	
	//Generate maze and display it
	/*
	Room** Maze = generator(mazeSize);
	drawRoom(Maze, mazeSize);
	*/
	
	//Set-up backend
	char** board = NULL;
	int tempE = 0;
	int level = 0;
	int* tempX = new int[4];
	int* tempY = new int[4];
	int counterDead = 0;
	int mapX = 0;
	int mapY = 0;

	Data** role = new Data * [6];
	for (int i = 0; i < 6; i++)
	{
		role[i] = new Data[100];
	}

	Data* item = new Data[3];

	GameRules(role, item);

	//Draw room
	drawRoom(role, item, board, &tempE, &level, tempX, tempY, &counterDead, &mapY, &mapX);

	//Draw player
	goToXY(10 + rowPlayer, 1 + colPlayer);
	std::cout << "x";
	
	//Start the dialgue
	startDialogue(dialogueAtStart);

	while (playing) 
	{
		switch ((input = _getch()))
		{
			case ARROW_LEFT:
			case 'a':
			case 'A':
				if (isMovePosible(rowPlayer - 1, colPlayer, role, item, playing, &tempE, &level, tempX, tempY, &counterDead, &mapY, &mapX))
				{
					goToXY(10 + rowPlayer, 1 + colPlayer);
					std::cout << " ";

					rowPlayer--;

					goToXY(10 + rowPlayer, 1 + colPlayer);
					std::cout << "x";
				}

				break;
			case ARROW_RIGHT:
			case 'd':
			case 'D':
				if (isMovePosible(rowPlayer + 1, colPlayer, role, item, playing, &tempE, &level, tempX, tempY, &counterDead, &mapY, &mapX))
				{
					goToXY(10 + rowPlayer, 1 + colPlayer);
					std::cout << " ";

					rowPlayer++;

					goToXY(10 + rowPlayer, 1 + colPlayer);
					std::cout << "x";
				}

				break;
			case ARROW_UP:
			case 'w':
			case 'W':
				if (isMovePosible(rowPlayer, colPlayer - 1, role, item, playing, &tempE, &level, tempX, tempY, &counterDead, &mapY, &mapX))
				{
					goToXY(10 + rowPlayer, 1 + colPlayer);
					std::cout << " ";

					colPlayer--;

					goToXY(10 + rowPlayer, 1 + colPlayer);
					std::cout << "x";
				}

				break;
			case ARROW_DOWN:
			case 's':
			case 'S':
				if (isMovePosible(rowPlayer, colPlayer + 1, role, item, playing, &tempE, &level, tempX, tempY, &counterDead, &mapY, &mapX))
				{
					goToXY(10 + rowPlayer, 1 + colPlayer);
					std::cout << " ";

					colPlayer++;
					
					goToXY(10 + rowPlayer, 1 + colPlayer);
					std::cout << "x";
				}

				break;
			// if escape key was pressed end program loop
			case ESCAPE_BUTTON: 
				playing = false;
				break;
			// no handled cases where pressed 
			default:  
				break;
		}
	}
} 

/**
 * @brief A function a Maze on the screen.
 * @param Maze A pointer to dynamic two-dimensional array of Room
 * @param length The size of the maze
*/

void drawRoom(Data** role, Data* item, char** board, int* tempE, int* level, int* tempX, int* tempY, int* counterDead, int* mapY, int* mapX)
{
	board = room(role, item, tempE, level, tempX, tempY, counterDead, mapY, mapX);

	goToXY(10, 1);
	for (int i = 0; i < ROW_ROOM; i++)
	{
		for (int j = 0; j < COL_ROOM; j++) 
		{
			goToXY(10 + i, 1 + j);
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}

void drawMaze(Room** Maze, int length)
{
	
	for (int i = 0; i < length; i++)
	{
		
		for (int j = 0; j < length; j++)
		{
			std::cout << Maze[i][j].show;
		}
		if (i == 18)
		{
			return;
		}
	}
}


// normal room
/*
void drawBoard(Data* role, Data* item) {
	board = room(role, item);
    for (int i = 0; i < rowRoom; i++) {
        for (int j = 0; j < colRoom; j++) {
                gotoxy(i, j);
                cout << board[i][j];
        }
        cout << endl;
    }
}
*/