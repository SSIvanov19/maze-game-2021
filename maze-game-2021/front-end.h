//Include libraries
#pragma once
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <vector>

//Defines
#define ESCAPE_BUTTON 27
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ARROW_UP 72
#define ARROW_DOWN 80
#define COLOR_MAIN 15
#define KEY_ENTER 13

typedef void (*Operation)(int option);

//Structures
struct MenuOptions;

//Functions

//Handle and console releated functions
bool checkForInvalidHandle();
HANDLE getOutputHandle();
void setConsoleColorTo(int color);

//Menu releated functions
void printOptions(std::vector<MenuOptions> menuOptions, int selectedOption, Operation opt);
void printLogo();
void printMainMenu(int selectedOption);
void printSettings(int selectedOption);
void printSettingsLogo();
void printHowToPlayLogo();
void printHowToPlay();
