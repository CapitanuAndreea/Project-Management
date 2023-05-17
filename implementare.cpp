#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <memory>
#include "Project.h"

using namespace std;

///Array
template <typename type>
Array<type>::Array()
{
    dimensiune = 0;
    ptr = nullptr;
}

template <typename type>
Array<type>::Array(int Size)
{
    dimensiune = Size;
    ptr = new type[dimensiune];
    for(int i = 0; i < dimensiune; i++)
        ptr[i] = 0;
}

template <typename type>
Array<type>::Array(const Array &array_de_copiat)
{
    dimensiune = array_de_copiat.dimensiune;
    ptr = new type[dimensiune];
    for(int i = 0; i < dimensiune; i++)
        ptr[i] = array_de_copiat.ptr[i];
}

template <typename type>
Array<type>::~Array()
{
    delete[] ptr;
}

template <typename type>
int Array<type>::Get_Size()const
{
    return dimensiune;
}

template <typename type>
int *Array<type>::Get_Ptr()
{
    return ptr;
}

template <typename type>
const Array<type> &Array<type>::operator=(const Array<type> &other)
{
    delete[] ptr;
    dimensiune = other.dimensiune;
    ptr = new int[dimensiune];
    for(int i = 0; i < dimensiune; i++)
        ptr[i] = other.ptr[i];
    return *this;
}

template <typename type>
void Array<type>::Citire()
{
    for(int i = 0; i < dimensiune; i++)
        cin >> ptr[i];
}

/**template <typename type> class Array;
template <typename type>
istream &operator>>(istream &Cin, Array<type> &x)
{
    for(int i = 0; i < x.dimensiune; i++)
        Cin >> x.ptr[i];
    return Cin;
}*/

template <typename type> class Array;
template <typename type>
ostream &operator<<(ostream &Cout, Array<type> &x)
{
    for(int i = 0; i < x.dimensiune; i++)
        Cout << x.ptr[i];
    Cout << "\n";
    return Cout;
}


///Angajat
Angajat::Angajat()
{
    strcpy(nume, "Unknown");
    an_angajare = 0;
    departament = "Unknown";
}

Angajat::Angajat(char Nume[], int An_angajare, string Departament)
{
    strcpy(nume, Nume);
    an_angajare = An_angajare;
    departament = Departament;
}

template <typename Type>
Type Angajat::Adaugare_Bonus(Type bonus)
{
    Type salariu = 4000;
    if(bonus > 0 && bonus < 1)
        salariu += salariu * bonus;
    else
        salariu += bonus;
    return salariu;
}

void Angajat::Calculare_Salariu()
{
    int an_actual = 2023;
    if(an_angajare == 0)
        cout << Adaugare_Bonus<int>((int)0);
    else
    {
        if(an_actual - an_angajare <= 1)
            cout << Adaugare_Bonus<int>((int)200);
        else if(an_actual - an_angajare >= 10)
            cout << Adaugare_Bonus<double>((double)0.3);
        else if(an_actual - an_angajare >= 5)
            cout << Adaugare_Bonus<double>((double)0.2);
        else
            cout << Adaugare_Bonus<int>((int)0);
    }
}

void Angajat::operator=(const Angajat& angajatul)
{
    strcpy(nume, angajatul.nume);
    an_angajare = angajatul.an_angajare;
    departament = angajatul.departament;
}

string Angajat::Get_Department()
{
    return departament;
}

void Angajat::Schimbare_Departament(string Departament)
{
    departament = Departament;
}

ostream& operator<<(ostream& Cout, Angajat x)
{
    Cout << "Nume: " << x.nume << "\n";
    Cout << "An angajare: " << x.an_angajare << "\n";
    Cout << "Departament: " << x.departament << "\n";
    return Cout;
}


///Task
Task::Task()
{
    strcpy(nume, "Unknown");
    status = 0;
}

Task::Task(char Nume[50], Angajat angajatul, char Status[50])
{
    strcpy(nume, Nume);
    angajat = angajatul;
    if(strcmp (Status, "Completed") == 0)
        status = 2;
    else if(strcmp(Status, "In progress") == 0)
        status = 1;
    else if(strcmp(Status, "Not started") == 0)
        status = 0;
}

