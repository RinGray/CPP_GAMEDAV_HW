#include <iostream>
#include <iomanip>
#include <cctype>
//#include "Func.h"
using namespace std; 

string database[] = { "WORDD" , "WAAAA", "WBBBB" };



//функціонал вибору РАНДОМНОГО СЛОВА з бази даних
//(наприклад std::string database[] = { “WORD1”, “WORD2”, “WORDN” }; або в будь - який інший спосіб);
//Алгоритм порівняння вашого слова із загаданим словом :
//Простий варіант : без врахування того, що літери можуть дублюватися
//Підрахунок кількості спроб;
//Завантажити код на гітхаб;



string getRandomWord() {
    std::cout << size(database) << endl;
    const int GeneratingRange = size(database);
    //const int GeneratedNum = std::rand() % GeneratingRange + 1;
    return database[std::rand() % GeneratingRange];
}

void toUppercase(string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}

bool validate(string& str) {
    //int counter = 0;
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] < 'A' || str[i] > 'Z') {
            return false;
        }
    }
    return true;
}


int main()
{
    std::srand((unsigned int)time(NULL));
    string word, searchedWord, maskOfSymbol;
    bool SwitchGame = true, isGameActive = false;
    while (SwitchGame) {
        std::cout << "Word of the day: 1" << endl;
        std::cout << "Random wordle: 2" << endl;
        std::cout << "Exit: 0" << endl;
        unsigned menuSelect;
        std::cin >> menuSelect;
        switch (menuSelect)
        {
        default:
            break;
        case 1:
            std::cout << "Word of the day: 1" << endl;
            break;
        case 2:
            std::cout << "Random wordle: 2"<< endl;

            searchedWord = getRandomWord();
            std::cout << searchedWord << endl;
            isGameActive = true;
            maskOfSymbol = "*****";
            while (isGameActive) {
                std::cout << maskOfSymbol << endl;
                std::cin >> word;
                //word = "wsdfg";
                toUppercase(word);
                std::cout << word<< " size: "<<size(word);
                if (validate(word)) {
                    if (size(word) == 5) {
                        std::cout << "+++++" << endl;
                        for (int i = 0; i < 5; i++) {
                            std::cout << "word + " << i << ": " << word[i] << endl;
                            if (searchedWord[i] == word[i]) {
                                std::cout << "!!!" << endl;
                                maskOfSymbol[i] = word[i];
                            }

                            std::cout << "***" << endl;
                            for (int j = 0; j < 5; j++) {



                            }
                        }
                    }
                    else {
                        std::cout << "Invalid count of word" << endl;
                    }
                }
                else {
                    std::cout << "Invalid symbol" << endl;
                }

                
            }
            
            break;
        case 0:
            SwitchGame = false;
            break;
        }

    }
}

