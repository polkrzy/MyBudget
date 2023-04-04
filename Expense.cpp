#include "Expense.h"

int Expense::getExpenseId() {
    return expenseId;
}

int Expense::getUserId() {
    return userId;
}

int Expense::getExpenseDate() {
    return expenseDate;
}

string Expense::getItem() {
    return item;
}

float Expense::getAmount() {
    return amount;
}

void Expense::setExpenseId(int newExpenseId){
    expenseId = newExpenseId;
}

void Expense::setUserId(int newUserId) {
    userId = newUserId;
}

void Expense::setExpenseDate(int newExpenseDate) {
    expenseDate = newExpenseDate;
}

void Expense::setItem(string newItem) {
    item = newItem;
}

void Expense::setAmount(float newAmount) {
    amount = newAmount;
}
