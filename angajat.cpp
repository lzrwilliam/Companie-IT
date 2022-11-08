//
// Created by lazar on 10/25/2022.
//

#include "angajat.h"
Angajat::Angajat(const string &nume, const std::vector<Task> &TaskuriAngajat, int TaskRez, float ProfitAngajat,
                 int TaskuriRestante) :
        nume{nume},
        TaskAngajat{TaskuriAngajat},
        NrTaskuriRezolvate{TaskRez},
        ProfitAngajat{ProfitAngajat},
        TaskuriRestante{TaskuriRestante} {
    this->CalculeazaTaskAngajat();

}

Angajat &Angajat::operator=(const Angajat &altul) {

    nume = altul.nume;
    TaskAngajat = altul.TaskAngajat;
    NrTaskuriRezolvate = altul.NrTaskuriRezolvate;
    ProfitAngajat = altul.ProfitAngajat;
    TaskuriRestante = altul.TaskuriRestante;
    return *this;
    // cout<<"Operator = de copiere angajat "<<'\n';
}

Angajat::Angajat(const Angajat &altul) :
        nume{altul.nume},
        TaskAngajat{altul.TaskAngajat},
        NrTaskuriRezolvate{altul.NrTaskuriRezolvate},
        ProfitAngajat{altul.ProfitAngajat},
        TaskuriRestante{altul.TaskuriRestante} {
    //cout<<"Constructor copiere angajat "<<'\n';
}

std::ostream &operator<<(std::ostream &afisare, Angajat &angajat) {
    //Angajat::CalcProfitAngajat(const_cast<Angajat &>(angajat));
    afisare << "Nume angajat: " << angajat.nume << '\n';
    // afisare << "Profit generat:" << angajat.ProfitAngajat << '\n';
    afisare << "Profit generat:" << angajat.GetProfitAngajat() << '\n';

    afisare << "Task-uri rezolvate: " << angajat.NrTaskuriRezolvate << std::endl;


    afisare << "Task-urile pe care le are angajatul de rezolvat:\n";
    for (const auto &i: angajat.TaskAngajat) {
        if (Task::GetStatusTask(i) == 0)
            afisare << i << std::endl;

        ;
    }
    angajat.AfisareTaskRestant();


    afisare << std::endl << std::endl;


    return afisare;
}


void Angajat::CalculeazaTaskAngajat() {

    for (const auto &i: this->TaskAngajat) {
        if (Task::GetStatusTask(i) == 1)
            this->NrTaskuriRezolvate++;


    }


}

void Angajat::AfisareTaskRestant() {

    int ok = 0;
    cout << this->nume;
    for (const auto &i: this->TaskAngajat) {
        if (Task::TaskRestant(i)) {
            ok++;
            if (ok == 1) cout << " este in urma cu task-urile cu ID: ";

            cout << Task::GetTaskId(i) << " ";
        }


    }
    this->TaskuriRestante = ok;
    if (ok == 0) cout << " nu are task-uri restante!";

}

float Angajat::GetProfitAngajat() const {
    float profit = 0;
    for (const auto &i: this->TaskAngajat) {
        if (Task::GetStatusTask(i) == 1) profit += Task::GetProfitTask(i);
        else if (Task::GetStatusTask(i) == 0 && Task::TaskRestant(i) == true) profit -= Task::GetProfitTask(i);


    }
    return profit;


}



int Angajat::GetNrTaskRestante() {
    return this->TaskuriRestante;
}

string Angajat::GetNume() {
    return this->nume;
}







