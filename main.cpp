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
    std::vector<Angajat> Angajati;
    std::vector<Departament> Departamente;

    Task t1(1, "Configurare router principal", 900, 0,2022,6,7);
    Task t2(2, "Reparare ip", 200, 1,2023,6,2);
    Task t3(3, "Configurare switch", 500, 1,2020,1,2);

 //cout<<Task::TaskRestant(t1)<<std::endl; verifica daca task-ul a depasit deadline-ul
    Taskuri.push_back(t1);
    Angajat a1("William", Taskuri);
    Taskuri.clear();
    Angajat a2("Turis", Taskuri);
    Taskuri.push_back(t1);
    Taskuri.push_back(t3);


    Angajat a3("Tudor", Taskuri);

    Angajati.push_back(a1);
    Angajati.push_back(a2);
    Angajati.push_back(a3);


    Departament d1("HR", Angajati);
    Departamente.push_back(d1);
    cout<<d1;


    Companie c1("IBM", Departamente);
   // cout << c1;
    // Companie c2("Microsoft",Angajati,Taskuri);
    // Companie c2=c1;

    // cout<<c2;



    return 0;
}