#include "MyBudget.h"

int main() {

    MyBudget myBudget("users.xml", "incomes.xml", "expenses.xml");

    while (true) {
        if (!myBudget.getLoogedUserId()) {
            switch (myBudget.selectOptionWithMainMenu()) {
            case '1':
                myBudget.registerUser();
                break;
            case '2':
                myBudget.logInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            switch (myBudget.selectOptionWithUserMenu()) {
            case '1':
                myBudget.addIncome();
                break;
            case '2':
                myBudget.addExpense();
                break;
            case '3':
                myBudget.showBalanceSheetFromCurrentMonth();
                break;
            case '4':
                myBudget.showBalanceSheetFromPreviousMonth();
                break;
            case '5':
                myBudget.showBalanceSheetFromSelectedPeriod();
                break;
            case '6':
                myBudget.changeUserPassword();
                break;
            case '9':
                myBudget.logOutUser();
                break;
            }
        }
    }
    return 0;
}
