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
    string cardNumber = "0BY"; // ������� ��� Visa
    for (int i = 0; i < 13; ++i) {
        cardNumber += to_string(rand() % 10); // ��������� ��������� ����
    }
    return cardNumber;
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
    string folderPath = "schot_info"; // ��� �����, ������� �� ����� �������

    // �������� �����, ���� � ���
    if (_mkdir(folderPath.c_str()) != 0 && errno != EEXIST) {
        cerr << "������: �� ������� ������� �����.\n";
        return 1;
    }

    // ���� � �����, ������� ����� �������� � �����
    string filePath = folderPath + "\\schot_info.txt";
    ofstream outFile(filePath, ios::app);
    if (!outFile.is_open()) {
        std::cerr << "������: �� ������� ������� ��� ������� ���� ��� ������.\n";
        return 1; // ���������� ��������� � �������
    }

    // ������ ������ � ����
    outFile << "=== ������ ����� ===\n";
    outFile << "��������: " << cardHolder << "\n";
    outFile << "����� �����: " << cardNumber << "\n";
    outFile << "���� = 0 " << currency << "\n";
    outFile << "--------------------\n";

    outFile.close(); // ��������� ����

    std::cout << "\n������ ����� ������� ��������� � ���� '" << filePath << "'.\n";
    return 0;
}
