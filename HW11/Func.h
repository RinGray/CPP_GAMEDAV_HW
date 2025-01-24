#pragma once


int bar(int taskCounter);

void get_random_array(int* arr, int collumn, int rows, bool shafle = true, bool reverse = false);

void printArray(int* arr, int collumn, int rows);

bool find(int* arr, int collumn, int rows, int toFind);

bool isSorted(const int* arr, int size);

void printArrayLikeInTask3(int* arr, int collumn, int rows);
