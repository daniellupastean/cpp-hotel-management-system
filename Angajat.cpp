#include "Angajat.h"

Angajat::Angajat(string _date) :Persoana(_date)
{
    vector<string> dateAsArrayOfStrings = Functii::split(_date,",");
    functie = dateAsArrayOfStrings[3];
    salariu = stof(dateAsArrayOfStrings[4]);

}

string Angajat::ConversieLaSir()
{
    string dateForDisplay = CNP + "\t" + nume + " " + prenume + "\t" + functie + "\t" + Functii::to_string_with_precision(salariu, 2);

    return dateForDisplay;
}

string Angajat::ConversieLaSir_PentruScriereInFisier()
{
    string dateForDisplay = CNP + "," + nume + "," + prenume + "," + functie + "," + to_string(salariu);

    return dateForDisplay;
}

string Angajat::HeaderInfo()
{
    return "CNP\t\tNUME\t\tFUNCTIE\t\tSALARIU (LEI)";
}
