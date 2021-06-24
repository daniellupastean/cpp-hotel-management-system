#include "Meniu.h"


Meniu::Meniu()
{
    system("title Administrare Hotel");
    clienti = admin.GetClienti();
    camere = admin.GetCamere();
    rezervari = admin.GetRezervari();
    angajati = admin.GetAngajati();

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
}

Meniu::~Meniu()
{
    //dtor
}

void Meniu::AfisareOptiuni()
{
    cout<<"                             _           _       _     _                        _    _       _       _"<<endl;
    cout<<"                    /\\      | |         (_)     (_)   | |                      | |  | |     | |     | |"<<endl;
    cout<<"                   /  \\   __| |_ __ ___  _ _ __  _ ___| |_ _ __ __ _ _ __ ___  | |__| | ___ | |_ ___| |"<<endl;
    cout<<"                  / /\\ \\ / _` | '_ ` _ \\| | '_ \\| / __| __| '__/ _` | '__/ _ \\ |  __  |/ _ \\| __/ _ \\ |"<<endl;
    cout<<"                 / ____ \\ (_| | | | | | | | | | | \\__ \\ |_| | | (_| | | |  __/ | |  | | (_) | ||  __/ |"<<endl;
    cout<<"                /_/    \\_\\__,_|_| |_| |_|_|_| |_|_|___/\\__|_|  \\__,_|_|  \\___| |_|  |_|\\___/ \\__\\___|_|";
    cout<<endl<<"                ______________________________________________________________________________________ ";
    cout<<endl<<"               / 11 - Afisare clienti                 |                                               \\";
    cout<<endl<<"               | 12 - Afisare angajati                |                                               |";
    cout<<endl<<"               | 13 - Afisare camere                  |                                               |";
    cout<<endl<<"               | 14 - Afisare rezervari               |                                               |";
    cout<<endl<<"               |--------------------------------------|                                               |";
    cout<<endl<<"               | 21 - Creare si adaugare client       |                                               |";
    cout<<endl<<"               | 22 - Creare si adaugare angajat      |                                               |";
    cout<<endl<<"               | 23 - Creare si adaugare camera       |-----------------------------------------------|";
    cout<<endl<<"               | 24 - Creare si adaugare rezervare    |                                               |";
    cout<<endl<<"               |--------------------------------------|                                               |";
    cout<<endl<<"               | 31 - Cauta client dupa nume          |                                               |";
    cout<<endl<<"               | 32 - Cauta angajat dupa nume         |-----------------------------------------------|";
    cout<<endl<<"               | 33 - Cauta camera dupa id            |                                               |";
    cout<<endl<<"               | 34 - Cauta rezervare dupa id         |                                               |";
    cout<<endl<<"               |--------------------------------------|                                               |";
    cout<<endl<<"               | 41 - Modifica client dupa nume       |                                               |";
    cout<<endl<<"               | 42 - Modifica angajat dupa nume      |                                               |";
    cout<<endl<<"               | 43 - Modifica camera dupa id         |                                               |";
    cout<<endl<<"               | 44 - Modifica rezervare dupa id      |                                               |";
    cout<<endl<<"               |--------------------------------------|                                               |";
    cout<<endl<<"               | 0  - Inchidere program               |                                               |";
    cout<<endl<<"               |______________________________________|_______________________________________________|";
    cout<<endl;
}



