#include "Customer.h"
#include <iostream>
#include "Utils.h"
#include "Bank.h"

using namespace std;

void menu_c() {
    cout << "\n\t\tCustomer Menu\n";
    cout << "1. Create new account\n";
    cout << "2. Update existing account information\n";
    cout << "3. Make transactions\n";
    cout << "4. Check account details\n";
    cout << "5. Transfer funds\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

void customer() {
    int choice;
    Bank bank;

    do {
        system("cls");
        menu_c();
        cin >> choice;

        switch (choice) {
        case 1:
            bank.acc_write();
            break;
        case 2:
            bank.modify_account();
            break;
        case 3:
            bank.deposit_withdraw();
            break;
        case 4:
            bank.search_rec();
            break;
        case 5:
            bank.transfer();
            break;
        case 6:
            return;
        default:
            cout << "\nInvalid choice! Please try again.\n";
            fordelay(1000);
        }
    } while (choice != 6);
}
