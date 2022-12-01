//
// Created by lazar on 11/27/2022.
//

#ifndef OOP_COMPANIE_H
#define OOP_COMPANIE_H

#include <iostream>
#include "Departamente.h"
#include <vector>
#include <memory>

using std::string;


class Companie {
private:
    string DenumireCompanie;
    std::vector<std::shared_ptr<Departament>> Departamente;


public:
    Companie(const string &Denumire, const std::vector<std::shared_ptr<Departament>> &Departamente1);


    Companie &operator=(const Companie &altul);

    friend void swap(Companie c1, Companie c2);

    Companie(const Companie &other);


    ~Companie() = default;

    friend std::ostream &operator<<(std::ostream &afisare, const Companie &companie);

};


#endif //OOP_COMPANIE_H