void Meniu::gotoxy(int x, int y) {
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void Meniu::Executare()
{
    while(true)
    {
        system("cls");
        SetConsoleTextAttribute(hConsole, 7);
        Meniu::AfisareOptiuni();
        int optiune;
        SetConsoleTextAttribute(hConsole, 9);
        gotoxy(65,16);
        cout<<" Alege o optiune: ";
        cin>>optiune;
        system("cls");
        SetConsoleTextAttribute(hConsole, 15);
        gotoxy(0,6);        switch(optiune)
        {
        case 11:
        {
            AfisareClienti();
            break;
        }
        case 12:
        {
            AfisareAngajati();
            break;
        }
        case 13:
        {
            AfisareCamere();
            break;
        }
        case 14:
        {
            AfisareRezervari();
            break;
        }
        case 21:
        {
            AdaugareClient();
            break;
        }
        case 22:
        {
            AdaugareAngajat();
            break;
        }
        case 23:
        {
            AdaugareCamera();
            break;
        }
        case 24:
        {
            AdaugareRezervare();
            break;
        }
        case 31:
        {
            CautareClient();
            break;
        }
        case 32:
        {
            CautareAngajat();
            break;
        }
        case 33:
        {
            CautareCamera();
            break;
        }
        case 34:
        {
            CautareRezervare();
            break;
        }
        case 41:
        {
            ModificareClient();
            break;
        }
        case 42:
        {
            ModificareAngajat();
            break;
        }
        case 43:
        {
            ModificareCamera();
            break;
        }
        case 44:
        {
            ModificareRezervare();
            break;
        }

        case 0:
            system("cls");
            return;
        default:
            SetConsoleTextAttribute(hConsole, 4);
            cout<<endl<<decalaj<<"Optiune inexistenta."<<endl;
            SetConsoleTextAttribute(hConsole, 15);
        }
        cout<<endl<<decalaj<<"Apasa orice tasta pentru a reveni la meniul principal...";
        getch();
    }
}

void Meniu::AfisareClienti()
{
    cout<<decalaj<<"-------------------- AFISARE CLIENTI ---------------------\n\n";
    SetConsoleTextAttribute(hConsole, 8);
    cout<<decalaj<<Client::HeaderInfo()<<endl;
    SetConsoleTextAttribute(hConsole, 15);
    for(Client client : clienti)
    {
        cout<<decalaj<<client.ConversieLaSir()<<endl;
    }
    cout<<endl<<decalaj<<"----------------------------------------------------------\n";
}

void Meniu::AfisareAngajati()
{
    cout<<decalaj3<<"--------------------- AFISARE ANGAJATI -----------------------\n\n";
    SetConsoleTextAttribute(hConsole, 8);
    cout<<decalaj3<<Angajat::HeaderInfo()<<endl;
    SetConsoleTextAttribute(hConsole, 15);
    for(Angajat angajat : angajati)
    {
        cout<<decalaj3<<angajat.ConversieLaSir()<<endl;
    }
    cout<<endl<<decalaj3<<"--------------------------------------------------------------\n";
}

void Meniu::AfisareCamere()
{
    cout<<decalaj<<"----------------------- AFISARE CAMERE ------------------------\n\n";
    SetConsoleTextAttribute(hConsole, 8);
    cout<<decalaj<<Camera::HeaderInfo()<<endl;
    SetConsoleTextAttribute(hConsole, 15);
    for(Camera camera : camere)
    {
        cout<<decalaj<<camera.ConversieLaSir()<<endl;
    }
    cout<<endl<<decalaj<<"---------------------------------------------------------------\n";
}

void Meniu::AfisareRezervari()
{
    cout<<decalaj<<"----------------- AFISARE REZERVARI --------------------\n\n";
    SetConsoleTextAttribute(hConsole, 8);
    cout<<decalaj<<Rezervare::HeaderInfo()<<endl;
    SetConsoleTextAttribute(hConsole, 15);
    for(Rezervare rezervare : rezervari)
    {
        cout<<decalaj<<rezervare.ConversieLaSir()<<endl;
    }
    cout<<endl<<decalaj<<"--------------------------------------------------------\n";
}

void Meniu::AdaugareClient()
{
    cout<<decalaj<<"---------------------- ADAUGARE CLIENT -----------------------------\n\n";
    string dateCitite;
    string buff;
    cout<<endl<<decalaj<<"CNP-ul clientului: ";
    cin>>buff;
    dateCitite += buff;
    cout<<endl<<decalaj<<"Numele clientului: ";
    cin>>buff;
    dateCitite += "," + buff;
    cout<<endl<<decalaj<<"Prenumele clientului: ";
    cin>>buff;
    dateCitite += "," + buff;
    cout<<endl<<decalaj<<"ID-urile rezervarilor clientului (id1-id2-id3): ";
    cin>>buff;
    dateCitite += "," + buff;

    Client tempClient(dateCitite);
    clienti.push_back(tempClient);
    admin.AddClient(tempClient);
    cout<<endl<<decalaj<<"---------------------------------------------------------------------\n";
    SetConsoleTextAttribute(hConsole, 2);
    cout<<endl<<decalaj<<"Clientul a fost adaugat cu succes"<<endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout<<endl<<decalaj<<"---------------------------------------------------------------------\n";
}

void Meniu::AdaugareAngajat()
{
    cout<<decalaj<<"-------------------- ADAUGARE ANGAJAT -----------------------\n\n";
    string dateCitite;
    string buff;
    cout<<endl<<decalaj<<"CNP-ul angajatului: ";
    cin>>buff;
    dateCitite += buff;
    cout<<endl<<decalaj<<"Numele angajatului: ";
    cin>>buff;
    dateCitite += "," + buff;
    cout<<endl<<decalaj<<"Prenumele angajatului: ";
    cin>>buff;
    dateCitite += "," + buff;
    cout<<endl<<decalaj<<"Functia angajatului: ";
    cin>>buff;
    dateCitite += "," + buff;
    cout<<endl<<decalaj<<"Salariul angajatului: ";
    cin>>buff;
    dateCitite += "," + buff;

    Angajat tempAngajat(dateCitite);
    angajati.push_back(tempAngajat);
    admin.AddAngajat(tempAngajat);
    cout<<endl<<decalaj<<"-------------------------------------------------------------\n";
    SetConsoleTextAttribute(hConsole, 2);
    cout<<endl<<decalaj<<"Angajatul a fost adaugat cu succes"<<endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout<<endl<<decalaj<<"-------------------------------------------------------------\n";
}

void Meniu::AdaugareCamera()
{
    gotoxy(0, 1);
    cout<<decalaj<<"---------------------- ADAUGARE CAMERA -----------------------------\n\n";
    string dateCitite;
    string buff;
    cout<<endl<<decalaj<<"ID-ul camerei: ";
    cin>>buff;
    dateCitite += buff;
    cout<<endl<<decalaj<<"Denumirea camerei: ";
    cin>>buff;
    dateCitite += "," + buff;
    cout<<endl<<decalaj<<"Dimensiunea camerei(m2): ";
    cin>>buff;
    dateCitite += "," + buff;
    cout<<endl<<decalaj<<"Etajul la care se afla camera: ";
    cin>>buff;
    dateCitite += "," + buff;
    cout<<endl<<decalaj<<"Facilitatile camerei(f1+f2+f3).\n"<<decalaj<<"(1 - niciuna, 2 - televizor, 3 - internet, 4 - seif, 5 - jacuzzi, 6 - frigider)\n"<<decalaj;
    cin>>buff;
    dateCitite += "," + buff;
    cout<<endl<<decalaj<<"Tipul camerei. \n"<<decalaj<<"(1 - Single, 2 - Dubla, 3 - Twin, 4 - Matrimoniala, 5 - Tripla, 6 - Quad)\n"<<decalaj;
    cin>>buff;
    dateCitite += "," + buff;
    cout<<endl<<decalaj<<"Pretul/noapte al camerei(lei): ";
    cin>>buff;
    dateCitite += "," + buff;

    Camera tempCamera(dateCitite);
    camere.push_back(tempCamera);
    admin.AddCamera(tempCamera);
    cout<<endl<<decalaj<<"---------------------------------------------------------------------\n";
    SetConsoleTextAttribute(hConsole, 2);
    cout<<endl<<decalaj<<"Camera a fost adaugata cu succes"<<endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout<<endl<<decalaj<<"---------------------------------------------------------------------\n";
}

void Meniu::AdaugareRezervare()
{
    cout<<decalaj<<"-------------------- ADAUGARE REZERVARE -----------------------\n\n";
    string dateCitite;
    string buff;
    cout<<endl<<decalaj<<"ID-ul rezervarii: ";
    cin>>buff;
    dateCitite += buff;
    cout<<endl<<decalaj<<"CNP-ul clientului: ";
    cin>>buff;
    dateCitite += "," + buff;
    cout<<endl<<decalaj<<"ID-ul camerei: ";
    cin>>buff;
    dateCitite += "," + buff;
    cout<<endl<<decalaj<<"Data de check-in (zz.ll.aa): ";
    cin>>buff;
    dateCitite += "," + buff;
    cout<<endl<<decalaj<<"Data de check-out (zz.ll.aa): ";
    cin>>buff;
    dateCitite += "," + buff;


    Rezervare tempRezervare(dateCitite);
    rezervari.push_back(tempRezervare);
    admin.AddRezervare(tempRezervare);
    cout<<endl<<decalaj<<"---------------------------------------------------------------\n";
    SetConsoleTextAttribute(hConsole, 2);
    cout<<endl<<decalaj<<"Rezervarea a fost adaugata cu succes"<<endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout<<endl<<decalaj<<"---------------------------------------------------------------\n";
}

void Meniu::CautareClient()
{
    cout<<decalaj<<"---------------------- CAUTARE CLIENT ----------------------------\n\n";
    cout<<endl<<decalaj<<"Numele clientului cautat: ";
    string nume;
    cin>>nume;
    cout<<endl<<decalaj<<"Prenumele clientului cautat: ";
    string prenume;
    cin>>prenume;
    Client clientAfisare = admin.GetClient(nume, prenume);
    cout<<endl<<endl<<decalaj<<"------------------------------------------------------------------\n";
    if(clientAfisare.CNP.compare("nesetat") == 0)
    {
        SetConsoleTextAttribute(hConsole, 4);
        cout<<endl<<decalaj<<"Acest client nu se afla in baza de date"<<endl;
    }
    else
    {

        SetConsoleTextAttribute(hConsole, 2);
        cout<<endl<<decalaj<<"Gasit:      "<<clientAfisare.ConversieLaSir()<<endl;
    }
    SetConsoleTextAttribute(hConsole, 15);
    cout<<endl<<decalaj<<"------------------------------------------------------------------\n";
}

void Meniu::CautareAngajat()
{
    cout<<decalaj<<"---------------------- CAUTARE ANGAJAT -----------------------------\n\n";
    cout<<endl<<decalaj<<"Numele angajatului cautat: ";
    string nume;
    cin>>nume;
    cout<<endl<<decalaj<<"Prenumele angajatului cautat: ";
    string prenume;
    cin>>prenume;
    Angajat angajatAfisare = admin.GetAngajat(nume, prenume);
    cout<<endl<<endl<<decalaj<<"--------------------------------------------------------------------\n";
    if(angajatAfisare.CNP.compare("nesetat") == 0)
    {
        SetConsoleTextAttribute(hConsole, 4);
        cout<<endl<<decalaj<<"Acest angajat nu se afla in baza de date"<<endl;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 2);
        cout<<endl<<decalaj<<"Gasit:    "<<angajatAfisare.ConversieLaSir()<<endl;
    }
    SetConsoleTextAttribute(hConsole, 15);
    cout<<endl<<decalaj<<"--------------------------------------------------------------------\n";
}

