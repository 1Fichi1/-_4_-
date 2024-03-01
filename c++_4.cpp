#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <clocale>
#include <Windows.h>

using namespace std;


string reverse(const string& word) {
    string reversedWord = word;
    reverse(reversedWord.begin(), reversedWord.end());
    return reversedWord;
}


string removeVowels(const string& word) {
    string result;
    for (char ch : word) {
        if (string("аеёиоуыэюяАЕЁИОУЫЭЮЯ").find(ch) == string::npos) {
            result += ch;
        }
    }
    return result;
}


string removeConsonants(const string& word) {
    string result;
    for (char ch : word) {
        if (string("аеёиоуыэюяАЕЁИОУЫЭЮЯ").find(ch) != string::npos) {
            result += ch;
        }
    }
    return result;
}


string shuffle(const string& word) {
    string shuffledWord = word;
    random_shuffle(shuffledWord.begin(), shuffledWord.end());
    return shuffledWord;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "");

    srand(unsigned(time(0)));
    string word;
    cout << "Введите слово: ";
    cin >> word;

    int choice;
    cout << "Выберите действие:\n";
    cout << "1. Слово выводится задом наперед.\n";
    cout << "2. Вывести слово без гласных.\n";
    cout << "3. Вывести слово без согласных.\n";
    cout << "4. Рандомно раскидывать буквы заданного слова.\n";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Перевернутое слово: " << reverse(word) << endl;
        break;
    case 2:
        cout << "Слово без гласных: " << removeVowels(word) << endl;
        break;
    case 3:
        cout << "Слово без согласных: " << removeConsonants(word) << endl;
        break;
    case 4:
        cout << "Перемешанное слово: " << shuffle(word) << endl;
        break;
    default:
        cout << "Неверный выбор. Пожалуйста, выберите действие от 1 до 4." << endl;
        break;
    }

    return 0;
}
