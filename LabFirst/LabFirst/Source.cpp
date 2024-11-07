#include <iostream>
#include <cmath>
#include "header.h"

#define PI 3.14159265358979323846

IsoscelesTriangle::IsoscelesTriangle() : side(0), angle(0) {}

bool IsoscelesTriangle::setProperties(double s, double a) 
{
    if (s <= 0) {
        std::cout << "Ошибка: боковая сторона должна быть положительной." << std::endl;
        return false;
    }
    if (a <= 0 || a >= 89) {
        std::cout << "Ошибка: угол при основании должен быть в пределах от 0 до 89 градусов." << std::endl;
        return false;
    }

    double radAngle = a * PI / 180;
    double h = s * std::sin(radAngle);
    double base = 2 * sqrt(pow(s, 2) - pow(h, 2));

    if (base <= 0) {
        std::cout << "Ошибка: равнобедренного треугольника с такими параметрами не существует." << std::endl;
        return false;
    }
    side = s;
    angle = a;
    return true;
}

bool IsoscelesTriangle::scale(double factor) 
{
    if (factor == 0) {
        std::cout << "Ошибка: множитель не может быть равен нулю." << std::endl;
        return false;
    }
    if (factor < 0) {
        side /= factor * (-1);
    }
    if (factor > 0) {
        side *= factor;
    }
    return true;
}

double IsoscelesTriangle::calculateBisector(double& bis, double& bisSide) const 
{
    if (side == 0 || angle == 0) {
        std::cout << "Ошибка: некорректные параметры треугольника." << std::endl;
        return -1;
    }
    double radAngle = angle * PI / 180;
    double s = side;
    double b = 2 * side * std::sin(radAngle);
    bis = std::sin(radAngle) * s;
    bisSide = sqrt(s * b * (s + b + s) * (s + b - s)) / (s + b);
}   

double IsoscelesTriangle::calculateHeight(double& h, double& hs) const 
{
    if (side == 0 || angle == 0) {
        std::cout << "Ошибка: некорректные параметры треугольника." << std::endl;
        return -1;
    }
    double radAngle = angle * PI / 180;
    double s = side;
    double b = 2 * side * std::sin(radAngle);
    h = side* std::sin(radAngle);
    double S = b * h / 2;
    hs = (2*S)/s;

}

void IsoscelesTriangle::calculateSides(double& base, double& leftSide, double& rightSide) const 
{
    leftSide = rightSide = side;
    if (side == 0 || angle == 0) {
        std::cout << "Ошибка: некорректные параметры треугольника." << std::endl;
        base = 0;
        return;
    }
    double radAngle = angle * PI / 180;
    double h = side * std::sin(radAngle);
    base = 2 * sqrt(pow(side, 2) - pow(h, 2));
}