#define _CRT_SECURE_NO_WARNINGS
#include "Bank.h"
#include"Utils.h"
#include"Customer.h"
#include"Employee.h"
int main_exit;
using namespace std;
void Bank::read_data()
{
    int x, i = 0;
    string acc_no;

    while (true) {
        cout << "\nEnter Account Number: ";
        cin >> account_number;

        ifstream is("Account_info.csv");
        bool accountExists = false;

        while (is.good()) {
            getline(is, acc_no, ',');
            getline(is, password, '\n');

            if (acc_no == account_number) {
                accountExists = true;
                break;
            }
        }

        is.close();

        if (accountExists) {
            cout << "\nAccount No. Matches with Existing Account!";
            cout << "\n1. Try Again!\n2. Login To Account\nEnter your choice: ";
            cin >> x;

            if (x == 1) {
                continue;  // Retry entering account number
            }
            else if (x == 2) {
                customer();
                return;  // Exit the function after login
            }
            else {
                cout << "\nInvalid choice! Please try again.\n";
            }
        }
        else {
            break;  // Account does not exist, proceed to collect data
        }
    }

    fflush(stdin);
    cout << "\nEnter Name: ";
    cin.ignore();  // Clear buffer
    getline(cin, name);

    cout << "\nEnter the date of birth (mm/dd/yyyy): ";
    cin >> dob;

    cout << "\nEnter the age: ";
    cin >> age;

    cout << "\nEnter the address: ";
    cin.ignore();  // Clear buffer
    getline(cin, address);

    cout << "\nEnter the phone number: ";
    cin >> phone;

    cout << "\nDo you want to deposit amount?\n\t1. Yes\n\t2. No\nEnter your choice: ";
    cin >> x;

    if (x == 1) {
        cout << "\nEnter the amount to deposit: Byn ";
        cin >> depo;
    }
    else {
        depo = "0";
    }

    cout << "\nType of account:\n\t# Saving\n\t# Current\nEnter your choice: ";
    cin >> acc_type;

    cout << endl;
    time_t now = time(0);
    string dt = ctime(&now);
    cout << "\nDate and Time of Account Creation: " << dt << endl;
    date = dt;

    struct tm* ltm = localtime(&now);
    doc = to_string(ltm->tm_mday);
    interest = to_string(i++);

    cout << "\nEnter Password For Your Account: ";
    cin >> password;

    printf("\nAccount created successfully!");

    bool validChoice = false;
    while (!validChoice) {
        cout << "\n\nEnter 1. For Main Menu\n\t2. For Previous Menu\n\t0. To Exit: ";
        cin >> main_exit;

        switch (main_exit) {
        case 1:
            system("cls");
            close();
            validChoice = true;
            break;
        case 0:
            system("cls");
            close();
            validChoice = true;
            break;
        case 2:
            system("cls");
            menu_c();
            validChoice = true;
            break;
        default:
            cout << "\nInvalid choice! Please try again.";
            fordelay(1000000000);
            system("cls");
            break;
        }
    }
}

void Bank::acc_write() {
	ofstream MyFile1, MyFile2;
	read_data();
	MyFile1.open("Bank_Record.csv", ios::out | ios::app);
	MyFile1 << account_number << "," << name << "," << dob << ","
		<< age << "," << address << "," << phone << "," << depo
		<< "," << acc_type << "," << date << "," << doc << "," << interest << "\n";
	MyFile1.close();
	MyFile2.open("Account_info.csv", ios::out | ios::app);
	MyFile2 << account_number << "," << password << "," << "\n";
	MyFile2.close();
}

