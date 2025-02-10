//#define NDEBUG
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cctype>

//#include<chrono>
//#include<format>
//#include "Func.h"
using namespace std; 

#ifdef _DEBUG
string database[] = { "HELLO" , "COCON", "SPEAK" };
string wordOneInput[] = { "eeeee" , "leali", "oello", "HELLO" };
string wordOneOutput[] = { "*E***" , "lE*L*", "*ELLO", "HELLO" };

string wordTwoInput[] = { "olovo" , "hooch", "noone", "conon",  "cocon"};
string wordTwoOutput[] = { "o*o**" , "*Ooc*", "nOo**", "CO*ON" , "COCON"};

string wordThreeInput[] = { "hello" , "enjoy", "clean", "smart",  "slept", "speak"};
string wordThreeOutput[] = { "*e***" , "e****", "**EA*", "S*a**" , "S*Ep*", "SPEAK"};

#else
string database[] = { "HELLO" , "COCON", "SPEAK" };
#endif

enum class GameEnd { ////////////////////////////////////////////////////////////////////
    Win,
    Defeat
};

enum class GameMenu {
    Exit,
    WordleOfTheDay,
    RandomWordle
};


//Основна частина:
// +функціонал вибору РАНДОМНОГО СЛОВА з бази даних
//+(наприклад std::string database[] = { “WORD1”, “WORD2”, “WORDN” }; або в будь - який інший спосіб);
//+Алгоритм порівняння вашого слова із загаданим словом :
//+Простий варіант : без врахування того, що літери можуть дублюватися
//+Підрахунок кількості спроб;
//+Завантажити код на гітхаб;

//ДОДАТКОВЕ ДОМАШНЄ ЗАВДАННЯ (3 бал)
/*
Додаткові бали(кількість додаткових балів буде відповідна кількості виеонаних підзавдань - це означає, що не обов’язково виконати все, для того, щоб отримати хоч якийсь бал) :

    Алгоритм порівняння вашого слова із загаданим словом :
+Складніший варіант : врахувати всі можливі випадки з дублікованими літерами у загаданому та відгаданому словах;
+Наявність слова у англійській мові перевіряти непотрібно(слово AAAAA - валідне слово)
-Функціонал СЛОВО ДНЯ без виходу з програми; Getting date time in simple fashion
-Функціонал запису / зчитування відгаданого СЛОВА ДНЯ з файлу для підтримки крос - запускового фунціоналу(при відгадуванні СЛОВА ДНЯ після перезапуску програми СЛОВО ДНЯ все ще не доступне до наступного дня)
-Зчитування слів з текстового файлу як бази даних.
Чистота коду, послідовність алгоритму, швидкодія та загальна ефективність алгоритму порівняння.
Завантажити свій алгоритм у сервіс
-Підготувати коротку супровідну документацію до гри на гітхабі(за допомогою README.md файлу, завантажених скріншотів, тощо) :
-приклади роботи скріншотами;
-принцип роботи алгоритму;
-покриті тест - кейси(всі, більшість, але не всі, лише прості кейси) з коментарем та скріншотами;
За необхідності прокоментувати окремі модулі програми(файли, функції, змінні, алгоритми, туду - шки(відомі проблемні місця, або частини для покращення в майбутньому), тощо)
*/


