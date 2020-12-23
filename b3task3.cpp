/***********************************************************
 *                      Перевод чисел                      *
 *                    блок 3 - задача 3                    *
 *                  Зарецкая Дарья ПИ-203                  *
 **********************************************************/

#include <iostream>
#include <string>

using namespace std;

const int arabic[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

void arabicToRoman () {
    int i;
    int j;
    int inputArabic;

    cout << "\nYour arabic number: ";
    cin >> inputArabic;
    if (inputArabic > 4000) {
        cout << "\nYour number should be less than 4000. Try again:";
        cin >> inputArabic;
    }

    cout << "\nin roman numerals: ";
    while (inputArabic > 0) {
        for (i = 0; i < 13; ++i) {
            j = arabic[i];
            for (j; inputArabic >= j; inputArabic -= j) {
                cout << roman[i];
            }
        }
        cout << endl;
    }
}

void romanToArabic () {
    int i;
    int j;
    string inputRoman;
    int outputArabic = 0;
    string currentRoman;
    string prevRoman;
    int prevArabic = 0;

    cout << "\nYour roman number: ";
    cin >> inputRoman;

    cout << "\nin arabic numerals: ";
    for (i = inputRoman.length() - 1; i >= 0; --i) {
        currentRoman = inputRoman[i];
        for (j = 12; j >= 0; j -= 2) {
            if (currentRoman == roman[j]) {
                if (arabic[j] < prevArabic) {
                    outputArabic -= arabic[j];
                } else {
                    outputArabic += arabic[j];
                    prevRoman = roman[j];
                    prevArabic = arabic[j];
                }
            }
        }
    }
    cout << outputArabic << endl;
}

int main () {
    int mode;

    cout << "1 - Arabic to roman\n2 - Roman to arabic\n";
    cin >> mode;
    while (mode != 1 && mode != 2) {
        cout << "Error! Try again\n";
        cin >> mode;
    }

    switch (mode) {
        case 1:
        arabicToRoman();
        break;

        case 2:
        romanToArabic();
        break;
    }
}
