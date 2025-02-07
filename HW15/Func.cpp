#include <iostream>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include "Student.h"
using namespace std;


int bar(int taskCounter) {
    std::cout << setw(25) << std::setfill('-') << " (" << taskCounter << ") " << setw(25) << "" << std::endl;
    return 0;
}

int averageRating(Student& student) {
    if (student.name == nullptr || student.name == "") {
        return 0;
    }
    else {
        int avarage = 0;
        for (int i = 0; i < static_cast<int>(size(student.marks)); i++) {
            avarage += student.marks[i];
        }
        avarage /= static_cast<int>(size(student.marks));
        return avarage;
    }
}

void printInfo(Student& student) {
    if (student.name == nullptr || student.name == "") {
        std::cout << "Student is not defined" << std::endl;
        return;
    }
    else {
        std::cout << "Student: " << student.name << ", mark1: " << student.marks[0] << ", mark2: " << student.marks[1] << ", mark3: " << student.marks[2]
            << ", mark4: " << student.marks[3] << endl;
        std::cout << "Count marks : " << size(student.marks) << std::endl;
    }
}

void printInfo(Student studentArray[], int totalStudents = 1) {
    for (int i = 0; i < totalStudents; i++) {
        if (studentArray[i].name == nullptr || studentArray[i].name == "") {
            std::cout << "Student is not defined" << std::endl;
        }
        else {
            std::cout << "Student: " << studentArray[i].name << std::endl;
            for (int j = 0; j < std::size(studentArray[i].marks); j++) {
                if (studentArray[i].marks[j] < 0 || studentArray[i].marks[j] > 100) {
                    std::cout << "mark" << j + 1 << ": " << studentArray[i].marks[j] << " is not correct" << std::endl;
                }
                else {
                    std::cout << "mark" << j + 1 << ": " << studentArray[i].marks[j] << std::endl;
                }
            }
            std::cout << "Average rating: " << averageRating(studentArray[i]) << std::endl;
            std::cout << std::endl;

        }
    }
    std::cout << "Total Students : " << totalStudents << std::endl;
}

Student* BestStudent(Student studentArray[], int totalStudents) {
    int bestAvarageMark = averageRating(studentArray[0]), bestStudyPointer = 0;
    for (int i = 1; i < totalStudents; i++) {
        if (studentArray[i].name != nullptr || studentArray[i].name != "") {
            if (averageRating(studentArray[i]) > bestAvarageMark) {
                bestAvarageMark = averageRating(studentArray[i]);
                bestStudyPointer = i;
            }
        }
    }
    return &studentArray[bestStudyPointer];
}

int TheBestStudents(Student studentArray[], int totalStudents = 1, int N = 75) {
    int total = 0;
    for (int i = 0; i < totalStudents; i++) {
        if (studentArray[i].name != nullptr || studentArray[i].name != "") {
            if (averageRating(studentArray[i]) >= N) {
                total++;
            }
        }
    }
    return total;
}

bool CompareByMarks(const Student& st1, const Student& st2) {
    return averageRating(const_cast<Student&>(st1)) > averageRating(const_cast<Student&>(st2));
}


void getBestStudents(Student* inStudents, unsigned inSize, Student* outStudents, unsigned& outSize, unsigned percent) {
    outSize = percent * inSize / 100;
    for (unsigned i = 0; i < inSize; i++) {
        outStudents[i] = inStudents[i];
    }
    std::sort(outStudents, outStudents + inSize, CompareByMarks);
}