void Task::operator=(const Task& taskul)
{
    strcpy(nume, taskul.nume);
    angajat = taskul.angajat;
    status = taskul.status;
}

ostream& operator<<(ostream& Cout, Task x)
{
    Cout << "Nume: " << x.nume << "\n";
    Cout << "Angajat:\n" << x.angajat;
    if(x.status == 0)
        Cout << "Status: Not started" << "\n";
    else if(x.status == 1)
        Cout << "Status: In progress" << "\n";
    else if(x.status == 2)
        Cout << "Status: Completed" << "\n";
    return Cout;
}

void Task::Schimbare_Status(char Status[])
{
    if(strcmp (Status, "Completed") == 0)
        status = 2;
    else if(strcmp(Status, "In progress") == 0)
        status = 1;
    else if(strcmp(Status, "Not started") == 0)
        status = 0;
}


///Necesitati
Necesitati::Necesitati()
{
    strcpy(nume, "Unknown");
    pret_bucata = 0;
    nr_bucati = 0;
}

Necesitati::Necesitati(char Nume[], double Pret_bucata, int Nr_bucati)
{
    strcpy(nume, Nume);
    pret_bucata = Pret_bucata;
    nr_bucati = Nr_bucati;
}

double Necesitati::Get_Pret_Bucata()
{
    return pret_bucata;
}

int Necesitati::Get_Nr_Bucati()
{
    return nr_bucati;
}

void Necesitati::Schimbare_Nr_Bucati(int Nr_bucati)
{
    nr_bucati = Nr_bucati;
}

ostream& operator<<(ostream& Cout, Necesitati x)
{
    Cout << "Nume: " << x.nume << "\n";
    Cout << "Pret/bucata: " << x.pret_bucata << "\n";
    Cout << "Nr. bucati: " << x.nr_bucati << "\n";
    return Cout;
}

void Necesitati::operator=(const Necesitati& necesitatile)
{
    strcpy(nume, necesitatile.nume);
    pret_bucata = necesitatile.pret_bucata;
    nr_bucati = necesitatile.nr_bucati;
}


///Proiect
Proiect::Proiect(Angajat Echipa[], int size_Echipa, Necesitati necesitatile[], int size_necesitatile, Task Taskuri[], int size_Taskuri)
{
    size_necesitati = size_necesitatile;
    size_taskuri = size_Taskuri;
    for(int i = 0; i < size_Echipa; i++)
        echipa.push_back(Echipa[i]);
    for(int i = 0; i < size_necesitatile; i++)
        necesitati[i] = necesitatile[i];
    for(int i = 0; i < size_Taskuri; i++)
        taskuri[i] = Taskuri[i];
    Array<int> other(size_Echipa);
    feedback = other;
}

void Proiect::Exista_Reprezentant(string Departament)
{
    vector<Angajat>::iterator i;
    i = find_if(echipa.begin(), echipa.end(),
                [&dep = Departament]
                (Angajat& ang) -> bool {return ang.Get_Department() == dep;});
    if(i != echipa.end())
        cout << "Exista reprezentant " << Departament << " in aceasta echipa de lucru.\n";
    else
        cout << "Nu exista reprezentanti " << Departament << " in aceasta echipa de lucru!\n";
}

double Proiect::Calculare_Buget_Necesar()
{
    double buget = 0;
    for(int i = 0; i < size_necesitati; i++)
        buget += necesitati[i].Get_Pret_Bucata() * necesitati[i].Get_Nr_Bucati();
    return buget;
}

double Proiect::Calculare_Feedback_Proiect()
{
    double medie = 0;
    int dim = feedback.Get_Size();
    int *p = feedback.Get_Ptr();
    cout << "Introduceti feedbackul fiecarui angajat: ";
    feedback.Citire();
    for(int i = 0; i < dim; i++)
        medie += p[i];
    medie = double(medie / dim);
    return medie;
}


///Sponsor
Sponsor::Sponsor()
{
    strcpy(nume, "Unknown");
    suma = 0;
}

