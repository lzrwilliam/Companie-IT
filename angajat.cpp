//
// Created by lazar on 10/25/2022.
//

#include "angajat.h"

Angajat::Angajat(const string &nume, const std::vector<int> &TaskuriAngajat, int TaskRez) :
        nume{nume},
        TaskuriAngajat{TaskuriAngajat},
        NrTaskuriRezolvate{TaskRez}
{
}

Angajat &Angajat::operator=(const Angajat &altul) {

    nume=altul.nume;
    TaskuriAngajat=altul.TaskuriAngajat;
    NrTaskuriRezolvate=altul.NrTaskuriRezolvate;
    return *this;
    // cout<<"Operator = de copiere angajat "<<'\n';
}

Angajat::Angajat(const Angajat &altul) :
        nume{altul.nume},
        TaskuriAngajat{altul.TaskuriAngajat},
        NrTaskuriRezolvate{altul.NrTaskuriRezolvate} {
    //cout<<"Constructor copiere angajat "<<'\n';
}

std::ostream &operator<<(std::ostream &cout1, const Angajat &angajat) {

    cout1 << "Nume angajat: " << angajat.nume << '\n';
    cout1 << "Task-uri rezolvate: " << angajat.NrTaskuriRezolvate << std::endl;
    cout1 << "Task-urile pe care le are angajatul:\n";

    for (int i: angajat.TaskuriAngajat)
        cout1 << "Id task: " << i << " \n";

    cout1 << std::endl;
    return cout1;
}
