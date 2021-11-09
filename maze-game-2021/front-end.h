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

//Defines
#define ESCAPE_BUTTON 27
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ARROW_UP 72
#define ARROW_DOWN 80
#define COLOR_MAIN 15
#define KEY_ENTER 13
#define SPACE 32
#define VERTICAL_LINE 179
#define VERTICAL_LEFT_LINE 180
#define UPPER_RIGHT_CORNER 191
#define LOWER_LEFT_CORNER 192
#define HORIZONTAL_UP_LINE 193
#define HORIZONTAL_DOWN_LINE 194
#define VERTICAL_RIGHT_LINE 195
#define HORIZONTAL_LINE 196
#define LOWER_RIGHT_CORNER 217
#define UPPER_LEFT_CORNER 218

/* ART

char uSword = 179;
char dSword = 216;
char key = 12;
char healthShop = 3;
char armorShop = 233;
char wizard = 30;
char money = 36;
char firstMonster = 254;
char secondMonster = 4;
char fPartThirdMonster = 203;
char sPartThirdMonster = 176;
char fPartFourthMonster = 209;
char sPartFourthMonster = 215;
char bossFPart = 206;
char bossSPart = 178;
char bossTPart = 201;
char bossFoPart = 184;
char chest = 127;
char bush = 157;
char rock = 240;
char holegl = 201;
char holegd = 187;
char holedl = 200;
char holedd = 188;
char holesr1 = 205;
char holesr2 = 186;
*/
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
void printSettingsLogo();
void printSettings(int selectedOption, bool printLogo);
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