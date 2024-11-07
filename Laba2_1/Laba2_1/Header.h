#pragma once
#include <string>

class Worker {
public:
    int age = 0;
    std::string name;
private:
    float weight = 0;
    int mood = 10;

public:
    void display();
    void eat(float how_much);
    float get_weight();
    void walk();
    void dance();
    void work();
    int get_mood();
};
void menu(Worker* wrk1);