void Bank::modify_account() {
    int test = 0;
    string acc_no, account_number, name, dob, age, address, phone, depo, acc_type, date, doc, interest, x, y, z;
    int choice, opt, main_exit;

    cout << "For Verification:\n";
    cout << "Enter the Account Number again: ";
    cin >> acc_no;

    ifstream is("Bank_Record.csv");
    while (getline(is, account_number, ','))
    {
        getline(is, name, ',');
        getline(is, dob, ',');
        getline(is, age, ',');
        getline(is, address, ',');
        getline(is, phone, ',');
        getline(is, depo, ',');
        getline(is, acc_type, ',');
        getline(is, date, ',');
        getline(is, doc, ',');
        getline(is, interest, '\n');

        if (acc_no == account_number)
        {
            test = 1;
            cout << "\nAccount NO.:" << account_number << endl;
            cout << "\nName: " << name << endl;
            cout << "\nDOB: " << dob << endl;
            cout << "\nAge: " << age << endl;
            cout << "\nAddress: " << address << endl;
            cout << "\nPhone number: " << phone << endl;
            cout << "\nType Of Account: " << acc_type << endl;
            cout << "\nDate of Account creation: " << date << endl;
            cout << "\nAmount deposited: " << depo << endl;
            break;
        }
    }
    is.close();

    if (test == 1)
    {
        ifstream file("Bank_Record.csv");
        ofstream ofile("temp.csv");

        do
        {
            cout << "\n\n\n\t\t1.Update Name\n";
            cout << "\t\t2.Update DOB Of Birth\n";
            cout << "\t\t3.Update Age\n";
            cout << "\t\t4.Update Address\n";
            cout << "\t\t5.Update Phone No.\n";
            cin >> choice;

            switch (choice)
            {
            case 1:
                system("color 3");
                cout << "\t\tUpdate Name\n\n";
                cout << "Enter Old Name: ";
                cin >> y;
                cout << "Enter New Name: ";
                cin >> z;
                while (!file.eof())
                {
                    getline(file, x, ',');
                    if (x == y)
                        ofile << z << ",";
                    else
                        ofile << x << ",";
                }
                break;

            case 2:
                system("color 4");
                cout << "\t\tUpdate DOB Of Birth\n\n";
                cout << "Enter Old DOB Of Birth(mm/dd/yyyy): ";
                cin >> y;
                cout << "Enter New DOB Of Birth(mm/dd/yyyy): ";
                cin >> z;
                while (!file.eof())
                {
                    getline(file, x, ',');
                    if (x == y)
                        ofile << z << ",";
                    else
                        ofile << x << ",";
                }
                break;

            case 3:
                system("color 5");
                cout << "\t\tUpdate Age\n\n";
                cout << "Enter Old Age: ";
                cin >> y;
                cout << "Enter New Age: ";
                cin >> z;
                while (!file.eof())
                {
                    getline(file, x, ',');
                    if (x == y)
                        ofile << z << ",";
                    else
                        ofile << x << ",";
                }
                break;

            case 4:
                system("color 6");
                cout << "\t\tUpdate Address\n\n";
                cout << "Enter Old Address: ";
                cin >> y;
                cout << "Enter New Address: ";
                cin >> z;
                while (!file.eof())
                {
                    getline(file, x, ',');
                    if (x == y)
                        ofile << z << ",";
                    else
                        ofile << x << ",";
                }
                break;

            case 5:
                system("color 2");
                cout << "\t\tUpdate Phone No.\n\n";
                cout << "Enter Old Phone No.: ";
                cin >> y;
                cout << "Enter New Phone No.: ";
                cin >> z;
                while (!file.eof())
                {
                    getline(file, x, ',');
                    if (x == y)
                        ofile << z << ",";
                    else
                        ofile << x << ",";
                }
                break;

            default:
                cout << "Invalid Input" << endl;
            }

            remove("Bank_Record.csv");
            rename("temp.csv", "Bank_Record.csv");
            file.seekg(0, ios::beg);
            ofile.seekp(0, ios::beg);

            cout << "\n\n\t\tDo You Want To Update Any Other Field: "
                << "\n\t\t1: YES\n\t\t2: NO\n";
            cin >> opt;

        } while (opt != 2);

        file.close();
        ofile.close();
    }
    else
    {
        cout << "\nAccount Doesn't Exist" << endl;
    }

    bool validExitChoice = false;
    while (!validExitChoice)
    {
        cout << "\nEnter 1 for Main Menu, 2 for Previous Menu, or 0 to Exit: ";
        cin >> main_exit;

        switch (main_exit)
        {
        case 1:
            system("cls");
            close();
            validExitChoice = true;
            break;
        case 0:
            system("cls");
            close();
            validExitChoice = true;
            break;
        case 2:
            system("cls");
            menu_c();
            validExitChoice = true;
            break;
        default:
            cout << "\nInvalid Input! Please try again." << endl;
        }
    }
}

