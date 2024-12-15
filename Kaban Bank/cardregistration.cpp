#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<windows.h>
#include <filesystem>
#include <direct.h>
using namespace std;
// Функция для генерации случайного номера карты
string generateCardNumber() {
    string cardNumber = "4000"; // Префикс для Visa
    for (int i = 0; i < 12; ++i) {
        cardNumber += to_string(rand() % 10); // Генерация случайных цифр
    }
    return cardNumber;
}

// Функция для генерации PIN-кода
string generatePin() {
    string pin;
    for (int i = 0; i < 4; ++i) {
        pin += to_string(rand() % 10);
    }
    return pin;
}

// Функция для генерации срока действия карты (MM/YY)
std::string generateExpiryDate() {
    time_t now = time(0);
    tm localTime;
    localtime_s(&localTime, &now); // Используем безопасную версию localtime_s

    int month = localTime.tm_mon; // Случайный месяц
    int year = localTime.tm_year % 100 + 5; // Случайный год в пределах 5 лет

    return (month < 10 ? "0" : "") + to_string(month) + "/" + to_string(year);
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    // Ввод данных владельца
    cout << "Введите имя владельца карты: ";
    string cardHolder;
    getline(cin, cardHolder);
    cout << "Введите желаемую валюту: ";
    string currency;
    getline(cin, currency);
    // Генерация данных карты
    string cardNumber = generateCardNumber();
    string pin = generatePin();
    string expiryDate = generateExpiryDate();
    string folderPath = cardHolder+"card_data"; // Имя папки, которую мы хотим создать

    // Создание папки, если её нет
    if (_mkdir(folderPath.c_str()) != 0 && errno != EEXIST) {
        cerr << "Ошибка: Не удалось создать папку.\n";
        return 1;
    }

    // Путь к файлу, который будет сохранен в папке
    string filePath = folderPath + "\\card_info.txt";
    ofstream outFile(filePath, ios::app);
    if (!outFile.is_open()) {
        std::cerr << "Ошибка: Не удалось создать или открыть файл для записи.\n";
        return 1; // Завершение программы с ошибкой
    }

    // Запись данных в файл
    outFile << "=== Данные карты ===\n";
    outFile << "Владелец: " << cardHolder << "\n";
    outFile << "Номер карты: " << cardNumber << "\n";
    outFile << "Срок действия: " << expiryDate << "\n";
    outFile << "PIN-код: " << pin << "\n";
    outFile << "Счёт = 0 " << currency << "\n";
    outFile << "--------------------\n";

    outFile.close(); // Закрываем файл

    std::cout << "\nДанные карты успешно сохранены в файл '" << filePath << "'.\n";
    return 0;
}
