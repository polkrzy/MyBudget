#ifndef DATEMENAGER_H
#define DATEMENAGER_H

#include "AuxiliaryMethods.h"
#include <time.h>

class DateMenager {
public:
    static int getNewDate();
    static int getStartDateOfCurrentMonth();
    static int getEndDateOfCurrentMonth();
    static int getStartDateOfPreviousMonth();
    static int getEndDateOfPreviousMonth();
    static int enterDate();
    static bool isCorrectDateFormat(string date);
    static int getMaxDayOfMonth(int month, int year);
    static string transformStringDate(string date);
};

#endif
