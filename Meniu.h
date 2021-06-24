#ifndef MENIU_H
#define MENIU_H

#include <iostream>
#include<iomanip>
#include <windows.h>
#include <conio.h>


#include"Persoana.h"
#include"Client.h"
#include"Angajat.h"
#include"Camera.h"
#include"Rezervare.h"
#include"AdministratorFisiere.h"

using namespace std;

class Meniu
{
public:

    Meniu();
    virtual ~Meniu();
    void Executare();

private:
    AdministratorFisiere admin;

    vector<Client> clienti;
    vector<Camera> camere;
    vector<Rezervare> rezervari;
    vector<Angajat> angajati;
    string decalaj = "                           ";
    string decalaj2 = "                    ";
    string decalaj3 = "                         ";

    HANDLE  hConsole;

    void AfisareOptiuni();

    void AfisareClienti();
    void AfisareAngajati();
    void AfisareCamere();
    void AfisareRezervari();

    void AdaugareClient();
    void AdaugareAngajat();
    void AdaugareCamera();
    void AdaugareRezervare();

    void CautareClient();
    void CautareAngajat();
    void CautareCamera();
    void CautareRezervare();

    void ModificareClient();
    void ModificareAngajat();
    void ModificareCamera();
    void ModificareRezervare();


    void gotoxy(int, int);


};

#endif // MENIU_H
