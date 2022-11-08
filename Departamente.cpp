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
    int poz = 0;
    for (auto &angajat: this->AngajatiDepartament) {
angajat.SetTaskRestant();
        if (angajat.GetNrTaskRestante() >= 3) {

            cout << "Angajatul " << angajat.GetNume() << " din departamentul " << this->NumeDepartament
                 << " a fost concediat!" << '\n';
            this->AngajatiDepartament.erase(this->AngajatiDepartament.begin() + poz);
//            this->AngajatiDepartament.erase(
//                    std::remove_if(this->AngajatiDepartament.begin(),
//                                   this->AngajatiDepartament.end(),angajat.GetNrTaskRestante()>=3),
//                                   this->AngajatiDepartament.end());

        }

        poz++;


    }

}