void Meniu::CautareCamera()
{
    cout<<decalaj<<"------------------------- CAUTARE CAMERA -------------------------------\n\n";
    cout<<endl<<decalaj<<"Denumirea camerei cautate: ";
    string denumire;
    cin>>denumire;
    Camera cameraAfisare = admin.GetCamera(denumire);
    cout<<endl<<endl<<decalaj<<"------------------------------------------------------------------------\n";
    if(cameraAfisare.denumire.compare("nesetat") == 0)
    {
        SetConsoleTextAttribute(hConsole, 4);
        cout<<endl<<decalaj<<"Acesta camera nu se afla in baza de date"<<endl;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 2);
        cout<<endl<<decalaj<<"Gasit:    "<<cameraAfisare.ConversieLaSir()<<endl;
    }
    SetConsoleTextAttribute(hConsole, 15);
    cout<<endl<<decalaj<<"------------------------------------------------------------------------\n";
}

void Meniu::CautareRezervare()
{
    cout<<decalaj<<"----------------------- CAUTARE REZERVARE --------------------------\n\n";
    cout<<endl<<decalaj<<"ID-ul rezervarii cautate: ";
    int id;
    cin>>id;
    Rezervare rezervareAfisare = admin.GetRezervare(id);
    cout<<endl<<endl<<decalaj<<"--------------------------------------------------------------------\n";
    if(rezervareAfisare.CNP_client.compare("nesetat") == 0)
    {
        SetConsoleTextAttribute(hConsole, 4);
        cout<<endl<<decalaj<<"Acesta rezervare nu se afla in baza de date"<<endl;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 2);
        cout<<endl<<decalaj<<"Gasit:\t"<<rezervareAfisare.ConversieLaSir()<<endl;
    }
    SetConsoleTextAttribute(hConsole, 15);
    cout<<endl<<decalaj<<"--------------------------------------------------------------------\n";
}

