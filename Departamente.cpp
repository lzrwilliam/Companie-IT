//
// Created by lazar on 10/25/2022.
//

#include "Departamente.h"

Departament::Departament(const string &Nume, const std::vector<Angajat> &Angajati) :
        NumeDepartament{Nume},
        AngajatiDepartament{Angajati} {

}

Departament::Departament(const Departament &other) :
        NumeDepartament{other.NumeDepartament},
        AngajatiDepartament{other.AngajatiDepartament} {}

Departament &Departament::operator=(const Departament &altul) {
    NumeDepartament = altul.NumeDepartament;
    AngajatiDepartament = altul.AngajatiDepartament;
    return *this;
}

std::ostream &operator<<(std::ostream &afisare, const Departament &departament) {

    afisare << "Numele departamentului: " << departament.NumeDepartament << std::endl;
    afisare << "Angajatii din departament:" << std::endl << '\n';
    for (auto angajat: departament.AngajatiDepartament)
        afisare << angajat;
    return afisare;

}

void Departament::StergereAngajatCuTaskuriRestante() {
    for (auto &angajat: this->AngajatiDepartament) {
        angajat.SetTaskRestant();
        if (angajat.GetNrTaskRestante() >= 3) {

            cout << "Angajatul " << angajat.GetNume() << " din departamentul " << this->NumeDepartament
                 << " a fost concediat!" << '\n';
        }
    }

    //cout<<"inainte de stergere"<<this->AngajatiDepartament.size();
//                    std::erase_if(
//                            AngajatiDepartament,
//                            [](const auto& angajat) {
//                                return angajat.GetNrTaskuriRestante() >= 3;
//                            }
//                    );

    // cout<<"dupa stergere"<<this->AngajatiDepartament.size();






}