Sponsor::Sponsor(char Nume[], int Suma)
{
    strcpy(nume, Nume);
    suma = Suma;
}


///Contribuitor
int Contribuitor::finantare_minima = 1000;

Contribuitor::Contribuitor()
{
    finantare_minima = 1000;
    strcpy(nume, "Unknown");
    suma = 0;
    badge = 0;
}

Contribuitor::Contribuitor(char Nume[], int Suma)
{
    strcpy(nume, Nume);
    suma = Suma;
    if(Oferire_Badge(suma) == 1)
        badge = 1;
    else
        badge = 0;
}

string Contribuitor::Get_Role()
{
    return "Contribuitor";
}

void Contribuitor::Afisare()
{
    cout << Get_Role() << ": " << nume;
    if(badge == 1)
        cout << ", Badge: Special\n";
    else if(badge == 0)
        cout << "\n";
}

void Contribuitor::Verificare1(int Suma)
{
    try
    {
        if(Suma < 0)
            throw Finantare_Negativa();
        if(Suma < finantare_minima)
            throw Finantare_Minima();
    }
    catch(Finantare_Negativa e)
    {
        cout << e.what();
        throw;
    }
}

void Contribuitor::Verificare(int Suma)
{
    try
    {
        Verificare1(Suma);
    }
    catch(Finantare_Minima e)
    {
        Finantare_Minima *bp;
        bp = dynamic_cast<Finantare_Minima*>(&e);
        cout << bp->what();
    }
}

///Premium
int Premium::finantare_minima = 3000;

Premium::Premium()
{
    strcpy(nume, "Unknown");
    strcpy(tematica_proiect, "Unknown");
    suma = 0;
    badge = 0;
}

Premium::Premium(char Nume[], int Suma, char Tematica_proiect[])
{
    strcpy(nume, Nume);
    strcpy(tematica_proiect, Tematica_proiect);
    suma = Suma;
    if(Oferire_Badge(suma) == 1)
        badge = 1;
    else
        badge = 0;
}

string Premium::Get_Role()
{
    return "Premium";
}

void Premium::Afisare()
{
    cout << Get_Role() << ": " << nume;
    if(badge == 1)
        cout << ", Badge: Special\n";
    else if(badge == 0)
        cout << "\n";
}

void Premium::Verificare1(int Suma)
{
    try
    {
        if(Suma < 0)
            throw Finantare_Negativa();
        if(Suma < finantare_minima)
            throw Finantare_Minima();
    }
    catch(Finantare_Negativa e)
    {
        cout << e.what();
        throw;
    }
}

void Premium::Verificare(int Suma)
{
    try
    {
        Verificare1(Suma);
    }
    catch(Finantare_Minima e)
    {
        Finantare_Minima *bp;
        bp = dynamic_cast<Finantare_Minima*>(&e);
        cout << bp->what();
    }
}

///Asociatie
Asociatie::Asociatie()
: nume("Unknown"), descriere("Unknown")
{

}

Asociatie::Asociatie(string Nume, string Descriere)
: nume(Nume), descriere(Descriere)
{

}

string Asociatie::Tip_Beneficiar()
{
    return "Asociatie";
}

void Asociatie::Afisare_Cauza()
{
    cout << Tip_Beneficiar() << ": " << nume << "\nPoveste: " << descriere << "\n";
}

///Pers_Fizica
Pers_Fizica::Pers_Fizica()
{
    strcpy(nume, "Unknown");
    p = make_unique<char[]>(50);
    char text[] = "Unknown";
    for(int i = 0; text[i]; i++)
        p[i] = text[i];
}

Pers_Fizica::Pers_Fizica(char Nume[], char *P)
{
    strcpy(nume, Nume);
    p = make_unique<char[]>(50);
    for(int i = 0; P[i]; i++)
        p[i] = P[i];
}

string Pers_Fizica::Tip_Beneficiar()
{
    return "Persoana Fizica";
}

void Pers_Fizica::Afisare_Cauza()
{
    cout << Tip_Beneficiar() << ": " << nume << "\nPoveste: " << p.get() << "\n";
}