void Meniu::ModificareClient()
{
    gotoxy(0, 1);
    cout<<decalaj2<<"----------------------- MODIFICARE INFORMATII CLIENT --------------------------\n\n";
    cout<<endl<<decalaj2<<"Numele clientului ale carui informatii vor fi modificate: ";
    string nume;
    cin>>nume;
    cout<<endl<<decalaj2<<"Prenumele clientului: ";
    string prenume;
    cin>>prenume;
    Client clientAfisare = admin.GetClient(nume, prenume);
    cout<<endl<<decalaj2<<"-------------------------------------------------------------------------------\n";
    if(clientAfisare.CNP.compare("nesetat") == 0)
    {
        SetConsoleTextAttribute(hConsole, 4);
        cout<<endl<<decalaj2<<"Acest client nu se afla in baza de date"<<endl;
        SetConsoleTextAttribute(hConsole, 15);
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 8);
        cout<<endl<<decalaj2<<"Gasit:\t"<<clientAfisare.ConversieLaSir()<<endl;
        SetConsoleTextAttribute(hConsole, 15);
        cout<<endl<<decalaj2<<"-------------------------------------------------------------------------------\n";
        cout<<endl<<decalaj2<<"Ce modificari vrei sa faci?\n"<<decalaj2<<"[n=nume, p=prenume, c=CNP, np=nume+prenume etc]"<<endl<<decalaj2;
        string modificari;
        cin>>modificari;

        int i = 0;
        while(clienti[i].CNP.compare(clientAfisare.CNP) != 0)
            i++;

        if(modificari.find('c') != string::npos)
        {
            cout<<decalaj2<<"Noul CNP: ";
            cin>>clienti[i].CNP;
        }
        if(modificari.find('n') != string::npos)
        {
            cout<<decalaj2<<"Noul nume: ";
            cin>>clienti[i].nume;
        }
        if(modificari.find('p') != string::npos)
        {
            cout<<decalaj2<<"Noul prenume: ";
            cin>>clienti[i].prenume;
        }

        admin.UpdateFisierClienti(clienti);
        cout<<endl<<decalaj2<<"-------------------------------------------------------------------------------\n";
        SetConsoleTextAttribute(hConsole, 2);
        cout<<endl<<decalaj2<<"Modificarile au fost realizate cu succes\n";
        SetConsoleTextAttribute(hConsole, 15);
    }
    cout<<endl<<decalaj2<<"-------------------------------------------------------------------------------\n";
}

