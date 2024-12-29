#ifndef BANK_H
#define BANK_H

#include <string>
#include <iostream>
#include <fstream>

class Bank {
public:
    std::string account_number;
    std::string name;
    std::string dob;
    std::string age;
    std::string date;
    std::string address;
    std::string phone;
    std::string doc;
    std::string depo;
    std::string acc_type;
    std::string password;
    std::string interest;
public:
    void read_data();
    void acc_write();
    void modify_account();
    void deposit_withdraw();
    void search_rec();
    void display_all();
    void transfer();
};

#endif
