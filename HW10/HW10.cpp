#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;


int bar(int taskCounter) {
    std::cout << setw(25) << std::setfill('-') << " (" << taskCounter << ") " << setw(25) << "" << std::endl;
    return 0;
}

void swap(int& a, int& b) {
	int k = a;
	a = b;
    b = k;
}

void swap(int* a, int* b) {
	int k = *a;
	*a = *b;
	*b = k;
}

bool find(const int* arr, int size, int elem) {
	for (int i = 0; i < size; i++) {
		if (*(arr + i) == elem) {
			return true;
		}
	}
	return false;
}

bool calculateSum(const double* arr, int arrSize, double& sum) {
	if (arrSize > 0) {
		for (int i = 0; i < arrSize; i++) {
			sum += *(arr + i);
		}
		return true;
	}
	return false;
}


int main()
{
    int taskCounter = 0;
    // Реалізувати функції void swap(int& a, int& b); void swap(int* a, int* b); 
    // які приймають як вхідні параметри дві int змінні та змінюють їх місцями двома способами: з використанням вказівників та посилань.
    // (1 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int a = 10, b = 20;
    std::cout << "Before swap: " << std::endl;
    cout << "a = " << a << " b = " << b << endl;
    std::cout << "After swap: " << std::endl;
    swap(a, b);
    cout << "a = " << a << " b = " << b << endl;
    std::cout << "Swap again: " << std::endl;
    swap(&a, &b);
    cout << "a = " << a << " b = " << b << endl;

    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1)
    
    // Реалізувати функцію bool find(const int* arr, int size, int elem), яка повертає true, якщо число знайдено у масиві.
    // Зробити задачу з використанням арифметики над вказівниками(без використання оператора доступу до елементів масиву[]).
    // (2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, elem;
    std::cout << "Enter number: ";
    std::cin>>elem;
    find(arr, 10, elem) ? std::cout << "Element " << elem << " found in array" << std::endl : std::cout << "Element " << elem << " not found in array" << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 2)

    // Створити функцію bool calculateSum(const double* arr, int arrSize, double& sum); 
    // яка записує у змінну sum суму всіх елементів довільного масиву, повертає true, якщо розмір масиву > 0. 
    // (3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    double arr1[10] = { 5, 10, 15, 59, 33.3, 77, -90, 5.1, -10.1, 200 }, sum = 0;
	calculateSum(arr1, 10, sum) ? std::cout << "Sum of array elements: " << sum << std::endl : std::cout << "Array is empty" << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 3)
}
