#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;


namespace myPi {
    constexpr double pi = 3.141592653589793;
}
using namespace myPi;



int bar(int taskCounter) {
    std::cout << setw(25) << std::setfill('-') << " (" << taskCounter << ") " << setw(25) << "" << std::endl;
    return 0;
}



void Validate(int& F) {
    std::cout << "Enter factorial: ";
    while (true) {

        std::cin >> F;
        std::cout << std::endl;
        if (F > 0) {
            break;
        }
        else
        {
            std::cout << "Must be positive, try again: ";
            continue;
        }
    }
}

void funcFactorial(int F) {// source from HW5.cpp

    int fact = 1;
    for (int i = 1; i <= F; i++) {
        fact = fact * i;
        std::cout << "F" << i << " = " << fact << ", " << endl;
    }
}




float getArea(float radius) {
    return static_cast<float>(pi) * radius * radius;
}
float getCircumference(float radius) {
    return 2 * static_cast<float>(pi) * radius;
}



void printNaturalNumbersFuncInverse(int count) {
    while (count > 0)
    {
        std::cout << count << " ";
        count--;
    }
}

void printNaturalNumbersFunc(int count) {
    for (int i = 1; i <= count; i++) {
        std::cout << i << " ";
    }
}