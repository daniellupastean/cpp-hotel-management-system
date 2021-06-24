#include "Client.h"

Client::Client(string _date) : Persoana(_date)
{
    vector<string> dateAsArrayOfStrings = Functii::split(_date, ",");

    vector<string> rezervariAsArrayOfStrings = Functii::split(dateAsArrayOfStrings[3],"-");
    ID_rezervari.resize(rezervariAsArrayOfStrings.size());

    for(int i = 0; i<(int)rezervariAsArrayOfStrings.size(); i++)
    {
        ID_rezervari[i] = stoi(rezervariAsArrayOfStrings[i]);
    }
}

string Client::ConversieLaSir()
{
    string dateForDisplay = CNP + "\t" + nume + " " + prenume + "\t";
    for(int rezervare : ID_rezervari)
    {
        dateForDisplay += to_string(rezervare) + "-";
    }

    dateForDisplay.pop_back();

    return dateForDisplay;
}

string Client::ConversieLaSir_PentruScriereInFisier()
{
    string dateForDisplay = CNP + "," + nume + "," + prenume + ",";
    for(int rezervare:ID_rezervari)
    {
        dateForDisplay += to_string(rezervare) + "-";
    }

    dateForDisplay.pop_back();

    return dateForDisplay;
}

void Client::Update(string _CNP, string _nume, string _prenume, string _ID_rezervari)
{
    CNP = _CNP;
    nume = _nume;
    prenume = _prenume;

    vector<string> rezervariAsArrayOfStrings = Functii::split(_ID_rezervari,"-");

    ID_rezervari.clear();
    ID_rezervari.resize(rezervariAsArrayOfStrings.size());
    for (int i = 0; i < (int)ID_rezervari.size(); i++)
    {
        ID_rezervari[i] = stoi(rezervariAsArrayOfStrings[i]);
    }
}

string Client::HeaderInfo()
{
    return "CNP\t\t\tNUME\t\t\tID-URI REZERVARI";
}
