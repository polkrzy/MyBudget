#include "BudgetMenager.h"

void BudgetMenager::loadUserIncomes(){
    incomes = incomeFile.loadUserIncomes(getLoggedUserId());
}

void BudgetMenager::loadUserExpenses() {
    expenses = expenseFile.loadUserExpenses(getLoggedUserId());
}

struct lesserIncome {
    inline bool operator() (Income first, Income second) const {
        return (first.getIncomeDate() < second.getIncomeDate());
    }
};

struct lesserExpense {
    inline bool operator() (Expense first, Expense second) const {
        return (first.getExpenseDate() < second.getExpenseDate());
    }
};

void BudgetMenager::showBalance(int startDate, int endDate) {
    string startDateStr, endDateStr;
    float incomesSum = 0;
    float expensesSum = 0;

    startDateStr = DateMenager::transformStringDate(AuxiliaryMethods::intToStringConvert(startDate));
    endDateStr = DateMenager::transformStringDate(AuxiliaryMethods::intToStringConvert(endDate));

    sort(incomes.begin(), incomes.end(), lesserIncome());
    sort(expenses.begin(), expenses.end(), lesserExpense());

    cout << "--- WPLYWY Z OKRESU OD " << startDateStr << " DO " << endDateStr << " ---" << endl << endl;

    for (unsigned int i = 0; i < incomes.size(); i++) {
        if (incomes[i].getIncomeDate() >= startDate && incomes[i].getIncomeDate() <= endDate) {
            incomesSum += incomes[i].getAmount();

            cout << "Data: " << incomes[i].getIncomeDate() << "          Nazwa przychodu: " << setw(20) << incomes[i].getItem()
            << "          Wartosc: " << incomes[i].getAmount() << "zl" << endl;
        }
    }

    if (incomesSum == 0) {
            cout << "Brak wplywow w danym okresie" << endl;
    }
    else {
            cout << "Suma wplywow w danym okresie: " << incomesSum << "zl";
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << endl << endl << "--- WYDATKI Z OKRESU OD " << startDateStr << " DO " << endDateStr << " ---" << endl << endl;

    for (unsigned int i = 0; i < expenses.size(); i++) {
        if (expenses[i].getExpenseDate() >= startDate && expenses[i].getExpenseDate() <= endDate) {
            expensesSum += expenses[i].getAmount();

            cout << "Data: " << expenses[i].getExpenseDate() << "          Nazwa przychodu: " << setw(20) << expenses[i].getItem()
            << "          Wartosc: " << expenses[i].getAmount() << "zl" << endl;
        }
    }

    if (expensesSum == 0) {
            cout << "Brak wydatkow w danym okresie" << endl;
    }
    else {
            cout << "Suma wydatkow w danym okresie: " << expensesSum << "zl";
    }

    cout << endl << endl << "Bilans laczny w danym okresie: " << incomesSum - expensesSum << "zl" << endl;

    system("pause");
}

void BudgetMenager::showBalanceSheetFromCurrentMonth() {
    int startDateCurrentMonth, endDateCurrentMonth;

    startDateCurrentMonth = DateMenager::getStartDateOfCurrentMonth();
    endDateCurrentMonth = DateMenager::getEndDateOfCurrentMonth();

    showBalance(startDateCurrentMonth, endDateCurrentMonth);
}

void BudgetMenager::showBalanceSheetFromPreviousMonth() {
    int startDatePreviousMonth, endDatePreviousMonth;

    startDatePreviousMonth = DateMenager::getStartDateOfPreviousMonth();
    endDatePreviousMonth = DateMenager::getEndDateOfPreviousMonth();

    showBalance(startDatePreviousMonth, endDatePreviousMonth);
}

void BudgetMenager::showBalanceSheetFromSelectedPeriod() {
    int startDate, endDate;
    bool isCorrectDate;

    do {
        system("cls");
        cout << "Podaj od kiedy chcesz zobaczyc bilans (format <rrrr-mm-ss->): ";
        startDate = DateMenager::enterDate();

        cout << "Podaj do kiedy chcesz zobaczyc bilans (format <rrrr-mm-ss->): ";
        endDate = DateMenager::enterDate();

        if (startDate > endDate) {
            isCorrectDate = false;
            cout << "Data koncowa jest wczesniejsza niz poczatkowa" << endl;
            system("pause");
        }
        else {
            isCorrectDate = true;
        }
    } while (!isCorrectDate);

    showBalance(startDate, endDate);
}

void BudgetMenager::addIncome() {
    Income income = setNewIncomeData();

    incomes.push_back(income);
    if (!incomeFile.addIncomeToFile(income)) {
        cout << "Nie udalo dodac wplywu do pliku" << endl;
    }
    else {
        cout << endl << "Dodano dochod" << endl << endl;
    }
    system("pause");
}

Income BudgetMenager::setNewIncomeData() {
    Income income;
    string item;
    float amount;

    income.setIncomeId(getNewIncomeId());
    income.setUserId(LOGGED_USER_ID);

    cout << "Podaj dla jakiej daty wprowadzic dochod <1. Dziesiejsza 2. Inna>: ";
    income.setIncomeDate(DateMenager::getNewDate());

    cout << "Podaj rodzaj dochodu: ";
    item = AuxiliaryMethods::replaceFirstLetterUppercaseAndOtherLowercase(AuxiliaryMethods::enterLine());
    income.setItem(item);

    cout << "Podaj wartosc dochodu: ";
    amount = AuxiliaryMethods::formatCashAmount();
    income.setAmount(amount);

    return income;
}

int BudgetMenager::getNewIncomeId() {
    if (incomes.empty())
        return 1;
    else
        return incomeFile.getLastIncomeId() + 1;
}

void BudgetMenager::addExpense() {
    Expense expense = setNewExpenseData();

    expenses.push_back(expense);
    if (!expenseFile.addExpenseToFile(expense)) {
        cout << "Nie udalo dodac wplywu do pliku" << endl;
    }
    else {
        cout << endl << "Dodano wydatek" << endl << endl;
    }
    system("pause");
}

Expense BudgetMenager::setNewExpenseData() {
    Expense expense;
    string item;
    float amount;

    expense.setExpenseId(getNewExpenseId());
    expense.setUserId(LOGGED_USER_ID);

    cout << "Podaj dla jakiej daty wprowadzic dochod <1. Dziesiejsza 2. Inna>: ";
    expense.setExpenseDate(DateMenager::getNewDate());

    cout << "Podaj rodzaj dochodu: ";
    item = AuxiliaryMethods::replaceFirstLetterUppercaseAndOtherLowercase(AuxiliaryMethods::enterLine());
    expense.setItem(item);

    cout << "Podaj wartosc dochodu: ";
    amount = AuxiliaryMethods::formatCashAmount();
    expense.setAmount(amount);

    return expense;
}

int BudgetMenager::getNewExpenseId() {
    if (expenses.size() == 0) {
        return 1;
    }
    return expenseFile.getLastExpenseId() + 1;
}

int BudgetMenager::getLoggedUserId() {
    return LOGGED_USER_ID;
}
