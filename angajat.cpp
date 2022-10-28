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
    CalculeazaTaskAngajat(*this);

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

std::ostream &operator<<(std::ostream &cout1, const Angajat &angajat) {
    //Angajat::CalcProfitAngajat(const_cast<Angajat &>(angajat));
    cout1 << "Nume angajat: " << angajat.nume << '\n';
    cout1<<"Profit generat:"<< angajat.ProfitAngajat<<'\n';
    cout1 << "Task-uri rezolvate: " << angajat.NrTaskuriRezolvate << std::endl;
    cout1 << "RESTANTE" << angajat.TaskuriRestante << std::endl;



    cout1 << "Task-urile pe care le are angajatul de rezolvat:\n";
    for (const auto &i: angajat.TaskAngajat) {
        if (Task::GetStatusTask(i)==0)
            cout1<<i<<std::endl;

    ;}
    Angajat::AfisareTaskRestant(const_cast<Angajat &>(angajat));


        cout1 << std::endl<<std::endl;


    return cout1;
}

void Angajat::CalculeazaTaskAngajat(Angajat &a) {

    for (const auto &i: a.TaskAngajat) {
        if (Task::GetStatusTask(i) == 1)
            a.NrTaskuriRezolvate++;


    }


}

void Angajat::AfisareTaskRestant(Angajat &a) {

    int ok = 0;
    cout << a.nume;
    for (const auto &i: a.TaskAngajat) {
        if (Task::TaskRestant(i)) {
            ok++;
            if (ok == 1) cout << " este in urma cu task-urile cu ID: ";

            cout << Task::GetTaskId(i) << " ";
        }


    }
    a.TaskuriRestante = ok;
    if (ok == 0) cout << " nu are task-uri restante!";
    cout << "LOCAL RESTANTE " << a.TaskuriRestante << std::endl;

}

void Angajat::CalcProfitAngajat(Angajat &a) {
    float profit=0;
    for(const auto &i:a.TaskAngajat){
        if(Task::GetStatusTask(i)==1) profit+=Task::GetProfitTask(i);
        else if(Task::GetStatusTask(i)==0 && Task::TaskRestant(i)==true) profit-=Task::GetProfitTask(i);


    }
    a.ProfitAngajat = profit;


}

float Angajat::GetAngajatProfit(const Angajat &a) {
    return a.ProfitAngajat;
}

int Angajat::GetNrTaskRestante(const Angajat &a) {
    return a.TaskuriRestante;
}

string Angajat::GetNume(const Angajat &a) {
    return a.nume;
}







