#include "IncomeFile.h"

int IncomeFile::getLastIncomeId() {
    return lastIncomeId;
}

vector <Income> IncomeFile::loadUserIncomes(const int ID_OF_LOGGED_USSER) {
    Income income;
    vector <Income> incomes;
    lastIncomeId = 0;

    if (xml.Load(getFileName())) {
        xml.FindElem("Incomes");
        xml.IntoElem();
        while (xml.FindElem("Income")) {
            lastIncomeId++;

            xml.IntoElem();

            xml.FindElem("UserId");
            if (AuxiliaryMethods::stringToIntConversion(xml.GetData()) == ID_OF_LOGGED_USSER) {
                income.setUserId(AuxiliaryMethods::stringToIntConversion(xml.GetData()));

                xml.FindElem("IncomeId");
                income.setIncomeId(AuxiliaryMethods::stringToIntConversion(xml.GetData()));

                xml.FindElem("IncomeDate");
                income.setIncomeDate(AuxiliaryMethods::stringToIntConversion(xml.GetData()));

                xml.FindElem("Item");
                income.setItem(xml.GetData());

                xml.FindElem("Amount");
                income.setAmount(AuxiliaryMethods::stringToFloatConversion(xml.GetData()));
            }
            xml.OutOfElem();
            incomes.push_back(income);
        }
    }

    return incomes;
}

bool IncomeFile::addIncomeToFile(Income income) {
    bool fileExist = xml.Load(getFileName());
    string incomeAmountStr = AuxiliaryMethods::floatToStringConvert(income.getAmount());

    if(!fileExist) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("IncomeDate", income.getIncomeDate()); //sformatowana??
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", incomeAmountStr);

    xml.Save(getFileName());

    lastIncomeId++;

    return true;
}
