#include "header.h"
#include <iostream>
#include <clocale>
#include <Windows.h>

int main() {
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Worker* wrk1 = new Worker();

    std::cout << "������� ���: ";
    std::cin >> wrk1->name;

    std::cout << "������� �������: ";
    while (!(std::cin >> wrk1->age)) {
        std::cout << "������������ ����. ����������, ������� �����: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    menu(wrk1);

    delete wrk1;
    return 0;
}
