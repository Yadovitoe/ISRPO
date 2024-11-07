#include "header.h"
#include <iostream>
#include <limits>

void Worker::display() {
    std::cout << "���: " << name << ", �������: " << age << ", ���: " << weight << ", ����������: " << mood << std::endl;
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
        std::cout << "\n����:\n";
        std::cout << "1. �������� ���������� � �������\n";
        std::cout << "2. ������� ���\n";
        std::cout << "3. ������� ������\n";
        std::cout << "4. ������� �������\n";
        std::cout << "5. ������� �������� 9 ���\n";
        std::cout << "6. ������� �������� 1 ���\n";
        std::cout << "7. ��������� ���������� ��������\n";
        std::cout << "8. ������, �������� � �����������\n";
        std::cout << "0. �����\n";
        std::cout << "�������� �����: ";

        while (!(std::cin >> choice)) {
            std::cout << "������������ ����. ����������, ������� �����: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        switch (choice) {
        case 1:
            wrk1->display();
            break;
        case 2: {
            float food;
            std::cout << "������� ����������� ���� ���� �������? ";
            while (!(std::cin >> food)) {
                std::cout << "������������ ����. ����������, ������� �����: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            wrk1->eat(food);
            break;
        }
        case 3:
            wrk1->walk();
            std::cout << "������� �������.\n";
            break;
        case 4:
            wrk1->dance();
            std::cout << "������� ����������.\n";
            break;
        case 5:
            for (int i = 0; i < 9; i++) {
                wrk1->work();
            }
            std::cout << "������� ��������� 9 ���.\n";
            break;
        case 6:
            wrk1->work();
            std::cout << "������� ��������� 1 ���.\n";
            break;
        case 7:
            std::cout << "������� ���������� ��������: " << wrk1->get_mood() << std::endl;
            break;
        case 8: {
            float food;
            std::cout << "������� ����������� ���� ���� �������? ";
            while (!(std::cin >> food)) {
                std::cout << "������������ ����. ����������, ������� �����: ";
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
            std::cout << "������� ���� " << food << "�� ���, 2 ���� ������� � 3 ���� ����������.\n";
            break;
        }
        case 0:
            std::cout << "����� �� ���������.\n";
            break;
        default:
            std::cout << "������������ �����, ���������� ��� ���.\n";
        }
    } while (choice != 0);
}
