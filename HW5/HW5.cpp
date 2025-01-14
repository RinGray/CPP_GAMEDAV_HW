
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

int bar(int taskCounter) {
    std::cout << setw(25) << std::setfill('-') << " (" << taskCounter << ") " << setw(25) << "" << std::endl;
    return 0;
}
int main()
{
    int taskCounter = 0;
    // Зчитати з консолі три числа: перший елемент(a1), крок арифметичної прогресії(d),
    // номер останнього елемента арифметичної прогресії(n) (арифметична прогресія - це послідовність дійсних чисел, 
    // кожен член якої, починаючи з другого, утворюється додаванням до попереднього члена одного й того ж числа. 
    // Як результат, надрукувати всі елементи арифметичної прогресії починаючи з першого до останнього.
    // (1 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int a1, d, n;
    std::cout << "enter 3 numbers" << std::endl;
    std::cout << "a1: ";
    std::cin >> a1;
    std::cout << "d: ";
    std::cin >> d;
    std::cout << "n: ";
    while(true){
        
        std::cin >> n;
        std::cout << std::endl;
        if (n > 0) {
            break;
        }
        else
        {
            std::cout << "Incorrect n, try again: ";
            continue;
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << "number "<<i+1<<" = " << a1 + d * i<< std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1)

     // За допомогою циклу надрукувати геометричні фігури; розмір сторін/кількість рядків вводить користувач з консолі;
    // (2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int side;
    std::cout << "side: ";
    
    while (true) {

        std::cin >> side;
        std::cout << std::endl;
        if (side > 1) {
            break;
        }
        else
        {
            std::cout << "Incorrect side, side must be biger then 1; try again: ";
            continue;
        }
    }
    // a.
    std::cout << "a."<< std::endl;
    for (int i = 0; i < side; i++) {
        for (int j = i; j < side; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
    // b.
    std::cout << std::endl;
    std::cout << "b.";
    for (int i = side; i >= 0; i--) {
        for (int j = i; j < side; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    // c.
    std::cout << "c." << std::endl;
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    // d.
    std::cout << "d." << std::endl;
    for (int i = 0; i < side; i++) {
        for (int k = 0; k < i; k++) {
            std::cout << " ";
        }
        for (int j = 0; j < side; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    // e.
    std::cout << "e.";
    for (int i = side; i >= 0; i--) {
        for (int j = i; j < side; j++) {
            if (j % 2 == 0) {
                std::cout << "0 ";
            }
            else {
                std::cout << "1 ";
            }
            
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 2)

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 2)

    // В циклі зчитати символ char. В залежності від природи символу виконати наступні дії: 
    // a. буква в нижньому регістрі - привести до верхнього та вивести;
    // b. цифра - додати до загальної суми введених цифр, та вивести результат поточної суми;
    // c. Інше(розділові знаки, спецсимвол, тд) - вивести повідомлення, що цей символ не обробляється програмою та продовжити цикл;
    // d. Завершити програму, якщо введено символ ‘.’;
    // (3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    char ch;
    int sum = 0;
    int plus = 0;
    while (true) {
        std::cout << "for exit enter '.' " << std::endl;
        std::cout << "enter symbol: ";
        std::cin>>ch;
        std::cout << std::endl;
        // d.
        if (ch == '.') {
            std::cout << "Exit..." << std::endl;
            break;
        }
        //a.
        if (std::isalpha(ch)) {
            if (std::islower(ch)) {
                ch = std::toupper(ch);
                std::cout << "convert to upper: "<< ch<< std::endl;
                continue;
            }
            else {
                std::cout << "already upper: " << ch << std::endl;
                continue;
            }
        }
        //b.
        if (std::isalnum(ch)) {
            sum = sum + (ch-'0');
            std::cout << "Sum: " << sum << std::endl;
            continue;
        }
        //c.
        if (std::ispunct(ch)) {
            std::cout << "symbol incorrect, try again: " << std::endl;
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 3)

    // Зчитати з консолі число(n) - номер елемента послідовності Фібоначчі. 
    // Надрукувати значення зчитаного елемента послідовності Фібоначчі(Fn) (послідовність Фібоначчі - числова послідовність, задана таким співвідношенням:
    // F1 = 1, F2 = 1, Fn+2 = Fn + Fn+1, n = 1, 2, 3, …,
    // F1 = 1, F2 = 1, F3 = 2, F4 = 3, F5 = 5, F6 = 8, F7 = 13, F8 = 21
    // (4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int Fn;
    std::cout << "Fn: ";
    while (true) {

        std::cin >> Fn;
        std::cout << std::endl;
        if (Fn > 0) {
            break;
        }
        else
        {
            std::cout << "Incorrect Fn, try again: ";
            continue;
        }
    }
    int f = 1, first = 1, second = 1;
    for (int i = 1; i <= Fn; i++) {
        if (i < 3) {
            std::cout << "F" << i << " = " << f << ", ";
        }
        else {
            f = first + second;
            second = first;
            first = f;
            std::cout << "F" << i << " = " << f  << ", ";

            
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 4)

     // 5. Зчитати ціле додатне число.Вивести факторіал цього числа. 
     // (Факторіал натурального числа n - добуток чисел від 1 до цього числа, позначається як n!Н - д: 5!= 1⋅2⋅3⋅4⋅5 = 120).
     // (5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bar(++taskCounter);
    int F;
    std::cout << "Enter factorial: ";
    while (true) {

        std::cin >> F;
        std::cout << std::endl;
        if (F > 0) {
            break;
        }
        else
        {
            std::cout << "Must be positive, try again: ";
            continue;
        }
    }
    int fact = 1;
    for (int i = 1; i <= F; i++) {
        fact = fact * i;
        std::cout << "F" << i << " = " << fact << ", " << endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter..." << std::endl;
    cin.get();
    cin.get();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++ 5)

}
