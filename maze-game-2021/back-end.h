#pragma once 

#include <iostream>
#include <Windows.h>

void gotoxy(short x, short y);
void clear();
void move();
bool movePosible(short row, short col);
void space(short row, short col);
string** room(); // bug
void freeRoom(char** room);