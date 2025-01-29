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


int RecursFactorial(int F, int fact = 1, int i = 2)
{
	if (i <= F) {
		fact = fact * i;
		RecursFactorial(F, fact, ++i);
	}
	else {
		return fact;
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