void Bank::deposit_withdraw() {
    int choice, test = 0, amt, amount;
    string acc_no, y, x;
    ifstream file("Bank_Record.csv");
    ofstream ofile("temp.csv");
    Bank ac;
    cout << "Enter the account number:";
    cin >> acc_no;
    do
    {
        getline(file, account_number, ',');
        getline(file, name, ',');
        getline(file, dob, ',');
        getline(file, age, ',');
        getline(file, address, ',');
        getline(file, phone, ',');
        getline(file, depo, ',');
        getline(file, acc_type, ',');
        getline(file, date, ',');
        getline(file, doc, ',');
        getline(file, interest, '\n');
        amount = atoi(depo.c_str());
        if (acc_no == account_number)
        {
            test = 1;
            cout << "\nAccount No.:" << account_number << endl;
            cout << "\nName:" << name << endl;
            cout << "\nDOB:" << dob << endl;
            cout << "\nAge:" << age << endl;
            cout << "\nAddress: " << address << endl;
            cout << "\nPhone number:" << phone << endl;
            cout << "\nDate of Creation: " << date << endl;
            cout << "\nType Of Account:" << acc_type << endl;
            cout << "\nBalance:" << depo << endl;
            test = 1;
            cout << "\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\n"
                << "Enter your choice(1 for deposit and 2 for withdraw):";
            cin >> choice;
            if (choice == 1)
            {
                cout << "Enter the amount you want to deposit: ";
                cin >> amt;
                file.seekg(0, ios::beg);
                amt = atoi(depo.c_str()) + amt;
                y = to_string(amt);
                cout << "\n\tBalance : " << y;
                int i = 1;
                while (file.good())
                {
                    getline(file, x, ',');
                    if (x == depo)
                    {
                        ofile << y << ",";
                    }
                    else
                    {
                        ofile << x << ",";
                    }
                }
                printf("\n\nDeposited successfully!");
            }
            else
            {
                cout << "Enter the amount you want to Withdraw: ";
                cin >> amt;
                file.seekg(0, ios::beg);
                if (amt > atoi(depo.c_str()))
                    cout << "Not Enough Balance\n";
                else
                {
                    amt = atoi(depo.c_str()) - amt;
                    y = std::to_string(amt);
                    cout << "\n\tBalance : " << y;
                    while (file.good())
                    {
                        getline(file, x, ',');
                        if (x == depo)
                            ofile << y << ",";
                        else
                            ofile << x << ",";
                    }
                    printf("\n\nWithdrawn successfully!");
                }
            }
        }
    } while (file.good());
    file.close();
    ofile.close();
    remove("Bank_Record.csv");
    rename("temp.csv", "Bank_Record.csv");

    if (test == 0)
    {
        cout << "\n\nRecord not found!!";
    login_try:
        cout << "\nEnter 1. For Main Menu\n\t2. For Previous Menu and"
            << " 0 to try again:";
        scanf("%d", &main_exit);
        if (main_exit == 1)
        {
            system("cls");
            close();
        }
        else if (main_exit == 0)
        {
            system("cls");
            ac.deposit_withdraw();
        }
        else if (main_exit == 2)
        {
            system("cls");
            employee();
        }
        else
        {
            printf("\nInvalid!");
            fordelay(1000000000);
            system("cls");
            goto login_try;
        }
    }
    else
    {
    login_try1:
        cout << "\nEnter 1. For Main Menu\n\t2. For Previous Menu "
            << "and 0 to Exit:";
        scanf("%d", &main_exit);
        if (main_exit == 1)
        {
            system("cls");
            close();
        }
        else if (main_exit == 0)
        {
            system("cls");
            close();
        }
        else if (main_exit == 2)
        {
            system("cls");
            menu_c();
        }
        else
        {
            printf("\nInvalid!");
            fordelay(1000000000);
            system("cls");
            goto login_try1;
        }
    }

}

