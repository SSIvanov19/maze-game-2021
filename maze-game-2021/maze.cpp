

// Don't touch the code


#include <iostream>
#include <Windows.h>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>      

using namespace std;

short rowRoom = 22, colRoom = 11; // size of the rooms
string** board, ** maze;
short direction = 0;

void clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

void gotoxy(short x, short y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}


string** room() {
	string** room = new string * [rowRoom];
	for (int i = 0; i < rowRoom; i++)
		room[i] = new string[colRoom];

	for (int i = 0; i < rowRoom; i++) {
		for (int j = 0; j < colRoom; j++) {
			if (i == 0 && j == 0) {
				room[i][j] = "|";
			}
			if (i == 0 && j != 0) {
				room[i][j] = "|";
			}
			if (j == 0 && i != 0) {
				room[i][j] = "|";
			}

			if (j == colRoom - 1 && i != rowRoom - 1) {
				room[i][j] = "|";
			}
			if (i == rowRoom - 1 && j != 0) {
				room[i][j] = "|";
			}
			/*
			if (i == 0 && j == 1) {
				room[i][j] = " ";
			}
			*/
		}
	}

	return room;
}

void draw() {
	board = room();
	for (int i = 0; i < rowRoom; i++) {
		for (int j = 0; j < colRoom; j++) {
			if (direction != 0) {
				board = maze;
				if (board[i][j] == "#") {
					gotoxy(i, j);
					cout << "#";
				}

				if (board[i][j] == ".") {
					gotoxy(i, j);
					cout << ".";
				}
			}
			if (board[i][j] == "|") {
				gotoxy(i, j);
				cout << "|";
			}
		}
		cout << endl;
	}

}

bool mazeImposible(string** maze, short row, short col, short direction) {
	if (maze[row][col] == "|")
		return false;

	switch (direction) {
	case 1:
		if (maze[row][col - 1] == "#")
			return false;
		break;
	case 2:
		if (maze[row + 1][col] == "#")
			return false;
		break;
	case 3:
		if (maze[row][col + 1] == "#")
			return false;
		break;
	case 4:
		if (maze[row - 1][col] == "#")
			return false;
		break;
	}

	return true;
}

void mazeBuilder(string** maze, short row, short col, short direction) {
	if (maze[row - 1][col + 1] == "." && direction == 1) {
		maze[row - 1][col] = "#";
		if (maze[row - 1][col + 1] == "#")
			maze[row - 2][col] = "#";
	}
	if (maze[row + 1][col + 1] == "." && direction == 2) {
		maze[row][col - 1] = "#";
		if (maze[row - 1][col - 2] == "#")
			maze[row][col - 2] = "#";

	}
	if (maze[row - 1][col - 1] == "." && direction == 3) {
		maze[row - 1][col] = "#";
		if (maze[row - 2][col - 1] == "#")
			maze[row - 2][col] = "#";
	}
	if (maze[row + 1][col - 1] == "." && direction == 4) {
		maze[row][col - 1] = "#";
		if (maze[row + 1][col - 1] == "#")
			maze[row][col - 2] = "#";
	}
}

void mazeCreate() {
	maze = room();
	short i = 1, j = 1;
	maze[i][j] = " ";
	srand(time(NULL));
	bool full = true;
	while (full) {
		gotoxy(i, j);
		cout << "x";
		draw();
		cout << "Row = " << i << " Col = " << j << endl;
		direction = rand() % 4 + 1; // 1 - up, 2 - right, 3 - down, 4 - left
		cout << "Direction choise: ";
		switch (direction) {
		case 1: cout << "up" << endl;  break;
		case 2: cout << "rigth" << endl; break;
		case 3: cout << "down" << endl; break;
		case 4: cout << "left" << endl; break;
		}
		Sleep(1500);
		switch (direction) {
		case 1: // up
			if (mazeImposible(maze, i, j - 1, 1)) {
				j--;
				mazeBuilder(maze, i, j, 1);
				maze[i][j] = ".";
			}
			break;
		case 2: // rigth
			if (mazeImposible(maze, i + 1, j, 2)) {
				i++;
				mazeBuilder(maze, i, j, 2);
				maze[i][j] = ".";
			}
			break;
		case 3: // down
			if (mazeImposible(maze, i, j + 1, 3)) {
				j++;
				mazeBuilder(maze, i, j, 3);
				maze[i][j] = ".";
			}
			break;
		case 4: // left
			if (mazeImposible(maze, i - 1, j, 4)) {
				i--;
				mazeBuilder(maze, i, j, 4);
				maze[i][j] = ".";
			}
			break;
		default:
			break;
		}
		clear();
		if (i == rowRoom - 2 && j == colRoom - 2) {
			full = false;
		}
	}
}

void freeRoom(char** room) {
	for (int i = 0; i < rowRoom; i++) {
		delete[] room[i];
	}
	delete[] room;
}

int main() {
	mazeCreate();
	//move();
}