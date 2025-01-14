//#include <numeric>
//#include <numbers>
// piu piy
#include <iostream>
#include <iomanip>
using namespace std;

int bar(int taskCounter) {
    std::cout << setw(25) << std::setfill('-') << " (" << taskCounter << ") " << setw(25) << "" << std::endl;
    return 0;
}
enum class month
{
    January = 1,
    February = 2,
    March = 3,
    April = 4,
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12
};
int main()
{
    int taskCounter = 0;
    // Зчитати три числа, надрукувати максимальне з цих трьох чисел.
    // (1 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int a, b, c;
    std::cout << "enter 3 numbers" << std::endl;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    std::cout << "c: ";
    std::cin >> c;
    std::cout << std::endl;

    if ((a > b) and (a > c)) {
        std::cout << a << " bigger" << std::endl;
    }
    else {
        if ((b > a) and (b > c)) {
            std::cout << b << " bigger" << std::endl;
        }
        else {
            std::cout << c << " bigger" << std::endl;
        }
    }
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1)

    // Програма, що перевіряє, чи ділиться введене число націло на 5 та 11 одночасно;
    // (2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int k;
    std::cout << "enter number for division by 5 & 11: " << std::endl;
    std::cin >> k;
    std::cout << std::endl;
    if (k != 0) {
        if ((k % 5) == 0) {
            if ((k % 11) == 0) {
                std::cout << "yea" << std::endl;
            }
            else {
                std::cout << "only on 5" << std::endl;
            }
        }
        else {
            if ((k % 11) == 0) {
                std::cout << "only on 11" << std::endl;
            }
            else {
                std::cout << "NO" << std::endl;
            }
        }
    }
    else {
        std::cout << "number is zero" << std::endl;
    }
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 2)

    // Зчитати 3 числа - можливі значення кутів трикутника. Перевірити, чи дані кути формують трикутник;
    // (3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    std::cout << "enter 3 numbers" << std::endl;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    std::cout << "c: ";
    std::cin >> c;
    std::cout << std::endl;

    if ((a + b + c) == 180) {
        std::cout << "it's triangle" << std::endl;
    }
    else {
            std::cout << "it's not triangle" << std::endl;
        }
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 3)

    //Зчитати з консолі число від 1 до 12. Це номер місяця (1 — січень, 2 — лютий тощо). Вивести на екран пору року, якій відповідає цей місяць. Наприклад, користувач ввів 5. Потрібно вивести Spring.
    // (4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int m;
    std::cout << "enter number of month: " << std::endl;
    std::cin >> m;
    std::cout << std::endl;
    std::cout << "it's ";
    month Month = static_cast<month>(m);
    switch (Month)
    {
    case (month::December):
    case (month::January):
    case (month::February):
        std::cout << "Winter" << std::endl;
        break;
    case (month::March):
    case (month::April):
    case (month::May):
        std::cout << "Spring" << std::endl;
        break;
    case (month::June):
    case (month::July):
    case (month::August):
        std::cout << "Summer" << std::endl;
        break;
    case (month::September):
    case (month::October):
    case (month::November):
        std::cout << "Autumn" << std::endl;
        break;
    default:
        std::cout << " not number of month" << std::endl;
    }

    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 4)

    // Зчитати два числа, знайти мінімум з двох чисел, використовуючи тернарний оператор;
    // (D1 +++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int first, second;
    std::cout << "enter 2 numbers" << std::endl;
    std::cout << "first: ";
    std::cin >> first;
    std::cout << "second: ";
    std::cin >> second;
    std::cout << std::endl;
    int min = (first > second) ? second : first;
    std::cout << "MIN = " << min << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++ D1)

    // Створити enum class Month для всіх місяців; зчитати з консолі число, привести його до відповідного значення з енама місяців; 
    // використовуючи switch та значення з enum class Month, надрукувати назву місяця в консоль. У разі, якщо число введено неправильно
    // (н.д. 13 - не може бути коректно приведено до enum class Month), повідомити користувача про помилку.
    // (D2 +++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    std::cout << "enter number of month: " << std::endl;
    std::cin >> m;
    std::cout << std::endl;
    std::cout << "it's ";
    Month = static_cast<month>(m);
    switch (Month)
    {
    case (month::December):
        std::cout << "December" << std::endl;
        break;
    case (month::January):
        std::cout << "January" << std::endl;
        break;
    case (month::February):
        std::cout << "February" << std::endl;
        break;
    case (month::March):
        std::cout << "March" << std::endl;
        break;
    case (month::April):
        std::cout << "April" << std::endl;
        break;
    case (month::May):
        std::cout << "May" << std::endl;
        break;
    case (month::June):
        std::cout << "June" << std::endl;
        break;
    case (month::July):
        std::cout << "July" << std::endl;
        break;
    case (month::August):
        std::cout << "August" << std::endl;
        break;
    case (month::September):
        std::cout << "September" << std::endl;
        break;
    case (month::October):
        std::cout << "October" << std::endl;
        break;
    case (month::November):
        std::cout << "November" << std::endl;
        break;
    default:
        std::cout << " not number of month" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++ D2)
}
