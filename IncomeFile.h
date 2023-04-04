#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include "AuxiliaryMethods.h"
#include "XmlFile.h"
#include "Income.h"

class IncomeFile : public XmlFile {
    int lastIncomeId;

public:
    IncomeFile(string incomeFileName)
    : XmlFile(incomeFileName) {};

    int getLastIncomeId();
    vector <Income> loadUserIncomes(const int ID_OF_LOGGED_USSER);
    bool addIncomeToFile(Income income);

};

#endif
