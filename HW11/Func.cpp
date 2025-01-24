#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>
#include <random>
#include "SortingDirection.h"

using namespace std;




int bar(int taskCounter) {
    std::cout << setw(25) << std::setfill('-') << " (" << taskCounter << ") " << setw(25) << "" << std::endl;
    return 0;
}

void get_random_array(int* arr, int column, int rows, bool shafle = true, bool reverse = false) {
    int maxNumber = (column) * (rows);
    vector<int> array_for_gen(maxNumber);
    if (reverse) {
        for (int i = 0; i < maxNumber; i++) {
            array_for_gen[i] = maxNumber - i;
        }
    }
    else
        for (int i = 0; i < maxNumber; i++) {
            array_for_gen[i] = i + 1;
        }
    if (shafle) {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(array_for_gen.begin(), array_for_gen.end(), g);
    }

    for (int i = 0; i < column; i++) {
        for (int j = 0; j < rows; j++) {
            arr[i * rows + j] = array_for_gen[i * rows + j];
        }
    }
}

void printArray(int* arr, int column, int rows) {
    for (int i = 0; i < column; i++) {
        for (int j = 0; j < rows; j++) {

            if (arr[i * rows + j] < 10) {
                std::cout << arr[i * rows + j] << "   ";
            }
            else if (arr[i * rows + j] > 99) {
                std::cout << arr[i * rows + j] << " ";

            }
            else {
                std::cout << arr[i * rows + j] << "  ";
            }
        }
        std::cout << std::endl;
        if (rows > 50) {
            std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl; // just for better view in console if row > 50
        }
    }
}

bool find(int* arr, int column, int rows, int toFind) {
    for (int i = 0; i < column; i++) {
        for (int j = 0; j < rows; j++) {
            if (arr[i * rows + j] == toFind) {
                return true;
            }
        }
    }
    return false;
}

bool isSorted(const int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (*(arr + i) > *(arr + i + 1)) {
            return false;
        }
    }
    return true;
}

void printArrayLikeInTask3(int* arr, int column, int rows) {
    for (int i = column - 1; i >= 0; i--) {
        for (int j = 0; j < rows; j++) {
            std::cout << arr[i + j * rows] << " ";
        }
    }
}

void printArrayLikeInTask4(int* arr, int column, int rows) {
    int i = column - 1, j = 0;
    while (true) {
        if (j == 0) {
            std::cout << arr[i * rows + j] << " ";
            while (j < rows - 1) {

                j++;
                std::cout << arr[i * rows + j] << " ";
            }
        }
        else {
            std::cout << arr[i * rows + j] << " ";
            while (j > 0) {

                j--;
                std::cout << arr[i * rows + j] << " ";
            }
        }
        if (column % 2 == 1) {
            if (i == 0 && j == rows - 1) {
                break;
            }
        }
        else {
            if (i == 0 && j == 0) {
                break;
            }
        }
        i--;
    }
}

bool isSorted(const int* arr, int size, SortingDirection direction) {
    if (direction == SortingDirection::ascending) {
        for (int i = 0; i < size - 1; i++) {
            if (*(arr + i) > *(arr + i + 1)) {
                return false;
            }
        }
        return true;
    }
    if (direction == SortingDirection::descending) {
        for (int i = 0; i < size - 1; i++) {
            if (*(arr + i) < *(arr + i + 1)) {
                return false;
            }
        }
        return true;
    }

}