#include "header.h"
#include <iostream>
#include <limits>

void Worker::display() {
    std::cout << "Имя: " << name << ", Возраст: " << age << ", Вес: " << weight << ", Настроение: " << mood << std::endl;
}

void Worker::eat(float how_much) {
    if (how_much > 10) {
        age++;
        weight += how_much / 2;
    }
    else {
        weight += how_much;
    }
}

float Worker::get_weight() {
    return weight;
}

void Worker::walk() {
    mood += 1;
}

void Worker::dance() {
    mood += 2;
}

void Worker::work() {
    if (mood > 0) {
        mood -= 2;
        if (mood < 0) mood = 0;
    }
}

int Worker::get_mood() {
    return mood;
}

void menu(Worker* wrk1) {
    int choice;
    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Показать информацию о рабочем\n";
        std::cout << "2. Рабочий ест\n";
        std::cout << "3. Рабочий гуляет\n";
        std::cout << "4. Рабочий танцует\n";
        std::cout << "5. Рабочий работает 9 раз\n";
        std::cout << "6. Рабочий работает 1 раз\n";
        std::cout << "7. Проверить настроение рабочего\n";
        std::cout << "8. Поесть, погулять и потанцевать\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите опцию: ";

        while (!(std::cin >> choice)) {
            std::cout << "Некорректный ввод. Пожалуйста, введите число: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        switch (choice) {
        case 1:
            wrk1->display();
            break;
        case 2: {
            float food;
            std::cout << "Сколько килограммов пищи съел рабочий? ";
            while (!(std::cin >> food)) {
                std::cout << "Некорректный ввод. Пожалуйста, введите число: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            wrk1->eat(food);
            break;
        }
        case 3:
            wrk1->walk();
            std::cout << "Рабочий погулял.\n";
            break;
        case 4:
            wrk1->dance();
            std::cout << "Рабочий потанцевал.\n";
            break;
        case 5:
            for (int i = 0; i < 9; i++) {
                wrk1->work();
            }
            std::cout << "Рабочий поработал 9 раз.\n";
            break;
        case 6:
            wrk1->work();
            std::cout << "Рабочий поработал 1 раз.\n";
            break;
        case 7:
            std::cout << "Текущее настроение рабочего: " << wrk1->get_mood() << std::endl;
            break;
        case 8: {
            float food;
            std::cout << "Сколько килограммов пищи съел рабочий? ";
            while (!(std::cin >> food)) {
                std::cout << "Некорректный ввод. Пожалуйста, введите число: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            wrk1->eat(food);
            for (int i = 0; i < 2; i++) {
                wrk1->walk();
            }
            for (int i = 0; i < 3; i++) {
                wrk1->dance();
            }
            std::cout << "Рабочий съел " << food << "кг еды, 2 раза погулял и 3 раза потанцевал.\n";
            break;
        }
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Некорректный выбор, попробуйте еще раз.\n";
        }
    } while (choice != 0);
}
