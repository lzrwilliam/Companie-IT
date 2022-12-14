//
// Created by lazar on 11/27/2022.
//

#include "Departamente.h"

#include <utility>



std::ostream &operator<<(std::ostream &afisare, const Departament &departament) {

    afisare << "Numele departamentului: " << departament.NumeDepartament << std::endl;

    departament.afisare(afisare);
if (!departament.AngajatiiDinDepartamente.empty()) {
    for (const auto &angajat: departament.AngajatiiDinDepartamente)
        afisare << *angajat << '\n';
}
    afisare << '\n';
    return afisare;

}

void Departament::afisare(std::ostream &) const {}

Departament::Departament(string Nume, std::vector<std::shared_ptr<Angajat>> AngajatiiDinDepartamente) : NumeDepartament(
        std::move(Nume)), AngajatiiDinDepartamente(std::move(AngajatiiDinDepartamente)) {

}

Departament &Departament::operator=(const Departament &altul) {

    auto copie=altul.clone();
    std::swap(NumeDepartament,copie->NumeDepartament);
    std::swap(AngajatiiDinDepartamente, copie->AngajatiiDinDepartamente);
    return *this;

}

Departament::Departament(const Departament &altul) : NumeDepartament(altul.NumeDepartament) {
    for (const auto &Angajati: altul.AngajatiiDinDepartamente)
        AngajatiiDinDepartamente.emplace_back(Angajati->clone());
}

void Departament::AdaugaAngajat(std::shared_ptr<Angajat> Ang) {
    if (std::find(AngajatiiDinDepartamente.begin(), AngajatiiDinDepartamente.end(), Ang) ==
        AngajatiiDinDepartamente.end()) {
        AngajatiiDinDepartamente.emplace_back(Ang);
        cout << "Angajatul " << Ang->GetNume() << " adaugat cu succes \n";
    } else throw ResursaLipsa("Nu putem avea mai multi angajati identici! \n");

}






std::shared_ptr<Angajat> Departament::AfisareAngajatDupaNume(const string &nume) {
    if (!AngajatiiDinDepartamente.empty()) {
        for (const auto &angajat: AngajatiiDinDepartamente)
            if (nume.compare(angajat->GetNume()) == 0)
                return angajat;
    }
    throw ResursaLipsa("Angajatul nu exista, se returneaza pointer null!");
}

//std::vector<std::shared_ptr<Angajat>> Departament::GetVectAng() const {
//
//        std::vector<std::shared_ptr<Angajat>>vec (AngajatiiDinDepartamente.begin(),AngajatiiDinDepartamente.end());
//        return vec;
//    }

std::vector<std::shared_ptr<Angajat>> Departament::GetVectAng() const {


    return AngajatiiDinDepartamente;
}





DepartamenteTehnice::DepartamenteTehnice(const std::string &NumeDepartament,
                                         const std::vector<std::shared_ptr<Angajat>> &AngajatiDepartamente,
                                         float Profit, int nrtaskuri) :
        Departament(NumeDepartament, AngajatiDepartamente), ProfitTotal(Profit),
        NrTaskuriTotale(nrtaskuri) {
    if (AngajatiDepartamente.empty()) throw ArgumentInvalid("Departamentul trebuie sa aiba minim un angajat!");


}

void DepartamenteTehnice::afisare(std::ostream &afis) const {
    afis << "Profit Departament: " << ProfitTotal << '\n';
    afis << "Nr total de task-uri:" << NrTaskuriTotale << '\n';
    afis << "Angajatii Departamentului tehnic:" << '\n';



}


void DepartamenteTehnice::SetProfitDepartament() {
    if (!AngajatiiDinDepartamente.empty()) {
        for (const auto &angajat: AngajatiiDinDepartamente) {
            std::shared_ptr<NetworkEngineer> Angajat = std::dynamic_pointer_cast<NetworkEngineer>(angajat);
            if (Angajat != nullptr) {
                ProfitTotal += Angajat->GetReteleRez() * 300 - Angajat->GetNrEchipDis() * 100;
                for (const auto &task: angajat->GetVectorTaskAng()) {
                    std::shared_ptr<TaskRetelistica> t = std::dynamic_pointer_cast<TaskRetelistica>(task);
                    if (t != nullptr) {
                        if (task->GetStatusTask() == false &&
                            DiferentaIntreDouaDati(DataCurenta(), task->GetDeadlineTask()) == false) {
                            ProfitTotal -= t->GetValoareTask();


                        } else if (task->GetStatusTask() == true) ProfitTotal += t->GetValoareTask();


                    }
                }

            }
        }


    }

}

