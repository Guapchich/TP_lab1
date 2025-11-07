#pragma once
#include <vector>
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include "mentor.h"
#include <string>

using namespace std;

Mentor::Mentor(const Mentor& new_Mentor)
{
    cout << "Вызван конструктор копирования" << endl;
    FIO = new_Mentor.FIO;
    groups[gr_size] = new_Mentor.groups[gr_size];
    objects[obj_size] = new_Mentor.objects[obj_size];
}

Mentor::Mentor()
{
    cout << "Вызван конструктор по умолчанию м" << endl;
    this->FIO = "None";
    for (int i = 0; i < gr_size; ++i) {
        groups[i] = "None";  // Задаем пустую строку
    }
    for (int i = 0; i < obj_size; ++i) {
        objects[i] = "None"; // Задаем пустую строку
    }
}

Mentor::Mentor(string FIO, int gr_size, int obj_size, string* groups, string* objects)
{
    cout << "Вызван конструктор" << endl;
    this->FIO = FIO;
    this->groups[gr_size] = groups[gr_size];
    this->objects[obj_size] = objects[obj_size];
}

Mentor::~Mentor()
{
    cout << "Вызван деструктор" << endl;
}

void Mentor::setFIO(string FIO) { this->FIO = FIO; }

void Mentor::setGroup(int gr_size)
{
    for (int i = 0; i < gr_size; i++) {
        string new_gr;
        cout << "Введите группу №" << i + 1 << ":" << endl;
        cin >> new_gr;
        groups[i] = new_gr;
    }
}

void Mentor::setOneGr(int i, string line)
{
    groups[i] = line;
}

void Mentor::setOneObj(int i, string line)
{
    objects[i] = line;
}

void Mentor::setObj(int obj_size)
{
    for (int i = 0; i < obj_size; i++) {
        string new_obj;
        cout << "Введите предмет №" << i + 1 << ":" << endl;
        cin >> new_obj;
        objects[i] = new_obj;
    }
}

string Mentor::getFIO() { return FIO; }

int Mentor::getGr_size() { return gr_size; }

void Mentor::getGroup()
{
    int i = 0;
    cout << groups[i] << endl;
    while (groups[i] != "None") {
        cout << "Группа №" << i + 1 << ": " << groups[i] << endl;
        i++;
    }
    return;
}

int Mentor::getObj_size() { return obj_size; }

void Mentor::getObj()
{
    int i = 0;
    while (objects[i] != "None") {
        cout << "Предмет №" << i + 1 << ": " << objects[i] << endl;
        i++;
    }
    return;
}

void Mentor::print()
{
    int i = 0;
    cout << "-----Преподаватель-----" << endl;
    cout << "ФИО: " << getFIO() << endl;
    getGroup();
    getObj();
}

void Mentor::input()
{
    string nFIO;
    string ngr_size;
    string nobj_size;
    int number = 0;

    cout << " Введите ФИО: " << endl;
    getline(cin, nFIO);
    if (nFIO == "") {
        getline(cin, nFIO);
    }
    setFIO(nFIO);

    cout << "Введите количество групп( не больше 10): " << endl;
    cin >> ngr_size;
    try {
        number = stoi(ngr_size);
    } catch (std::invalid_argument) {
        // Говорим, что можно вводить только числа
        std::cout << "Only numbers are allowed! \n";
    }
    if (number > 0) {
        setGroup(number);
    }

    cout << "Введите количество предметов( не больше 10): " << endl;
    cin >> nobj_size;
    try {
        number = stoi(nobj_size);
    } catch (std::invalid_argument) {
        // Говорим, что можно вводить только числа
        std::cout << "Only numbers are allowed! \n";
    }
    if (number > 0) {
        setObj(number);
    }
}

void Mentor::change()
{
    string nFIO;
    string ngr_size;
    string nobj_size;
    int number = 0;

    cout << " Для отмены изменения введите 'N'" << endl;
    cout << " Введите новое ФИО: " << endl;
    getline(cin, nFIO);
    if (nFIO == "") {
        getline(cin, nFIO);
    }
    if (nFIO == "N") {
    } else {
        setFIO(nFIO);
    }

    cout << "Введите новое число групп(Не больше 10): " << endl;
    cin >> ngr_size;
    if (ngr_size == "N") {
    } else {
        try {
            number = stoi(ngr_size);
        } catch (std::invalid_argument) {
            // Говорим, что можно вводить только числа
            std::cout << "Only numbers are allowed! \n";
        }
        if (number > 0) {
            setGroup(number);
        }
    }

    cout << "Введите новое число предметов (Не больше 10): " << endl;
    cin >> nobj_size;
    if (ngr_size == "N") {
    } else {
        try {
            number = stoi(nobj_size);
        } catch (std::invalid_argument) {
            // Говорим, что можно вводить только числа
            std::cout << "Only numbers are allowed! \n";
        }
        if (number > 0) {
            setObj(number);
        }
    }
    return;
}

void Mentor::save(ofstream& file)
{
    file << "-----Преподаватель-----" << endl;
    file << "ФИО: " << getFIO() << endl;
    for (int i = 0; i < getGr_size(); i++) {
        file << "Группа №" << i + 1 << ": " << groups[i] << endl;
    }
    for (int i = 0; i < getObj_size(); i++) {
        file << "Предмет №" << i + 1 << ": " << objects[i] << endl;
    }
}

void Mentor::load(ifstream& file)
{
    string line;
    getline(file, line);
    getline(file, line);
    setFIO(line.substr(line.find(":") + 2));
    
    for (int i = 0; i < getGr_size(); i++) {
        getline(file, line);
        setOneGr(i, line.substr(line.find(":") + 2));
    }
    
    for (int i = 0; i < getObj_size(); i++) {
        getline(file, line);
        setOneObj(i, line.substr(line.find(":") + 2));
    }
}