#include "MyBudget.h"

void MyBudget::registerUser() {
    userMenager.registerUser();
}

void MyBudget::logInUser() {
    userMenager.logInUser();

    if(userMenager.isUserLogged()) {
        budgetMenager = new BudgetMenager(userMenager.getLoggedUserId(), INCOME_FILE_NAME, EXPENSE_FILE_NAME);
    }
}

void MyBudget::logOutUser() {
    userMenager.logOutUser();
    delete budgetMenager;
    budgetMenager = NULL;
}

void MyBudget::changeUserPassword() {
    userMenager.changeUserPassword();
}

void MyBudget::addIncome() {
    budgetMenager->addIncome();
}

void MyBudget::addExpense() {
    budgetMenager->addExpense();
}

void MyBudget::showBalanceSheetFromCurrentMonth() {
    int firstDateCurrentMonth, lastDateCurrentMonth;

    if (userMenager.isUserLogged()) {
        firstDateCurrentMonth = budgetMenager->getFirstDateOfCurrentMonth();
        lastDateCurrentMonth = budgetMenager->getLastDateOfCurrentMonth();

        budgetMenager->showIncomes(firstDateCurrentMonth, lastDateCurrentMonth);
        budgetMenager->showExpenses(firstDateCurrentMonth, lastDateCurrentMonth);
    }
}

void MyBudget::showBalanceSheetFromPreviousMonth() {
    int firstDatePreviousMonth, lastDatePreviousMonth;

    if (userMenager.isUserLogged()) {
        firstDatePreviousMonth = budgetMenager->getFirstDateOfPreviousMonth();
        lastDatePreviousMonth = budgetMenager->getLastDateOfPreviousMonth();

        budgetMenager->showIncomes(firstDatePreviousMonth, lastDatePreviousMonth);
        budgetMenager->showExpenses(firstDatePreviousMonth, lastDatePreviousMonth);
    }
}

void MyBudget::showBalanceSheetFromSelectedPeriod() {
    int firstDate, lastDate;
    string firstDateStr, lastDateStr;
    bool areCorrectDates = true;

   do {
   //     system("cls");
        do {
            system("cls");
            cout << "Podaj od kiedy chcesz zobaczyc bilans (format <rrrr-mm-ss->): ";
            firstDateStr = AuxiliaryMethods::enterLine();
        } while (!AuxiliaryMethods::isCorrectDateFormat(firstDateStr));

        firstDateStr.erase(7, 1);
        firstDateStr.erase(4, 1);
        firstDate = stoi(firstDateStr);

        do {
            system("cls");
            cout << "Podaj do kiedy chcesz zobaczyc bilans (format <rrrr-mm-ss->): ";
            lastDateStr = AuxiliaryMethods::enterLine();
        } while (!AuxiliaryMethods::isCorrectDateFormat(lastDateStr));

        lastDateStr.erase(7, 1);
        lastDateStr.erase(4, 1);
        lastDate = stoi(lastDateStr);

        if (firstDate > lastDate) {
            areCorrectDates = false;
        }
   } while (!areCorrectDates);

    budgetMenager->showIncomes(firstDate, lastDate);
    budgetMenager->showExpenses(firstDate, lastDate);
}

char MyBudget::selectOptionWithMainMenu() {
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    return AuxiliaryMethods::enterChar();
}

char MyBudget::selectOptionWithUserMenu() {
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj dochod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "9. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    return AuxiliaryMethods::enterChar();
}

int MyBudget::getLoogedUserId() {
    return userMenager.getLoggedUserId();
}
