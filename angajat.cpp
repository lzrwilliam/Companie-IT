//
// Created by lazar on 10/25/2022.
//

#include "angajat.h"
Angajat::Angajat(const string &nume, const std::vector<Task> &TaskuriAngajat, int TaskRez) :
        nume{nume},
        TaskAngajat{TaskuriAngajat},
        NrTaskuriRezolvate{TaskRez}
{
}

Angajat &Angajat::operator=(const Angajat &altul) {

    nume = altul.nume;
    TaskAngajat = altul.TaskAngajat;
    NrTaskuriRezolvate = altul.NrTaskuriRezolvate;
    return *this;
    // cout<<"Operator = de copiere angajat "<<'\n';
}

Angajat::Angajat(const Angajat &altul) :
        nume{altul.nume},
        TaskAngajat{altul.TaskAngajat},
        NrTaskuriRezolvate{altul.NrTaskuriRezolvate} {
    //cout<<"Constructor copiere angajat "<<'\n';
}

std::ostream &operator<<(std::ostream &cout1, const Angajat &angajat) {

    cout1 << "Nume angajat: " << angajat.nume << '\n';
    cout1 << "Task-uri rezolvate: " << angajat.NrTaskuriRezolvate << std::endl;
    cout1 << "Task-urile pe care le are angajatul:\n";

  //  for (const auto &i: angajat.TaskAngajat)

        cout1 << std::endl;
    return cout1;
}

void Angajat::CalculNrTaskRez() {
    for (const auto &i: TaskAngajat)
        if (true == i.StatusTask)
            NrTaskuriRezolvate += 1;

    cout << "Angajatul " << nume << " a rezolvat " << NrTaskuriRezolvate << " taskuri!";


}
