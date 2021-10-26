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

//Functions
bool isMovePossible(Room** board, short row, short col);
Room** generator(int length);
void set(Room** Maze, int length);