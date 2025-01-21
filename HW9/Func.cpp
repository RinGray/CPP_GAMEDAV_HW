#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

int bar(int taskCounter) {
	std::cout << setw(25) << std::setfill('-') << " (" << taskCounter << ") " << setw(25) << "" << std::endl;
	return 0;
}

void translateArray(int numbers[], int size) {
	for (int i = 0; i < size; i++) {
		if (numbers[i] > 0) {
			numbers[i] *= 2;
		}
		else {
			numbers[i] = 0;
		}
	}
}

void toUppercase(char str[]) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= 32;
		}
	}
}


bool isPalindrom(const char str[], int size) {
	for (int i = 0; i <= (sizeof(str[size]) / 2); i++) {
		if (str[i] != str[size - i - 1]) {
			return false;
		}
		else {
			return true;
		}
	}
}

int returnSize(const char str[]) {
	int size = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		size++;
	}
	return size;
}

void parseStringLetters(const char str[], int& vowelsCount, int& constonantsCount) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'Y') {
			vowelsCount++;
		}
		else {
			constonantsCount++;
		}
	}

}

bool isEqual(const char str1[], const char str2[]) {
	if (returnSize(str1) == returnSize(str2)) {// need check if string #2 longer
		for (int i = 0; str1[i] != '\0'; i++) {
			if (str1[i] != str2[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}
