#include <iostream>
#include "front-end.h"

void initializeTheGame()
{
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
        printMainMenu(1);
    }
}