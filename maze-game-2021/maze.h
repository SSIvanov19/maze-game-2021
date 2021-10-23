#pragma once

#include <iostream>
#include <ctime> // random number
#include <windows.h> // clean screen
#include <stack> // backtracking path

#define LENGTH 21 // length of maze

struct Room
{
	bool visited;
	bool top;
	bool bot;
	bool left;
	bool right;
	char show;
};

void Set(Room Maze[][LENGTH]);
void Draw(Room Maze[][LENGTH]);
void Generator(Room Maze[][LENGTH]);
void Clear();