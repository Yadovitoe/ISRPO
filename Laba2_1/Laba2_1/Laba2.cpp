#include "header.h"
#include <iostream>
#include <clocale>
#include <Windows.h>

int main() {
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Worker* wrk1 = new Worker();

    std::cout << "Введите имя: ";
    std::cin >> wrk1->name;

    std::cout << "Введите возраст: ";
    while (!(std::cin >> wrk1->age)) {
        std::cout << "Некорректный ввод. Пожалуйста, введите число: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    menu(wrk1);

    delete wrk1;
    return 0;
}