void Bank::display_all()
{
    int amount;
    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "====================================================="
        << "========================================================="
        << "=========================\n";
    cout << "  Account No.\t\tName\t\tType\t\tBalance\t\tAddress"
        << "\t\tPhone No.\t\tCreation Date\n";
    cout << "====================================================="
        << "========================================================="
        << "=========================\n";
    ifstream is("Bank_record.csv");
    int i = 1, sz = 0, sz1 = 0;
    char c;
    is.seekg(0, ios::end);
    sz = is.tellg();
    //cout<<sz<<endl;
    is.seekg(0, ios::beg);
    while (!is.eof())
    {
        cout << i << ". ";
        i++;
        getline(is, account_number, ',');
        getline(is, name, ',');
        getline(is, dob, ',');
        getline(is, age, ',');
        getline(is, address, ',');
        getline(is, phone, ',');
        getline(is, depo, ',');
        getline(is, acc_type, ',');
        getline(is, date, ',');
        getline(is, doc, ',');
        getline(is, interest, '\n');
        amount = atoi(depo.c_str());
        sz1 = is.tellg();
        //cout<<sz1<<" ";
        cout << account_number << "\t\t" << name << "\t\t" << acc_type
            << "\t\t" << amount << "\t\t" << address << "\t\t"
            << phone << "\t\t" << date << endl;
        if (sz == (sz1))
            break;
    }
login_try:
    cout << "\nEnter 1. For Main Menu\n\t2. For Previous Menu "
        << "and 0 to Exit:";
    scanf("%d", &main_exit);
    if (main_exit == 1)
    {
        system("cls");
        close();
    }
    else if (main_exit == 0)
    {
        system("cls");
        close();
    }
    else if (main_exit == 2)
    {
        system("cls");
        menu_e();
    }
    else
    {
        printf("\nInvalid!");
        fordelay(1000000000);
        system("cls");
        goto login_try;
    }
}

