#include <iostream>
#include <iomanip>
#include <cctype>
#include "Func.h"
using namespace std;

int main()
{
    int taskCounter = 0;
    // Користувач зчитує з клавіатури масив, розмір 10. 
    // Написати функцію, яка додатні елементи масиву множить на 2, від’ємні робить 0. 
    // void translateArray(int numbers[], int size); Вивести масив у консоль.
    // (1 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);

    int numbers[10];
    std::cout << "Enter 10 numbers;" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "Enter number " << i + 1 << ": ";
        std::cin >> numbers[i];
    }
    translateArray(numbers, 10);
    for (int i = 0; i < 10; i++) {
        std::cout << numbers[i] << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1)

    // Зчитати рядок з консолі. Функція, яка перетворює усі символи латиниці у верхній регістр (без використання std функцій); 
    // void toUppercase(char str[]);
    // Input: aBBcce% . - ab
    // Output : ABBCCE % . - AB
    // (2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    char str[100];
    std::cout << "Enter string: ";
    std::cin.getline(str, 100);
    toUppercase(str);
    std::cout << str << std::endl;


    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 2)

    // ) Функція, яка перевіряє чи введений рядок паліндром 
    // (Паліндром - слово, число, набір символів, що однаково читається в обох напрямках: зліва направо та справа наліво)
    // bool isPalindrom(const char str[]);
    // aba -> true; tenet -> true; cbbc -> true; teneT -> false; abcd -> false; abca -> false
    // (3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    char strPal[100];
    std::cout << "Enter string: ";
    std::cin.getline(strPal, 100);
    toUppercase(strPal); // optional?
    if (isPalindrom(strPal, returnSize(strPal))) {
        std::cout << "It's palindrom" << std::endl;
    }
    else {
        std::cout << "Not a palindrom" << std::endl;
    }


    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 3)

    // Функція, яка підраховує кількість голосних та приголосних у рядку:
    // void parseStringLetters(const char[] str, int& vowelsCount, int& constonantsCount);
    // (4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int vowelsCount = 0, constonantsCount = 0;
    char strVowelsCounter[100];
    std::cout << "Enter string: ";
    std::cin.getline(strVowelsCounter, 100);
    toUppercase(strVowelsCounter); // optional?

    parseStringLetters(strVowelsCounter, vowelsCount, constonantsCount);

    std::cout << "In string vowels: " << vowelsCount << ", constonants: " << constonantsCount << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 4)

    //Функція для порівняння двох рядків без використання вбудованих бібліотек:
    // bool isEqual(const char str1[], const char str2[]);
    // ++++++++++++++++++++++++++++++++++++++++++++++++++++++ 5)

    bar(++taskCounter);
    char string1[100], string2[100];
    std::cout << "Enter string number one: ";
    std::cin.getline(string1, 100);
    std::cout << std::endl;
    std::cout << "Enter string number two: ";
    std::cin.getline(string2, 100);
    std::cout << std::endl;

    if (isEqual(string1, string2)) {
        std::cout << "Strings are equal" << std::endl;
    }
    else {
        std::cout << "Strings are not equal" << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 5)
}
