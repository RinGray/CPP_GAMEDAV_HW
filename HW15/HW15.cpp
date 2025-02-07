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
    Student students[10] = { {"Anton", 50, 60, 70, 80}, {"Vasyl", 60, 70, 30, 90}, {"Ivan", 70, 20, 90, 100}, {"Andrey", 7, 2, 9, 10}, {"Alexander", 50, 30, 20, 25}, {"Anna", 40, 55, 57, 67},  
        {"Dmitriy", 80, 90, 50, 70},  {"Herman", 60, 70, 66, 77}, {"Olha", 11, 22, 88, 99}, {"Gkeb", 59, 55, 57, 65} };
    printInfo(students, 10);


    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 2)

    //  функція, що повертає посилання(pointer) на найуспішнішого студента у масиві;
    // (3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    Student* bestStudent = BestStudent(students, 10);
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
    std::cout << "Count of the best students, who have averaged more than 65: " << TheBestStudents(students, 10, 65) << std::endl;


    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 4)

    // 5) функція, яка повертає масив з N% найуспішніших студентів:
    // void getBestStudents(Student * inStudents, unsigned inSize, Student * outStudents, unsigned& outSize, unsigned percent); 
    // 6) функція, що сортує студентів у масиві по критерію середньої оцінки;
    // (5/6 ++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    std::cout << "Best 30%: " << std::endl;
    std::cout << std::endl;

    unsigned N=30, outSize;
    Student* studentOut = new Student[10];
    getBestStudents(students,10, studentOut, outSize, N);
    printInfo(studentOut, outSize);

    delete[] studentOut;


    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++ 5/6)
}
