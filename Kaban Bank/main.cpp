#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Для форматирования вывода

using namespace std;

// Структура для хранения информации о карте
struct Card {
    string cardNumber;
    string currency;
};

// Глобальный вектор для хранения карт
vector<Card> cards;

// Функция для создания нового номера карты
string generateCardNumber() {
    static int cardCount = 1; // Счётчик карт
    return "1234-5678-" + to_string(1000 + cardCount++);
}

// Функция отображения главного окна
bool login() {
    string login, password;

    cout << setw(50) << "" << "=== Вход в систему ===" << endl;
    cout << setw(50) << "" << "Логин: ";
    cin >> login;
    cout << setw(50) << "" << "Пароль: ";
    cin >> password;

    // Простая проверка (логин: admin, пароль: 1234)
    if (login == "admin" && password == "1234") {
        cout << setw(50) << "" << "Успешный вход!" << endl;
        return true;
    }
    else {
        cout << setw(50) << "" << "Неверный логин или пароль!" << endl;
        return false;
    }
}

// Функция для отображения главного меню
void mainMenu() {
    int choice;

    while (true) {
        cout << "\n=== Главное меню ===" << endl;
        cout << "1. Создать новую карту" << endl;
        cout << "2. Создать валютный счет" << endl;
        cout << "3. Просмотреть все карты" << endl;
        cout << "4. Выход" << endl;
        cout << "Введите номер действия: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Создание новой карты
            Card newCard;
            newCard.cardNumber = generateCardNumber();
            cout << "Выберите валюту (BYN/RUB/USD/EUR/CNY): ";
            cin >> newCard.currency;

            cards.push_back(newCard);
            cout << "Карта создана! Номер: " << newCard.cardNumber
                << ", Валюта: " << newCard.currency << endl;
            break;
        }
        case 2: {
            // Создание валютного счета
            string currency;
            cout << "Выберите валюту для счета (BYN/RUB/USD/EUR/CNY): ";
            cin >> currency;

            cout << "Валютный счет с валютой " << currency << " создан!" << endl;
            break;
        }
        case 3: {
            // Просмотр всех карт
            if (cards.empty()) {
                cout << "Нет созданных карт." << endl;
            }
            else {
                cout << "Список карт:" << endl;
                for (const auto& card : cards) {
                    cout << "Номер карты: " << card.cardNumber
                        << ", Валюта: " << card.currency << endl;
                }
            }
            break;
        }
        case 4: {
            cout << "Выход из программы." << endl;
            return;
        }
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    if (login()) {
        mainMenu();
    }
    else {
        cout << "Попробуйте снова." << endl;
    }

    return 0;
}
