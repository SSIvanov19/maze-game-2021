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
 * @brief A function that get the output handle.
 * @return HANDLE
*/
HANDLE getOutputHandle()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (checkForInvalidHandle(handle))
	{
		showError(
			"maze-game.cpp",
			"initializeTheGame -> checkForInvalidHandle", 
			GetLastError(),
			GetLastErrorAsString(GetLastError())
		);
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
		showError(
			"front-end.cpp",
			"setCursor -> SetConsoleCursorInfo",
			GetLastError(),
			GetLastErrorAsString(GetLastError())
		);
	}
}

/**
 * @brief Check if the output that was returned from getOutputHandle() is INVALID_HANDLE_VALUE.
 * @param handle The handle given from getOutputHandle()
 * @return bool Is the handle invalid
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
		showError(
			"front-end.cpp",
			"setConsoleColorTo -> SetConsoleTextAttribute",
			GetLastError(),
			GetLastErrorAsString(GetLastError())
		);
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
		showError(
			"front-end.cpp",
			"clearConsole -> GetConsoleScreenBufferInfo",
			GetLastError(),
			GetLastErrorAsString(GetLastError())
		);
	}

	if (FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	) == 0)
	{
		showError(
			"front-end.cpp",
			"clearConsole -> FillConsoleOutputCharacterA",
			GetLastError(),
			GetLastErrorAsString(GetLastError())
		);
	}

	if (FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	) == 0)
	{
		showError(
			"front-end.cpp",
			"clearConsole -> FillConsoleOutputAttribute", 
			GetLastError(), 
			GetLastErrorAsString(GetLastError())
		);
	}

	goToXY(topLeft.X, topLeft.Y);
}

/**
 * @brief Function for getting current coordiantes of the Cursor on the console
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
		showError(
			"front-end.cpp",
			"GetConsoleCursorPosition -> GetConsoleScreenBufferInfo", 
			GetLastError(),
			GetLastErrorAsString(GetLastError())
		);

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
		showError(
			"front-end.cpp",
			"goToXY -> SetConsoleCursorPosition", 
			GetLastError(), 
			GetLastErrorAsString(GetLastError())
		);
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
		case int(Buttons::ARROW_UP):
			selectedOption == 1 ? opt(int(menuOptions.size()), false) : opt(selectedOption - 1, false);
			break;
		case 's':
		case 'S':
		case int(Buttons::ARROW_DOWN):
			selectedOption == menuOptions.size() ? opt(1, false) : opt(selectedOption + 1, false);
			break;
		case int(Buttons::KEY_ENTER):
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
	printMessage("");
	game();
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

/**
 * @brief Function for printing one row from the game UI (Game Board)
 * @param firstCornerElement The element in left
 * @param secondCornerElement The element in the middle
 * @param thirdCornerElement The element in right
 * @param fillElements The element for first fill
 * @param secondfillElements The element for second fill
*/
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
					printRow(int(Art::UPPER_LEFT_CORNER), int(Art::HORIZONTAL_DOWN_LINE), int(Art::UPPER_RIGHT_CORNER), int(Art::HORIZONTAL_LINE), int(Art::HORIZONTAL_LINE));
					break;
				case 6: 
				case 11:
				case 16:
					printRow(int(Art::VERTICAL_RIGHT_LINE), int(Art::VERTICAL_LEFT_LINE), int(Art::VERTICAL_LINE), int(Art::HORIZONTAL_LINE), int(Art::SPACE));
					break;
				case 21:
					printRow(int(Art::VERTICAL_RIGHT_LINE), int(Art::HORIZONTAL_UP_LINE), int(Art::VERTICAL_LEFT_LINE), int(Art::HORIZONTAL_LINE), int(Art::HORIZONTAL_LINE));
					break;
				case 30:
					printRow(int(Art::LOWER_LEFT_CORNER), int(Art::HORIZONTAL_LINE), int(Art::LOWER_RIGHT_CORNER), int(Art::HORIZONTAL_LINE), int(Art::HORIZONTAL_LINE));
					break;
				default:
					printRow(int(Art::VERTICAL_LINE), int(Art::VERTICAL_LINE), int(Art::VERTICAL_LINE), int(Art::SPACE), int(Art::SPACE));
					break;
			}
		}
		else
		{
			printRow(int(Art::VERTICAL_LINE), int(Art::SPACE), int(Art::VERTICAL_LINE), int(Art::SPACE), int(Art::SPACE));
		}
	}
}

