#include "linkedlist.h"
#include <iostream>
#include "student.h"
#include "mentor.h"
#include "admin.h"

void LinkedList::add(University* university) {
    LNode* newNode = new LNode{ university };
    if (head == nullptr) {
        head = newNode;
    } else {
        LNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    ++size;
}

void LinkedList::print() const {
    LNode* current = head;
    while (current != nullptr) {
        current->university->print();
        current = current->next;
    }
}

void LinkedList::print_oneTypeAnimal(int type) const {
    LNode* current = head;
    while (current != nullptr) {
        if (dynamic_cast<Student*>(current->university) && type == 1) {
            current->university->print();
        } else if (dynamic_cast<Admin*>(current->university) && type == 2) {
            current->university->print();
        } else if (dynamic_cast<Mentor*>(current->university) && type == 3) {
            current->university->print();
        }
        current = current->next;
    }
}