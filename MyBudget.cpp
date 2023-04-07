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
    if (userMenager.isUserLogged()) {
        budgetMenager->showBalanceSheetFromCurrentMonth();
    }
}

void MyBudget::showBalanceSheetFromPreviousMonth() {
    if (userMenager.isUserLogged()) {
        budgetMenager->showBalanceSheetFromPreviousMonth();
    }
}

void MyBudget::showBalanceSheetFromSelectedPeriod() {
    if (userMenager.isUserLogged()) {
        budgetMenager->showBalanceSheetFromSelectedPeriod();
    }
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
