#pragma once 

#include <iostream>
#include <Windows.h>

void gotoxy(int x, int y);
void clear();
void move();
bool movePosible(int row, int col);