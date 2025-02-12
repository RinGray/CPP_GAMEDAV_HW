#include <iostream>
#include <fstream>


#include <iomanip>
#include <cctype>
#include <vector>
#include <random>
#include <sstream>
#include <string>
using namespace std;

int SwitchSearchWordF = 0;

enum class GameMenu {
    Exit,
    WordleOfTheDay,
    RandomWordle
};


void writeFile(const char* fileName, const std::string& todayDate, const std::string& word) {
    std::fstream file;
    file.open(fileName, std::ios::out);

    if (!file) {
        std::cout << "File not created!\n";
    }
    else {
        file << todayDate;
        file << "/";
        file << word;
        file << "\n";
    }
    file.close();
}

void readFile(const char* fileName, string& data)
{
    std::fstream file;
    file.open(fileName, std::ios::in);

    if (!file)
    {
        std::cout << "File not found!\n";
    }
    else
    {
        const unsigned int MaxLineSize = 256;
        char line[MaxLineSize]{};

        char ch = '\0';

        file >> std::noskipws;
        while (!file.eof())
        {

            file.getline(line, MaxLineSize, '\n');
            data = data + line + '\n';
        }
    }

    file.close();
}

void removeWordFromFile(const std::string& filename, const std::string& wordToRemove) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "File not found!\n" << std::endl;
        return;
    }

    std::ostringstream buffer;
    std::string line, word;

    while (std::getline(file, line)) {
        std::istringstream stream(line);
        std::string newLine;

        while (stream >> word) {
            if (word != wordToRemove) {
                if (!newLine.empty()) newLine += " ";
                newLine += word;
            }
        }

        buffer << newLine << "\n";
    }

    file.close();

    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "File not found!\n" << std::endl;
        return;
    }

    outFile << buffer.str();
    outFile.close();
}



#ifdef _DEBUG
string wordOneInput[] = { "eeeee" , "leali", "oello", "HELLO" };
string wordOneOutput[] = { "*E***" , "lE*L*", "*ELLO", "HELLO" };

string wordTwoInput[] = { "olovo" , "hooch", "noone", "conon",  "cocon" };
string wordTwoOutput[] = { "o*o**" , "*Ooc*", "nOo**", "CO*ON" , "COCON" };

string wordThreeInput[] = { "hello" , "enjoy", "clean", "smart",  "slept", "speak" };
string wordThreeOutput[] = { "*e***" , "e****", "**EA*", "S*a**" , "S*Ep*", "SPEAK" };
#endif

std::string getRandomWord(const std::string& input) {
    std::istringstream stream(input);
    std::vector<std::string> words;
    std::string word;
    while (stream >> word) {
        words.push_back(word);
    }

    if (words.empty()) return ""; // If no words, return an empty string

    // Generate a random index
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, words.size() - 1);

    return words[dist(gen)];
}

void toUpperCase(string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}

bool validate(string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] < 'A' || str[i] > 'Z') {
            return false;
        }
    }
    return true;
}

bool checkUpper(char str) {
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

#endif

bool checkDate(const std::string& dateFromFile) {
    string str;
    readFile("Save.dat", str);
    std::stringstream ss(str);
    std::stringstream firstWord;
    std::string firstWordStr;
    std::getline(ss, firstWordStr, '/');
    firstWord << firstWordStr;
    if (firstWord.str() == dateFromFile) {
        return true;
    }
    return false;
}

std::ostringstream oss() {
    std::time_t now = std::time(nullptr);
    std::tm localTime;
    localtime_s(&localTime, &now);
    std::cout << "Date: " << std::put_time(&localTime, "%Y %m %d") << std::endl;
    std::ostringstream oss;
    oss << std::put_time(&localTime, "%Y %m %d");
    return oss;
}

bool MainMenu(string& searchedWord, bool& isGameActive) {



    string WordleData;
    int menuSelect;
    std::cout << "Wordle of the day: 1" << endl;
    std::cout << "Random wordle: 2" << endl;
    std::cout << "Exit: 0" << endl;
    std::cin >> menuSelect;



    clearConsole();
    std::ostringstream dateStream = oss();



    switch (static_cast<GameMenu>(menuSelect))
    {
    default:
        std::cout << "incorrect select: try again" << endl;
        return false;
    case GameMenu::WordleOfTheDay:

        if (!checkDate(dateStream.str())) {
            std::cout << "Wordle of the day:" << endl;
            readFile("WordleOfTheDayData.dat", WordleData);
            searchedWord = getRandomWord(WordleData);
            writeFile("Save.dat", dateStream.str(), searchedWord);
            removeWordFromFile("WordleOfTheDayData.dat", searchedWord);
            isGameActive = true;
            return false;
        }
        else {
            std::cout << "Today you already play. Come back tommorow!" << endl;
            cin.get();
            cin.get();
            isGameActive = false;
            return false;
        }

    case GameMenu::RandomWordle:
        std::cout << "Random wordle:" << endl;
        readFile("WordleData.dat", WordleData);
        searchedWord = getRandomWord(WordleData);

        isGameActive = true;
        return false;
    case GameMenu::Exit:
        isGameActive = false;
        return true;
    }

}

void GameStart(string& searchedWord) {
    toUpperCase(searchedWord);
    bool isGameActive = true;
    short int countOfTry;
    string word, maskOfSymbol = "*****", countMask;
    countOfTry = 1;
    while (isGameActive) {
        std::cout << endl;
        std::cout << "RESULT : " << maskOfSymbol << endl;
        maskOfSymbol = countMask = "*****";


        std::cout << "ENTER  : ";
#ifdef _DEBUG
        switch (SwitchSearchWordF + 1)
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
        toUpperCase(word);
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
                switch (SwitchSearchWordF + 1)
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
                    if (SwitchSearchWordF < 2)
                        SwitchSearchWordF++;
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