void Meniu::ModificareAngajat()
{
    gotoxy(0, 1);
    cout<<decalaj2<<"---------------------- MODIFICARE INFORMATII ANGAJAT --------------------------\n\n";
    cout<<endl<<decalaj2<<"Numele angajatului ale carui informatii vor fi modificate: ";
    string nume;
    cin>>nume;
    cout<<endl<<decalaj2<<"Prenumele angajatului: ";
    string prenume;
    cin>>prenume;
    Angajat angajatAfisare = admin.GetAngajat(nume, prenume);
    cout<<endl<<decalaj2<<"-------------------------------------------------------------------------------\n";
    if(angajatAfisare.CNP.compare("nesetat") == 0)
    {
        SetConsoleTextAttribute(hConsole, 4);
        cout<<endl<<decalaj2<<"Acest angajat nu se afla in baza de date"<<endl;
        SetConsoleTextAttribute(hConsole, 15);
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 8);
        cout<<endl<<decalaj2<<"Gasit:\t"<<angajatAfisare.ConversieLaSir()<<endl;
        SetConsoleTextAttribute(hConsole, 15);
        cout<<endl<<decalaj2<<"-------------------------------------------------------------------------------\n";
        cout<<endl<<decalaj2<<"Ce modificari vrei sa faci?\n"<<decalaj2<<"[ n=nume, p=prenume, c=CNP, f=functie, s=salariu, np=nume+prenume etc ]\n"<<decalaj2;
        string modificari;
        cin>>modificari;
        cout<<endl;
        int i = 0;
        while(angajati[i].CNP.compare(angajatAfisare.CNP) != 0)
            i++;

        if(modificari.find('c') != string::npos)
        {
            cout<<decalaj2<<"Introdu noul CNP: ";
            cin>>angajati[i].CNP;
        }
        if(modificari.find('n') != string::npos)
        {
            cout<<decalaj2<<"Introdu noul nume: ";
            cin>>angajati[i].nume;
        }
        if(modificari.find('p') != string::npos)
        {
            cout<<decalaj2<<"Introdu noul prenume: ";
            cin>>angajati[i].prenume;
        }
        if(modificari.find('f') != string::npos)
        {
            cout<<decalaj2<<"Introdu noua funtie: ";
            cin>>angajati[i].functie;
        }
        if(modificari.find('s') != string::npos)
        {
            cout<<decalaj2<<"Introdu noul salariu: ";
            cin>>angajati[i].salariu;
        }


        admin.UpdateFisierAngajati(angajati);
        cout<<endl<<decalaj2<<"-------------------------------------------------------------------------------\n";
        SetConsoleTextAttribute(hConsole, 2);
        cout<<endl<<decalaj2<<"Modificarile au fost realizate cu succes\n";
        SetConsoleTextAttribute(hConsole, 15);
    }
    cout<<endl<<decalaj2<<"-------------------------------------------------------------------------------\n";
}

