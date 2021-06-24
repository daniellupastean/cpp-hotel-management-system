#include "AdministratorFisiere.h"

AdministratorFisiere::AdministratorFisiere()
{
    //ctor
}

AdministratorFisiere::~AdministratorFisiere()
{
    //dtor
}

///Administrare fisier Clienti.txt
Client AdministratorFisiere::GetClient(string _nume, string _prenume)
{
    ifstream inf(NUME_FISIER_CLIENTI);
    string line;
    vector<Client> clienti_temp;
    while(getline(inf, line))
    {
        Client c(line);
        if(c.GetNume().compare(_nume) == 0 && c.GetPrenume().compare(_prenume) == 0)
        {
            return (Client(line));
            break;
        }
    }
    return Client("nesetat,nesetat,nesetat,0");
}

vector<Client> AdministratorFisiere::GetClienti()
{
    ifstream inf(NUME_FISIER_CLIENTI);
    string line;
    vector<Client> clienti_temp;
    while(getline(inf, line))
    {
        clienti_temp.push_back(Client(line));
    }

    return clienti_temp;
}

void AdministratorFisiere::AddClient(Client client)
{
    ofstream of(NUME_FISIER_CLIENTI, ios::app);
    of<<client.ConversieLaSir_PentruScriereInFisier()<<endl;
    of.close();
}

void AdministratorFisiere::UpdateFisierClienti(vector<Client> clienti)
{
    ofstream of(NUME_FISIER_CLIENTI, ios::out | ios::trunc);
    for(Client client:clienti)
        of<<client.ConversieLaSir_PentruScriereInFisier()<<endl;
    of.close();
}


/// Administrare fisier Angajati.txt
Angajat AdministratorFisiere::GetAngajat(string _nume, string _prenume)
{
    ifstream inf(NUME_FISIER_ANGAJATI);
    string line;
    vector<Angajat> angajati_temp;
    while(getline(inf, line))
    {
        Angajat a(line);
        if(a.GetNume().compare(_nume) == 0 && a.GetPrenume().compare(_prenume) == 0)
        {
            return a;
        }
    }
    return Angajat("nesetat,nesetat,nesetat,nesetat,0");
}

vector<Angajat> AdministratorFisiere::GetAngajati()
{
    ifstream inf(NUME_FISIER_ANGAJATI);
    string line;
    vector<Angajat> angajati_temp;
    while(getline(inf, line))
    {
        angajati_temp.push_back(Angajat(line));
    }

    return angajati_temp;
}

void AdministratorFisiere::AddAngajat(Angajat angajat)
{
    ofstream of(NUME_FISIER_ANGAJATI, ios::app);
    of<<angajat.ConversieLaSir_PentruScriereInFisier()<<endl;
    of.close();
}

void AdministratorFisiere::UpdateFisierAngajati(vector<Angajat> angajati)
{
    ofstream of(NUME_FISIER_ANGAJATI, ios::out | ios::trunc);
    for(Angajat angajat:angajati)
        of<<angajat.ConversieLaSir_PentruScriereInFisier()<<endl;
    of.close();
}


/// Administrare fisier Camere.txt
Camera AdministratorFisiere::GetCamera(string _denumire)
{
    ifstream inf(NUME_FISIER_CAMERE);
    string line;
    vector<Camera> camere_temp;
    while(getline(inf, line))
    {
        Camera c(line);
        if(c.denumire.compare(_denumire) == 0)
        {
            return c;
        }
    }
    return Camera("0,nesetat,0,0,0,0,0");
}

vector<Camera> AdministratorFisiere::GetCamere()
{
    ifstream inf(NUME_FISIER_CAMERE);
    string line;
    vector<Camera> camere_temp;
    while(getline(inf, line))
    {
        camere_temp.push_back(Camera(line));
    }

    return camere_temp;
}

void AdministratorFisiere::AddCamera(Camera camera)
{
    ofstream of(NUME_FISIER_CAMERE, ios::app);
    of<<camera.ConversieLaSir_PentruScriereInFisier()<<endl;
    of.close();
}

void AdministratorFisiere::UpdateFisierCamere(vector<Camera> camere)
{
    ofstream of(NUME_FISIER_CAMERE, ios::out | ios::trunc);
    for(Camera camera:camere)
        of<<camera.ConversieLaSir_PentruScriereInFisier()<<endl;
    of.close();
}


/// Administrare fisier Rezervari.txt
Rezervare AdministratorFisiere::GetRezervare(int _id)
{
    ifstream inf(NUME_FISIER_REZERVARI);
    string line;
    vector<Rezervare> rezervari_temp;
    while(getline(inf, line))
    {
        Rezervare r(line);
        if(r.ID_rezervare == _id)
        {
            return r;
        }
    }
    return Rezervare("0,nesetat,0,0,0");
}

vector<Rezervare> AdministratorFisiere::GetRezervari()
{
    ifstream inf(NUME_FISIER_REZERVARI);
    string line;
    vector<Rezervare> rezervari_temp;
    while(getline(inf, line))
    {
        rezervari_temp.push_back(Rezervare(line));
    }

    return rezervari_temp;
}

void AdministratorFisiere::AddRezervare(Rezervare rezervare)
{
    ofstream of(NUME_FISIER_REZERVARI, ios::app);
    of<<rezervare.ConversieLaSir_PentruScriereInFisier()<<endl;
    of.close();
}

void AdministratorFisiere::UpdateFisierRezervari(vector<Rezervare> rezervari)
{
    ofstream of(NUME_FISIER_REZERVARI, ios::out | ios::trunc);
    for(Rezervare rezervare:rezervari)
        of<<rezervare.ConversieLaSir_PentruScriereInFisier()<<endl;
    of.close();
}


