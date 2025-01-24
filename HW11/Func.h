#pragma once
#include "SortingDirection.h"


int bar(int taskCounter);

void get_random_array(int* arr, int column, int rows, bool shafle = true, bool reverse = false);

void printArray(int* arr, int column, int rows);

bool find(int* arr, int column, int rows, int toFind);

bool isSorted(const int* arr, int size);

void printArrayLikeInTask3(int* arr, int column, int rows);

void printArrayLikeInTask4(int* arr, int column, int rows);

bool isSorted(const int* arr, int size, SortingDirection direction);