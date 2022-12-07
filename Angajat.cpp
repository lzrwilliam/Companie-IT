//
// Created by lazar on 11/30/2022.
//

#include "Angajat.h"

Angajat::Angajat(const string &nume, const std::vector<std::shared_ptr<Task>>&TaskAng,float salariu, int Penalizari) : NumeAngajat(nume), TaskAng(TaskAng),Salariu(salariu),
                                                                      PenalizariPentruTaskuriIntarziate(Penalizari),IdAngajat(Id) { Id++;

}
int Angajat::Id=1;

std::ostream &operator<<(std::ostream &afis, const Angajat &angajat) {
    afis<<"Id Angajat:"<<angajat.IdAngajat<<'\n';
    afis << "Numele angajatului: " << angajat.NumeAngajat << '\n';
    afis << "Salariul:" << angajat.Salariu << '\n';
    afis << "Penalitati:" << angajat.PenalizariPentruTaskuriIntarziate << '\n';
    afis<<"Task-urile angajatului: "<<'\n';
    for(const auto &task:angajat.TaskAng)
        afis<<*task<<'\n';
    angajat.afisare(afis);
    return afis;
}

Angajat &Angajat::operator=(const Angajat &altul) {
 auto copie=altul.clone();
 std::swap(NumeAngajat,copie->NumeAngajat);
 std::swap(TaskAng,copie->TaskAng);
 std::swap(Salariu,copie->Salariu);
 std::swap(PenalizariPentruTaskuriIntarziate,copie->PenalizariPentruTaskuriIntarziate);
    return *this;
}

Angajat::Angajat(const Angajat &other):NumeAngajat(other.NumeAngajat),Salariu(other.Salariu),PenalizariPentruTaskuriIntarziate(other.PenalizariPentruTaskuriIntarziate),IdAngajat(Id) {
    Id++;
    for(const auto &task:other.TaskAng)
        TaskAng.emplace_back(task->clone());


}

void Angajat::AdaugaTask(const std::shared_ptr<Task> TaskAng1) {
    TaskAng.emplace_back(TaskAng1);

}

int Angajat::GetSizeOfVectTaskAng() {
    return TaskAng.size();
}

std::vector<std::shared_ptr<Task>> Angajat::GetVectorAng() const {
   std::vector<std::shared_ptr<Task>>vec (TaskAng.begin(),TaskAng.end());
   return vec;
}


NetworkEngineer::NetworkEngineer(const string &Nume, const std::vector<std::shared_ptr<Task>>&TaskAng,float Salariu, int Penalizari, int ReteleRez, int EchipamenteDis,
                                 int ClientiMultu) : Angajat(Nume, TaskAng,Salariu, Penalizari),
                                                     ReteleRezolvate(ReteleRez), EchipamenteDistruse(EchipamenteDis),
                                                     ClientiMultumiti(ClientiMultu) {

}

std::shared_ptr<Angajat> NetworkEngineer::clone() const {
    return std::make_shared<NetworkEngineer>(*this);
}

void NetworkEngineer::afisare(std::ostream &afis) const {
    afis << "Nr de retele rezolvate: " << ReteleRezolvate << '\n';
    afis << "Echipamente Distruse:" << EchipamenteDistruse << '\n';
    afis << "Clienti care s-au declarat multumiti: " << ClientiMultumiti << '\n';
}

int NetworkEngineer::GetNrEchipDis()  {
    return EchipamenteDistruse;
}

int NetworkEngineer::GetReteleRez() {
    return ReteleRezolvate;
}

void NetworkEngineer::SetEchipDistruseReteleRez() {
    for(const auto &task: TaskAng ){
        std::shared_ptr<TaskRetelistica> t= std::dynamic_pointer_cast<TaskRetelistica>(t);
        if(t!= nullptr){


            if(task->GetStatusTask()==false)
                EchipamenteDistruse=t->GetEchipamente();
            else ReteleRezolvate=t->GetReteleImplicate();
        }


    }

}

void OperatorCallCenter::afisare(std::ostream &afis) const {
    afis << "Apelurile din ultima luna: " << NrApeluriPeUltimaLuna << '\n';
    afis << "NrNecesarPtTarget:" << NrPentruTargetLunar << '\n';
    afis << "Procentul realizat din target: " << ProcentTarget << '\n';
}

std::shared_ptr<Angajat> OperatorCallCenter::clone() const {
    return std::make_shared<OperatorCallCenter>(*this);
}

OperatorCallCenter::OperatorCallCenter(const string &Nume, const std::vector<std::shared_ptr<Task>>&TaskAng,float Salariu, int Penalizari, int NrApeluriPeUltimaLuna,
                                       int NrPentruTargetLunar, float ProcentTarget) : Angajat(Nume, TaskAng,Salariu,
                                                                                               Penalizari),
                                                                                       NrApeluriPeUltimaLuna(
                                                                                               NrApeluriPeUltimaLuna),
                                                                                       NrPentruTargetLunar(
                                                                                               NrPentruTargetLunar),
                                                                                       ProcentTarget(ProcentTarget) {}
