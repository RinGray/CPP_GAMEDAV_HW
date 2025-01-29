#pragma once
#include "SortingDirection.h"


int bar(int taskCounter);

void get_random_array(int* arr, int column, int rows, bool shafle = true, bool reverse = false);

void printArray(int* arr, int column, int rows);

void bubbleSort(int arr[], int rows, int column = 0, SortingDirection direction = SortingDirection::ByRows);

void sort(int* arr, int column, int rows, SortingDirection direction = SortingDirection::ByRows);