/*! @file front-end.h
*   @brief A header file for the presentation layer.
*/

/*! @def ESCAPE_BUTTON
*	@brief A macro that return the ASCII code of the escape buttoon.
*/

/*! @def KEY_ENTER
*	@brief A macro that return the ASCII code of the enter buttoon.
*/

/*! @def ARROW_LEFT
*	@brief A macro that return the ASCII code of the left arrow buttoon.
*/

/*! @def ARROW_RIGHT
*	@brief A macro that return the ASCII code of the right arrow buttoon.
*/

/*! @def ARROW_UP
*	@brief A macro that return the ASCII code of the upper arrow buttoon.
*/

/*! @def ARROW_DOWN
*	@brief A macro that return the ASCII code of the down arrow buttoon.
*/

/*! @def COLOR_MAIN
*	@brief A macro that return the code of the main color.
*/

/*! @def LENGTH
*	@brief A macro that return the lenfth of the maze.
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

//Defines
#define ESCAPE_BUTTON 27
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ARROW_UP 72
#define ARROW_DOWN 80
#define COLOR_MAIN 15
#define KEY_ENTER 13
#define LENGTH 21

typedef void (*Operation)(int option, bool option2);

//Structures
struct MenuOptions;
struct Room;

//Functions

//Handle and console releated function
void goToXY(short x, short y);
bool checkForInvalidHandle();
HANDLE getOutputHandle();
void setConsoleColorTo(int color);
void clearConsole();
void showError(std::string fileName, std::string fucntionName, DWORD errorCode, std::string msg);

//Menu releated functions
void printOptions(std::vector<MenuOptions> menuOptions, int selectedOption, Operation opt);
void printMainLogo();
void printMainMenu(int selectedOption, bool printLogo);
void printSettingsLogo();
void printSettings(int selectedOption, bool printLogo);
void printHowToPlayLogo();
void printHowToPlay(int selectedOption, bool printLogo);

//Game releated functions
void move();
void drawRoom(Room** Maze);
void drawBoard();
