#include "BudgetMenager.h"

void BudgetMenager::loadUserIncomes(){
    incomes = incomeFile.loadUserIncomes(getLoggedUserId());
}

void BudgetMenager::loadUserExpenses() {
    expenses = expenseFile.loadUserExpenses(getLoggedUserId());
}

struct lesserIncome {
    inline bool operator() (const Income first, const Income second) const {
        return (first.getIncomeDate() < second.getIncomeDate());
    }
};

struct lesserExpense {
    inline bool operator() (const Expense first, const Expense second) const {
        return (first.getExpenseDate() < second.getExpenseDate());
    }
};

void BudgetMenager::sortIncomeCashOperationByDate(int firstDate, int lastDate) {
    vector <Income> incomesFromDesignatedPeriod;

    for (unsigned int i = 0; i < incomes.size(); i++) {
        cout << incomes[i].getIncomeId() << endl;

        if (incomes[i].getIncomeDate() >= firstDate && incomes[i].getIncomeDate() <= lastDate) {
            incomesFromDesignatedPeriod.push_back(incomes[i]);
        }
    }

    sort(incomesFromDesignatedPeriod.begin(), incomesFromDesignatedPeriod.end(), lesserIncome());

    for (unsigned int i = 0; i < incomesFromDesignatedPeriod.size(); i++) {
        cout << incomesFromDesignatedPeriod[i].getIncomeDate() << endl;
    }
    system("pause");
}

void BudgetMenager::sortExpenseCashOperationByDate(int firstDate, int lastDate) {
    vector <Expense> expensesFromDesignatedPeriod;

    for (unsigned int i = 0; i < expenses.size(); i++) {
        cout << expenses[i].getExpenseId() << endl;

        if (expenses[i].getExpenseId() >= firstDate && expenses[i].getExpenseId() <= lastDate) {
            expensesFromDesignatedPeriod.push_back(expenses[i]);
        }
    }

    sort(expensesFromDesignatedPeriod.begin(), expensesFromDesignatedPeriod.end(), lesserExpense());

    for (unsigned int i = 0; i < expensesFromDesignatedPeriod.size(); i++) {
        cout << expensesFromDesignatedPeriod[i].getExpenseId() << endl;
    }
    system("pause");
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
    income.setIncomeDate(getNewDate());

    cout << "Podaj rodzaj dochodu: ";
    item = AuxiliaryMethods::enterLine();
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

int BudgetMenager::getNewDate() {
    char choise;
    bool isCorrectChoice;
    int date;

    do {
        choise = AuxiliaryMethods::enterChar();

        if (choise == '1') {
            time_t t = time(nullptr);
            tm* now = localtime(&t);
            date = 10000 * (now->tm_year + 1900) + 100 * (now->tm_mon + 1) + now->tm_mday;
            isCorrectChoice = true;
        }
        else if (choise == '2') {
            string dateStr;

            cout << "Podaj dokladna date w formacie rrrr-mm-dd: ";
            do {
                dateStr = AuxiliaryMethods::enterLine();
                if (!AuxiliaryMethods::isCorrectDateFormat(dateStr)) {
                    cout << "Zly format lub data. Wpisz ponownie: " << endl;
                }
            } while (!AuxiliaryMethods::isCorrectDateFormat(dateStr));
            dateStr.erase(7, 1);
            dateStr.erase(4, 1);
            date = stoi(dateStr);
            isCorrectChoice = true;
        }
        else {
            cout << "Niepoprawny wybor. Podaj ponownie: ";
            system("Pause");
            isCorrectChoice = false;
        }
    } while(!isCorrectChoice);
    return date;
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
    expense.setExpenseDate(getNewDate());

    cout << "Podaj rodzaj dochodu: ";
    item = AuxiliaryMethods::enterLine();;
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

void BudgetMenager::showIncomes(int firstDate, int lastDate) {
    sortIncomeCashOperationByDate(firstDate, lastDate);
}

void BudgetMenager::showExpenses(int firstDate, int lastDate) {
    sortExpenseCashOperationByDate(firstDate, lastDate);
}

int BudgetMenager::getLoggedUserId() {
    return LOGGED_USER_ID;
}

int BudgetMenager::getFirstDateOfCurrentMonth() {
    int firstDateOfCurrentMonth;
    const int FIRST_DAY = 1;

    time_t t = time(nullptr);

    tm* now = localtime(&t);
    firstDateOfCurrentMonth = 10000 * (now->tm_year + 1900) + 100 * (now->tm_mon + 1) + FIRST_DAY;

    return firstDateOfCurrentMonth;
}

int BudgetMenager::getLastDateOfCurrentMonth() {
    int lastDateOfCurrentMonth, year, month, lastDay;
    time_t t = time(nullptr);

    tm* now = localtime(&t);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;

    lastDay = AuxiliaryMethods::getMaxDayOfMonth(month, year);

    lastDateOfCurrentMonth = 10000 * year + 100 * month + lastDay;

    return lastDateOfCurrentMonth;
}

int BudgetMenager::getFirstDateOfPreviousMonth() {
    int firstDateOfCurrentMonth, currentYear, currentMonth, previosMonth, year;
    const int DECEMBER = 12;
    const int FIRST_DAY = 1;
    time_t t = time(nullptr);

    tm* now = localtime(&t);
    currentYear = now->tm_year + 1900;
    currentMonth = now->tm_mon + 1;

    if (currentMonth == 1) {
        previosMonth = DECEMBER;
        year = currentYear - 1;
    }
    else {
        previosMonth = currentMonth - 1;
        year = currentYear;
    }

    firstDateOfCurrentMonth = 10000 * year + 100 * previosMonth + FIRST_DAY;

    return firstDateOfCurrentMonth;
}

int BudgetMenager::getLastDateOfPreviousMonth() {
    int lastDateOfCurrentMonth, currentYear, currentMonth, lastDay, previosMonth, year;
    const int DECEMBER = 12;
    time_t t = time(nullptr);

    tm* now = localtime(&t);
    currentYear = now->tm_year + 1900;
    currentMonth = now->tm_mon + 1;

    if (currentMonth == 1) {
        previosMonth = DECEMBER;
        year = currentYear - 1;
    }
    else {
        previosMonth = currentMonth - 1;
        year = currentYear;
    }

    lastDay = AuxiliaryMethods::getMaxDayOfMonth(previosMonth, year);

    lastDateOfCurrentMonth = 10000 * year + 100 * previosMonth + lastDay;


    return lastDateOfCurrentMonth;
}
