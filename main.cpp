#include <iostream>
#include <cstring>
#include <cmath>
#include "Project.h"

using namespace std;

int main()
{
    Angajat x; ///Testare constructor fara parametri
    cout << x; ///Supraincarcare "<<"
    Angajat y("Viorel", 2008, "Logistica"); ///Testare constructor cu parametri
    cout << y;
    y.Schimbare_Departament("Mecanica");
    cout << y;
    x = y; ///Supraincarcare "="
    cout << x;
    y.Calculare_Salariu();
    cout << "\n";

    Necesitati a;
    cout << a;
    Necesitati b("Biscuiti", 3, 4);
    cout << b;
    b.Schimbare_Nr_Bucati(5);
    cout << b;
    a = b;
    cout << a;

    Task c;
    cout << c;
    Task d("Afis",y,"In progress");
    cout << d;
    d.Schimbare_Status("Completed");
    cout << d;
    c = d;
    cout << c;

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

    return 0;
}
