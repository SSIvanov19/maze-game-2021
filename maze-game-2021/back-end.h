#pragma once 

#include <iostream>
#include <Windows.h>

bool isMovePossible(std::string** board, short row, short col);
//void space(short row, short col);
std::string** generateRoom(short rowRoom, short colRoom); //bug
void freeRoom(char** room, short rowRoom, short colRoom);