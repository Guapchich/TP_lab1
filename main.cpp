#include <iostream>
#include <string>
#include <locale.h>
#include "student.h"
#include "mentor.h"
#include "Admin.h"
#include "university.h"
#include "keeper.h"
#include <conio.h>
#include <windows.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    Keeper keeper;
    char command = 0;
    
    while (command != '7') {
        system("cls");
        cout << "------Меню------" << endl;
        cout << "1. Добавить запись" << endl;
        cout << "2. Изменить запись" << endl;
        cout << "3. Удалить запись" << endl;
        cout << "4. Показать содержимое контейнера" << endl;
        cout << "5. Сохранить в файл" << endl;
        cout << "6. Считать из файла" << endl;
        cout << "7. Закрыть программу" << endl;
        cin >> command;
        system("cls");
        
        switch (command) {
            case '1': {
                getchar();
                char command2 = 0;
                
                while (command2 <= '0' || command2 >= '5') {
                    cout << "1. Добавить студента" << endl;
                    cout << "2. Добавить преподавателя" << endl;
                    cout << "3. Добавить администратора" << endl;
                    cout << "4. Выйти в главное меню" << endl;
                    cin >> command2;
                }
                
                system("cls");
                
                switch (command2) {
                    case '1': {
                        Student* a = new Student();
                        a->input();
                        system("cls");
                        cout << "-----Добавленный Студент-----" << endl;
                        keeper.addUniversity(a);
                        a->print();
                        system("pause");
                        getchar();
                        break;
                    }
                    
                    case '2': {
                        Mentor* a = new Mentor();
                        a->input();
                        system("cls");
                        cout << "-----Добавленный Преподаватель-----" << endl;
                        keeper.addUniversity(a);
                        a->print();
                        system("pause");
                        break;
                    }
                    
                    case '3': {
                        Admin* a = new Admin();
                        a->input();
                        system("cls");
                        cout << "-----Добавленный Администратор-----" << endl;
                        keeper.addUniversity(a);
                        a->print();
                        system("pause");
                        break;
                    }
                }
                break;
            }
            
            case '2': {
                system("cls");
                keeper.changeUniversity();
                system("pause");
                system("cls");
                break;
            }
            
            case '3': {
                system("cls");
                keeper.removeUniversity();
                break;
            }
            
            case '4': {
                system("cls");
                keeper.printUniversity();
                system("pause");
                system("cls");
                break;
            }
            
            case '5': {
                system("cls");
                string fileName;
                cout << "Введите желаемое название файла: ";
                cin >> fileName;
                system("cls");
                keeper.save(fileName);
                system("pause");
                system("cls");
                break;
            }
            
            case '6': {
                system("cls");
                string fileName;
                cout << "Введите название файла: ";
                cin >> fileName;
                system("cls");
                keeper.load(fileName);
                system("pause");
                system("cls");
                break;
            }
            
            default: {
                // Пустой блок для default case
            }
        }
    }
}