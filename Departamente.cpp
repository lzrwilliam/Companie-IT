//
// Created by lazar on 10/25/2022.
//

#include "Departamente.h"

Departament::Departament(const string &Nume, const std::vector<Angajat> &Angajati, float Profit) :
        NumeDepartament{Nume},
        AngajatiDepartament{Angajati},
        ProfitDepartament{Profit} {}

Departament::Departament(const Departament &other) :
        NumeDepartament{other.NumeDepartament},
        AngajatiDepartament{other.AngajatiDepartament},
        ProfitDepartament{other.ProfitDepartament} {}

Departament &Departament::operator=(const Departament &altul) {
    NumeDepartament = altul.NumeDepartament;
    AngajatiDepartament = altul.AngajatiDepartament;
    ProfitDepartament = altul.ProfitDepartament;
    return *this;
}

std::ostream &operator<<(std::ostream &afisare, const Departament &departament) {

    afisare << "Numele departamentului: " << departament.NumeDepartament << std::endl;
    afisare << "Profit departament: " << departament.ProfitDepartament << std::endl;
    afisare << "Angajatii din departament:" << std::endl;
    for (const auto &i: departament.AngajatiDepartament)
        afisare << i;
    return afisare;

}


