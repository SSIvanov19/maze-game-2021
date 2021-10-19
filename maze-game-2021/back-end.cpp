#include "back-end.h"
#include <iostream>
#include <Windows.h>

std::string** generateRoom(short rowRoom, short colRoom)
{ // bug
    std::string** room = new std::string * [rowRoom];

    for (int i = 0; i < rowRoom; i++)
    {
        room[i] = new std::string[colRoom];
    }

    for (int i = 0; i < rowRoom; i++) 
    {
        for (int j = 0; j < colRoom; j++) 
        {
            if (i == 0 && j == 0) 
            {
                room[i][j] = "#";
            }
            if (i == 0 && j != 0) 
            {
                room[i][j] = "#";
            }
            if (j == 0 && i != 0) 
            {
                room[i][j] = "#";
            }

            if (j == colRoom - 1 && i != rowRoom - 1) 
            {
                room[i][j] = "#";
            }
            if (i == rowRoom - 1 && j != 0) 
            {
                room[i][j] = "#";
            }
        }
    }

    return room;
}

void freeRoom(char** room, short rowRoom, short colRoom)
{
    for (int i = 0; i < rowRoom; i++) 
    {
        delete[] room[i];
    }

    delete[] room;
}

bool isMovePossible(std::string **board, short row, short col) 
{
    if (row == -1 || col == -1)
    {
        return false;
    }
    
    if (board[row][col] == "#")
    {
        return false;
    }

    return true;
}

/*
int main() {
    move();
    //draw();
}
*/
