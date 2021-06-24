#include "Rezervare.h"

Rezervare::Rezervare(string _date)
{
    vector<string> dateAsArrayOfStrings = Functii::split(_date, ",");
    ID_rezervare = stoi(dateAsArrayOfStrings[0]);
    CNP_client = dateAsArrayOfStrings[1];
    ID_camera = stoi(dateAsArrayOfStrings[2]);

    checkin_date = dateAsArrayOfStrings[3];
    checkout_date = dateAsArrayOfStrings[4];
}

string Rezervare::ConversieLaSir()
{
    string dateForDisplay = to_string(ID_rezervare) + "\t" + CNP_client + "\t" + to_string(ID_camera) + "\t" + checkin_date + " - " + checkout_date;

    return dateForDisplay;
}


string Rezervare::ConversieLaSir_PentruScriereInFisier()
{
    string dateForDisplay = to_string(ID_rezervare) + "," + CNP_client + "," + to_string(ID_camera) + "," + checkin_date + "," + checkout_date;

    return dateForDisplay+"\0";
}

string Rezervare::HeaderInfo()
{
    return "ID\tCNP\t\tID CAM\tCHECK-IN     CHECK-OUT";
}
