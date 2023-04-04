#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income {
    int incomeId, userId, incomeDate;
    string item;
    float amount;

public:
    int getIncomeId();
    int getUserId();
    int getIncomeDate();
    string getItem();
    float getAmount();

    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setIncomeDate(int newIncomeDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

};

#endif