void Meniu::ModificareCamera()
{
    gotoxy(0, 1);
    cout<<decalaj2<<"----------------------- MODIFICARE INFORMATII CAMERA --------------------------\n\n";
    cout<<endl<<decalaj2<<"Denumirea camerei ale carei informatii vor fi modificate: ";
    string denumire;
    cin>>denumire;
    Camera cameraAfisare = admin.GetCamera(denumire);
    cout<<endl<<decalaj2<<"-------------------------------------------------------------------------------\n";
    if(cameraAfisare.denumire.compare("nesetat") == 0)
    {
        SetConsoleTextAttribute(hConsole, 4);
        cout<<endl<<decalaj2<<"Aceasta camera nu se afla in baza de date"<<endl;
        SetConsoleTextAttribute(hConsole, 15);
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 8);
        cout<<endl<<decalaj2<<"Gasit:\t"<<cameraAfisare.ConversieLaSir()<<endl;
        SetConsoleTextAttribute(hConsole, 15);
        cout<<endl<<decalaj2<<"-------------------------------------------------------------------------------\n";
        cout<<endl<<decalaj2<<"Ce modificari vrei sa faci?\n"<<decalaj2<<"[ i=id, n=nume/denumire, d = dimensiune, e=etaj, f=facilitati, t=tip, p=pret, ne=nume+etaj etc ]\n"<<decalaj2;
        string modificari;
        cin>>modificari;

        cout<<endl;
        int i = 0;
        while(camere[i].ID_camera != cameraAfisare.ID_camera)
            i++;

        if(modificari.find('i') != string::npos)
        {
            cout<<decalaj2<<"Introdu noul ID: ";
            cin>>camere[i].ID_camera;
        }
        if(modificari.find('n') != string::npos)
        {
            cout<<decalaj2<<"Introdu noua denumire: ";
            cin>>camere[i].denumire;
        }
        if(modificari.find('d') != string::npos)
        {
            cout<<decalaj2<<"Introdu noua dimensiune: ";
            cin>>camere[i].dimensiune;
        }
        if(modificari.find('e') != string::npos)
        {
            cout<<decalaj2<<"Introdu noul etaj: ";
            cin>>camere[i].etaj;
        }
        if(modificari.find('f') != string::npos)
        {
            cout<<decalaj2<<"Introdu noile facilitati sub forma \"1+2+4\". \n"<<decalaj2<<"[ 1 - niciuna, 2 - televizor, 3 - internet, 4 - seif, 5 - jacuzzi, 6 - frigider ]\n "<<decalaj2;

            string sirFacilitati;
            cin>>sirFacilitati;
            vector<string> facilitati = Functii::split(sirFacilitati,"+");
            camere[i].facilitati.clear();
            for(string facilitate : facilitati)
            {
                camere[i].facilitati.push_back(stoi(facilitate));
            }
        }
        if(modificari.find('t') != string::npos)
        {
            cout<<decalaj2<<"Introdu noul tip de camera. \n"<<decalaj2<<"[ 1 - Single, 2 - Dubla, 3 - Twin, 4 - Matrimoniala, 5 - Tripla, 6 - Quad ]\n "<<decalaj2;
            cin>>camere[i].tip;
        }

        if(modificari.find('p') != string::npos)
        {
            cout<<decalaj2<<"Introdu noul pret: ";
            cin>>camere[i].pret;
        }

        admin.UpdateFisierCamere(camere);
        cout<<endl<<decalaj2<<"-------------------------------------------------------------------------------\n";
        SetConsoleTextAttribute(hConsole, 2);
        cout<<endl<<decalaj2<<"Modificarile au fost realizate cu succes\n";
        SetConsoleTextAttribute(hConsole, 15);
    }
    cout<<endl<<decalaj2<<"-------------------------------------------------------------------------------\n";
}

