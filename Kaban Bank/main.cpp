#include <iostream>
#include "Employee.h"
#include "Customer.h"
#include "Utils.h"

using namespace std;

void displayMenu() {
    cout << "\n\t\t\t ---------------------" << endl;
    cout << "\t\t\t    | KABAN BANK |" << endl;
    cout << "\t\t\t ---------------------" << endl;
    cout << "\n\n\t\t\t\t MENU\n";
    cout << "\n\t\t1. Employee ";
    cout << "\n\t\t2. Customer ";
    cout << "\n\t\t3. Exit ";
    cout << "\n\t\tEnter Your Choice: ";
}

int main() {
    int choice;

    cout << "\n\n\n\n\n\t\t\t\tWelcome to our bank System";
    fordelay(1000);  // Ёффект загрузки

    do {
        system("cls");
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            employee();
            break;
        case 2:
            customer();
            break;
        case 3:
            close();
            break;
        default:
            cout << "\nInvalid Input! Try Again...\n";
            fordelay(1000);
        }
    } while (choice != 3);

    return 0;
}
