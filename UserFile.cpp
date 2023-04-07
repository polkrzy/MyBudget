#include "UserFile.h"

void UserFile::addUserToFile(User user) {
    bool fileExist = xml.Load(getFileName());

    if(!fileExist) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("FirstName", user.getFirstName());
    xml.AddElem("LastName", user.getLastName());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save(getFileName());
}

void UserFile::changeUserPasswordInFile(string newPassword, int loggedUserId) {
    bool fileExist = xml.Load(getFileName());

    if(!fileExist) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    if (xml.Load(getFileName())) {
        if (xml.FindElem("Users")) {
            xml.IntoElem();
            while (xml.FindElem("User")) {
                if (xml.GetAttrib("UserId") == to_string(loggedUserId)) {
                    xml.IntoElem();
                    if (xml.FindElem("Password")) {
                        xml.SetData(newPassword);
                        xml.Save(getFileName());
                        cout << "Haslo uzytkownika zostalo zmienione" << endl;
                    } else {
                        cout << "Nie udalo sie zmienic hasla uzytkownika" << endl;
                    }
                    xml.OutOfElem();
                    break;
                }
            }
            xml.OutOfElem();
        } else {
            cout << "Nie znaleziono uzytkownikow" << endl;
        }
    } else {
        cout << "Nie udalo sie otworzyc pliku XML" << endl;
    }
}
vector <User> UserFile::loadUsersFromFile() {
    User user;
    vector <User> users;

    if (xml.Load(getFileName())) {
        xml.FindElem("Users");
        xml.IntoElem();
        while (xml.FindElem("User")) {
            xml.IntoElem();

            xml.FindElem("UserId");
            user.setId(AuxiliaryMethods::stringToIntConversion(xml.GetData()));

            xml.FindElem("FirstName");
            user.setFirstName(xml.GetData());

            xml.FindElem("LastName");
            user.setLastName(xml.GetData());

            xml.FindElem("Login");
            user.setLogin(xml.GetData());

            xml.FindElem("Password");
            user.setPassword(xml.GetData());

            xml.OutOfElem();

            users.push_back(user);
        }
    }

    return users;
}