void DepartamenteTehnice::SetNrTaskuriTotale() {
    NrTaskuriTotale = 0;
    if (!AngajatiiDinDepartamente.empty()) {
        for (const auto &angajat: AngajatiiDinDepartamente) {
            NrTaskuriTotale += angajat->GetSizeOfVectTaskAng();
        }

    }
}

float DepartamenteTehnice::CalculareProcentReusitaDepartament() const {


    if (!AngajatiiDinDepartamente.empty()) {
        float procent;
        int TaskTerminate = 0;
        int TaskDepasitDeadline = 0;
        for (const auto &angajat: AngajatiiDinDepartamente)
            for (const auto &task: angajat->GetVectorTaskAng()) {
                if (task->GetStatusTask() == true)TaskTerminate++;
                if ((task->GetTerminatTask() == false && task->GetStatusTask() == false) &&
                    DiferentaIntreDouaDati(DataCurenta(), task->GetDeadlineTask()) == false)
                    TaskDepasitDeadline++;
            }

        procent = ((TaskTerminate - TaskDepasitDeadline) * 100) / NrTaskuriTotale;
        return procent;
    }


    return 0;

}






void DepartamenteTehnice::ConcediereAngajatiIneficienti() {
    if (!AngajatiiDinDepartamente.empty()) {
        for (auto angajat = AngajatiiDinDepartamente.begin(); angajat != AngajatiiDinDepartamente.end();) {

            std::shared_ptr<NetworkEngineer> Angajat = std::dynamic_pointer_cast<NetworkEngineer>(*angajat);
            if (Angajat != nullptr) {
                if (Angajat->GetNrEchipDis() >= 3 && (*angajat)->GetPenalizari() >= 3) {
                    angajat = AngajatiiDinDepartamente.erase(angajat++);
                    std::cout << "Angajatul " << Angajat->GetNume() << " din departamentul Tehnic a fost concediat!"
                              << '\n';

                } else ++angajat;
            }
        }
    }
}





DepartamentRelatiiClienti::DepartamentRelatiiClienti(const std::string &NumeDepartament,
                                                     const std::vector<std::shared_ptr<Angajat>> &AngajatiDepartamente,
                                                     int Target) :
        Departament(NumeDepartament, AngajatiDepartamente), Target(Target) {

    for(const auto&angajat:AngajatiDepartamente)
    {
        std::shared_ptr<OperatorCallCenter>Angajat=std::dynamic_pointer_cast<OperatorCallCenter>(angajat);
        if(Angajat!= nullptr){
            Angajat->SetNrTargetLunar(Target);

        }
    }


}

void DepartamentRelatiiClienti::afisare(std::ostream &afis) const {

    afis << "Targetul departamentului este de " << Target << " task-uri" << '\n';
    afis << "Angajatii Departamentului Relatii Clienti:" << '\n';


}

std::shared_ptr<Departament> DepartamentRelatiiClienti::clone() const {
    return std::make_shared<DepartamentRelatiiClienti>(*this);
}

float DepartamentRelatiiClienti::CalculareProcentReusitaDepartament() const {


    if (!AngajatiiDinDepartamente.empty()) {
        int TaskTerminate = 0;

        for (const auto &angajat: AngajatiiDinDepartamente)
            for (const auto &task: angajat->GetVectorTaskAng())
                if (task->GetStatusTask() == true)TaskTerminate++;

        if (Target != 0) {
            float procent = (TaskTerminate * 100) / Target;

            return procent;
        }

    }

    return 0;
}




void DepartamentRelatiiClienti::ConcediereAngajatiIneficienti() {

    std::erase_if(AngajatiiDinDepartamente, [](const std::shared_ptr<Angajat> &ang) {
        if (ang->GetPenalizari() >= 3) {

            cout << "Angajatul " << ang->GetNume()
                 << " a fost sters din departamentul Relatii Clienti din cauza penalizarilor '\n'";
        }
        return ang->GetPenalizari() >= 3;
    });


}












