#include <iostream>
#include <iomanip>
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

void bubbleSort(int arr[], int rows, int column = 0, SortingDirection direction = SortingDirection::ByRows) {
    int swap;
    
    if (direction == SortingDirection::ByRows) {
        rows = rows - 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < rows - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = swap;
                }
            }
        }
    }
    else {
        for (int i = 0; i < column; i++) {
            for (int j = 0; j < column - i-1; j++) {
                if (arr[j * rows] > arr[(j + 1) * rows]) {
                    swap = arr[j * rows];
                    arr[j * rows] = arr[(j + 1) * rows];
                    arr[(j + 1) * rows] = swap;
                }
            }
        }
    }
}

void sort(int* arr, int column, int rows, SortingDirection direction = SortingDirection::ByRows) {
    if (direction == SortingDirection::ByRows) {
        for (int i = 1; i < column; i++) {
            bubbleSort(&arr[i * rows], rows);
        }
    }
    else {
        for (int i = 0; i < rows; i++) {
            bubbleSort(&arr[i], rows, column, SortingDirection::byColumn);
        }
    }
}