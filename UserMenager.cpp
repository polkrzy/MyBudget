#include "UserMenager.h"

User UserMenager::setNewUserData() {
    User user;
    string firstName, lastName;

    user.setId(getNewUserId());

    cout << "Podaj imie: ";
    firstName = AuxiliaryMethods::enterLine();
    user.setFirstName(AuxiliaryMethods::replaceFirstLetterUppercaseAndOtherLowercase(firstName));

    cout << "Podaj nazwisko: ";
    lastName = AuxiliaryMethods::enterLine();
    user.setLastName(AuxiliaryMethods::replaceFirstLetterUppercaseAndOtherLowercase(lastName));

    string login;
    do {
        cout << "Podaj login: ";
        login = AuxiliaryMethods::enterLine();
        user.setLogin(login);
    } while (doesLoginExist(user.getLogin()));

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);
    return user;
}

int UserMenager::getNewUserId() {
    if (users.empty())
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserMenager::doesLoginExist(string login) {
    for (unsigned int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

int UserMenager::getLoggedUserId() {
    return loggedUserId;
}

void UserMenager::registerUser() {
    User user = setNewUserData();

    users.push_back(user);
    userFile.addUserToFile(user);

    cout << endl << "Konto zostalo utworzone" << endl << endl;
    system("pause");
}

void UserMenager::logInUser() {
    string login = "";
    string password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::enterLine();

    for (int i = 0; i < (int) users.size(); i++) {
        if (users[i].getLogin() == login) {
            for (int numberOfTry = 3; numberOfTry > 0; numberOfTry--) {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfTry << ": ";
                password = AuxiliaryMethods::enterLine();

                if (users[i].getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");

                    loggedUserId = users[i].getId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UserMenager::logOutUser() {
    loggedUserId = 0;
}

void UserMenager::changeUserPassword() {
    string newPassword = "";

    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::enterLine();

    for (int i = 0; i < (int) users.size(); i++) {
        if (users[i].getId() == loggedUserId) {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << newPassword<< endl;
            system("pause");
            userFile.changeUserPasswordInFile(newPassword, loggedUserId);
        }
    }
}

bool UserMenager::isUserLogged() {
    if (loggedUserId > 0) {
        return true;
    }
    return false;
}
