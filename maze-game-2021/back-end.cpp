#include "backEnd.h"

using namespace std;

int rowRoom, colRoom; // size of the rooms
int rowPlayer = (rowRoom-1)/2, colPlayer = (colRoom-1)/2, moves = 0;
int** room = new int *room[rowRoom];
for (int i = 0; i < rowRoom; i++)
    room[i] = new int[colRoom];

HANDLE rhnd = GetStdHandle(STD_INPUT_HANDLE);  // handle to read console

DWORD Events = 0;     // Event count
DWORD EventsRead = 0; // Events read from console

bool Running = true;

bool movePosible(int row, int col) {
    if (row = -1 || col = -1)
        return false;

    for (int i = 0; i < rowRoom; i++) {
        for (int j = 0; j < colRoom*2; j++) {
            if (row == 0 && col == j)
                return false;
            if (row == i && col == 0)
                return false;
            if (row == 0 && col == colRoom-1)
                return false;
            if (row == rowRoom-1 && col == 0)
                return false;
        }
    }
   
    return true;
}

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}

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

                    // check if the key press was an arrow key
                    if (moves > 0)
                        clear();
                    moves++;
                    switch (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode) {
                    case VK_LEFT:
                        rowPlayer--;
                        if (movePosible(rowPlayer, colPlayer)) {
                            gotoxy(rowPlayer, colPlayer);
                            //cout << "x"; 
                        }
                        else
                            rowPlayer++; 
                        break;
                    case VK_RIGHT:
                        rowPlayer++;
                        if (movePosible(rowPlayer, colPlayer)) {
                            gotoxy(rowPlayer, colPlayer);
                            //cout << "x"; 
                        }
                        else
                            rowPlayer--;
                        break;
                    case VK_UP:
                        colPlayer--;
                        if (movePosible(rowPlayer, colPlayer)) {
                            gotoxy(rowPlayer, colPlayer);
                            //cout << "x"; 
                        }
                        else
                            colPlayer++;
                        break;
                    case VK_DOWN:
                        colPlayer++;
                        if (movePosible(rowPlayer, colPlayer)) {
                            gotoxy(rowPlayer, colPlayer);
                            //cout << "x"; 
                        }
                        else
                            colPlayer--;

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
