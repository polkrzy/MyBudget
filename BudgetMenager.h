#ifndef BUDGETMENAGER_H
#define BUDGETMENAGER_H

#include <ctime>
#include <cstdlib>

#include "IncomeFile.h"
#include "ExpenseFile.h"

class BudgetMenager {
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;
    IncomeFile incomeFile;
    ExpenseFile expenseFile;

    void sortIncomeCashOperationByDate(int firstDate, int lastDate);
    void sortExpenseCashOperationByDate(int firstDate, int lastDate);

public:
    BudgetMenager(int loggedUserId, string incomeFileName, string expenseFileName)
        : LOGGED_USER_ID(loggedUserId), incomeFile(incomeFileName), expenseFile(expenseFileName) {
        loadUserExpenses();
        loadUserIncomes();
    };

    void addIncome();
    void addExpense();
    void showIncomes(int firstDate, int lastDate);
    void showExpenses(int firstDate, int lastDate);

    void loadUserIncomes();
    void loadUserExpenses();
    Income setNewIncomeData();
    Expense setNewExpenseData();
    int getNewIncomeId();
    int getNewExpenseId();
    int getNewDate();
    int getLoggedUserId();
    int getFirstDateOfCurrentMonth();
    int getLastDateOfCurrentMonth();
    int getFirstDateOfPreviousMonth();
    int getLastDateOfPreviousMonth();


};

#endif
