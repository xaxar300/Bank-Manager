
#include <iostream>
#include <string>
#include <conio.h>
#include "Utils.h" 
#include"Bank.h"
using namespace std;
void menu_e();
void employee() {
    string name, password;
    const string validPassword = "1234";
    const string validUser1 = "Arseniy";
    const string validUser2 = "Nosovich";
    bool loginSuccessful = false;

    while (!loginSuccessful) {
        system("cls");

        cout << "\n\n\t\tFor Security Purpose:";
        cout << "\n\n\t\tEnter the Login Employee Id: ";
        cin >> name;

        cout << "\n\n\t\tEnter the password to login: ";

        // Считывание пароля без отображения символов
        char ch;
        while (true) {
            ch = _getch(); // Для безопасного ввода пароля
            if (ch == '\r') break; // Если нажата клавиша Enter, завершаем ввод
            if (ch == '\b') { // Для обработки backspace
                if (!password.empty()) {
                    password.pop_back();
                    cout << "\b \b"; // Убираем последний символ на экране
                }
            }
            else {
                password += ch;
                cout << "*"; // Выводим * вместо символа
            }
        }

        // Проверка на правильность пароля и имени
        if (password == validPassword && (name == validUser1 || name == validUser2)) {
            cout << "\n\nAccess Granted!\nLOADING";
            for (int i = 0; i < 6; i++) {
                printf(".");
                fordelay(500); // Задержка в 500 миллисекунд
            }
            loginSuccessful = true;
            menu_e(); // После успешного входа, переход в меню сотрудника
        }
        else {
            cout << "\n\nWrong password or Employee Id!!\n";
            int main_exit;
            cout << "\nEnter 1 to try again, 2 for Main Menu, or 0 to Exit: ";
            cin >> main_exit;

            if (main_exit == 1) {
                continue; // Попробовать снова
            }
            else if (main_exit == 0) {
                system("cls");
                close(); // Закрытие программы
            }
            else if (main_exit == 2) {
                system("cls");
                close(); // Возврат в главное меню
            }
            else {
                cout << "\nInvalid input!";
                fordelay(1000);
            }
        }
    }
}


void menu_e() {
    int choice;
    Bank B;

    while (true) {
        system("cls");
        system("color 2");

        // Главное меню для сотрудника
        cout << "\n\n\t\t\tBANK RECORD SYSTEM";
        cout << "\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME "
            << "TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2";
        cout << "\n\n\t\t\tEmployee Menu";
        cout << "\n\t\t1. Check the details of existing account\n";
        cout << "\t\t2. Display All Account Holder Name\n";
        cout << "\t\t3. Exit\n\n\n\n\n\t\t Enter your choice: ";
        cin >> choice;
        system("cls");

        // Обработка выбора пользователя
        switch (choice) {
        case 1:
            B.search_rec();
            break;
        case 2:
            B.display_all();
            break;
        case 3:
            close();
            return;  // Закрытие программы
        default:
            cout << "Invalid Input!\nTry Again\n";
            break;
        }

        // Запрос на переход в главное меню или выход
        int main_exit;
        while (true) {
            cout << "\nEnter 1 for Main Menu, 2 for Previous Menu, and 0 to Exit: ";
            cin >> main_exit;

            if (main_exit == 1) {
                system("cls");
                close();// Возврат в главное меню
                return;
            }
            else if (main_exit == 0) {
                system("cls");
                close();  // Закрытие программы
                return;
            }
            else if (main_exit == 2) {
                system("cls");
                employee();  // Переход в меню сотрудника
                return;
            }
            else {
                cout << "\nInvalid Input! Please try again.\n";
            }
        }
    }
}
