/*! @file back-end.h
*   @brief A header file for the logic layer.
*/

#pragma once 

//Libraries
#include <iostream>
#include <Windows.h>
#include <stack>

//Structures
struct Room;
struct Data;

//Functions
void set(Room** Maze, int length);
//char** room(Data* role, Data* item);
Room** generator(int length);
bool isMovePossible(Room** board, short row, short col);
void GameRules();
//void atack(Data* role, short index, bool game);
//void shop(Data* role, Data* item, short index);