#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>
#include <random>

#include "Func.h"
#include "SortingDirection.h"

using namespace std;


int main()
{
    
    int taskCounter = 0;
    // Реалізувати void bubbleSort(int arr[], int size) для сортування вхідного масиву алгоритмом сортування бульбашкою;
    // (1 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int arr[10];
    get_random_array(&arr[0], 1, 10);
    std::cout << "Random array" << std::endl;
    printArray(&arr[0], 1, 10);
    bubbleSort(arr, 10);
    std::cout << std::endl;
    std::cout << "Array after sort" << std::endl;
    printArray(&arr[0], 1, 10);

    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1)
    
    // Відсортувати двовимірний масив по рядкам: void sort(int arr[ROWS][COLUMNS], SortingDirection); 
    // де SortingDirection - enum class SortingDirection{ByRows, byColumn}; 
    // Використовуючи будь-які алгоритми сортування (можна використовувати реалізації з лекції та з бібліотеки <algorithm>)
    // (2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int arr2[5][10];
    get_random_array(&arr2[0][0], 5, 10);
    std::cout << "Random array" << std::endl;
    printArray(&arr2[0][0], 5, 10);
    std::cout << std::endl;
    sort(&arr2[0][0], 5, 10);
    std::cout << "Array after sort" << std::endl;
    printArray(&arr2[0][0], 5, 10);

    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 2)
    
    // Відсортувати двовимірний масив по стовпцям: void sort(int arr[ROWS][COLUMNS], SortingDirection); 
    // де SortingDirection - enum class SortingDirection{ByRows, byColumn}; 
    // Використовуючи будь-які алгоритми сортування (можна використовувати реалізації з лекції та з бібліотеки <algorithm>)
    // (2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int arr3[10][5];
    get_random_array(&arr3[0][0], 10, 5);
    std::cout << "Random array" << std::endl;
    printArray(&arr3[0][0], 10, 5);
    std::cout << std::endl;

    sort(&arr3[0][0], 10, 5, SortingDirection::byColumn);
    std::cout << "Array after sort" << std::endl;
    printArray(&arr3[0][0], 10, 5);

    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 2)
}
    