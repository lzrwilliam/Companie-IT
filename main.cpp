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
    std::vector<Task> Taskuri;
    std::vector<Angajat *> Angajati;
    std::vector<Departament> Departamente;

    Task t1(1, "Configurare router principal", 900, 1, 2023, 6, 7);
    Task t2(2, "Reparare ip", 200, 1, 2023, 6, 2);
    Task t3(3, "Configurare switch", 500, 1, 2020, 1, 2);
    Task t4(4, "dasda", 500, 0, 2020, 1, 2);
    Task t5(5, "dasda", 500, 0, 2020, 1, 2);
    Task t6(6, "dasda", 500, 0, 2020, 1, 2);



    //cout<<Task::TaskRestant(t1)<<std::endl; verifica daca task-ul a depasit deadline-ul
    Taskuri.push_back(t1);
    Angajat a1("William", Taskuri);
    //  Angajat::CalcProfitAngajat(a1); calculeaza profitul generat de angajat
    Taskuri.clear();
    Angajat a2("Turis", Taskuri);
    Taskuri.push_back(t1);
    Taskuri.push_back(t3);


    Angajat a3("Tudor", Taskuri);

    Angajati.push_back(&a1);
    Angajati.push_back(&a2);
    Angajati.push_back(&a3);
    Taskuri.clear();
    Taskuri.push_back(t4);
    Taskuri.push_back(t5);
    Taskuri.push_back(t6);
    Angajat a4("catalin", Taskuri);
    Angajati.push_back(&a4);


    Departament d1("HR", Angajati);
    // calculeaza profitul departamentului  Departament::SetProfitDep(d1);
    Departamente.push_back(d1);


    //cout<<d1;




    Companie c1("IBM", Departamente);
    cout << c1;
    for (const auto &i: Departamente)
        Departament::StergereAngajatCuTaskuriRestante(const_cast<Departament &>(i));
    // Departament::StergereAngajatCuTaskuriRestante(d1);
    //concediem angajatul lenes!

    // Companie c2("Microsoft",Angajati,Taskuri);
    // Companie c2=c1;

    // cout<<c2;



    return 0;
}