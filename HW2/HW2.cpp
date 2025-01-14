// HW2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// 
//#include <numeric>
//#include <numbers>

#include <iostream>
#include <iomanip>
using namespace std;

enum WeekDay
{
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6,
    Sunday = 7
};
int bar(int taskCounter) {
    std::cout << setw(25) << std::setfill('-') << " (" << taskCounter << ") " << setw(25) << "" << std::endl;
    return 0;
 }
int main()
{

    int taskCounter = 1;
    // (1 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    int first;
    int second;
    int swap;
    //std::cout << setw(25) << std::setfill('-') << " (" << taskCounter << ") " << setw(25) << ""<< std::endl;
    bar(taskCounter);
    std::cout << "enter first number ";
    std::cin >> first;
    std::cout << "enter second number ";
    std::cin >> second;
    std::cout << std::endl;
    swap = first;
    first = second;
    second = swap;
    std::cout << "first now = " << first << std :: endl;
    std::cout << "second now = " << second << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    taskCounter++;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1)
  
    // (2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    double dou = 6.666666666666;
    bar(taskCounter);
    std::cout << "double = " << dou << std::endl;
    std::cout << "double like int = " << static_cast<int>(dou) << std::endl;
    std::cout << "fill:" << std::endl;
    std::cout << std::setfill('$') << std::setw(20) << dou << std::right << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    taskCounter++;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 2)

    // (3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    double douForScinece = 0.000007777777;
    bar(taskCounter);
    std::cout << "precision = 2: " << std::endl << std::setprecision(2) << douForScinece << std::endl;
    std::cout << "precision = 5: " << std::endl << std::setprecision(5) << douForScinece << std::endl;
    std::cout << "precision = 10: " << std::endl << std::setprecision(10) << douForScinece << std::endl;
    std::cout << "normal" << std::endl << std::fixed << douForScinece << std::endl;
    std::cout << "E: " << std::endl << std::scientific << douForScinece << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    taskCounter++;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 3)

    // (4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // I'm not sure if I understood correctly what needs to be done in this task
    bar(taskCounter);
    enum WeekDay Day;
    Day = Monday;
    int dayCounter = static_cast<int>(Day);
    do {
        switch (dayCounter)
        {
        case 1:
            cout << "Monday is day of week number: " << static_cast<int>(Day = Monday) << std::endl;
            break;
        case 2:
            cout << "Tuesday is day of week number: " << static_cast<int>(Day = Tuesday) << std::endl;
            break;
        case 3:
            cout << "Wednesday is day of week number: " << static_cast<int>(Day = Wednesday) << std::endl;
            break;
        case 4:
            cout << "Thursday is day of week number: " << static_cast<int>(Day = Thursday) << std::endl;
            break;
        case 5:
            cout << "Friday is day of week number: " << static_cast<int>(Day = Friday) << std::endl;
            break;
        case 6:
            cout << "Saturday is day of week number: " << static_cast<int>(Day = Saturday) << std::endl;
            break;
        case 7:
            cout << "Sunday is day of week number: " << static_cast<int>(Day = Sunday) << std::endl;
            break;
        }
        dayCounter++;
    } while (dayCounter < 8);
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    taskCounter++;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 4)
    
    // (5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(taskCounter);
    std::cout << "Print bool number: ";
    int input;
    std::cin >> input;
    std::cout << std::endl;
    if (static_cast<bool>(input)) {
        std::cout << "true" << std::endl;
    }
    else {
        std::cout << "false" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 5)
    return 0;
}


/*enum class Color
{
    Red,
    Green,
    Yelow,
    Blue,
    Gtrey,
    Brown
};
int main()
{
    Color myShirtColor = Color::Red;
    const unsigned int short MyAge = 65536;
    int short W;
    std::cout << "Hello World!\n";
    std::cout << MyAge<<"\n";
    std::cin >> W;
    W = W + MyAge;
    std::cout <<  W << "\n";

    double G = 25.5555;
    std::cout<<std::setprecision(40) << G << "\n";
    int a = 5;
    a = static_cast<int>(G);
    std::cout << a << "\n";
    bool c = 0;
    bool d = 666; // все что больше 0 true
    bool e = true;
    std::cout << c << "\n";
    std::cout << d << "\n";
    std::cout << e << "\n";

    cout << setw(25); //Modify the number to align it to the center
    cout << "Hello" << endl;  //This outputs Hello towards the middle
}
*/
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
