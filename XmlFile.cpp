#include "XmlFile.h"

bool XmlFile::isFileEmpty() {
    CMarkup xml;

    if(xml.Load("plik.xml")) {
        return xml.FindElem();
    } else {
        cout << "Nie udalo sie otworzyc pliku." << endl;
        return false;
    }
}

string XmlFile::getFileName() {
    return FILE_NAME;
}
