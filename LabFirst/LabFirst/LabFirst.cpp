#include <iostream>
#include <vector>
#include <clocale> 
#include "header.h"

void triangle() {
    std::vector<IsoscelesTriangle> triangles;
    int n;

    std::cout << "Введите количество треугольников: ";
    while (!(std::cin >> n) || n <= 0) {
        std::cout << "Ошибка: введите положительное целое число." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    // Ввод свойств треугольников
    for (int i = 0; i < n; i++) {
        IsoscelesTriangle triangle;
        double side, angle;

        std::cout << "Введите боковую сторону и угол при основании для треугольника " << i + 1 << ": ";
        while (!(std::cin >> side >> angle) || !triangle.setProperties(side, angle)) {
            std::cout << "Повторите ввод: боковая сторона должна быть положительной, угол должен быть в пределах от 0 до 180 градусов." << std::endl;
            std::cin.clear();
        }

        triangles.push_back(triangle);
    }

    // Меню операций
    int choice;
    do {
        std::cout << "\nВыберите треугольник (1-" << n << "): ";
        int index;
        while (!(std::cin >> index) || index < 1 || index > n) {
            std::cout << "Ошибка: выберите индекс от 1 до " << n << "." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        IsoscelesTriangle& selectedTriangle = triangles[index - 1];

        std::cout << "\nВыберите операцию:\n"
            << "1. Увеличить/уменьшить размер\n"
            << "2. Вычислить длину биссектрисы\n"
            << "3. Вычислить длину высоты\n"
            << "4. Определить значения сторон\n"
            << "0. Выход\n"
            << "Ваш выбор: ";
        while (!(std::cin >> choice) || (choice < 0 || choice > 4)) {
            std::cout << "Ошибка: выберите операцию от 0 до 4." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        switch (choice) {
        case 1: {
            system("cls");
            double factor;
            std::cout << "Введите множитель (положительное для увеличения, отрицательное для уменьшения): ";
            while (!(std::cin >> factor) || factor == 0) {
                std::cout << "Ошибка: введите ненулевое число." << std::endl;
                std::cin.clear();
                std::cin.ignore(1);
            }
            if (selectedTriangle.scale(factor)) {
                std::cout << "Размер треугольника изменён." << std::endl;
            }
            
            break;
        }
        case 2: {
            system("cls");
            double bis, bisSide;
            selectedTriangle.calculateBisector(bis, bisSide);
            std::cout << "Длина биссектрисы основания: " << bis << ". Длина бисектрисы сторон: " << bisSide <<std::endl;
            break;
        }
        case 3: {
            system("cls");
            double h, hs;
            selectedTriangle.calculateHeight(h, hs);
                std::cout << "Длина высоты основания: " << h << ". Длина высот сторон: " << hs << std::endl;
                break;
        }
        case 4: {
            system("cls");
            double base, leftSide, rightSide;
            selectedTriangle.calculateSides(base, leftSide, rightSide);
            std::cout << "Длина основания: " << base << ", Боковые стороны: " << leftSide << ", " << rightSide << std::endl;
            break;
        }
        case 0:
            system("cls");
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}

int main() {
    setlocale(LC_ALL, "Russian");
    triangle();
    return 0;
}
