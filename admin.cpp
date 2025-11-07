#pragma once
#include <vector>
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include "admin.h"
#include <string>

using namespace std;

Admin::Admin(const Admin& new_Admin)
{
    cout << "Вызван конструктор копирования" << endl;
    FIO = new_Admin.FIO;
    work = new_Admin.work;
    number = new_Admin.number;
    response = new_Admin.response;
}

Admin::Admin()
{
    cout << "Вызван конструктор по умолчанию а" << endl;
    this->FIO = "None";
    this->work = "None";
    this->number = "None";
    this->response = "None";
}

Admin::Admin(string FIO, string work, string number, string response)
{
    cout << "Вызван конструктор" << endl;
    this->FIO = FIO;
    this->work = work;
    this->number = number;
    this->response = response;
}

Admin::~Admin()
{
    cout << "Вызван деструктор" << endl;
}

void Admin::setFIO(string FIO) { this->FIO = FIO; }
void Admin::setWork(string work) { this->work = work; }
void Admin::setNumber(string number) { this->number = number; }
void Admin::setResponse(string response) { this->response = response; }

string Admin::getFIO() { return FIO; }
string Admin::getWork() { return work; }
string Admin::getNumber() { return number; }
string Admin::getResponse() { return response; }

void Admin::print()
{
    cout << "-----Админ-----" << endl;
    cout << "ФИО: " << getFIO() << endl;
    cout << "Должность: " << getWork() << endl;
    cout << "Телефон: " << getNumber() << endl;
    cout << "Область ответсвенности: " << getResponse() << endl;
}

void Admin::input()
{
    string nFIO;
    string nwork;
    string nnumber;
    int number = 0;
    string nresponse;

    cout << " Введите ФИО: " << endl;
    getline(cin, nFIO);
    if (nFIO == "") {
        getline(cin, nFIO);
    }
    setFIO(nFIO);

    cout << "Введите Должность: " << endl;
    getline(cin, nwork);
    if (nwork == "") {
        getline(cin, nwork);
    }
    setWork(nwork);

    cout << "Введите Телефон: " << endl;
    cin >> nnumber;
    try {
        number = stoi(nnumber);
    } catch (std::invalid_argument) {
        // Говорим, что можно вводить только числа
        std::cout << "Only numbers are allowed! \n";
    }
    if (number > 0) {
        setNumber(nnumber);
    }

    cout << "Введите Область ответственности: " << endl;
    getline(cin, nresponse);
    if (nresponse == "") {
        getline(cin, nresponse);
    }
    setResponse(nresponse);
}

void Admin::change()
{
    string nFIO;
    string nwork;
    string nnumber;
    string nresponse;
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

    cout << "Введите новую Должность: " << endl;
    getline(cin, nwork);
    if (nwork == "") {
        getline(cin, nwork);
    }
    if (nwork == "N") {
    } else {
        setWork(nwork);
    }

    cout << "Введите новый Телефон: " << endl;
    cin >> nnumber;
    if (nnumber == "N") {
    } else {
        try {
            number = stoi(nnumber);
        } catch (std::invalid_argument) {
            // Говорим, что можно вводить только числа
            std::cout << "Only numbers are allowed! \n";
        }
        if (number > 0) {
            setNumber(nnumber);
        }
    }

    cout << "Введите новую Область ответственности: " << endl;
    getline(cin, nresponse);
    if (nresponse == "") {
        getline(cin, nresponse);
    }
    if (nFIO == "N") {
    } else {
        setResponse(nresponse);
    }
    return;
}

void Admin::save(ofstream& file)
{
    file << "-----Админ-----" << endl;
    file << "Имя: " << getFIO() << endl;
    file << "Группа: " << getWork() << endl;
    file << "Специальность: " << getNumber() << endl;
    file << "Курс: " << getResponse() << endl;
}

void Admin::load(ifstream& file)
{
    string line;
    getline(file, line);
    getline(file, line);
    setFIO(line.substr(line.find(":") + 2));
    getline(file, line);
    setWork(line.substr(line.find(":") + 1));
    getline(file, line);
    setNumber(line.substr(line.find(":") + 1));
    getline(file, line);
    setResponse(line.substr(line.find(":") + 1));
}