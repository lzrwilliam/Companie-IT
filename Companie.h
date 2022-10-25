//
// Created by lazar on 10/25/2022.
//

#ifndef OOP_COMPANIE_H
#define OOP_COMPANIE_H

#include <iostream>
#include  <vector>
#include <ctime>
#include "Task.h"
#include "Departamente.h"

using std::cout;
using std::string;


class Companie {
private:
    string DenumireCompanie;
    std::vector<Departament> Departamente;
    std::vector<Task> TaskuriCompanie;


public:
    Companie(const string &Denumire, const std::vector<Departament> &Departamente1,
             const std::vector<Task> &TaskuriCompanie);


    Companie &operator=(const Companie &altul);

    Companie(Companie &other);


    ~Companie() = default;

    friend std::ostream &operator<<(std::ostream &cout, const Companie &companie);

};


#endif //OOP_COMPANIE_H
