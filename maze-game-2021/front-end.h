/*! @file front-end.h
*   @brief A header file for the presentation layer.
*/

/*! @def COLOR_MAIN
*	@brief A macro that return the code of the main color.
*/

/*!	@var typedef void (*Operation)(int option, bool option2);
	@brief A type definition for a function pointer in a MenuOptions stuct.
*/

#pragma once

//Include libraries
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <stack>

//Define
#define COLOR_MAIN 15

//Enums

/**
 * @brief A enum for the Buttons pressed on the keyboard
*/
enum class Buttons
{
	ESCAPE_BUTTON = 27, /*!< Escape button on the keyboard */
	ARROW_LEFT = 75, /*!< Arrow left button on the keyboard */
	ARROW_RIGHT = 77, /*!< Arrow right button on the keyboard */
	ARROW_UP = 72, /*!< Arrow up button on the keyboard */
	ARROW_DOWN = 80, /*!< Arrow down button on the keyboard */
	KEY_ENTER = 13 /*!< Enter button on the keyboard */
};

/**
 * @brief A enum that holds every ASCII character that we use
*/
enum class Art
{
	SPACE = 32, /*!< The empty space character */
	VERTICAL_LINE = 179, /*!< Vertical line */
	VERTICAL_LEFT_LINE = 180, /*!< Vertical line with left line */
	UPPER_RIGHT_CORNER = 191, /*!< Upper right corner */
	LOWER_LEFT_CORNER = 192, /*!< Lower left corner */
	HORIZONTAL_UP_LINE = 193, /*! Horizontal line with upper vertical line */
	HORIZONTAL_DOWN_LINE = 194, /*! Horizontal line with lower vertical line */
	VERTICAL_RIGHT_LINE = 195, /*!< Vertical line with right line */
	HORIZONTAL_LINE = 196, /*!< Horizontal line */
	LOWER_RIGHT_CORNER = 217, /*!< Lower right corner */
	UPPER_LEFT_CORNER = 218, /*!< Upper left corner */
	U_SWORD = 179, /*!< The upper part of the sword */
	D_SWORD = 216, /*!< The lower part of the sword */
	KEY = 12, /*!< Symbol for the key */
	HEALTH_SHOP = 3, /*!< Symbol for the health in the shop */
	ARMOR_SHOP = 233, /*!< Symbol for the armor in the shop */
	WIZARD = 30, /*!< Symbol for the wizard */
	MONEY = 36, /*!< Symbol for the money / Dolar sign */
	FIRST_MONSTER = 254, /*!< ASCII character representation of the first monster */
	SECOND_MONSTER = 4,/*!< ASCII character representation of the second monster */
	F_PART_THIRD_MONSTER = 203, /*!< ASCII character representation of the first part of the third monster */
	S_PART_THIRD_MONSTER = 176, /*!< ASCII character representation of the second part of the third monster */
	F_PART_FOURTH_MONSTER = 209, /*!< ASCII character representation of the first part of the fourth monster */
	S_PART_FOURTH_MONSTER = 215, /*!< ASCII character representation of the second part of the fourth monster */
	BOSS_F_PART = 206, /*!< ASCII character representation of the first part of the Boss */
	BOSS_S_PART = 178, /*!< ASCII character representation of the second part of the Boss */
	BOSS_T_PART = 201, /*!< ASCII character representation of the third part of the Boss */
	BOSS_FO_PART = 187, /*!< ASCII character representation of the fourth part of the Boss */
	CHEST = 219, /*!< Symbol for the chest */
	BUSH = 157, /*!< Symbol for the bush */
	ROCK = 240, /*!< Symbol for the rock */
	HOLE_GL = 201, /*!< Symbol for the hole */
	HOLE_GD = 187, /*!< Symbol for the hole */
	HOLE_DL = 200, /*!< Symbol for the hole */
	HOLE_DD = 188, /*!< Symbol for the hole */
	HOLES_R1 = 205, /*!< Symbol for the hole */
	HOLES_R2 = 186 /*!< Symbol for the hole */
};

//Typedef
typedef void (*Operation)(int option, bool option2);

//Structures
struct MenuOptions;
struct Room;
struct Data;

//Functions

//Handle and console related function
void setCursor(bool shown);
void goToXY(short x, short y);
bool checkForInvalidHandle(HANDLE handle);
HANDLE getOutputHandle();
COORD GetConsoleCursorPosition();
void setConsoleColorTo(int color);
void clearConsole();
void showError(std::string fileName, std::string functionName, DWORD errorCode, std::string msg);

//Menu related functions
void printOptions(std::vector<MenuOptions> menuOptions, int selectedOption, Operation opt);
void printBossOnMenu();
void printMainLogo();
void printMainMenu(int selectedOption, bool printLogo);
void printHowToPlayLogo();
void printHowToPlay(int selectedOption, bool printLogo);

//Game related functions
void game();
void drawBoard();
void printPlayerData(Data** role);
void printMessage(std::string msg);
void clearMessage(std::string msg);
void drawRoom(Data** role, Data* item, char** board, int* tempE, int* level, int* tempX, int* tempY, int* counterDead, int* mapY, int* mapX, int& keyChest);
void teleport(Data** role, char** board, short* row, short* col, int direction);
void drawMaze(Room** Maze, int length);
void moveInMaze(bool firstTimeInAMaze);