#include "Persoana.h"

Persoana::Persoana(string _date)
{
    vector<string> dateAsArrayOfStrings = Functii::split(_date, ",");

    CNP = dateAsArrayOfStrings[0];
    nume = dateAsArrayOfStrings[1];
    prenume = dateAsArrayOfStrings[2];
}

string Persoana::ConversieLaSir()
{
    string dateForDisplay = CNP + "," + nume + " " + prenume;

    return dateForDisplay;
}


