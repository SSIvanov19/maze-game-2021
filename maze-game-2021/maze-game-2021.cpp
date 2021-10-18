#include <iostream>
#include "front-end.h"
#include "back-end.h"

void initializeTheGame()
{
    //Set the console output to the main color (White)
    setConsoleColorTo(COLOR_MAIN);

    if (checkForInvalidHandle())
    {
        std::cout << "Failed to get STD_OUTPUT_HANDLE!\nThe program is going to close itself!\n";
        exit(1);
    }
}

int main()
{
    initializeTheGame();
    
    while (true)
    {
        printMainMenu(1, true);
    }
}