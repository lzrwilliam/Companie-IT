#include <iostream>
#include  <vector>
#include <ctime>
#include "angajat.h"
#include "Departamente.h"
#include "Task.h"
#include "Companie.h"

using std::cout;
using std::string;


int main() {
    std::vector<Angajat> Angajati;
    std::vector<Departament> Departamente;

    Task t1(1, "Configurare router principal", 900, 1, 2023, 6, 7);
    Task t2(2, "Reparare ip", 200, 1, 2023, 6, 2);
    Task t3(3, "Configurare switch", 500, 1, 2020, 1, 2);
    Task t4(4, "dasda", 500, 0, 2020, 1, 2);
    Task t5(5, "dasda", 500, 0, 2020, 1, 2);
    Task t6(6, "dasda", 500, 0, 2020, 1, 2);




    // cout<<t1.TaskRestant();verifica daca task-ul a depasit deadline-ul
    Angajat a1("William", {t1});

    //cout<<a1.GetProfitAngajat(); obtinem profitul unui angajat
    Angajat a2("Turis", {});


    Angajat a3("Tudor", {t1, t3});

    Angajati.push_back(a1);
    Angajati.push_back(a2);
    Angajati.push_back(a3);

    Angajat a4("catalin", {t4, t5, t6});
    Angajati.push_back(a4);


    Departament d1("HR", Angajati);

    Departamente.push_back(d1);


    //cout<<d1;




    Companie c1("IBM", Departamente);
    cout << c1;
    for (auto &i: Departamente)
        i.StergereAngajatCuTaskuriRestante();

    //concediem angajatul lenes!




    return 0;
}