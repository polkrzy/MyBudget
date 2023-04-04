#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int id;
    string firstName, lastName, login, password;

public:
    int getId();
    string getFirstName();
    string getLastName();
    string getLogin();
    string getPassword();

    void setId(int newId);
    void setFirstName(string newFirstName);
    void setLastName(string newLastName);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
};

#endif
