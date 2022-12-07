//
// Created by lazar on 11/27/2022.
//

#include "Departamente.h"

#include <utility>


/// daca vreau sa fac departamentul d1=d2,unul sa fie departament tehnic, altul sa fie relatii clienti

std::ostream &operator<<(std::ostream &afisare, const Departament &departament) {

    afisare << "Numele departamentului: " << departament.NumeDepartament << std::endl;

    departament.afisare(afisare);
    for (const auto &angajat: departament.AngajatiiDinDepartamente)
        afisare << *angajat << '\n';
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
    std::swap(AngajatiiDinDepartamente,copie->AngajatiiDinDepartamente);
    return *this;

}

Departament::Departament(const Departament &altul):NumeDepartament(altul.NumeDepartament) {
    for(const auto &Angajati:altul.AngajatiiDinDepartamente)
        AngajatiiDinDepartamente.emplace_back(Angajati->clone());
}

void Departament::AdaugaAngajat(std::shared_ptr<Angajat> Ang){
    AngajatiiDinDepartamente.emplace_back(Ang);

}




DepartamenteTehnice::DepartamenteTehnice(const std::string &NumeDepartament,
                                         const std::vector<std::shared_ptr<Angajat>> &AngajatiDepartamente,
                                         float Profit, int nrtaskuri) :
        Departament(NumeDepartament, AngajatiDepartamente), ProfitTotal(Profit),
        NrTaskuriTotale(nrtaskuri) {
    if(AngajatiiDinDepartamente.size()==0) throw EroareLaConstructor("Departamentul trebuie sa aiba minim un angajat!");

}

void DepartamenteTehnice::afisare(std::ostream &afis) const {
    afis << "Profit Departament: " << ProfitTotal << '\n';
    afis << "Nr total de task-uri:" << NrTaskuriTotale << '\n';
    afis << "Angajatii Departamentului tehnic:" << '\n';



}


void DepartamenteTehnice::SetProfitDepartament() {

    for(const auto &angajat:AngajatiiDinDepartamente){
        std::shared_ptr<NetworkEngineer>Angajat = std::dynamic_pointer_cast<NetworkEngineer>(angajat);
        if(Angajat!= nullptr) {
            ProfitTotal += Angajat->GetReteleRez() * 300 - Angajat->GetNrEchipDis() * 100;
            for (const auto &task: angajat->GetVectorTaskAng()) {
                std::shared_ptr<TaskRetelistica> t = std::dynamic_pointer_cast<TaskRetelistica>(task);
                if(t!= nullptr){
                if (task->GetStatusTask() == false && DiferentaIntreDouaDati(DataCurenta(), task->GetDeadlineTask()) ==false) {
ProfitTotal-=t->GetValoareTask();



                    } else if(task->GetStatusTask()== true) ProfitTotal+=t->GetValoareTask();


                }
            }


        }


    }

}

void DepartamenteTehnice::SetNrTaskuriTotale() {
    NrTaskuriTotale=0;
for(const auto&angajat:AngajatiiDinDepartamente){
    NrTaskuriTotale+=angajat->GetSizeOfVectTaskAng();

}
}

void DepartamenteTehnice::AfisareProcentReusitaDepartament()const {
    float procent;
    int TaskTerminate=0;
    for( const auto&angajat:AngajatiiDinDepartamente)
        for(const auto &task: angajat->GetVectorTaskAng())
            if(task->GetStatusTask()== true)TaskTerminate++;

    procent=(TaskTerminate*100)/NrTaskuriTotale;
    cout<<"Reusita departamentului tehnic este de : "<<procent<<"% \n";








}
//
//void DepartamenteTehnice::ConcediereAngajatiIneficienti() {
//    for(const auto &angajat:AngajatiiDinDepartamente){
//
//       std::shared_ptr<NetworkEngineer>Angajat= std::dynamic_pointer_cast<NetworkEngineer>(angajat);
//       if(Angajat!= nullptr){
//if(Angajat->GetNrEchipDis()>=3 && angajat->GetPenalizari()>=3)
//    AngajatiiDinDepartamente.erase(std::remove(AngajatiiDinDepartamente.begin(),AngajatiiDinDepartamente.end()
//    ,angajat),AngajatiiDinDepartamente.end());
//
//
//       }
//    }
//
//}


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

void DepartamentRelatiiClienti::AfisareProcentReusitaDepartament() const {
    float procent;
    int TaskTerminate=0;
    for( const auto&angajat:AngajatiiDinDepartamente)
        for(const auto &task: angajat->GetVectorTaskAng())
            if(task->GetStatusTask()== true)TaskTerminate++;

    procent=(TaskTerminate*100)/Target;
    cout<<"Reusita departamentului RelatiiClienti este de : "<<procent<<"%\n";





}

//void DepartamentRelatiiClienti::ConcediereAngajatiIneficienti() {
//    for( auto &angajat:AngajatiiDinDepartamente){
//            if(angajat->GetPenalizari()>=3)
//                AngajatiiDinDepartamente.erase(std::remove(AngajatiiDinDepartamente.begin(),AngajatiiDinDepartamente.end()
//                        ,angajat),AngajatiiDinDepartamente.end());
//
//
//
//    }
//
//}












