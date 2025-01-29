#include <iostream>
using namespace std;

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


void PrintRecursFactorial(int F, int fact = 1, int i = 1)
{
	if (i <= F) {
		fact = fact * i;
		std::cout << "F" << F << " = " << fact << ", " << endl;
		PrintRecursFactorial(F, fact, ++i);
	}
	else {
		return;
	}
}

void printNaturalNumbers(int count) {
	if (count > 0) {
		printNaturalNumbers(--count);
		std::cout << count + 1 << " ";
	}
}

void printNaturalNumbersInverse(int count) {
	if (count > 0) {
		std::cout << count << " ";
		printNaturalNumbersInverse(--count);

	}
}