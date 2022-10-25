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
    Task t1(1, "Configurare router principal", "William", 900, true);
    Angajat a1("William", {1});
    std::vector<Task> Taskuri;
    std::vector<Angajat> Angajati;
    std::vector<Departament> Departamente;
    Taskuri.push_back(t1);
    Angajati.push_back(a1);

    Angajat a2("Turis", {1, 2});
    Task t2(2, "Reparare ip", "Turis", 200, false);
    Taskuri.push_back(t2);
    Angajati.push_back(a2);

    Departament d1("HR", Angajati);
    Departamente.push_back(d1);
    //cout<<d1;


    Companie c1("IBM", Departamente, Taskuri);
    cout << c1;
    // Companie c2("Microsoft",Angajati,Taskuri);
    // Companie c2=c1;

    // cout<<c2;



    return 0;
}