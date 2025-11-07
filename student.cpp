#pragma once
#include <vector>
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include "student.h"
#include <string>

using namespace std;

Student::Student(const Student& new_Student)
{
    cout << "Вызван конструктор копирования" << endl;
    FIO = new_Student.FIO;
    group = new_Student.group;
    speciality = new_Student.speciality;
    course = new_Student.course;
    av_grad = new_Student.av_grad;
}

Student::Student()
{
    cout << "Вызван конструктор по умолчанию c" << endl;
    this->FIO = "None";
    this->group = "None";
    this->speciality = "None";
    this->course = "None";
    this->av_grad = "None";
}

Student::Student(string FIO, string group, string speciality, string course, string av_grad)
{
    cout << "Вызван конструктор" << endl;
    this->FIO = FIO;
    this->group = group;
    this->speciality = speciality;
    this->course = course;
    this->av_grad = av_grad;
}

Student::~Student()
{
    cout << "Вызван деструктор" << endl;
}

void Student::setFIO(string FIO) { this->FIO = FIO; }
void Student::setGroup(string group) { this->group = group; }
void Student::setSpec(string speciality) { this->speciality = speciality; }
void Student::setCourse(string course) { this->course = course; }
void Student::setAv(string av_grad) { this->av_grad = av_grad; }

string Student::getFIO() { return FIO; }
string Student::getGroup() { return group; }
string Student::getSpec() { return speciality; }
string Student::getCourse() { return course; }
string Student::getAv() { return av_grad; }

void Student::print()
{
    cout << "-----Студент-----" << endl;
    cout << "ФИО: " << getFIO() << endl;
    cout << "Группа: " << getGroup() << endl;
    cout << "Специальность: " << getSpec() << endl;
    cout << "Курс: " << getCourse() << endl;
    cout << "Средний балл: " << getAv() << endl;
}

void Student::input()
{
    string nFIO;
    string ngroup;
    string nspeciality;
    string ncourse;
    int course = 0;
    string nav_grad;
    double av_grad = 0;

    cout << " Введите ФИО: " << endl;
    getline(cin, nFIO);
    if (nFIO == "") {
        getline(cin, nFIO);
    }
    setFIO(nFIO);

    cout << "Введите Группу: " << endl;
    cin >> ngroup;
    setGroup(ngroup);

    cout << "Введите Специальность: " << endl;
    getline(cin, nspeciality);
    if (nspeciality == "") {
        getline(cin, nspeciality);
    }
    setSpec(nspeciality);

    cout << "Введите Курс: " << endl;
    cin >> ncourse;
    try {
        course = stoi(ncourse);
    } catch (std::invalid_argument) {
        // Говорим, что можно вводить только числа
        std::cout << "Only numbers are allowed! \n";
    }
    if (course > 0) {
        setCourse(ncourse);
    }

    cout << "Введите Средний балл: " << endl;
    cin >> nav_grad;
    try {
        av_grad = stoi(nav_grad);
    } catch (std::invalid_argument) {
        // Говорим, что можно вводить только числа
        std::cout << "Only numbers are allowed! \n";
    }
    if (av_grad > 0) {
        setAv(nav_grad);
    }
}

void Student::change()
{
    string nFIO;
    string ngroup;
    string nspeciality;
    string ncourse;
    int course = 0;
    string nav_grad;
    double av_grad = 0;

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

    cout << "Введите новую Группу: " << endl;
    cin >> ngroup;
    if (ngroup == "N") {
    } else {
        setGroup(ngroup);
    }

    cout << "Введите новую Специальность: " << endl;
    getline(cin, nspeciality);
    if (nspeciality == "") {
        getline(cin, nspeciality);
    }
    if (nspeciality == "N") {
    } else {
        setSpec(nspeciality);
    }

    cout << "Введите новый Курс: " << endl;
    cin >> ncourse;
    if (ncourse == "N") {
    } else {
        try {
            course = stoi(ncourse);
        } catch (std::invalid_argument) {
            // Говорим, что можно вводить только числа
            std::cout << "Only numbers are allowed! \n";
        }
        if (course > 0) {
            setCourse(ncourse);
        }
    }

    cout << "Введите новый Средний балл: " << endl;
    cin >> nav_grad;
    if (nav_grad == "N") {
    } else {
        try {
            av_grad = stoi(nav_grad);
        } catch (std::invalid_argument) {
            // Говорим, что можно вводить только числа
            std::cout << "Only numbers are allowed! \n";
        }
        if (av_grad > 0) {
            setAv(nav_grad);
        }
    }
    return;
}

void Student::save(ofstream& file)
{
    file << "-----Студент-----" << endl;
    file << "Имя: " << getFIO() << endl;
    file << "Группа: " << getGroup() << endl;
    file << "Специальность: " << getSpec() << endl;
    file << "Курс: " << getCourse() << endl;
    file << "Средний балл: " << getAv() << endl;
}

void Student::load(ifstream& file)
{
    string line;
    getline(file, line);
    getline(file, line);
    setFIO(line.substr(line.find(":") + 2));
    getline(file, line);
    setGroup(line.substr(line.find(":") + 1));
    getline(file, line);
    setSpec(line.substr(line.find(":") + 1));
    getline(file, line);
    setCourse(line.substr(line.find(":") + 1));
    getline(file, line);
    setAv(line.substr(line.find(":") + 1));
}