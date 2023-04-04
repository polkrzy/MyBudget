#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

class AuxiliaryMethods {
public:
    static bool isCorrectDateFormat(string date);
    static float formatCashAmount();

    static char enterChar();
    static string enterLine();
    static string replaceFirstLetterUppercaseAndOtherLowercase(string text);
    static int stringToIntConversion(string number);
    static bool isAmountFormatCorrect(string amount);
    static string replaceComaWithPeriod(string amount);
    static float stringToFloatConversion(string number);
    static int getMaxDayOfMonth(int month, int yaer);

};

#endif
