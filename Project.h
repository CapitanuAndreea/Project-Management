#include <iostream>

using namespace std;

class Array
{
private:
    int dimensiune;
    int *ptr;
public:
    Array();
    Array(int Size);
    Array(const Array &array_de_copiat);
    ~Array();
    int Get_Size() const;
    int* Get_Ptr();
    const Array &operator=(const Array &other);
    friend istream& operator>>(istream& Cin, Array &x);
    friend ostream& operator<<(ostream& Cout, Array &x);
};


class Angajat
{
private:
    char nume[50];
    int an_angajare;
    char departament[50];
public:
    Angajat();
    Angajat(char Nume[], int An_angajare, char Departament[]);
    friend ostream& operator<<(ostream& Cout, Angajat x);
    void Schimbare_Departament(char Departament[]);
    void operator=(const Angajat& angajatul);
    double Calculare_Salariu();
    double Adaugare_Bonus(int bonus);
    double Adaugare_Bonus(double bonus);
};


class Task
{
private:
    char nume[50];
    Angajat angajat;
    int status;
public:
    Task();
    Task(char Nume[50], Angajat angajatul, char Status[50]);
    void operator=(const Task& taskul);
    friend ostream& operator<<(ostream& Cout, Task x);
    void Schimbare_Status(char Status[]);
};


class Necesitati
{
private:
    char nume[50];
    double pret_bucata;
    int nr_bucati;
public:
    Necesitati();
    Necesitati(char Nume[], double Pret_bucata, int Nr_bucati);
    friend ostream& operator<<(ostream& Cout, Necesitati x);
    void Schimbare_Nr_Bucati(int Nr_bucati);
    void operator=(const Necesitati& necesitatile);
    double Get_Pret_Bucata();
    int Get_Nr_Bucati();
};


class Proiect
{
private:
    Angajat echipa[50];
    Necesitati necesitati[50];
    Task taskuri[50];
    Array feedback;
    int size_echipa;
    int size_necesitati;
    int size_taskuri;
public:
    Proiect(Angajat Echipa[], int size_Echipa, Necesitati necesitatile[], int size_necesitatile, Task Taskuri[], int size_Taskuri);
    double Calculare_Buget_Necesar();
    double Calculare_Feedback_Proiect();
};
