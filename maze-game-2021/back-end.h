#pragma once 

#include <iostream>
#include <Windows.h>
#include <stack>

#define LENGTH 21

struct Room;

bool isMovePossible(std::string** board, short row, short col);
void generator(Room** Maze);
void set(Room** Maze);