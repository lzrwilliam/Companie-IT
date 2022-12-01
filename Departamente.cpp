//
// Created by lazar on 11/27/2022.
//

#include "Departamente.h"

#include <utility>


/// daca vreau sa fac departamentul d1=d2, cum fac??????

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


DepartamenteTehnice::DepartamenteTehnice(const std::string &NumeDepartament,
                                         const std::vector<std::shared_ptr<Angajat>> &AngajatiDepartamente,
                                         float Profit, int nrtaskuri) :
        Departament(NumeDepartament, AngajatiDepartamente), ProfitTotal(Profit),
        NrTaskuriTotale(nrtaskuri) {

}

void DepartamenteTehnice::afisare(std::ostream &afis) const {
    afis << "Profit Departament: " << ProfitTotal << '\n';
    afis << "Nr total de task-uri:" << NrTaskuriTotale << '\n';
    afis << "Angajatii Departamentului tehnic:" << '\n';



}

void swap(DepartamenteTehnice &d1, DepartamenteTehnice &d2) {
    std::swap(d1.ProfitTotal, d2.ProfitTotal);
    std::swap(d1.NrTaskuriTotale, d2.NrTaskuriTotale);

}

DepartamenteTehnice &DepartamenteTehnice::operator=(DepartamenteTehnice altul) {
    swap(*this, altul);
    return *this;
}

DepartamenteTehnice::~DepartamenteTehnice() {}

DepartamentRelatiiClienti::DepartamentRelatiiClienti(const std::string &NumeDepartament,
                                                     const std::vector<std::shared_ptr<Angajat>> &AngajatiDepartamente,
                                                     int Target) :
        Departament(NumeDepartament, AngajatiDepartamente), Target(Target) {}

void DepartamentRelatiiClienti::afisare(std::ostream &afis) const {

    afis << "Targetul departamentului este de " << Target << " task-uri" << '\n';
    afis << "Angajatii Departamentului Relatii Clienti:" << '\n';


}

std::shared_ptr<Departament> DepartamentRelatiiClienti::clone() const {
    return std::make_shared<DepartamentRelatiiClienti>(*this);
}

DepartamentRelatiiClienti &DepartamentRelatiiClienti::operator=(DepartamentRelatiiClienti altul) {
    swap1(*this, altul);
    return *this;
}

void swap1(DepartamentRelatiiClienti &d1, DepartamentRelatiiClienti &d2) {
    std::swap(d1.Target, d2.Target);


}




