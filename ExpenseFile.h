#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include "AuxiliaryMethods.h"
#include "XmlFile.h"
#include "Expense.h"

class ExpenseFile : public XmlFile {
    int lastExpenseId;

public:
    ExpenseFile(string expenseFileName)
    : XmlFile(expenseFileName) {};

    int getLastExpenseId();
    vector <Expense> loadUserExpenses(const int ID_OF_LOGGED_USSER);
    bool addExpenseToFile(Expense expense);


};

#endif
