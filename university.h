#pragma once
#include <vector>
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>

using namespace std;

class University
{
public:
    virtual void print() = 0;
    virtual void input() = 0;
    virtual void save(ofstream& file);
    virtual void load(ifstream& file);
    virtual void change();
};