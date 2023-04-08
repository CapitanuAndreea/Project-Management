#include <iostream>
#include <cstring>
#include <cmath>
#include "Project.h"

using namespace std;

///Array
Array::Array()
{
    dimensiune = 0;
    ptr = nullptr;
}

Array::Array(int Size)
{
    dimensiune = Size;
    ptr = new int[dimensiune];
    for(int i = 0; i < dimensiune; i++)
        ptr[i] = 0;
}

Array::Array(const Array &array_de_copiat)
{
    dimensiune = array_de_copiat.dimensiune;
    ptr = new int[dimensiune];
    for(int i = 0; i < dimensiune; i++)
        ptr[i] = array_de_copiat.ptr[i];
}

Array::~Array()
{
    delete[] ptr;
}

int Array::Get_Size()const
{
    return dimensiune;
}

int *Array::Get_Ptr()
{
    return ptr;
}

const Array &Array::operator=(const Array &other)
{
    delete[] ptr;
    dimensiune = other.dimensiune;
    ptr = new int[dimensiune];
    for(int i = 0; i < dimensiune; i++)
        ptr[i] = other.ptr[i];
    return *this;
}

istream &operator>>(istream &Cin, Array &x)
{
    for(int i = 0; i < x.dimensiune; i++)
        Cin >> x.ptr[i];
    return Cin;
}

ostream &operator<<(ostream &Cout, Array &x)
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
    strcpy(departament, "Unknown");
}

Angajat::Angajat(char Nume[], int An_angajare, char Departament[])
{
    strcpy(nume, Nume);
    an_angajare = An_angajare;
    strcpy(departament, Departament);
}

double Angajat::Adaugare_Bonus(int bonus)
{
    double salariu = 4000;
    salariu += 200;
    return salariu;
}

double Angajat::Adaugare_Bonus(double bonus)
{
    double salariu = 4000;
    salariu += salariu * bonus;
    return salariu;
}

double Angajat::Calculare_Salariu()
{
    int an_actual = 2023;
    if(an_angajare == 0)
        cout << Adaugare_Bonus(0);
    else
    {
        if(an_actual - an_angajare <= 1)
            cout << Adaugare_Bonus(200);
        else if(an_actual - an_angajare >= 10)
            cout << Adaugare_Bonus(0.3);
        else if(an_actual - an_angajare >= 5)
            cout << Adaugare_Bonus(0.2);
        else
            cout << Adaugare_Bonus(0);
    }

}

void Angajat::operator=(const Angajat& angajatul)
{
    strcpy(nume, angajatul.nume);
    an_angajare = angajatul.an_angajare;
    strcpy(departament, angajatul.departament);
}

void Angajat::Schimbare_Departament(char Departament[])
{
    strcpy(departament, Departament);
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
    size_echipa = size_Echipa;
    size_necesitati = size_necesitatile;
    size_taskuri = size_Taskuri;
    for(int i = 0; i < size_Echipa; i++)
        echipa[i] = Echipa[i];
    for(int i = 0; i < size_necesitatile; i++)
        necesitati[i] = necesitatile[i];
    for(int i = 0; i < size_Taskuri; i++)
        taskuri[i] = Taskuri[i];
    Array other(size_Echipa);
    feedback = other;
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
    cin >> feedback;
    for(int i = 0; i < dim; i++)
        medie += p[i];
    medie = double(medie / dim);
    return medie;
}
