#pragma once
#include "university.h"

struct LNode {
    University* university;
    LNode* next;
    
    LNode(University* new_un) : university(new_un), next(nullptr) {}
};

class LinkedList {
private:
    LNode* head;
    size_t size;
    
public:
    LinkedList() : head(nullptr), size(0) {};
    void add(University* university);
    void print() const;
    void print_oneTypeAnimal(int type) const;
    LNode* getHead() { return head; }
    void setHead(LNode* newHead) { head = newHead; }
};