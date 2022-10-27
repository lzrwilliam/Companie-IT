//
// Created by lazar on 10/25/2022.
//

#ifndef OOP_DEPARTAMENTE_H
#define OOP_DEPARTAMENTE_H

#include <iostream>
#include  <vector>
#include <ctime>
#include "angajat.h"


using std::cout;
using std::string;


class Departament {
    string NumeDepartament;
    std::vector<Angajat> AngajatiDepartament;
    float ProfitDepartament = 0;

public:
    Departament(const string &Nume, const std::vector<Angajat> &Angajati, float Profit = 0);

    Departament(const Departament &other);

    Departament &operator=(const Departament &altul);

    friend std::ostream &operator<<(std::ostream &afisare, const Departament &departament);



    ~Departament() {}


};


#endif //OOP_DEPARTAMENTE_H
