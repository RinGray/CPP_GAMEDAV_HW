#pragma once
#include "Student.h"

int bar(int taskCounter);

int averageRating(Student& student);

void printInfo(Student& student);

void printInfo(Student studentArray[], int totalStudents = 1);

Student* BestStudent(Student studentArray[], int totalStudents);

int TheBestStudents(Student studentArray[], int totalStudents = 1, int N = 75);
