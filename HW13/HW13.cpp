
#include <iostream>
#include "Func.h"
using namespace std; 

int main()
{
#ifdef _DEBUG
    int SwitchSearchWord = 0;
    string database[] = { "HELLO" , "COCON", "SPEAK" };
#endif
    std::srand((unsigned int)time(NULL));
    string searchedWord;
    bool Exit = false, isGameActive = false;
    while (!Exit) {     
#ifdef _DEBUG
        if (SwitchSearchWord == 2)
            Exit = true;
        searchedWord = database[SwitchSearchWord];
        GameStart(searchedWord);
        SwitchSearchWord++;
#else
        Exit = MainMenu(searchedWord, isGameActive);
        if (isGameActive)
            GameStart(searchedWord);

            
#endif      
    }
}

