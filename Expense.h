#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense {
    int expenseId, userId, expenseDate;
    string item;
    float amount;

public:
    int getExpenseId();
    int getUserId();
    int getExpenseDate();
    string getItem();
    float getAmount();

    void setExpenseId(int newExpenseId);
    void setUserId(int newUserId);
    void setExpenseDate(int newExpenseDate);
    void setItem(string newItem);
    void setAmount(float newAmount);
};

#endif
