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
    Keeper keeper;
    char command = 0;
    
    while (command != '7') {
        system("cls");
        cout << "------Menu------" << endl;
        cout << "1. Add record" << endl;
        cout << "2. Modify record" << endl;
        cout << "3. Delete record" << endl;
        cout << "4. Show container contents" << endl;
        cout << "5. Save to file" << endl;
        cout << "6. Load from file" << endl;
        cout << "7. Close program" << endl;
        cin >> command;
        system("cls");
        
        switch (command) {
            case '1': {
                getchar();
                char command2 = 0;
                
                while (command2 <= '0' || command2 >= '5') {
                    cout << "1. Add student" << endl;
                    cout << "2. Add teacher" << endl;
                    cout << "3. Add administrator" << endl;
                    cout << "4. Return to main menu" << endl;
                    cin >> command2;
                }
                
                system("cls");
                
                switch (command2) {
                    case '1': {
                        Student* a = new Student();
                        a->input();
                        system("cls");
                        cout << "-----Added Student-----" << endl;
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
                        cout << "-----Added Teacher-----" << endl;
                        keeper.addUniversity(a);
                        a->print();
                        system("pause");
                        break;
                    }
                    
                    case '3': {
                        Admin* a = new Admin();
                        a->input();
                        system("cls");
                        cout << "-----Added Administrator-----" << endl;
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
                cout << "Enter desired file name: ";
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
                cout << "Enter file name: ";
                cin >> fileName;
                system("cls");
                keeper.load(fileName);
                system("pause");
                system("cls");
                break;
            }
            
            default: {
                // Empty block for default case
            }
        }
    }
}