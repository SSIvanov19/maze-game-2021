#include "front-end.h"
#include "back-end.h"

void initializeTheGame()
{
    if (checkForInvalidHandle())
    {
        showError("Failed to get STD_OUTPUT_HANDLE!");
    }

    //Set the console output to the main color (White)
    setConsoleColorTo(COLOR_MAIN);

}

int main()
{
    initializeTheGame();
    
    while (true)
    {
        printMainMenu(1, true);
    }
}