void Bank::transfer()
{
    int amount, amt, test = 0;
    string acc_no, y, x, account_number, name, dob, age, address, phone, depo, acc_type, date, doc, interest;

    ifstream file("Bank_Record.csv");
    ofstream ofile("temp.csv");

    cout << "Enter Your account number: ";
    cin >> acc_no;

    // Ïîèñê è âûâîä èíôîðìàöèè îá àêêàóíòå îòïðàâèòåëÿ
    do {
        getline(file, account_number, ',');
        getline(file, name, ',');
        getline(file, dob, ',');
        getline(file, age, ',');
        getline(file, address, ',');
        getline(file, phone, ',');
        getline(file, depo, ',');
        getline(file, acc_type, ',');
        getline(file, date, ',');
        getline(file, doc, ',');
        getline(file, interest, '\n');

        if (acc_no == account_number) {
            test = 1;
            cout << "Account No.:" << account_number << endl;
            cout << "Name:" << name << endl;
            cout << "DOB:" << dob << endl;
            cout << "Age:" << age << endl;
            cout << "Address: " << address << endl;
            cout << "Phone number: " << phone << endl;
            cout << "Type Of Account:" << acc_type << endl;
            cout << "Balance:" << depo << endl;

            cout << "\nEnter the amount you want to transfer: ";
            cin >> amt;

            file.seekg(0, ios::beg);

            if (amt > atoi(depo.c_str())) {
                cout << "Not Enough Balance\n";
            }
            else {
                amount = atoi(depo.c_str()) - amt;
                y = std::to_string(amount);
                cout << "\n\tBalance : " << y;

                while (file.good()) {
                    getline(file, x, ',');
                    if (x == depo) {
                        ofile << y << ",";
                    }
                    else {
                        ofile << x << ",";
                    }
                }
            }
            break;
        }
    } while (file.good());

    file.close();
    ofile.close();
    remove("Bank_Record.csv");
    rename("temp.csv", "Bank_Record.csv");

    if (test == 0) {
        cout << "\n\n\t\tAccount doesn't Exist!";
    }
    else {
        test = 0;
        cout << "\nEnter account number where to transfer: ";
        cin >> acc_no;

        file.open("Bank_Record.csv");
        ofile.open("temp.csv");

        file.seekg(0, ios::beg);

        // Ïîèñê è îáíîâëåíèå èíôîðìàöèè î ïîëó÷àòåëå
        do {
            getline(file, account_number, ',');
            getline(file, name, ',');
            getline(file, dob, ',');
            getline(file, age, ',');
            getline(file, address, ',');
            getline(file, phone, ',');
            getline(file, depo, ',');
            getline(file, acc_type, ',');

            if (acc_no == account_number) {
                test = 1;
                cout << "Account No.:" << account_number << endl;
                cout << "Name:" << name << endl;

                amt = atoi(depo.c_str()) + amt;
                y = std::to_string(amt);
                file.seekg(0, ios::beg);

                while (file.good()) {
                    getline(file, x, ',');
                    if (x == depo) {
                        ofile << y << ",";
                    }
                    else {
                        ofile << x << ",";
                    }
                }

                cout << "\n\tTransfer Successful!";
                break;
            }
        } while (file.good());

        file.close();
        ofile.close();
        remove("Bank_Record.csv");
        rename("temp.csv", "Bank_Record.csv");

        if (test == 0) {
            cout << "\n\n\t\tAccount doesn't Exist!";
        }
    }

    // Ìåíþ ïîñëå âûïîëíåíèÿ îïåðàöèè
    bool validExitChoice = false;
    while (!validExitChoice) {
        int main_exit;
        cout << "\nEnter 1 for Main Menu, 2 for Previous Menu, or 0 to Exit: ";
        cin >> main_exit;

        switch (main_exit) {
        case 1:
            system("cls");
            close();
            validExitChoice = true;
            break;
        case 0:
            system("cls");
            close();
            validExitChoice = true;
            break;
        case 2:
            system("cls");
            menu_c();
            validExitChoice = true;
            break;
        default:
            cout << "\nInvalid Input! Please try again." << endl;
        }
    }

}

