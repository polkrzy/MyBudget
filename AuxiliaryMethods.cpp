#include "AuxiliaryMethods.h"

bool AuxiliaryMethods::isCorrectDateFormat(string date) {
    int number = 0;
    int maxDay = 0;
    int year, month, day, currentYear, currentMonth, currentDay;

    for (int unsigned i = 0; i < date.length(); i++) {
        number++;
        if ((i == 4 || i == 7) && date[i] != '-' ) {
            return false;
        }
    }

    if (number != 10) {
        return false;
    }

    year = stoi(date.substr(0, 4));
    month = stoi(date.substr(5, 2));
    day = stoi(date.substr(8, 2));

    time_t t = time(nullptr);
    tm* now = localtime(&t);
    currentYear = now->tm_year + 1900;
    currentMonth = now->tm_mon + 1;
    currentDay = now->tm_mday;

    if (year < 2000 || year > currentYear || month < 1 || month > 12) {
        return false;
    }

    if (year == currentYear ) {
        if (month > currentMonth) {
            return false;
        }
        if (month == currentMonth && day > currentDay) {
            return false;
        }
    }

    maxDay = getMaxDayOfMonth(month, year);

    if (day < 1 || day > maxDay) {
        return false;
    }
    return true;
}

int AuxiliaryMethods::getMaxDayOfMonth(int month, int year) {
    int maxDay;

    switch (month) {
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            maxDay = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            maxDay = 30;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                maxDay = 29;
            } else {
                maxDay = 28;
            }
            break;
        default:
            break;
    }
    return maxDay;
}

float AuxiliaryMethods::formatCashAmount() {
    float result;
    string cashAmount;

    do {
        cashAmount = enterLine();
        cashAmount = replaceComaWithPeriod(cashAmount);
    } while (!isAmountFormatCorrect(cashAmount));

    result = stringToFloatConversion(cashAmount);
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
    for(int unsigned i = 0; i < amount.length(); i++) {
        if((amount[i] < '0' || amount[i] > '9') && (amount[i] != '.')) {
            cout << "Wartosc niepoprawna. Sprobuj ponownie: ";
            return false;
        }
    }
    return true;
}

string AuxiliaryMethods::replaceComaWithPeriod(string amount) {
    for(int unsigned i = 0; i < amount.length(); i++) {
        if(amount[i] == ',') {
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