/**
 * @brief Function for printing player information (Helath, Armour, etc) on the board
 * @param role Array of all entities
*/
void printPlayerData(Data** role)
{
	struct PLAYER_DATA 
	{
		short health;
		short armour;
		short keys;
		short money;
	};

	PLAYER_DATA playerData = { 
		role[0][0].health, 
		role[0][0].armor, 
		role[0][0].keys, 
		role[0][0].money 
	};

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
				std::cout << "   ";
				goToXY(3, 3);
				std::cout << playerData.health;
				break;
			case 2:
				goToXY(2, 7);
				std::cout << "Armour";
				break;
			case 3:
				goToXY(3, 8);
				std::cout << "   ";
				goToXY(3, 8);
				std::cout << playerData.armour;
				break;
			case 4:
				goToXY(3, 12);
				std::cout << "Keys";
				break;
			case 5:
				goToXY(3, 13);
				std::cout << "   ";
				goToXY(3, 13);
				std::cout << playerData.keys;
				break;
			case 6:
				goToXY(2, 17);
				std::cout << "$Money";
				break;
			case 7:
				goToXY(3, 18);
				std::cout << "   ";
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
void game()
{
	bool playing = true;
	short rowPlayer = 2, colPlayer = 2;
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

	Dialogue afterFirstWalkDialogue =
	{
		{
			{
				"Wizard", "Ok so you can walk, but can you fight. Now go to that enemy and try to fight him!"
			}
		}
	};
	
	//Set-up backend
	char** board = NULL;
	int tempE = 0;
	int level = 0;
	int* tempX = new int[4];
	int* tempY = new int[4];
	int counterDead = 0;
	int mapX = 0;
	int mapY = 0;
	int keyChest = 1 + rand() % 4;
	int moves = 0;
	bool toDrawRoom = true;
	bool countMoves = true;
	bool bossIsDead = false;

	Data** role = new Data * [6];
	for (int i = 0; i < 6; i++)
	{
		role[i] = new Data[100];
	}

	Data* item = new Data[3];

	//Set up the game rules
	GameRules(role, item);

	drawRoom(role, item, board, &tempE, &level, tempX, tempY, &counterDead, &mapY, &mapX, keyChest);

	
	printPlayerData(role);
	
	//Place player on start position
	goToXY(10 + rowPlayer, 1 + colPlayer);
	std::cout << "x";
	
	//Start the dialgue with the wizard
	startDialogue(dialogueAtStart);
	
	toDrawRoom = false;
	
	while (playing) 
	{
		if (moves == 4)
		{
			startDialogue(afterFirstWalkDialogue);
			countMoves = false;
			moves = NULL;
		}

		if (toDrawRoom)
		{
			clearConsole();
			drawBoard();
			printPlayerData(role);
			drawRoom(role, item, board, &tempE, &level, tempX, tempY, &counterDead, &mapY, &mapX, keyChest);
			goToXY(10 + rowPlayer, 1 + colPlayer);
			std::cout << "x";
			toDrawRoom = false;
			/* Debug Info
			goToXY(2, 33);
			std::cout << "Map x - " << mapX;
			goToXY(2, 34);
			std::cout << "Map y - " << mapY;
			*/
		}

		switch ( _getch())
		{
			case int(Buttons::ARROW_LEFT):
			case 'a':
			case 'A':
				rowPlayer--;
				if (isMovePossible(
					&toDrawRoom,
					&rowPlayer,
					&colPlayer,
					role, 
					item,
					playing,
					bossIsDead,
					&tempE,
					&level,
					tempX,
					tempY,
					&counterDead,
					&mapY,
					&mapX,
					keyChest
				))
				{
					rowPlayer++;
					goToXY(10 + rowPlayer, 1 + colPlayer);
					std::cout << " ";

					rowPlayer--;

					goToXY(10 + rowPlayer, 1 + colPlayer);
					std::cout << "x";

					if (countMoves)
					{
						moves++;
					}
				}
				else
				{
					rowPlayer++;
				}

				break;
			case int(Buttons::ARROW_RIGHT):
			case 'd':
			case 'D':
				rowPlayer++;

				if (isMovePossible(
					&toDrawRoom,
					&rowPlayer,
					&colPlayer,
					role,
					item,
					playing,
					bossIsDead,
					&tempE,
					&level,
					tempX,
					tempY,
					&counterDead,
					&mapY,
					&mapX,
					keyChest
				))
				{
					rowPlayer--;
					goToXY(10 + rowPlayer, 1 + colPlayer);
					std::cout << " ";

					rowPlayer++;
					goToXY(10 + rowPlayer, 1 + colPlayer);
					std::cout << "x";

					if (countMoves)
					{
						moves++;
					}
				}
				else
				{
					rowPlayer--;
				}

				break;
			case int(Buttons::ARROW_UP):
			case 'w':
			case 'W':
				colPlayer--;
				if (isMovePossible(
					&toDrawRoom,
					&rowPlayer,
					&colPlayer,
					role,
					item,
					playing,
					bossIsDead,
					&tempE,
					&level,
					tempX,
					tempY,
					&counterDead,
					&mapY,
					&mapX,
					keyChest
				))
				{
					colPlayer++;
					goToXY(10 + rowPlayer, 1 + colPlayer);
					std::cout << " ";

					colPlayer--;
					goToXY(10 + rowPlayer, 1 + colPlayer);
					std::cout << "x";

					if (countMoves)
					{
						moves++;
					}
				}
				else
				{
					colPlayer++;
				}

				break;
			case int(Buttons::ARROW_DOWN):
			case 's':
			case 'S':
				colPlayer++;
				if (isMovePossible(
					&toDrawRoom,
					&rowPlayer,
					&colPlayer,
					role,
					item,
					playing,
					bossIsDead,
					&tempE,
					&level,
					tempX,
					tempY,
					&counterDead,
					&mapY,
					&mapX,
					keyChest
				))
				{
					colPlayer--;
					goToXY(10 + rowPlayer, 1 + colPlayer);
					std::cout << " ";

					colPlayer++;
					goToXY(10 + rowPlayer, 1 + colPlayer);
					std::cout << "x";

					if (countMoves)
					{
						moves++;
					}
				}
				else
				{
					colPlayer--;
				}

				break;
			// if escape key was pressed end program loop
			case int(Buttons::ESCAPE_BUTTON):
				playing = false;
				break;
			// no handled cases where pressed 
			default:  
				break;
		}

	}
} 

/**
 * @brief A player movement controler for when the player is in maze
 * @param firstTimeInAMaze Is it the first time that you are in a maze
*/
void moveInMaze(bool firstTimeInAMaze)
{
	bool isChest = false;
	char input;
	bool playing = true;
	short rowPlayer = 1, colPlayer = 1;

	Room** Maze = new Room * [COL_ROOM];

	for (int i = 0; i < COL_ROOM; ++i)
	{
		Maze[i] = new Room[COL_ROOM];
	}

	setMaze(Maze);
	generateMaze(Maze);
	drawMaze(Maze, COL_ROOM);

	//Draw player
	goToXY(22 + rowPlayer, 1 + colPlayer);
	std::cout << "x";


	//Start the dialgue
	if (firstTimeInAMaze)
	{
		//startDialogue(dialogueAtStart);
	}

	while (playing)
	{
		switch ((input = _getch()))
		{
		case int(Buttons::ARROW_LEFT):
		case 'a':
		case 'A':
			if (isMovePossible(Maze, rowPlayer - 1, colPlayer, isChest))
			{
				goToXY(22 + rowPlayer, 1 + colPlayer);
				std::cout << " ";

				rowPlayer--;

				goToXY(22 + rowPlayer, 1 + colPlayer);
				std::cout << "x";
			}

			break;
		case int(Buttons::ARROW_RIGHT):
		case 'd':
		case 'D':
			if (isMovePossible(Maze, rowPlayer + 1, colPlayer, isChest))
			{
				goToXY(22 + rowPlayer, 1 + colPlayer);
				std::cout << " ";

				rowPlayer++;

				goToXY(22 + rowPlayer, 1 + colPlayer);
				std::cout << "x";
			}

			break;
		case int(Buttons::ARROW_UP):
		case 'w':
		case 'W':
			if (isMovePossible(Maze, rowPlayer, colPlayer - 1, isChest))
			{
				goToXY(22 + rowPlayer, 1 + colPlayer);
				std::cout << " ";

				colPlayer--;

				goToXY(22 + rowPlayer, 1 + colPlayer);
				std::cout << "x";
			}

			break;
		case int(Buttons::ARROW_DOWN):
		case 's':
		case 'S':
			if (isMovePossible(Maze, rowPlayer, colPlayer + 1, isChest))
			{
				goToXY(22 + rowPlayer, 1 + colPlayer);
				std::cout << " ";

				colPlayer++;

				goToXY(22 + rowPlayer, 1 + colPlayer);
				std::cout << "x";
			}

			break;
			// if escape key was pressed end program loop
		case int(Buttons::ESCAPE_BUTTON):
			playing = false;
			break;
		default:  // no handled cases where pressed 
			break;
		}

		if (isChest)
		{
			return;
		}
	}
}

/**
 * @brief Function for drawing a room on the screen
 * @param role All entities
 * @param item All item rules
 * @param board A two dimensional array of chars for visualising the board
 * @param tempE A varible for holding the number of enemies in one room
 * @param level The current level
 * @param tempX A varible for holding the X coordinates of the enemies
 * @param tempY A varible for holding the Y coordinates of the enemies
 * @param counterDead A counter for dead enemies
 * @param mapY The Y coordinate of the room
 * @param mapX The X coordinate of the room
 * @param keyChest Is the key obtained
*/
void drawRoom(Data** role, Data* item, char** board, int* tempE, int* level, int* tempX, int* tempY, int* counterDead, int* mapY, int* mapX, int& keyChest)
{
	board = room(role, item, tempE, level, tempX, tempY, counterDead, mapY, mapX, keyChest);

	goToXY(10, 1);
	for (int i = 0; i < ROW_ROOM + 2; i++)
	{
		for (int j = 0; j < COL_ROOM + 2; j++) 
		{
			goToXY(10 + i, 1 + j);
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}

/**
 * @brief Function for drawing a Maze on the console
 * @param Maze A pointer to dynamic two-dimensional array of Room
 * @param length The size of the maze
*/
void drawMaze(Room** Maze, int length)
{
	for (int i = 0; i < length; i++)
	{
		goToXY(22, i + 1);
		for (int j = 0; j < length; j++)
		{
			std::cout << Maze[i][j].show;
		}
	}
}

/**
 * @brief Function for teleporting player from one point to another
 * @param role All entities
 * @param board  A two dimensional array of chars for visualising the board
 * @param row The current X coordinate of the player
 * @param col The current Y coordinate of the player
 * @param direction The direction of the door
*/
void teleport(Data** role, char** board, short* row, short* col, int direction) 
{
	switch (direction)
	{
		case 1:
		{
			*col = 14;
			break;
		}
		case 2:
		{
			*row = 3;
			break;
		}
		case 3:
		{
			*col = 3;
			break;
		}
		case 4:
		{
			*row = 38;
			break;
		}
	}
}