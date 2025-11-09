#include <iostream>
#include <fstream>
#include "keeper.h"
#include "university.h"
#include <string>

void Keeper::addUniversity(University* university) {
    universityList.add(university);
}

void Keeper::printUniversity() const {
    universityList.print();
}

void Keeper::clearUniversity() {
    LNode* current = universityList.getHead();
    while (current != nullptr) {
        LNode* next = current->next;
        delete current->university;
        delete current;
        current = next;
    }
    universityList = LinkedList();
}

void Keeper::save(string filename) {
    LNode* current = universityList.getHead();
    ofstream file(filename);
    
    if (file.is_open()) {
        while (current != nullptr) {
            current->university->save(file);
            current = current->next;
        }
        file.close();
        cout << "Keeper saved to file!" << endl;
    } else {
        cout << "File opening error" << endl;
    }
}

void Keeper::load(string filename) {
    int answer = 0;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "File opening error" << endl;
        return;
    }
    
    cout << "File opened" << endl;
    cout << "When loading data from file, your current entered data will be cleared. "
         << "Do you want to continue?\n1 - Yes\n2 - Return to menu" << endl;
    cin >> answer;
    
    if (answer == 2) {
        return;
    }
    
    if (answer != 1 && answer != 2) {
        cout << "Invalid value. Please try again";
        return;
    }
    
    clearUniversity();
    string type;
    
    while (file >> type) {
        University* unit = nullptr;
        
        if (type == "-----Student-----")
            unit = new Student();
        else if (type == "-----Teacher-----")
            unit = new Mentor();
        else if (type == "-----Administrator-----")
            unit = new Admin();
            
        if (unit) {
            unit->load(file);
            addUniversity(unit);
        }
    }
    
    file.close();
    system("cls");
    cout << "University list successfully loaded from file." << endl;
}

void Keeper::removeUniversity() {
    char command = 0;
    string FIOstudent, FIOmentor, FIOadmin;
    LNode* current = universityList.getHead();
    LNode* prev = nullptr;
    
    while (command != '4') {
        cout << "Who do you want to remove?\n"
             << "1. Student\n"
             << "2. Teacher\n"
             << "3. Administrator\n"
             << "4. Exit\n";
        cin >> command;
        
        switch (command) {
            case '1': {
                cout << "Enter student's full name: ";
                getline(cin, FIOstudent);
                if (FIOstudent == "") {
                    getline(cin, FIOstudent);
                }
                
                while (current != nullptr) {
                    Student* student = dynamic_cast<Student*>(current->university);
                    if (student != nullptr && student->getFIO() == FIOstudent) {
                        // If Student found
                        if (prev == nullptr) {
                            // Remove first element
                            universityList.setHead(current->next);
                        } else {
                            // Move to next element
                            prev->next = current->next;
                        }
                        
                        delete current->university; // Delete object
                        delete current; // Delete node
                        cout << "Student with full name " << FIOstudent << " successfully removed." << endl;
                        return;
                    }
                    prev = current;
                    current = current->next;
                }
                break;
            }
            
            case '2': {
                cout << "Enter teacher's full name: ";
                getline(cin, FIOmentor);
                if (FIOmentor == "") {
                    getline(cin, FIOmentor);
                }
                
                while (current != nullptr) {
                    Mentor* mentor = dynamic_cast<Mentor*>(current->university);
                    if (mentor != nullptr && mentor->getFIO() == FIOmentor) {
                        // If Teacher found
                        if (prev == nullptr) {
                            // Remove first element
                            universityList.setHead(current->next);
                        } else {
                            // Move to next
                            prev->next = current->next;
                        }
                        
                        delete current->university; // Delete object
                        delete current; // Delete node
                        cout << "Teacher with full name " << FIOmentor << " successfully removed." << endl;
                        return;
                    }
                    prev = current;
                    current = current->next;
                }
                break;
            }
            
            case '3': {
                cout << "Enter administrator's full name: ";
                getline(cin, FIOadmin);
                if (FIOadmin == "") {
                    getline(cin, FIOadmin);
                }
                
                while (current != nullptr) {
                    Admin* admin = dynamic_cast<Admin*>(current->university);
                    if (admin != nullptr && admin->getFIO() == FIOadmin) {
                        // If Administrator found
                        if (prev == nullptr) {
                            // Remove first element
                            universityList.setHead(current->next);
                        } else {
                            // Move to next
                            prev->next = current->next;
                        }
                        
                        delete current->university; // Delete Administrator object
                        delete current; // Delete node
                        cout << "Administrator with full name " << FIOadmin << " successfully removed." << endl;
                        return;
                    }
                    prev = current;
                    current = current->next;
                }
                break;
            }
            
            case '4': {
                break;
            }
            
            default: {}
        }
    }
}

void Keeper::changeUniversity() {
    char command = 0;
    string FIOstudent, FIOmentor, FIOadmin;
    LNode* current = universityList.getHead();
    LNode* prev = nullptr;
    
    while (command != '4') {
        cout << "Who do you want to modify?\n"
             << "1. Student\n"
             << "2. Teacher\n"
             << "3. Administrator\n"
             << "4. Exit\n";
        cin >> command;
        
        switch (command) {
            case '1': {
                system("cls");
                universityList.print();
                cout << endl;
                cout << "Enter student's full name: ";
                getline(cin, FIOstudent);
                if (FIOstudent == "") {
                    getline(cin, FIOstudent);
                }
                system("cls");
                
                while (current != nullptr) {
                    Student* student = dynamic_cast<Student*>(current->university);
                    if (student != nullptr && student->getFIO() == FIOstudent) {
                        student->change();
                        return;
                    }
                    prev = current;
                    current = current->next;
                }
                break;
            }
            
            case '2': {
                system("cls");
                universityList.print();
                cout << "Enter teacher's full name: ";
                getline(cin, FIOmentor);
                if (FIOmentor == "") {
                    getline(cin, FIOmentor);
                }
                system("cls");
                
                while (current != nullptr) {
                    Mentor* mentor = dynamic_cast<Mentor*>(current->university);
                    if (mentor != nullptr && mentor->getFIO() == FIOmentor) {
                        mentor->change();
                        return;
                    }
                    prev = current;
                    current = current->next;
                }
                break;
            }
            
            case '3': {
                system("cls");
                universityList.print();
                cout << "Enter administrator's full name: ";
                getline(cin, FIOadmin);
                if (FIOadmin == "") {
                    getline(cin, FIOadmin);
                }
                system("cls");
                
                while (current != nullptr) {
                    Admin* admin = dynamic_cast<Admin*>(current->university);
                    if (admin != nullptr && admin->getFIO() == FIOadmin) {
                        admin->change();
                        return;
                    }
                    prev = current;
                    current = current->next;
                }
                break;
            }
            
            case '4': {
                break;
            }
            
            default: {}
        }
    }
}