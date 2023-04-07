#include "DateMenager.h"

int DateMenager::getNewDate() {
    char choise;
    bool isCorrectChoice, isCorrectDateFormat;
    int date;

    do {
        choise = AuxiliaryMethods::enterChar();

        if (choise == '1') {
            time_t t = time(nullptr);
            tm* now = localtime(&t);
            date = 10000 * (now->tm_year + 1900) + 100 * (now->tm_mon + 1) + now->tm_mday;
            isCorrectChoice = true;
        }
        else if (choise == '2') {
            string dateStr;

            cout << "Podaj dokladna date w formacie rrrr-mm-dd: ";
            do {
                dateStr = AuxiliaryMethods::enterLine();
                isCorrectDateFormat = DateMenager::isCorrectDateFormat(dateStr);
                if (!isCorrectDateFormat) {
                    cout << "Zly format lub data. Wpisz ponownie: " << endl;
                }
            } while (!isCorrectDateFormat);
            dateStr.erase(7, 1);
            dateStr.erase(4, 1);
            date = stoi(dateStr);
            isCorrectChoice = true;
        }
        else {
            cout << "Niepoprawny wybor. Podaj ponownie: ";
            system("Pause");
            isCorrectChoice = false;
        }
    } while(!isCorrectChoice);
    return date;
}

int DateMenager::getStartDateOfCurrentMonth() {
    int firstDateOfCurrentMonth;
    const int FIRST_DAY = 1;

    time_t t = time(nullptr);

    tm* now = localtime(&t);
    firstDateOfCurrentMonth = 10000 * (now->tm_year + 1900) + 100 * (now->tm_mon + 1) + FIRST_DAY;

    return firstDateOfCurrentMonth;
}

int DateMenager::getEndDateOfCurrentMonth() {
    int lastDateOfCurrentMonth, year, month, lastDay;
    time_t t = time(nullptr);

    tm* now = localtime(&t);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;

    lastDay = DateMenager::getMaxDayOfMonth(month, year);

    lastDateOfCurrentMonth = 10000 * year + 100 * month + lastDay;

    return lastDateOfCurrentMonth;
}

int DateMenager::getStartDateOfPreviousMonth() {
    int firstDateOfCurrentMonth, currentYear, currentMonth, previosMonth, year;
    const int DECEMBER = 12;
    const int FIRST_DAY = 1;
    time_t t = time(nullptr);

    tm* now = localtime(&t);
    currentYear = now->tm_year + 1900;
    currentMonth = now->tm_mon + 1;

    if (currentMonth == 1) {
        previosMonth = DECEMBER;
        year = currentYear - 1;
    }
    else {
        previosMonth = currentMonth - 1;
        year = currentYear;
    }

    firstDateOfCurrentMonth = 10000 * year + 100 * previosMonth + FIRST_DAY;

    return firstDateOfCurrentMonth;
}

int DateMenager::getEndDateOfPreviousMonth() {
    int lastDateOfCurrentMonth, currentYear, currentMonth, lastDay, previosMonth, year;
    const int DECEMBER = 12;
    time_t t = time(nullptr);

    tm* now = localtime(&t);
    currentYear = now->tm_year + 1900;
    currentMonth = now->tm_mon + 1;

    if (currentMonth == 1) {
        previosMonth = DECEMBER;
        year = currentYear - 1;
    }
    else {
        previosMonth = currentMonth - 1;
        year = currentYear;
    }

    lastDay = DateMenager::getMaxDayOfMonth(previosMonth, year);

    lastDateOfCurrentMonth = 10000 * year + 100 * previosMonth + lastDay;


    return lastDateOfCurrentMonth;
}

int DateMenager::enterDate() {
    int date;
    string dateStr;
    bool iscorrectDate = true;

    do {
        dateStr = AuxiliaryMethods::enterLine();
    } while (!DateMenager::isCorrectDateFormat(dateStr));

    dateStr.erase(7, 1);
    dateStr.erase(4, 1);
    date = stoi(dateStr);

    return date;
}

bool DateMenager::isCorrectDateFormat(string date) {
    int number = 0;
    int maxDay = 0;
    int year, month, day, currentYear, currentMonth, currentDay;

    for (int unsigned i = 0; i < date.length(); i++) {
        number++;
        if ((i == 4 || i == 7) && date[i] != '-' ) {
            cout << "Niepoprawny format";
            system("pause");

            return false;
        }
    }

    if (number != 10) {
        cout << "Niepoprawny format";
        system("pause");

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
        cout << "Niepoprawny rok lub miesiac";
        system("pause");

        return false;
    }

    if (year == currentYear ) {
        if (month > currentMonth) {
            cout << "Niepoprawny  miesiac";
            system("pause");

            return false;
        }
        if (month == currentMonth && day > currentDay) {
            cout << "Niepoprawny dzien";
            system("pause");

            return false;
        }
    }

    maxDay = getMaxDayOfMonth(month, year);

    if (day < 1 || day > maxDay) {
        cout << "Niepoprawny dzien";
        system("pause");

        return false;
    }

    return true;
}

int DateMenager::getMaxDayOfMonth(int month, int year) {
    int maxDay;

    switch (month) {
        case 1:
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

string DateMenager::transformStringDate(string date) {
    date = date.insert(4, "-");
    date = date.insert(7, "-");

    return date;
}