void Meniu::ModificareRezervare()
{
    gotoxy(0, 1);
    cout<<decalaj2<<"--------------------- MODIFICARE INFORMATII REZERVARE -------------------------\n\n";
    cout<<endl<<decalaj2<<"ID-ul rezervarii ale carei informatii vor fi modificate: ";
    int id;
    cin>>id;
    Rezervare rezervareAfisare = admin.GetRezervare(id);
    cout<<endl<<decalaj2<<"-------------------------------------------------------------------------------\n";
    if(rezervareAfisare.CNP_client.compare("nesetat") == 0)
    {
        SetConsoleTextAttribute(hConsole, 4);
        cout<<endl<<decalaj2<<"Aceasta rezervare nu se afla in baza de date"<<endl;
        SetConsoleTextAttribute(hConsole, 15);
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 8);
        cout<<endl<<decalaj2<<"Gasit:\t"<<rezervareAfisare.ConversieLaSir()<<endl;
        SetConsoleTextAttribute(hConsole, 15);
        cout<<endl<<decalaj2<<"-------------------------------------------------------------------------------\n";
        cout<<endl<<decalaj2<<"Ce modificari vrei sa faci?\n"<<decalaj2<<"[ r = ID rezervare, c = CNP client, i = ID camera]"<<endl<<decalaj2<<"[ d = data check-in + check-out, ci = CNP client + ID camera etc ]\n"<<decalaj2;
        string modificari;
        cin>>modificari;

        int i = 0;

        cout<<endl;
        while(rezervari[i].ID_rezervare != rezervareAfisare.ID_rezervare)
            i++;

        if(modificari.find('r') != string::npos)
        {
            cout<<decalaj2<<"Introdu noul ID al rezervarii: ";
            cin>>rezervari[i].ID_rezervare;
        }
        if(modificari.find('c') != string::npos)
        {
            cout<<decalaj2<<"Introdu noul CNP al clientului: ";
            cin>>rezervari[i].CNP_client;
        }
        if(modificari.find('i') != string::npos)
        {
            cout<<decalaj2<<"Introdu noul ID al camere: ";
            cin>>rezervari[i].ID_camera;
        }
        if(modificari.find('d') != string::npos)
        {
            cout<<decalaj2<<"Introdu noua data de check-in (zz.ll.aa) : ";
            cin>>rezervari[i].checkin_date;
            cout<<decalaj2<<"Introdu noua data de check-out (zz.ll.aa) : ";
            cin>>rezervari[i].checkout_date;
        }

        admin.UpdateFisierRezervari(rezervari);
        SetConsoleTextAttribute(hConsole, 2);
        cout<<endl<<decalaj2<<"Modificarile au fost realizate cu succes\n";
        SetConsoleTextAttribute(hConsole, 15);
    }
    cout<<endl<<decalaj2<<"-------------------------------------------------------------------------------\n";
}


