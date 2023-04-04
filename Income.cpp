#include "Income.h"

int Income::getIncomeId() {
    return incomeId;
}

int Income::getUserId() {
    return userId;
}

int Income::getIncomeDate() {
    return incomeDate;
}

string Income::getItem() {
    return item;
}

float Income::getAmount() {
    return amount;
}

void Income::setIncomeId(int newIncomeId) {
    incomeId = newIncomeId;
}

void Income::setUserId(int newUserId) {
    userId = newUserId;
}

void Income::setIncomeDate(int newIncomeDate) {
    incomeDate = newIncomeDate;
}

void Income::setItem(string newItem) {
    item = newItem;
}

void Income::setAmount(float newAmount) {
    amount = newAmount;
}
