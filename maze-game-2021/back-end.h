/*! @file back-end.h
*   @brief A header file for the logic layer.
*/

#pragma once 

//Libraries
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stack>

//Defines
#define ROW_ROOM 41
#define COL_ROOM 17

//Structures
struct Room
{
	bool visited;
	bool top;
	bool bot;
	bool left;
	bool right;
	char show;
};

struct Data
{
    char person;
    short health;
    short armor;
    short attack;
    short money;
    short keys;
};

//Functions
char** room(Data** role, Data* item, int* tempE, int* level, int* tempX, int* tempY, int* counterDead, int* mapY, int* mapX, int& keyChest);
void attack(Data** role, int index, bool& game, int idEnemies, int* counterDead, bool* showBoard, bool& bossIsDead);
void shop(Data** role, Data* item, short index);
bool isMovePossible(Room** board, short row, short col, bool& isChest);
bool isMovePossible(bool* showBoard, short* row, short* col, Data** role, Data* item, bool& game, bool& bossIsDead, int* tempE, int* level, int* tempX, int* tempY, int* counterDead, int* mapY, int* mapX, int& keyChest);
void GameRules(Data** role, Data* item);
void setMaze(Room** Maze);
void generateMaze(Room** maze);