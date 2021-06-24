#include "Camera.h"

Camera::Camera(string _date)
{
    vector<string> dateAsArrayOfStrings = Functii::split(_date,",");

    ID_camera = stoi(dateAsArrayOfStrings[0]);
    denumire = dateAsArrayOfStrings[1];

    dimensiune = stof(dateAsArrayOfStrings[2]);
    etaj = stof(dateAsArrayOfStrings[3]);
    vector<string> _facilitati = Functii::split(dateAsArrayOfStrings[4],"+");

    for(string facilitate : _facilitati)
    {
        facilitati.push_back(stoi(facilitate));
    }

    tip = stoi(dateAsArrayOfStrings[5]);
    pret = stoi(dateAsArrayOfStrings[6]);
}

string Camera::ConversieLaSir()
{
    string dateForDisplay = to_string(ID_camera) + "\t" + denumire + "\t" + Functii::to_string_with_precision(dimensiune, 2) + " m2  " + to_string(etaj) + "\t";
    for (int facilitate: facilitati)
    {
        dateForDisplay+= facilitatiCamera[facilitate] + "+";
    }
    dateForDisplay.pop_back();
    dateForDisplay += "\t" + tipCamera[tip] + "\t" + Functii::to_string_with_precision(pret,2) + " lei";
    return dateForDisplay;
}


string Camera::ConversieLaSir_PentruScriereInFisier()
{
    return to_string(ID_camera) + "," + denumire + "," + Functii::to_string_with_precision(dimensiune, 2) + "," + to_string(etaj) + "," + Functii::ivector_to_string(facilitati,"+") + "," + to_string(tip) + "," + Functii::to_string_with_precision(pret,2);
}

string Camera::HeaderInfo()
{
    return "ID\tNUME\tARIE\tETAJ\tFACILITATI\tTIP\tPRET";
}
