/*! @file dialogue.h
*   @brief A header file for the dialogue system.
*/

#pragma once

//Libraries
#include <iostream>
#include <vector>

typedef void (*dialgueOption)();

//Structures
struct Line
{
	std::string nameOfCharacter;
	std::string words;
	dialgueOption option = NULL;
};

struct Dialogue
{
	std::vector<Line> lines;
};

//Functions
void startDialogue(Dialogue dialogue);
std::string getBossName();
void askForBossName();
std::string getWord();