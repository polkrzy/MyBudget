#include "User.h"

int User::getId() {
    return id;
}

string User::getFirstName() {
    return firstName;
}

string User::getLastName() {
    return lastName;
}

string User::getLogin() {
    return login;
}

string User::getPassword() {
    return password;
}

void User::setId(int newId) {
    id = newId;
}

void User::setFirstName(string newFirstName) {
    firstName = newFirstName;
}

void User::setLastName(string newLastName) {
    lastName = newLastName;
}

void User::setLogin(string newLogin) {
    login = newLogin;
}

void User::setPassword(string newPassword) {
    password = newPassword;
}
