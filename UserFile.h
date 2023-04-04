#ifndef USERFILE_H
#define USERFILE_H

#include "AuxiliaryMethods.h"
#include "XmlFile.h"
#include "User.h"

class UserFile : public XmlFile {
public:
    UserFile(string userFileName)
    : XmlFile(userFileName) {};

    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void changeUserPasswordInFile(string newPassword, int loggedUserId);

};
#endif
