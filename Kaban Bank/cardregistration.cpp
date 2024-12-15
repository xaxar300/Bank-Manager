#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<windows.h>
#include <filesystem>
#include <direct.h>
using namespace std;
// ������� ��� ��������� ���������� ������ �����
string generateCardNumber() {
    string cardNumber = "4000"; // ������� ��� Visa
    for (int i = 0; i < 12; ++i) {
        cardNumber += to_string(rand() % 10); // ��������� ��������� ����
    }
    return cardNumber;
}

// ������� ��� ��������� PIN-����
string generatePin() {
    string pin;
    for (int i = 0; i < 4; ++i) {
        pin += to_string(rand() % 10);
    }
    return pin;
}

// ������� ��� ��������� ����� �������� ����� (MM/YY)
std::string generateExpiryDate() {
    time_t now = time(0);
    tm localTime;
    localtime_s(&localTime, &now); // ���������� ���������� ������ localtime_s

    int month = localTime.tm_mon; // ��������� �����
    int year = localTime.tm_year % 100 + 5; // ��������� ��� � �������� 5 ���

    return (month < 10 ? "0" : "") + to_string(month) + "/" + to_string(year);
}

int main() {
    srand(static_cast<unsigned>(time(0))); // ������������� ���������� ��������� �����
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    // ���� ������ ���������
    cout << "������� ��� ��������� �����: ";
    string cardHolder;
    getline(cin, cardHolder);
    cout << "������� �������� ������: ";
    string currency;
    getline(cin, currency);
    // ��������� ������ �����
    string cardNumber = generateCardNumber();
    string pin = generatePin();
    string expiryDate = generateExpiryDate();
    string folderPath = cardHolder+"card_data"; // ��� �����, ������� �� ����� �������

    // �������� �����, ���� � ���
    if (_mkdir(folderPath.c_str()) != 0 && errno != EEXIST) {
        cerr << "������: �� ������� ������� �����.\n";
        return 1;
    }

    // ���� � �����, ������� ����� �������� � �����
    string filePath = folderPath + "\\card_info.txt";
    ofstream outFile(filePath, ios::app);
    if (!outFile.is_open()) {
        std::cerr << "������: �� ������� ������� ��� ������� ���� ��� ������.\n";
        return 1; // ���������� ��������� � �������
    }

    // ������ ������ � ����
    outFile << "=== ������ ����� ===\n";
    outFile << "��������: " << cardHolder << "\n";
    outFile << "����� �����: " << cardNumber << "\n";
    outFile << "���� ��������: " << expiryDate << "\n";
    outFile << "PIN-���: " << pin << "\n";
    outFile << "���� = 0 " << currency << "\n";
    outFile << "--------------------\n";

    outFile.close(); // ��������� ����

    std::cout << "\n������ ����� ������� ��������� � ���� '" << filePath << "'.\n";
    return 0;
}
