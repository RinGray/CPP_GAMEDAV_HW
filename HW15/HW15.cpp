#include <iostream>
#include <iomanip>
#include <cctype>
#include "Func.h"
#include "Student.h"
using namespace std;

int main()
{
    int taskCounter = 0;
    // Створити структуру Student з полями name та marks[4]; 
    // написати функцію, що приймає студента як вхідний параметр та повертає середню оцінку по предметам студента;
    // (1 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    Student student1 = { "Anton", 50, 60, 70, 80 };
	printInfo(student1);
	std::cout << "Average rating: " << averageRating(student1) << std::endl;
    

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1)
    
    // створити масив of Student;
    // (2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
	Student students[3] = { {"Anton", 50, 60, 70, 80}, {"Vasyl", 60, 70, 30, 90}, {"Ivan", 70, 20, 90, 100} };
    printInfo(students, 3);


    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 2)

    //  функція, що повертає посилання(pointer) на найуспішнішого студента у масиві;
    // (3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    Student* bestStudent = BestStudent(students, 3);
    std::cout << "Pointer on best student:    " << bestStudent << std::endl;
    std::cout << "Best student: " << bestStudent->name << std::endl;


    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 3)

    // функція, яка підраховує кількість студентів, середня оцінка яких більше ніж вхідний параметр N;
    // (4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    std::cout << "Count of the best students, who have averaged more than 65: " << TheBestStudents(students, 3, 65) << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 4)

}