string getRandomWord() {
    //std::cout << size(database) << endl;
    const int GeneratingRange = size(database);
    const int GeneratedNum = std::rand() % GeneratingRange + 1;
    return database[std::rand() % GeneratingRange];
    //return database[0];
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

bool checkUpper(char str) {
    //int counter = 0;
        if (str >= 'A' && str <= 'Z') {
            return true;
        }
    return false;
}

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

#ifdef _DEBUG 
void testCase(string& maskOfSymbol, string TestCase) {
    if (maskOfSymbol != TestCase) {
        std::cout << "!!!ERROR!!!" << maskOfSymbol << " != " << TestCase << " !!!!!!!!!!!!!!!!!!!!!!!! " << endl;
        cin.get();
        cin.get();
    }
    else {
        std::cout << "expected  result: " << maskOfSymbol << " = " << TestCase << " Done!" << endl;
    }
}

int SwitchSearchWord = 0;
#endif


bool MainMenu(string& searchedWord, bool& isGameActive) {

    int menuSelect;
    std::cout << "Wordle of the day: 1" << endl;
    std::cout << "Random wordle: 2" << endl;
    std::cout << "Exit: 0" << endl;
    std::cin >> menuSelect;

    clearConsole();
    switch (static_cast<GameMenu>(menuSelect))
    {
    default:
        std::cout << "incorrect select: try again" << endl;
        return false;
    case GameMenu::WordleOfTheDay:
        std::cout << "Wordle of the day:" << endl;
        
        searchedWord = getRandomWord();
        isGameActive = true;
        return false;
    case GameMenu::RandomWordle:
        std::cout << "Random wordle:" << endl;
        searchedWord = getRandomWord();
        isGameActive = true;
        return false;
    case GameMenu::Exit:
        isGameActive = false;
        return true;
    }

}

void GameStart(string& searchedWord) {
    bool isGameActive = true;
    short int countOfTry;
    string word, maskOfSymbol = "*****", countMask;
    countOfTry = 0;
    while (isGameActive) {
        std::cout << endl;
        std::cout << "RESULT : " << maskOfSymbol << endl;
        maskOfSymbol = countMask = "*****";
        if (countOfTry < 9)
            countOfTry++;
        else {
            std::cout << std::endl;
            std::cout << "GAME OVER" << std::endl;
            std::cout << std::endl;
            std::cout << "Press Enter for return to menu..." << std::endl;
            cin.get();
            cin.get();
            isGameActive = false;
            break;
        }

        std::cout << "ENTER  : ";
#ifdef _DEBUG
        switch (SwitchSearchWord + 1)
        {
        default:
            std::cout << "Incorrect test case" << std::endl;
            break;
        case 1:
            word = wordOneInput[countOfTry - 1];
            break;
        case 2:
            word = wordTwoInput[countOfTry - 1];
            break;
        case 3:
            word = wordThreeInput[countOfTry - 1];
            break;
        }

        std::cout << word << endl;
#else
        std::cin >> word;
#endif
        toUppercase(word);
        if (validate(word)) {
            if (size(word) == 5) {
                for (int i = 0; i < 5; i++) {
                    if (searchedWord[i] == word[i]) {
                        countMask[i] = maskOfSymbol[i] = word[i];
                    }
                }
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (searchedWord[i] == word[j] && (maskOfSymbol[j] == '*' && countMask[i] == '*')) {
                            countMask[i] = maskOfSymbol[j] = tolower(word[j]);
                            j = 5;
                        }
                    }
                }
#ifdef _DEBUG
                switch (SwitchSearchWord + 1)
                {
                default:
                    std::cout << "!!!Incorrect test case!!!" << std::endl;
                    cin.get();
                    cin.get();
                    break;
                case 1:
                    testCase(maskOfSymbol, wordOneOutput[countOfTry - 1]);
                    break;
                case 2:
                    testCase(maskOfSymbol, wordTwoOutput[countOfTry - 1]);
                    break;
                case 3:
                    testCase(maskOfSymbol, wordThreeOutput[countOfTry - 1]);
                    break;
                }
#endif
                if (maskOfSymbol == searchedWord) {
                    std::cout << endl;
                    std::cout << "That's right!" << endl;
                    std::cout << "You made " << countOfTry << " tries" << endl;
                    std::cout << endl;
                    isGameActive = false;

                    std::cout << "Press Enter for return to menu..." << std::endl;
                    cin.get();
                    cin.get();
#ifdef _DEBUG
                    if (SwitchSearchWord < 2)
                        SwitchSearchWord++;
                    else {
                        clearConsole();
                        std::cout << "TEST COMPLETE" << std::endl;
                        std::cout << "TEST COMPLETE" << std::endl;
                        std::cout << "TEST COMPLETE" << std::endl;
                        cin.get();
                        cin.get();
                    }
#endif
                    clearConsole();

                }
            }
            else {
                std::cout << "Invalid count symbol in word" << endl;
#ifdef _DEBUG
                std::cout << word << endl;
#endif
            }
        }
        else {
            std::cout << "Invalid symbol" << endl;
        }
    }
}

void writeFile(const char* fileName, char lineToWrite) {
    std::fstream file;
    file.open(fileName, std::ios::out);

    if (!file) {
        std::cout << "File not created!\n";
    }
    else {/*
        //file<< database;
        for (const auto& word : lineToWrite) {

            file << word << std::endl;
        }*/
        file << lineToWrite;
    }
    file.close();
}


#include <sstream>

// Existing code...

void writeFile(const char* fileName, const std::string& todayDate) {
    std::fstream file;
    file.open(fileName, std::ios::out);

    if (!file) {
        std::cout << "File not created!\n";
    }
    else {
        file << todayDate;
        file << " // ";
    }
    file.close();
}

int main()
{
    // Existing code...
    std::cout << "Дарова ";
    std::time_t now = std::time(nullptr);
    std::tm localTime;
    localtime_s(&localTime, &now);
    std::cout << "Date: " << std::put_time(&localTime, "%Y %m %d") << std::endl;

    std::ostringstream oss;
    oss << std::put_time(&localTime, "%Y %m %d");
    writeFile("NewFile.txt", oss.str());

    std::srand((unsigned int)time(NULL));
    string searchedWord;
    bool Exit = false, isGameActive = false;
    while (!Exit) {     
#ifdef _DEBUG
        if (SwitchSearchWord == 2)
            Exit = true;
        searchedWord = database[SwitchSearchWord];
        GameStart(searchedWord);
#else
        Exit = MainMenu(searchedWord, isGameActive);
        GameStart(searchedWord);  
#endif      
    }
}

