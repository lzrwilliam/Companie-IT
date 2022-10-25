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
        NrTaskuriRezolvate{altul.NrTaskuriRezolvate}
{
    //cout<<"Constructor copiere angajat "<<'\n';
}
