#include "backEnd.h"
#include <iostream>
#include <Windows.h>

using namespace std;

short rowRoom = 22, colRoom = 11; // size of the rooms
int helper = 0;
string** board; // bug
short rowPlayer = 1, colPlayer = 1, moves = 0;

HANDLE rhnd = GetStdHandle(STD_INPUT_HANDLE);  // handle to read console

DWORD Events = 0;     // Event count
DWORD EventsRead = 0; // Events read from console

bool Running = true;

string** room() { // bug
    string** room = new string * [rowRoom];
    for (int i = 0; i < rowRoom; i++)
        room[i] = new string[colRoom];

    for (int i = 0; i < rowRoom; i++) {
        for (int j = 0; j < colRoom; j++) {
            if (i == 0 && j == 0) {
                room[i][j] = "#";
            }
            if (i == 0 && j != 0) {
                room[i][j] = "#";
            }
            if (j == 0 && i != 0) {
                room[i][j] = "#";
            }

            if (j == colRoom - 1 && i != rowRoom - 1) {
                room[i][j] = "#";
            }
            if (i == rowRoom - 1 && j != 0) {
                room[i][j] = "#";
            }
        }
    }

    return room;
}

void freeRoom(char** room) {
    for (int i = 0; i < rowRoom; i++) {
        delete[] room[i];
    }
    delete[] room;
}

bool movePosible(short row, short col) {
    if (row == -1 || col == -1)
        return false;
    board = room();
    if (board[row][col] == "#")
        return false;

    return true;
}

void gotoxy(short x, short y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}

/* for frontend :)
void draw() {
    board = room();
    for (int i = 0; i < rowRoom; i++) {
        for (int j = 0; j < colRoom; j++) {
            if (board[i][j] == "#") {
                gotoxy(i, j);
                cout << "#";
            }
        }
        cout << endl;
    }

}
*/

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

void move() {
    //programs main loop
    while (Running) {
        // gets the systems current "event" count
        GetNumberOfConsoleInputEvents(rhnd, &Events);

        if (Events != 0) { // if something happened we will handle the events we want
            // create event buffer the size of how many Events
            INPUT_RECORD* eventBuffer = new INPUT_RECORD[Events];

            // fills the event buffer with the events and saves count in EventsRead
            ReadConsoleInput(rhnd, eventBuffer, Events, &EventsRead);

            // loop through the event buffer using the saved count
            for (DWORD i = 0; i < EventsRead; ++i) {

                // check if event[i] is a key event && if so is a press not a release
                if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown) {

                    if (moves > 0) {
                        clear();
                    }
                    moves++;
                    // check if the key press was an arrow key

                    switch (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode) {
                    case VK_LEFT:
                        rowPlayer--;
                        if (!movePosible(rowPlayer, colPlayer))
                            rowPlayer++;
                        gotoxy(rowPlayer, colPlayer);
                        cout << "x";
                        break;
                    case VK_RIGHT:
                        rowPlayer++;
                        if (!movePosible(rowPlayer, colPlayer))
                            rowPlayer--;
                        gotoxy(rowPlayer, colPlayer);
                        cout << "x";
                        break;
                    case VK_UP:
                        colPlayer--;
                        if (!movePosible(rowPlayer, colPlayer))
                            colPlayer++;
                        gotoxy(rowPlayer, colPlayer);
                        cout << "x";
                        break;
                    case VK_DOWN:
                        colPlayer++;
                        if (!movePosible(rowPlayer, colPlayer))
                            colPlayer--;
                        gotoxy(rowPlayer, colPlayer);
                        cout << "x";
                        break;

                        // if any arrow key was pressed go to these cordinates
                    case VK_ESCAPE: // if escape key was pressed end program loop
                        //cout << " escape key pressed.\n";
                        Running = false;
                        break;

                    default:        // no handled cases where pressed 
                        //cout << "dont press other buttons.\n";
                        break;
                    }
                }

            } // end EventsRead loop

        } // end of events

    } // end program loop
}

int main() {
    move();
    //draw();
}