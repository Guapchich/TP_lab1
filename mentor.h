#pragma once
#include <vector>
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include "university.h"

using namespace std;

class Mentor : public University
{
public:
    Mentor(const Mentor& new_Mentor);
    Mentor();
    Mentor(string FIO, int gr_size, int obj_size, string* groups, string* objects);
    ~Mentor();
    
    void setFIO(string FIO);
    void setGroup(int gr_size);
    void setObj(int obj_size);
    void setOneGr(int i, string line);
    void setOneObj(int i, string line);
    
    string getFIO();
    int getGr_size();
    void getGroup();
    int getObj_size();
    void getObj();
    
    void print();
    void input();
    void save(ofstream& file);
    void load(ifstream& file);
    void change();

private:
    string FIO;
    static const int gr_size = 10;
    static const int obj_size = 10;
    string groups[gr_size];   // Массив строк (по 50 символов на строку)
    string objects[obj_size];
};