//
// Created by lazar on 11/27/2022.
//

#include "Departamente.h"


std::ostream &operator<<(std::ostream &afisare, const Departament &departament) {

    afisare << "Numele departamentului: " << departament.NumeDepartament << std::endl;

    departament.afisare(afisare);
    afisare << '\n';
    return afisare;

}

void Departament::afisare(std::ostream &) const {

}

Departament::Departament(const string &Nume) : NumeDepartament(Nume) {

}


DepartamenteTehnice::DepartamenteTehnice(const std::string &NumeDepartament, float Profit, int nrtaskuri,
                                         std::vector<std::shared_ptr<Angajat>> AngajatiTehnic) :
        Departament(NumeDepartament), ProfitTotal(Profit),
        NrTaskuriTotale(nrtaskuri), AngajatiTehnic(AngajatiTehnic) {

}

void DepartamenteTehnice::afisare(std::ostream &afis) const {
    afis << "Profit Departament: " << ProfitTotal << '\n';
    afis << "Nr total de task-uri:" << NrTaskuriTotale << '\n';
    afis << "Angajatii Departamentului tehnic:" << '\n';
    for (const auto &angajat: AngajatiTehnic)
        afis << *angajat << '\n';


}

void swap(DepartamenteTehnice &d1, DepartamenteTehnice &d2) {
    std::swap(d1.ProfitTotal, d2.ProfitTotal);
    std::swap(d1.NrTaskuriTotale, d2.NrTaskuriTotale);
    std::swap(d1.AngajatiTehnic, d2.AngajatiTehnic);

}

DepartamenteTehnice &DepartamenteTehnice::operator=(DepartamenteTehnice altul) {
    swap(*this, altul);
    return *this;
}

DepartamenteTehnice::~DepartamenteTehnice() {}




