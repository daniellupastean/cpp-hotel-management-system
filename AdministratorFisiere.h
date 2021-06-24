#ifndef ADMINISTRATORFISIERE_H
#define ADMINISTRATORFISIERE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Client.h"
#include "Angajat.h"
#include "Camera.h"
#include "Rezervare.h"

using namespace std;

class AdministratorFisiere
{
private:
    const string NUME_FISIER_CLIENTI = "Clienti.txt";
    const string NUME_FISIER_ANGAJATI = "Angajati.txt";
    const string NUME_FISIER_CAMERE = "Camere.txt";
    const string NUME_FISIER_REZERVARI = "Rezervari.txt";


public:
    AdministratorFisiere();
    virtual ~AdministratorFisiere();

    Client GetClient(string, string);
    vector<Client> GetClienti();
    void AddClient(Client);
    void UpdateFisierClienti(vector<Client>);

    Angajat GetAngajat(string, string);
    vector<Angajat> GetAngajati();
    void AddAngajat(Angajat);
    void UpdateFisierAngajati(vector<Angajat>);

    Camera GetCamera(string);
    vector<Camera> GetCamere();
    void AddCamera(Camera);
    void UpdateFisierCamere(vector<Camera>);

    Rezervare GetRezervare(int);
    vector<Rezervare> GetRezervari();
    void AddRezervare(Rezervare);
    void UpdateFisierRezervari(vector<Rezervare>);
};

#endif // ADMINISTRATORFISIERE_H
