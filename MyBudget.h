#ifndef MYBUDGET_H
#define MYBUDGET_H

#include "UserMenager.h"
#include "BudgetMenager.h"

class MyBudget {
    UserMenager userMenager;
    BudgetMenager *budgetMenager;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;

public:
    MyBudget(string userFileName, string incomeFileName, string expenseFileName)
        : userMenager(userFileName), INCOME_FILE_NAME(incomeFileName), EXPENSE_FILE_NAME(expenseFileName) {
        budgetMenager = NULL;
    };
    ~MyBudget() {
        delete budgetMenager;
        budgetMenager = NULL;
    }

    void registerUser();
    void logInUser();
    void logOutUser();
    void changeUserPassword();
    void addIncome();
    void addExpense();
    void showBalanceSheetFromCurrentMonth();
    void showBalanceSheetFromPreviousMonth();
    void showBalanceSheetFromSelectedPeriod();
    char selectOptionWithUserMenu();
    char selectOptionWithMainMenu();
    int getLoogedUserId();



};

#endif
