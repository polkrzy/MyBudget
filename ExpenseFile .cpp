#include "ExpenseFile.h"

int ExpenseFile::getLastExpenseId() {
    return lastExpenseId;
}


vector <Expense> ExpenseFile::loadUserExpenses(const int ID_OF_LOGGED_USSER) {
    Expense expense;
    vector <Expense> expenses;
    lastExpenseId = 0;

    if (xml.Load(getFileName())) {
        xml.FindElem("Expenses");
        xml.IntoElem();
        while (xml.FindElem("Expense")) {
            lastExpenseId++;
            xml.IntoElem();
            xml.FindElem("UserId");

            if (AuxiliaryMethods::stringToIntConversion(xml.GetData()) == ID_OF_LOGGED_USSER) {
                expense.setUserId(AuxiliaryMethods::stringToIntConversion(xml.GetData()));

                xml.FindElem("ExpenseId");
                expense.setExpenseId(AuxiliaryMethods::stringToIntConversion(xml.GetData()));

                xml.FindElem("ExpenseDate");
                expense.setExpenseDate(AuxiliaryMethods::stringToIntConversion(xml.GetData()));

                xml.FindElem("Item");
                expense.setItem(xml.GetData());

                xml.FindElem("Amount");
                expense.setAmount(AuxiliaryMethods::stringToFloatConversion(xml.GetData()));
            }
            xml.OutOfElem();

            expenses.push_back(expense);
        }
    }

    return expenses;
}

bool ExpenseFile::addExpenseToFile(Expense expense) {
    bool fileExist = xml.Load(getFileName());
    string expenseAmountStr = AuxiliaryMethods::floatToStringConvert(expense.getAmount());

    if(!fileExist) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("ExspenseDate", expense.getExpenseDate());
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", expenseAmountStr);

    xml.Save(getFileName());

    return true;
}
