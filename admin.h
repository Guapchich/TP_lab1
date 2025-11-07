#pragma once
#include <vector>
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include "university.h"

using namespace std;

class Admin : public University
{
public:
    Admin(const Admin& new_Admin);
    Admin();
    Admin(string FIO, string work, string number, string response);
    ~Admin();
    
    void setFIO(string FIO);
    void setWork(string Work);
    void setNumber(string number);
    void setResponse(string response);
    
    string getFIO();
    string getWork();
    string getNumber();
    string getResponse();
    
    void print();
    void input();
    void save(ofstream& file);
    void load(ifstream& file);
    void change();

private:
    string FIO;
    string work;
    string number;
    string response;
};