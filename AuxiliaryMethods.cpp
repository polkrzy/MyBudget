#include "AuxiliaryMethods.h"

float AuxiliaryMethods::formatCashAmount() {
    float result;
    string cashAmount;

    do {
        cashAmount = enterLine();
        cashAmount = replaceComaWithPeriod(cashAmount);
    } while (!isAmountFormatCorrect(cashAmount));

    result = round(stringToFloatConversion(cashAmount) * 100) / 100;

    return result;
}

char AuxiliaryMethods::enterChar() {
    string input = "";
    char sign  = {0};

    while (true) {
        cin.sync();
        getline(cin, input);

        if (input.length() == 1) {
            sign = input[0];
            break;
        }
        cout << "Niepoprawny wybor. Podaj ponownie: ";
    }
    return sign;
}

string AuxiliaryMethods::enterLine() {
    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
}

string AuxiliaryMethods::replaceFirstLetterUppercaseAndOtherLowercase(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int AuxiliaryMethods::stringToIntConversion(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

bool AuxiliaryMethods::isAmountFormatCorrect(string amount) {
    if (amount == "0") {
        cout << "Wartosc nie moze wynosic 0. Sprobuj ponownie: ";
        return false;
    }

    for (int unsigned i = 0; i < amount.length(); i++) {
        if ((amount[i] < '0' || amount[i] > '9') && (amount[i] != '.')) {
            cout << "Wartosc niepoprawna. Sprobuj ponownie: ";
            return false;
        }
    }
    return true;
}

string AuxiliaryMethods::replaceComaWithPeriod(string amount) {
    for (int unsigned i = 0; i < amount.length(); i++) {
        if (amount[i] == ',') {
            amount[i] = '.';
        }
    }
    return amount;
}

float AuxiliaryMethods::stringToFloatConversion(string number) {
    istringstream ss(number);
    float result;
    ss >> result;
    return result;
}

string AuxiliaryMethods::floatToStringConvert(float amount) {
    ostringstream stream;
    stream << amount;
    return stream.str();
}

string AuxiliaryMethods::intToStringConvert(int input) {
    ostringstream stream;
    stream << input;
    return stream.str();
}

