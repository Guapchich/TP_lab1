#pragma once
#include "university.h"
#include "linkedlist.h"
#include <iostream>
#include "student.h"
#include "mentor.h"
#include "admin.h"

using namespace std;

class Keeper {
private:
    LinkedList universityList;
    
public:
    Keeper() {};
    ~Keeper() { clearUniversity(); };
    
    void addUniversity(University* university);
    void removeUniversity();
    void changeUniversity();
    void printUniversity() const;
    void clearUniversity();
    void save(string filename);
    void load(string filename);
};