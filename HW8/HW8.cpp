
#include <iostream>
#include <iomanip>
#include <cctype>

#include "Func.h"
#include "Recursion.h"
using namespace std;


int main()
{
    int taskCounter = 0;
    //Функція приймає число — кількість чисел для вводу юзеру. 
    // Порахувати кількість введених юзером додатних чисел, від’ємних та 0. 
    // Вивести у консоль ці лічильники; 
    // Example input : 5  1 2 - 2 0 0 Output : Positive : 2, negative : 1, zeroes : 2
    // (1 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);

    int n, positive = 0, negative = 0, zero = 0, number = 0;
	std::cout << "Enter quantity: ";
	std::cin >> n;
    counter(n, positive, negative, zero, number);
    std::cout << "Positive: " << positive << ", negative: " << negative << ", zero: " << zero << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    //cin.get();
    //cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1)

     // Функція int factorial(int count) приймає число - count! 
     // Написати функції, які обраховують значення факторіала:
     // за допомогою цикла;
     // з використанням рекурсії;
    // (2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int F;
	F = readAndValidate();
    std::cout << std::endl;
    std::cout << "Func:" << FuncFactorial(F) <<std::endl;
    std::cout << std::endl;
    std::cout << "Recursion:" << RecursFactorial(F) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 2)

    //Функції обрахунку площі та довжини кола: 
    // float getArea(float radius), 
    // float getCircumference(float radius);
    // (3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);

    float r;
    std::cout << "enter radius:" << std::endl;
    std::cin >> r;
    std::cout << std::endl;
    std::cout << "area: " << getArea(r) << std::endl;
    std::cout << "length: " << getCircumference(r) << std::endl;


    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 3)

    // (4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);

    int N;
    std::cout << "Enter natural namber: ";
    std::cin >> N;
    std::cout << std::endl;
	// a.
    std::cout << "Func invert: " << std::endl;
    printNaturalNumbersFuncInverse(N);
    std::cout << std::endl;
	// b.
    std::cout << "Func normal: " << std::endl;
    printNaturalNumbersFunc(N);
    std::cout << std::endl;
    // c.
    std::cout << "Recursion invert: " << std::endl;
    printNaturalNumbersInverse(N);
    std::cout << std::endl;
    // d.
    std::cout << "Recursion normal: " << std::endl;
    printNaturalNumbers(N);

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 4)
}

