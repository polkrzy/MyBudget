#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

class AuxiliaryMethods {
public:
    static float formatCashAmount();
    static char enterChar();
    static string enterLine();
    static string replaceFirstLetterUppercaseAndOtherLowercase(string text);
    static int stringToIntConversion(string number);
    static bool isAmountFormatCorrect(string amount);
    static string replaceComaWithPeriod(string amount);
    static float stringToFloatConversion(string number);
    static string floatToStringConvert(float amount);
    static string intToStringConvert(int amount);
};

#endif
