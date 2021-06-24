#ifndef ANGAJAT_H
#define ANGAJAT_H

#include "Persoana.h"
#include "Functii.h"


class Angajat : public Persoana
{
public:
    string functie;
    float salariu;

    Angajat(string _date);

    static string HeaderInfo();
    string ConversieLaSir();
    string ConversieLaSir_PentruScriereInFisier();
};

#endif // ANGAJAT_H
