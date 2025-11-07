#pragma once
#include <vector>
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include "university.h"

using namespace std;

class Student : public University
{
public:
    Student(const Student& new_Student);
    Student();
    Student(string FIO, string group, string speciality, string course, string av_grad);
    ~Student();
    
    void setFIO(string FIO);
    void setGroup(string group);
    void setSpec(string speciality);
    void setCourse(string course);
    void setAv(string av_grad);
    
    string getFIO();
    string getGroup();
    string getSpec();
    string getCourse();
    string getAv();
    
    void print();
    void input();
    void save(ofstream& file);
    void load(ifstream& file);
    void change();

private:
    string FIO;
    string group;
    string speciality;
    string course;
    string av_grad;
};