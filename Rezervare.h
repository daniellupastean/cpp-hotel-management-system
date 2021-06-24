#ifndef REZERVARE_H
#define REZERVARE_H

#include <iostream>
#include <string>
#include <vector>

#include "Functii.h"

using namespace std;

class Rezervare
{
public:
    static int nrRezervari;
    int ID_rezervare;
    string CNP_client;
    int ID_camera;
    string checkin_date;
    string checkout_date;

    static string HeaderInfo();
    Rezervare(string _date);
    string ConversieLaSir();
    string ConversieLaSir_PentruScriereInFisier();
};

#endif // REZERVARE_H
