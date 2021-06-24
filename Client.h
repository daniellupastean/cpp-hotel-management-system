#ifndef CLIENT_H
#define CLIENT_H

#include "Persoana.h"
#include "Functii.h"
#include <string>


class Client : public Persoana
{
    vector<int> ID_rezervari;
public:
    Client(string _date);
    static string HeaderInfo();
    string ConversieLaSir();
    string ConversieLaSir_PentruScriereInFisier();
    void Update(string _CNP, string _nume, string _prenume, string _ID_rezervari);
};

#endif // CLIENT_H
