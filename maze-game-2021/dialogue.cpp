/*! @file dialogue.cpp
*   @brief A source file for the dialogue system.
*/
#include "dialogue.h"
#include "front-end.h"

//Ignore this line, please!
std::string bossName;

/**
 * @brief Function that starts dialogue
 * @param dialogue Dialogue to be startted
*/
void startDialogue(Dialogue dialogue)
{
	std::string stringToDisplay;

	for (auto line : dialogue.lines)
	{
		stringToDisplay = line.nameOfCharacter + '\n' + line.words;
		printMessage(stringToDisplay);

		if (line.option != NULL)
		{
			line.option();
		}
		else
		{
			_getch();
		}

		clearMessage(stringToDisplay);
	}
}

/**
 * @brief Function for input the boss name from the user
*/
void askForBossName()
{
	goToXY(2, 24);

	setCursor(true);

	bossName = getWord();

	setCursor(false);

	if (bossName.size() == 0)
	{
		askForBossName();
	}

	goToXY(2, 24);

	for (size_t i = 0; i < bossName.size(); i++)
	{
		std::cout << " ";
	}
}

/**
 * @brief Function for getting words from the console line
 * @return string The word
*/
std::string getWord()
{
	std::string word;
	char c = _getch();

	while (c != 13)
	{
		if (c == 32)
		{
			c = _getch();
			continue;
		}
		//If c == backspase remove char from string
		//else add char
		if (c == 8)
		{
			if (word.size() == 0)
			{
				c = _getch();
				continue;
			}
			else
			{
				word.pop_back();
				COORD coordOfCursor = GetConsoleCursorPosition();
				goToXY(coordOfCursor.X - 1, coordOfCursor.Y);
				std::cout << " ";
				std::cout << c;
			}
		}
		else
		{
			if (c > 64 && c < 91 || c > 96 && c < 123)
			{
				word.push_back(c);
				std::cout << c;
			}
		}

		c = _getch();
	}
	std::cout << c;
	return word;
}

/**
 * @brief Function that return the name of the boss
 * @return string The name of the boss
*/
std::string getBossName()
{
	return bossName;
}