#ifndef PERSOANA_H
#define PERSOANA_H

#include<iostream>
#include<string>
#include<vector>
#include"Functii.h"

using namespace std;

class Persoana
{
public:
    string nume;
    string prenume;
    string CNP;
    Persoana(string _date);
    string GetNume()
    {
        return nume;
    }
    string GetPrenume()
    {
        return prenume;
    }
    virtual string ConversieLaSir();
};

#endif // PERSOANA_H
