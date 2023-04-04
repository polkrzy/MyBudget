#ifndef USERMENAGER_H
#define USERMENAGER_H

#include "UserFile.h"

class UserMenager {
    int loggedUserId;
    vector <User> users;
    UserFile userFile;

    int getNewUserId();
    bool doesLoginExist(string login);
    User setNewUserData();
public:
    UserMenager(string userFileName)
        : userFile(userFileName) {
            loggedUserId = 0;
            users = userFile.loadUsersFromFile();
        };

    int getLoggedUserId();
   // void setLoggedUserId(int newIdOfLoggedUser);
    bool isUserLogged();

    void registerUser();
    void logInUser();
    void logOutUser();
    void changeUserPassword();

};

#endif
