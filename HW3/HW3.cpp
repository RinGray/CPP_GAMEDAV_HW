//#include <numeric>

#include <iostream>
#include <numbers>
#include <iomanip>
using namespace std;

int bar(int taskCounter) {
    std::cout << setw(25) << std::setfill('-') << " (" << taskCounter << ") " << setw(25) << "" << std::endl;
    return 0;
}
int main()
{
    // Зчитати з клавіатури число: скільки секунд гравець провів в грі. Підрахувати і надрукувати скільки це годин, хвилин, секунд. Н-д: на вхід отримали 3870 секунд, програма має вивести: 1 hour, 4 minutes, 30 seconds.
    // (1 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    int taskCounter = 0;
    bar(++taskCounter);
    std::cout << "enter time in seconds: ";
    int Sec;
    std::cin >> Sec;
    const unsigned int ConstHourTime = 60;
    int Minutes = Sec / ConstHourTime;
    int Hours = Minutes / ConstHourTime;
    Sec = Sec % ConstHourTime;
    Minutes = Minutes % ConstHourTime;
    std::cout << Hours << " hour, " << Minutes << " minutes, " << Sec << " seconds, " << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1)
  
    // Зчитати з консолі три числа. Надрукувати їх суму, добуток, середнє арифметичне;
    // (2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int a, b, c;
    std::cout << "enter 3 numbers" << std::endl;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    std::cout << "c: ";
    std::cin >> c;
    int Sum = a + b + c;
    int Mult = a * b * c;
    std::cout << "Sum = " << Sum << std::endl;
    std::cout << "Multiplies = " << Mult << std::endl;
    std::cout << "int Mean = " << Sum / 3 << std::endl;
    std::cout << "float Mean = " << setprecision(3) << static_cast<float>(Sum) / 3 << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 2)

    //Зчитати з клавіатури два числа. Створити змінні типу бул lessThan, equal, moreThan, lessOrEqual; присвоїти їм значення порівняння першого та другого числа у форматі бул; Вивести бул змінні в консоль; Вивести бул змінні в рядковому форматі “true/false” замість числового “1/0”
    // (3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int first, second;
    std::cout << "enter 2 numbers" << std::endl;
    std::cout << "first: ";
    std::cin >> first;
    std::cout << "second: ";
    std::cin >> second;
    std::cout  << std::endl;
    bool lessThan = first < second, equal = first == second, moreThan = first > second, lessOrEqual = first <= second;

    if (lessThan) {
        std::cout << first << " less Than  " << second << ": true"<< std::endl;
    }
    else {
        std::cout << first << " less Than  " << second << ": false" << std::endl;
    }
    if (equal) {
        std::cout << first << " equal  " << second << ": true" << std::endl;
    }
    else {
        std::cout << first << " equal  " << second << ": false" << std::endl;
    }
    if (moreThan) {
        std::cout << first << " more Than  " << second << ": true" << std::endl;
    }
    else {
        std::cout << first << " more Than  " << second << ": false" << std::endl;
    }
    if (lessOrEqual) {
        std::cout << first << " less Or Equal  " << second << ": true" << std::endl;
    }
    else {
        std::cout << first << " less Or Equal  " << second << ": false" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 3)

    // Зчитати два числа: width, height прямокутника. Порахувати та вивести площу, периметр.
    // (4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int width, height;
    std::cout << "enter width & height" << std::endl;
    std::cout << "width: ";
    std::cin >> width;
    std::cout << "height: ";
    std::cin >> height;
    std::cout << std::endl;
    std::cout << "area: "<< width* height << std::endl;
    std::cout << "perimeter: " << 2 * (width + height) << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 4)

    // Зчитати радіус кола. Порахувати площу та довжину кола.
    // (5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int r;
    std::cout << "enter radius:" << std::endl;
    std::cin >> r;
    std::cout << std::endl;
    constexpr double pi = 3.141592653589793;
    std::cout << "area: " << pi * r * r << std::endl;
    std::cout << "length: " << 2 * pi * r << std::endl;


    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 5)
}

    /*
    int taskCounter = 1;
    // (1 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    int first;
    int second;
    int swap;
    bar(taskCounter++);
    std::cout << "enter first number ";
    std::cin >> first;
    std::cout << "enter second number ";
    std::cin >> second;
    std::cout << std::endl;
    swap = first;
    first = second;
    second = swap;
    std::cout << "first now = " << first << std::endl;
    std::cout << "second now = " << second << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1)

    // (2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    double dou = 6.666666666666;
    bar(taskCounter++);
    std::cout << "double = " << dou << std::endl;
    std::cout << "double like int = " << static_cast<int>(dou) << std::endl;
    std::cout << "fill:" << std::endl;
    std::cout << std::setfill('$') << std::setw(20) << dou << std::right << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 2)

    // (3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    double douForScinece = 0.000007777777;
    bar(taskCounter++);
    std::cout << "precision = 2: " << std::endl << std::setprecision(2) << douForScinece << std::endl;
    std::cout << "precision = 5: " << std::endl << std::setprecision(5) << douForScinece << std::endl;
    std::cout << "precision = 10: " << std::endl << std::setprecision(10) << douForScinece << std::endl;
    std::cout << "normal" << std::endl << std::fixed << douForScinece << std::endl;
    std::cout << "E: " << std::endl << std::scientific << douForScinece << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 3)

    // (4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // I'm not sure if I understood correctly what needs to be done in this task
    bar(taskCounter++);
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

}*/
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
