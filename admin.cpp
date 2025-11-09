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
    cout << "Copy constructor called" << endl;
    FIO = new_Admin.FIO;
    work = new_Admin.work;
    number = new_Admin.number;
    response = new_Admin.response;
}

Admin::Admin()
{
    cout << "Default constructor called" << endl;
    this->FIO = "None";
    this->work = "None";
    this->number = "None";
    this->response = "None";
}

Admin::Admin(string FIO, string work, string number, string response)
{
    cout << "Constructor called" << endl;
    this->FIO = FIO;
    this->work = work;
    this->number = number;
    this->response = response;
}

Admin::~Admin()
{
    cout << "Destructor called" << endl;
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
    cout << "-----Admin-----" << endl;
    cout << "Full Name: " << getFIO() << endl;
    cout << "Position: " << getWork() << endl;
    cout << "Phone: " << getNumber() << endl;
    cout << "Area of Responsibility: " << getResponse() << endl;
}

void Admin::input()
{
    string nFIO;
    string nwork;
    string nnumber;
    int number = 0;
    string nresponse;

    cout << " Enter Full Name: " << endl;
    getline(cin, nFIO);
    if (nFIO == "") {
        getline(cin, nFIO);
    }
    setFIO(nFIO);

    cout << "Enter Position: " << endl;
    getline(cin, nwork);
    if (nwork == "") {
        getline(cin, nwork);
    }
    setWork(nwork);

    cout << "Enter Phone: " << endl;
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

    cout << "Enter Area of Responsibility: " << endl;
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

    cout << " Enter 'N' to cancel changes" << endl;
    cout << " Enter new Full Name: " << endl;
    getline(cin, nFIO);
    if (nFIO == "") {
        getline(cin, nFIO);
    }
    if (nFIO == "N") {
    } else {
        setFIO(nFIO);
    }

    cout << "Enter new Position: " << endl;
    getline(cin, nwork);
    if (nwork == "") {
        getline(cin, nwork);
    }
    if (nwork == "N") {
    } else {
        setWork(nwork);
    }

    cout << "Enter new Phone: " << endl;
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

    cout << "Enter new Area of Responsibility: " << endl;
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
    file << "-----Admin-----" << endl;
    file << "Name: " << getFIO() << endl;
    file << "Group: " << getWork() << endl;
    file << "Specialty: " << getNumber() << endl;
    file << "Course: " << getResponse() << endl;
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