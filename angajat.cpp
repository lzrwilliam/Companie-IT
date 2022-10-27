//
// Created by lazar on 10/25/2022.
//

#include "angajat.h"
Angajat::Angajat(const string &nume, const std::vector<Task> &TaskuriAngajat, int TaskRez) :
        nume{nume},
        TaskAngajat{TaskuriAngajat},
        NrTaskuriRezolvate{TaskRez}
{
    CalculeazaTaskAngajat(*this);

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
    cout1 << "Task-urile pe care le are angajatul de rezolvat:\n";


    for (const auto &i: angajat.TaskAngajat) {
        if (Task::GetStatusTask(i)==0)
            cout1<<i<<std::endl;

    ;}

        cout1 << std::endl;
    return cout1;
}

void Angajat::CalculeazaTaskAngajat(Angajat &a) {

    for (const auto &i: a.TaskAngajat) {
        if (i.StatusTask == 1)
            a.NrTaskuriRezolvate++;


    }


}

//void Angajat::AfisareTaskRestant(Angajat &a) {
//
//
//}




