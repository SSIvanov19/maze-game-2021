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
struct Room;

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
char** room(Data** role, Data* item, int* tempE, int* level, int* tempX, int* tempY, int* counterDead, int* mapY, int* mapX);
void attack(Data** role, int index, bool game, int idEnemies, int* counterDead);
void shop(Data** role, Data* item, short index);
bool isMazeMovePossible(Room** board, short row, short col/*, Data* role, Data* item, , bool game*/);
bool isMovePosible(short row, short col, Data** role, Data* item, bool game, int* tempE, int* level, int* tempX, int* tempY, int* counterDead, int* mapY, int* mapX);
void GameRules(Data** role, Data* item);

/*
void set(Room** Maze, int length);
//char** room(Data* role, Data* item);
Room** generator(int length);
bool isMovePossible(Room** board, short row, short col);
void GameRules();
//void atack(Data* role, short index, bool game);
//void shop(Data* role, Data* item, short index);
*/