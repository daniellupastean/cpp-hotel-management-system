#ifndef CAMERA_H
#define CAMERA_H
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"Functii.h"

using namespace std;
class Camera
{
public:
    map<int, string> facilitatiCamera
    {
        { 1, "Niciuna" },
        { 2, "TV" },
        { 3, "Internet" },
        { 4, "Seif" },
        { 5, "Jacuzzi" },
        { 6, "Frigider" }
    };
    map<int, string> tipCamera
    {
        {1, "Single"},
        {2, "Dubla"},
        {3, "Twin"},
        {4, "Matrimoniala"},
        {5, "Tripla"},
        {6, "Quad"}
    };

    static int IdUltimaCamera;
    int ID_camera;
    string denumire;
    float dimensiune;
    int etaj;
    vector<int> facilitati;
    int tip;
    float pret;

    Camera(string _date);
    static string HeaderInfo();
    string ConversieLaSir();
    string ConversieLaSir_PentruScriereInFisier();

};
#endif // CAMERA_H
