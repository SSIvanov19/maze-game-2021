/*! @file back-end.h
*   @brief A header file for the logic layer.
*/

#pragma once 

/*! @def LENGTH
*	@brief A macro that return the length of the maze.
*/

//Libraries
#include <iostream>
#include <Windows.h>
#include <stack>

#define LENGTH 21

//Structures
struct Room;

//Functions
bool isMovePossible(Room** board, short row, short col);
void generator(Room** Maze);
void set(Room** Maze);