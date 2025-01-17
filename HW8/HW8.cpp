
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

void counter(int& n, int& positive, int& negative, int& zero, int& number)
{
    if (n > 0) {
        std::cout << "Enter number # " << n << " for calculate: ";
        std::cin >> number;
		if (number > 0) {
			positive++;
		}
		else if (number < 0) {
			negative++;
		}
		else {
			zero++;
		}
		counter(--n, positive, negative, zero, number);
    }
    
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


void recursFactorial(int F, int fact = 1, int i = 1)
{
	if (i<= F) {
		fact = fact * i;
		std::cout << "F" << F << " = " << fact << ", " << endl;
        recursFactorial(F, fact, ++i);
	}
	else {
		return;
	}
}

float getArea(float radius) {
	return pi * radius * radius;
}
float getCircumference(float radius) {
	return 2 * pi * radius;
}

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
	Validate(F);
    std::cout << std::endl;
    std::cout << "Func:" << std::endl;
	funcFactorial(F);
    std::cout << std::endl;
    std::cout << "Recursion:" << std::endl;
	recursFactorial(F);

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

}

