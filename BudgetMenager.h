#ifndef BUDGETMENAGER_H
#define BUDGETMENAGER_H

#include <ctime>
#include <cstdlib>
#include <iomanip>

#include "IncomeFile.h"
#include "ExpenseFile.h"
#include "DateMenager.h"


class BudgetMenager {
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;
    IncomeFile incomeFile;
    ExpenseFile expenseFile;

public:
    BudgetMenager(int loggedUserId, string incomeFileName, string expenseFileName)
        : LOGGED_USER_ID(loggedUserId), incomeFile(incomeFileName), expenseFile(expenseFileName) {
        loadUserExpenses();
        loadUserIncomes();
    };

    void addIncome();
    void addExpense();
    void showBalanceSheetFromCurrentMonth();
    void showBalanceSheetFromPreviousMonth();
    void showBalanceSheetFromSelectedPeriod();
    void showBalance(int startDate, int endDate);

    Income setNewIncomeData();
    Expense setNewExpenseData();
    void loadUserIncomes();
    void loadUserExpenses();
    int getNewIncomeId();
    int getNewExpenseId();
    int getLoggedUserId();
};

#endif
