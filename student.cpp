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
    cout << "Copy constructor called" << endl;
    FIO = new_Student.FIO;
    group = new_Student.group;
    speciality = new_Student.speciality;
    course = new_Student.course;
    av_grad = new_Student.av_grad;
}

Student::Student()
{
    cout << "Default constructor called" << endl;
    this->FIO = "None";
    this->group = "None";
    this->speciality = "None";
    this->course = "None";
    this->av_grad = "None";
}

Student::Student(string FIO, string group, string speciality, string course, string av_grad)
{
    cout << "Constructor called" << endl;
    this->FIO = FIO;
    this->group = group;
    this->speciality = speciality;
    this->course = course;
    this->av_grad = av_grad;
}

Student::~Student()
{
    cout << "Destructor called" << endl;
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
    cout << "-----Student-----" << endl;
    cout << "Full Name: " << getFIO() << endl;
    cout << "Group: " << getGroup() << endl;
    cout << "Specialty: " << getSpec() << endl;
    cout << "Course: " << getCourse() << endl;
    cout << "Average Grade: " << getAv() << endl;
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

    cout << " Enter Full Name: " << endl;
    getline(cin, nFIO);
    if (nFIO == "") {
        getline(cin, nFIO);
    }
    setFIO(nFIO);

    cout << "Enter Group: " << endl;
    cin >> ngroup;
    setGroup(ngroup);

    cout << "Enter Specialty: " << endl;
    getline(cin, nspeciality);
    if (nspeciality == "") {
        getline(cin, nspeciality);
    }
    setSpec(nspeciality);

    cout << "Enter Course: " << endl;
    cin >> ncourse;
    try {
        course = stoi(ncourse);
    } catch (std::invalid_argument) {
        std::cout << "Only numbers are allowed! \n";
    }
    if (course > 0) {
        setCourse(ncourse);
    }

    cout << "Enter Average Grade: " << endl;
    cin >> nav_grad;
    try {
        av_grad = stoi(nav_grad);
    } catch (std::invalid_argument) {
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

    cout << "Enter new Group: " << endl;
    cin >> ngroup;
    if (ngroup == "N") {
    } else {
        setGroup(ngroup);
    }

    cout << "Enter new Specialty: " << endl;
    getline(cin, nspeciality);
    if (nspeciality == "") {
        getline(cin, nspeciality);
    }
    if (nspeciality == "N") {
    } else {
        setSpec(nspeciality);
    }

    cout << "Enter new Course: " << endl;
    cin >> ncourse;
    if (ncourse == "N") {
    } else {
        try {
            course = stoi(ncourse);
        } catch (std::invalid_argument) {
            std::cout << "Only numbers are allowed! \n";
        }
        if (course > 0) {
            setCourse(ncourse);
        }
    }

    cout << "Enter new Average Grade: " << endl;
    cin >> nav_grad;
    if (nav_grad == "N") {
    } else {
        try {
            av_grad = stoi(nav_grad);
        } catch (std::invalid_argument) {
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
    file << "-----Student-----" << endl;
    file << "Name: " << getFIO() << endl;
    file << "Group: " << getGroup() << endl;
    file << "Specialty: " << getSpec() << endl;
    file << "Course: " << getCourse() << endl;
    file << "Average Grade: " << getAv() << endl;
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