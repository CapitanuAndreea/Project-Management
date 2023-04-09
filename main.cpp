#include <iostream>
#include <cstring>
#include <cmath>
#include "Project.h"

using namespace std;

void Testare_Functionalitati();
void Meniu_Interactiv();

int main()
{
    ///Testare_Functionalitati();
    Meniu_Interactiv();

    return 0;
}

void Testare_Functionalitati()
{
    Angajat x; ///Testare constructor fara parametri
    cout << x << "\n"; ///Supraincarcare "<<"
    Angajat y("Viorel", 2008, "Logistica"); ///Testare constructor cu parametri
    cout << y << "\n";
    y.Schimbare_Departament("Mecanica");
    cout << y << "\n";
    x = y; ///Supraincarcare "="
    cout << x << "\n";
    y.Calculare_Salariu();
    cout << "\n";

    Necesitati a;
    cout << a << "\n";
    Necesitati b("Biscuiti", 3, 4);
    cout << b << "\n";
    b.Schimbare_Nr_Bucati(5);
    cout << b << "\n";
    a = b;
    cout << a << "\n";

    Task c;
    cout << c << "\n";
    Task d("Afis",y,"In progress");
    cout << d << "\n";
    d.Schimbare_Status("Completed");
    cout << d << "\n";
    c = d;
    cout << c << "\n";

    Angajat echipa[2];
    Angajat z("Arthur", 2020, "Management");
    echipa[0] = y;
    echipa[1] = z;

    Necesitati necesitati[2];
    Necesitati e("Briose", 2, 3);
    necesitati[0] = b;
    necesitati[1] = e;

    Task taskuri[1];
    taskuri[0] = c;

    Proiect proiect(echipa, 2, necesitati, 2, taskuri, 1);
    cout << proiect.Calculare_Buget_Necesar() << "\n";
    cout << proiect.Calculare_Feedback_Proiect() << "\n";
}

void Meniu_Interactiv()
{
    int nr_angajati, an_angajare, nr_taskuri, nr_angajat, nr_bucati, nr_necesitati, nr, nr_task, nr_necesitate;
    double pret_bucata;
    char nume[50], departament[50], status[50];
    Angajat echipa[50];
    Task taskuri[50];
    Necesitati necesitati[50];

    cout << "Introduceti numarul de angajati din echipa(>= 1 && <= 50): ";
    cin >> nr_angajati;
    for(int i = 0; i < nr_angajati; i++)
    {
        cout << "\nIntroduceti datele angajatului " << i + 1 << ":";
        cout << "\nNume: ";
        cin.get();
        cin.get(nume,50);
        cout << "An angajare: ";
        cin >> an_angajare;
        cout << "Departament: ";
        cin.get();
        cin.get(departament, 50);
        Angajat x(nume, an_angajare, departament);
        echipa[i] = x;
    }

    cout << "\nAfisare angajati: \n";
    for(int i = 0; i < nr_angajati; i++)
    {
        cout << "\nDate angajat " << i + 1 << ":\n";
        cout << echipa[i];
    }

    cout << "\nIntroduceti numarul de taskuri(>= 1 && <= 50): ";
    cin >> nr_taskuri;
    for(int i = 0; i < nr_taskuri; i++)
    {
        cout << "\nIntroduceti datele taskului " << i + 1 << ":";
        cout << "\nNume: ";
        cin.get();
        cin.get(nume, 50);
        cout << "Numar angajat: ";
        cin >> nr_angajat;
        cout << "Status task(Not started, In progress, Completed): ";
        cin.get();
        cin.get(status, 50);
        Task z(nume, echipa[nr_angajat - 1], status);
        taskuri[i] = z;
    }

    cout << "\nAfisare taskuri: \n";
    for(int i = 0; i < nr_taskuri; i++)
    {
        cout << "\nDate task " << i + 1 << ":\n";
        cout << taskuri[i];
    }

    cout << "\nIntroduceti numarul de necesitati(>= 1 && <= 50): ";
    cin >> nr_necesitati;
    for(int i = 0; i < nr_necesitati; i++)
    {
        cout << "\nIntroduceti datele materialului " << i + 1 << ":";
        cout << "\nNume: ";
        cin.get();
        cin.get(nume, 50);
        cout << "Pret/bucata: ";
        cin >> pret_bucata;
        cout << "Nr. bucati: ";
        cin >> nr_bucati;
        Necesitati a(nume, pret_bucata, nr_bucati);
        necesitati[i] = a;
    }

    cout << "\nAfisare materiale necesare: \n";
    for(int i = 0; i < nr_necesitati; i++)
    {
        cout << "\nDate necesitate " << i + 1 << ":\n";
        cout << necesitati[i];
    }

    Proiect proiect(echipa, nr_angajati, necesitati, nr_necesitati, taskuri, nr_taskuri);

    cout << "\nAlege optiunea dorita:\n 0 - Iesire\n 1 - Calculare buget proiect\n 2 - Calculare feedback proiect\n 3 - Calculare salariu angajat\n 4 - Schimbare status task\n 5 - Schimbare nr. bucati material\n";
    cin >> nr;
    while(nr)
    {
        switch(nr)
        {
            case 1:
                cout << "Buget necesar: " << proiect.Calculare_Buget_Necesar() << "\n";
                break;
            case 2:
                cout << "Feedbackul reprezinta un numar de la 1 la 5\n";
                cout << proiect.Calculare_Feedback_Proiect() << "\n";
                break;
            case 3:
                cout << "Numar angajat: ";
                cin >> nr_angajat;
                cout << echipa[nr_angajat - 1] << "\n";
                cout << "Salariu: " << echipa[nr_angajat - 1].Calculare_Salariu() << "\n";
                break;
            case 4:
                cout << "Numar task: ";
                cin >> nr_task;
                cout << taskuri[nr_task - 1] << "\n";
                cout <<"Status nou: ";
                cin.get();
                cin.get(status, 50);
                taskuri[nr_task - 1].Schimbare_Status(status);
                cout << taskuri[nr_task - 1];
                break;
            case 5:
                cout << "Numar necesitate: ";
                cin >> nr_necesitate;
                cout << necesitati[nr_necesitate - 1];
                cout <<"Nr. bucati nou: ";
                cin >> nr_bucati;
                necesitati[nr_necesitate - 1].Schimbare_Nr_Bucati(nr_bucati);
                cout << necesitati[nr_necesitate - 1];
                break;
        }
        cout << "\nAlege optiunea: ";
        cin >> nr;
    }
}
