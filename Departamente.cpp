//
// Created by lazar on 10/25/2022.
//

#include "Departamente.h"

Departament::Departament(const string &Nume, const std::vector<Angajat *> &Angajati, float Profit) :
        NumeDepartament{Nume},
        AngajatiDepartament{Angajati},
        ProfitDepartament{Profit} {

}

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
    Departament::SetProfitDep(const_cast<Departament &>(departament));

    afisare << "Numele departamentului: " << departament.NumeDepartament << std::endl;
    afisare << "Profit departament: " << departament.ProfitDepartament << std::endl;
    afisare << "Angajatii din departament:" << std::endl << '\n';
    for (const auto *angajat: departament.AngajatiDepartament)
        afisare << *angajat;
    return afisare;

}

void Departament::StergereAngajatCuTaskuriRestante(Departament &d) {
    int poz = 0;
    for (const auto &angajat: d.AngajatiDepartament) {

        if (angajat->GetNrTaskRestante() >= 3) {
            cout << "Angajatul " << Angajat::GetNume(*angajat) << " din departamentul " << d.NumeDepartament
                 << " a fost concediat!" << '\n';
            d.AngajatiDepartament.erase(d.AngajatiDepartament.begin() + poz);
        }

        poz++;


    }

}


void Departament::SetProfitDep(Departament &d) {

    float profit = 0;
    for (const auto &i: d.AngajatiDepartament) {
        Angajat::CalcProfitAngajat(const_cast<Angajat &>(*i));
        profit += Angajat::GetAngajatProfit(*i);


    }
    d.ProfitDepartament=profit;


}





