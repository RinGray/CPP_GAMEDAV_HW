#pragma once
#include <string> 

enum class GameMenu {
    Exit,
    WordleOfTheDay,
    RandomWordle
};

void writeFile(const char* fileName, const std::string& todayDate, const std::string& word);

void readFile(const char* fileName, std::string& data);
void removeWordFromFile(const std::string& filename, const std::string& wordToRemove);

std::string getRandomWord(const std::string& input);

void toUpperCase(std::string& str);

bool validate(std::string& str);

bool checkUpper(char str);

void clearConsole();

#ifdef _DEBUG 
void testCase(std::string& maskOfSymbol, std::string TestCase);
#endif

bool checkDate(const std::string& s);

std::ostringstream oss();

bool MainMenu(std::string& searchedWord, bool& isGameActive);

void GameStart(std::string& searchedWord);