void Bank::search_rec() {
    int test = 0, rate;
    int choice, date1;
    float t;
    string intrst, x, y;
    int amount, b;
    string acc_no, name_s;
    ifstream is("Bank_Record.csv");

    cout << "Do you want to check by\n1.Account no\n2.Name"
        << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {  // Ïîèñê ïî íîìåðó ñ÷åòà
        cout << "Enter the account number: ";
        cin >> acc_no;

        do {
            getline(is, account_number, ',');
            getline(is, name, ',');
            getline(is, dob, ',');
            getline(is, age, ',');
            getline(is, address, ',');
            getline(is, phone, ',');
            getline(is, depo, ',');
            getline(is, acc_type, ',');
            getline(is, date, ',');
            getline(is, doc, ',');
            getline(is, interest, '\n');

            amount = atoi(depo.c_str());
            if (acc_no == account_number) {
                test = 1;
                system("cls");
                cout << "\nAccount NO.:" << account_number << endl;
                cout << "\nName: " << name << endl;
                cout << "\nDOB: " << dob << endl;
                cout << "\nAge: " << age << endl;
                cout << "\nAddress: " << address << endl;
                cout << "\nPhone number: " << phone << endl;
                cout << "\nType Of Account: " << acc_type << endl;
                cout << "\nDate of Account creation: " << date << endl;
                cout << "\nAmount deposited: " << depo << endl;

                ifstream file("Bank_Record.csv");
                ofstream ofile("temp.csv");

                if (acc_type == "Saving" || acc_type == "Current") {
                    time_t now = time(0);
                    struct tm* ltm = localtime(&now);
                    date1 = ltm->tm_mday;

                    if (date1 != atoi(doc.c_str())) {
                        t = date1 - atoi(doc.c_str());
                        rate = 15;
                        intrst = std::to_string(inter(t, amount, rate));
                        cout << "\n\nYou will get BYN " << intrst << " as interest";
                        file.clear();
                        while (!file.eof()) {
                            getline(file, x, ',');
                            if (x == interest) {
                                ofile << intrst << ",";
                            }
                            else if (x == depo) {
                                y = (atoi(depo.c_str()) + atoi(intrst.c_str()));
                                ofile << y << ",";
                            }
                            else {
                                ofile << x << ",";
                            }
                        }
                    }
                    else {
                        cout << "\n\nYou will get BYN 0 as interest for today...";
                    }
                    break;
                }
            }
        } while (is.good());
    }
    else if (choice == 2) {  // Ïîèñê ïî èìåíè
        cout << "Enter the Name of Account Holder: ";
        cin >> name_s;

        do {
            getline(is, account_number, ',');
            getline(is, name, ',');
            getline(is, dob, ',');
            getline(is, age, ',');
            getline(is, address, ',');
            getline(is, phone, ',');
            getline(is, depo, ',');
            getline(is, acc_type, ',');
            getline(is, date, ',');
            getline(is, doc, ',');
            getline(is, interest, '\n');

            amount = atoi(depo.c_str());
            if (name_s == name) {
                test = 1;
                system("cls");
                cout << "\nAccount NO.:" << account_number << endl;
                cout << "\nName: " << name << endl;
                cout << "\nDOB: " << dob << endl;
                cout << "\nAge: " << age << endl;
                cout << "\nAddress: " << address << endl;
                cout << "\nPhone number: " << phone << endl;
                cout << "\nType Of Account: " << acc_type << endl;
                cout << "\nDate of Account creation: " << date << endl;
                cout << "\nAmount deposited: " << depo << endl;

                ifstream file("Bank_Record.csv");
                ofstream ofile("temp.csv");

                if (acc_type == "Saving" || acc_type == "Current") {
                    time_t now = time(0);
                    struct tm* ltm = localtime(&now);
                    date1 = ltm->tm_mday;

                    if (date1 != atoi(doc.c_str())) {
                        t = date1 - atoi(doc.c_str());
                        rate = 15;
                        intrst = std::to_string(inter(t, amount, rate));
                        cout << "\n\nYou will get BYN " << intrst << " as interest";
                        file.clear();
                        while (!file.eof()) {
                            getline(file, x, ',');
                            if (x == interest) {
                                ofile << intrst << ",";
                            }
                            else if (x == depo) {
                                y = (atoi(depo.c_str()) + atoi(intrst.c_str()));
                                ofile << y << ",";
                            }
                            else {
                                ofile << x << ",";
                            }
                        }
                    }
                    else {
                        cout << "\n\nYou will get Byn 0 as interest for today...";
                    }
                    break;
                }
            }
        } while (is.good());
    }

    if (test == 0) {
        cout << "\n\n\t\tAccount doesn't Exist!";
    }

    remove("Bank_Record.csv");
    rename("temp.csv", "Bank_Record.csv");

    is.close();

    // Ìåíþ âûáîðà äåéñòâèÿ ïîñëå âûïîëíåíèÿ îïåðàöèè
    bool validExitChoice = false;
    while (!validExitChoice) {
        int main_exit;
        cout << "\nEnter 1 for Main Menu, 2 for Customer Menu, 3 for Employee Menu, or 0 to Exit: ";
        cin >> main_exit;

        switch (main_exit) {
        case 1:
            system("cls");
            close();
            validExitChoice = true;
            break;
        case 0:
            system("cls");
            close();
            validExitChoice = true;
            break;
        case 2:
            system("cls");
            menu_c();
            validExitChoice = true;
            break;
        case 3:
            system("cls");
            employee();
            validExitChoice = true;
            break;
        default:
            cout << "\nInvalid Input! Please try again." << endl;
        }
    }
}

