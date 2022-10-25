//
// Created by lazar on 10/25/2022.
//

#include "Companie.h"

Companie::Companie(const string &Denumire, const std::vector<Departament> &Departamente1) :
        DenumireCompanie{Denumire},
        Departamente{Departamente1} {}

Companie &Companie::operator=(const Companie &altul) {
    DenumireCompanie = altul.DenumireCompanie;

    // cout<<"operator= de copiere compani "<<'\n';
    return *this;


}

Companie::Companie(Companie &other) :
        DenumireCompanie{other.DenumireCompanie},
        Departamente{other.Departamente} { cout << "CC Companie" << std::endl; }

std::ostream &operator<<(std::ostream &cout1, const Companie &companie) {
    cout1 << "Numele companiei: " << companie.DenumireCompanie << '\n' << "Departamentele companiei:" << '\n';
    for (const auto &i: companie.Departamente) {
        cout1 << i;
        cout1 << std::endl;
    }

    return cout1;


}
