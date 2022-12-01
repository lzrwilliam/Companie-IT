//
// Created by lazar on 11/27/2022.
//

#include "Companie.h"

Companie::Companie(const string &Denumire, const std::vector<std::shared_ptr<Departament>> &Departamente1) :
        DenumireCompanie{Denumire},
        Departamente{Departamente1} {}

Companie &Companie::operator=(const Companie &altul) {
    swap(*this, altul);
    return *this;
}

void swap(Companie c1, Companie c2) {
    std::swap(c1.DenumireCompanie, c2.DenumireCompanie);
    std::swap(c1.Departamente, c2.Departamente);

}


Companie::Companie(const Companie &other) : DenumireCompanie(other.DenumireCompanie) {
    for (const auto &departamente: other.Departamente)
        Departamente.emplace_back(departamente->clone());


}

std::ostream &operator<<(std::ostream &afisare, const Companie &companie) {
    afisare << "Numele companiei: " << companie.DenumireCompanie << '\n' << "Departamentele companiei:" << '\n';
    for (const auto &i: companie.Departamente) {
        afisare << *i;
        afisare << std::endl;
    }

    return afisare;


}



