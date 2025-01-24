#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>
#include <random>

#include "Func.h"
using namespace std;



int main()
{
    int taskCounter = 0;
    // Реалізувати функцію лінійного пошуку в двовимірному масиві;
    // bool find(int arr_2d[ROWS][COLUMNS], int toFind)
    // (1 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
	int arr[2][100];
	get_random_array(&arr[0][0], 2, 100);

	printArray(&arr[0][0], 2, 100);

	int toFind;

	std::cout << "Enter number to find: ";
	std::cin >> toFind;

	find(&arr[0][0], 2, 100, toFind) ? std::cout << "Element " << toFind << " found in array" << std::endl : std::cout << "Element " << toFind << " not found in array" << std::endl;

    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1)

    // Функція bool isSorted(const int* arr, int size) яка перевіряє, чи заданий масив посортований за зростанням;
    // (2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);

	int arr1[10], arr2[10];
	get_random_array(arr1, 1, 10, false, false);
	get_random_array(arr2, 1, 10);
	printArray(arr1, 1, 10);
	printArray(arr2, 1, 10);
	isSorted(arr1,10) ? std::cout << "Array 1 is sorted" << std::endl : std::cout << "Array 1 is not sorted" << std::endl;
    isSorted(arr2, 10) ? std::cout << "Array 2 is sorted" << std::endl : std::cout << "Array 2 is not sorted" << std::endl;

    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 2)

    // Написати функції двовимірного масива зазначеним способом
    // (3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);

	int arr3[3][3];
	get_random_array(&arr3[0][0], 3, 3, false, false);

    std::cout << "Prin array: " << std::endl;
    std::cout << std::endl;
	printArray(&arr3[0][0], 3, 3);
    
    std::cout << std::endl;
    std::cout << "Prin array like in task" << std::endl;
    std::cout << std::endl;
	printArrayLikeInTask3(&arr3[0][0], 3, 3);

    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 3)

}
 