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
        cout << "Keeper записан в файл!" << endl;
    } else {
        cout << "Ошибка открытия файла" << endl;
    }
}

void Keeper::load(string filename) {
    int answer = 0;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "Ошибка открытия файла" << endl;
        return;
    }
    
    cout << "Файл открыт" << endl;
    cout << "При загрузке данных из файла, текущие внесенные вами данные будут очищены. "
         << "Вы хотите продолжить?\n1 - Да\n2 - Выйти в меню" << endl;
    cin >> answer;
    
    if (answer == 2) {
        return;
    }
    
    if (answer != 1 && answer != 2) {
        cout << "Неверное значение. Попробуйте снова";
        return;
    }
    
    clearUniversity();
    string type;
    
    while (file >> type) {
        University* unit = nullptr;
        
        if (type == "-----Студент-----")
            unit = new Student();
        else if (type == "-----Преподаватель-----")
            unit = new Mentor();
        else if (type == "-----Администратор-----")
            unit = new Admin();
            
        if (unit) {
            unit->load(file);
            addUniversity(unit);
        }
    }
    
    file.close();
    system("cls");
    cout << "Список ВУЗА успешно загружен из файла." << endl;
}

void Keeper::removeUniversity() {
    char command = 0;
    string FIOstudent, FIOmentor, FIOadmin;
    LNode* current = universityList.getHead();
    LNode* prev = nullptr;
    
    while (command != '4') {
        cout << "Кого вы хотите удалить?\n"
             << "1. Студент\n"
             << "2. Преподаватель\n"
             << "3. Администратор\n"
             << "4. Выход\n";
        cin >> command;
        
        switch (command) {
            case '1': {
                cout << "Введите ФИО студента: ";
                getline(cin, FIOstudent);
                if (FIOstudent == "") {
                    getline(cin, FIOstudent);
                }
                
                while (current != nullptr) {
                    Student* student = dynamic_cast<Student*>(current->university);
                    if (student != nullptr && student->getFIO() == FIOstudent) {
                        // Если Студент найден
                        if (prev == nullptr) {
                            // Удаляем первый элемент
                            universityList.setHead(current->next);
                        } else {
                            // Переходим к следующему элементу
                            prev->next = current->next;
                        }
                        
                        delete current->university; // Удаляем объект
                        delete current; // Удаляем узел
                        cout << "Студент с ФИО " << FIOstudent << " успешно удален." << endl;
                        return;
                    }
                    prev = current;
                    current = current->next;
                }
                break;
            }
            
            case '2': {
                cout << "Введите ФИО преподавателя: ";
                getline(cin, FIOmentor);
                if (FIOmentor == "") {
                    getline(cin, FIOmentor);
                }
                
                while (current != nullptr) {
                    Mentor* mentor = dynamic_cast<Mentor*>(current->university);
                    if (mentor != nullptr && mentor->getFIO() == FIOmentor) {
                        // Если Преподаватель найден
                        if (prev == nullptr) {
                            // Удаляем первый элемент
                            universityList.setHead(current->next);
                        } else {
                            // Переходим к следующему
                            prev->next = current->next;
                        }
                        
                        delete current->university; // Удаляем объект
                        delete current; // Удаляем узел
                        cout << "Преподаватель с ФИО " << FIOmentor << " успешно удален." << endl;
                        return;
                    }
                    prev = current;
                    current = current->next;
                }
                break;
            }
            
            case '3': {
                cout << "Введите ФИО Администратора: ";
                getline(cin, FIOadmin);
                if (FIOadmin == "") {
                    getline(cin, FIOadmin);
                }
                
                while (current != nullptr) {
                    Admin* admin = dynamic_cast<Admin*>(current->university);
                    if (admin != nullptr && admin->getFIO() == FIOadmin) {
                        // Если Администратор найден
                        if (prev == nullptr) {
                            // Удаляем первый элемент
                            universityList.setHead(current->next);
                        } else {
                            // Переходим к следующему
                            prev->next = current->next;
                        }
                        
                        delete current->university; // Удаляем объект Администратора
                        delete current; // Удаляем узел
                        cout << "Администратор с ФИО " << FIOadmin << " успешно удален." << endl;
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
        cout << "Кого вы хотите изменить?\n"
             << "1. Студент\n"
             << "2. Преподаватель\n"
             << "3. Администратор\n"
             << "4. Выход\n";
        cin >> command;
        
        switch (command) {
            case '1': {
                system("cls");
                universityList.print();
                cout << endl;
                cout << "Введите ФИО Студента: ";
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
                cout << "Введите ФИО преподавателя: ";
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
                cout << "Введите ФИО администратора: ";
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