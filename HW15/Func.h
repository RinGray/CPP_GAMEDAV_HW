#pragma once
#include "Student.h"

int bar(int taskCounter);

int averageRating(Student& student);

void printInfo(Student& student);

void printInfo(Student studentArray[], int totalStudents = 1);

Student* BestStudent(Student studentArray[], int totalStudents);

int TheBestStudents(Student studentArray[], int totalStudents = 1, int N = 75);

bool CompareByMarks(const Student& st1, const Student& st2);


void getBestStudents(Student* inStudents, unsigned inSize, Student* outStudents, unsigned& outSize, unsigned percent);