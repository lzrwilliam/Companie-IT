//
// Created by lazar on 10/25/2022.
//

#include "angajat.h"
Angajat::Angajat(const string &nume, const std::vector<Task> &TaskuriAngajat, int TaskRez, int TaskuriRestante) :
        nume{nume},
        TaskAngajat{TaskuriAngajat},
        NrTaskuriRezolvate{TaskRez},

        TaskuriRestante{TaskuriRestante} {
    this->CalculeazaTaskAngajat();

}

Angajat &Angajat::operator=(const Angajat &altul) {

    nume = altul.nume;
    TaskAngajat = altul.TaskAngajat;
    NrTaskuriRezolvate = altul.NrTaskuriRezolvate;

    TaskuriRestante = altul.TaskuriRestante;
    return *this;
    // cout<<"Operator = de copiere angajat "<<'\n';
}

Angajat::Angajat(const Angajat &altul) :
        nume{altul.nume},
        TaskAngajat{altul.TaskAngajat},
        NrTaskuriRezolvate{altul.NrTaskuriRezolvate},
        TaskuriRestante{altul.TaskuriRestante} {
    //cout<<"Constructor copiere angajat "<<'\n';
}

std::ostream &operator<<(std::ostream &afisare, Angajat &angajat) {

    afisare << "Nume angajat: " << angajat.nume << '\n';
    afisare << "Profit generat:" << angajat.GetProfitAngajat() << '\n';

    afisare << "Task-uri rezolvate: " << angajat.NrTaskuriRezolvate << std::endl;


    afisare << "Task-urile pe care le are angajatul de rezolvat:\n";
    for (const auto &i: angajat.TaskAngajat) {
        if (i.GetStatusTask() == 0)
            afisare << i << std::endl;


    }
    angajat.AfisareTaskRestant();


    afisare << std::endl << std::endl;


    return afisare;
}


void Angajat::CalculeazaTaskAngajat() {

    for (const auto &i: this->TaskAngajat) {
        if (i.GetStatusTask() == 1)
            this->NrTaskuriRezolvate++;


    }


}

void Angajat::SetTaskRestant() {

    int ok = 0;
    for (const auto &i: this->TaskAngajat) {
        if (i.TaskRestant())
            ok++;
    }
    this->TaskuriRestante = ok;


}

void Angajat::AfisareTaskRestant() {

    int ok = 0;
    cout << this->nume;
    for (const auto &i: this->TaskAngajat) {
        if (i.TaskRestant()) {
            ok++;
            if (ok == 1) cout << " este in urma cu task-urile cu ID: ";

            cout << i.GetTaskId() << " ";
        }


    }

    this->TaskuriRestante = ok;
    if (ok == 0) cout << " nu are task-uri restante!";

}

float Angajat::GetProfitAngajat() const {
    float profit = 0;
    for (const auto &i: this->TaskAngajat) {
        if (i.GetStatusTask() == 1) profit += i.GetProfitTask();
        else if (i.GetStatusTask() == 0 && i.TaskRestant() == true) profit -= i.GetProfitTask();


    }
    return profit;


}


int Angajat::GetNrTaskRestante() const {
    return this->TaskuriRestante;
}

string Angajat::GetNume() {
    return this->nume;
}







