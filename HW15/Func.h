#pragma once
#include "Student.h"

int bar(int taskCounter);

int averageRating(const Student& student);

void printInfo(const Student& student);

void printInfo(const Student studentArray[], int totalStudents = 1);

void printInfoV(const std::vector<Student>& studentArray, int totalStudents = 1);

Student* BestStudent(Student studentArray[], int totalStudents);

int TheBestStudents(Student studentArray[], int totalStudents = 1, int N = 75);

bool CompareByMarks(const Student& st1, const Student& st2);

void getBestStudents(Student* inStudents, unsigned inSize, std::vector<Student>& outStudents, unsigned& outSize, unsigned percent);