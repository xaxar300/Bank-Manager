#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<windows.h>
#include <filesystem>
#include <direct.h>
using namespace std;
// Ôóíêöèÿ äëÿ ãåíåðàöèè ñëó÷àéíîãî íîìåðà êàðòû
string generateCardNumber() {
    string cardNumber = "4000"; // Ïðåôèêñ äëÿ Visa
    for (int i = 0; i < 12; ++i) {
        cardNumber += to_string(rand() % 10); // Ãåíåðàöèÿ ñëó÷àéíûõ öèôð
    }
    return cardNumber;
}

// Ôóíêöèÿ äëÿ ãåíåðàöèè PIN-êîäà
string generatePin() {
    string pin;
    for (int i = 0; i < 4; ++i) {
        pin += to_string(rand() % 10);
    }
    return pin;
}

// Ôóíêöèÿ äëÿ ãåíåðàöèè ñðîêà äåéñòâèÿ êàðòû (MM/YY)
std::string generateExpiryDate() {
    time_t now = time(0);
    tm localTime;
    localtime_s(&localTime, &now); // Èñïîëüçóåì áåçîïàñíóþ âåðñèþ localtime_s

    int month = localTime.tm_mon; // Ñëó÷àéíûé ìåñÿö
    int year = localTime.tm_year % 100 + 5; // Ñëó÷àéíûé ãîä â ïðåäåëàõ 5 ëåò

    return (month < 10 ? "0" : "") + to_string(month) + "/" + to_string(year);
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Èíèöèàëèçàöèÿ ãåíåðàòîðà ñëó÷àéíûõ ÷èñåë
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    // Ââîä äàííûõ âëàäåëüöà
    cout << "Ââåäèòå èìÿ âëàäåëüöà êàðòû: ";
    string cardHolder;
    getline(cin, cardHolder);
    cout << "Ââåäèòå æåëàåìóþ âàëþòó: ";
    string currency;
    getline(cin, currency);
    // Ãåíåðàöèÿ äàííûõ êàðòû
    string cardNumber = generateCardNumber();
    string pin = generatePin();
    string expiryDate = generateExpiryDate();
    string folderPath = "card_data"; // Èìÿ ïàïêè, êîòîðóþ ìû õîòèì ñîçäàòü

    // Ñîçäàíèå ïàïêè, åñëè å¸ íåò
    if (_mkdir(folderPath.c_str()) != 0 && errno != EEXIST) {
        cerr << "Îøèáêà: Íå óäàëîñü ñîçäàòü ïàïêó.\n";
        return 1;
    }

    // Ïóòü ê ôàéëó, êîòîðûé áóäåò ñîõðàíåí â ïàïêå
    string filePath = folderPath + "\\card_info.txt";
    ofstream outFile(filePath, ios::app);
    if (!outFile.is_open()) {
        std::cerr << "Îøèáêà: Íå óäàëîñü ñîçäàòü èëè îòêðûòü ôàéë äëÿ çàïèñè.\n";
        return 1; // Çàâåðøåíèå ïðîãðàììû ñ îøèáêîé
    }

    // Çàïèñü äàííûõ â ôàéë
    outFile << "=== Äàííûå êàðòû ===\n";
    outFile << "Âëàäåëåö: " << cardHolder << "\n";
    outFile << "Íîìåð êàðòû: " << cardNumber << "\n";
    outFile << "Ñðîê äåéñòâèÿ: " << expiryDate << "\n";
    outFile << "PIN-êîä: " << pin << "\n";
    outFile << "Ñ÷¸ò = 0 " << currency << "\n";
    outFile << "--------------------\n";

    outFile.close(); // Çàêðûâàåì ôàéë

    std::cout << "\nÄàííûå êàðòû óñïåøíî ñîõðàíåíû â ôàéë '" << filePath << "'.\n";
    return 0;
}
