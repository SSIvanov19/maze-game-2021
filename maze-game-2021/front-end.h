#pragma once
#include <windows.h>
#include <iostream>
#include <conio.h>

#define ESCAPE_BUTTON 27
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ARROW_UP 72
#define ARROW_DOWN 80
#define COLOR_MAIN 15
#define KEY_ENTER 13

struct MENU_OPTION
{
	std::string name;
	void* function;
};

bool checkForInvalidHandle();
HANDLE getOutputHandle();
void printMenu(int selectedOption);
void setConsoleColorTo(int color);