//
// Created by lazar on 10/25/2022.
//

#ifndef OOP_ANGAJAT_H
#define OOP_ANGAJAT_H

#include <iostream>
#include  <vector>
#include <ctime>
#include "Task.h"
#include "AlteFunctii.h"


using std::cout;
using std::string;

class Angajat{

    string nume;

    std::vector<Task> TaskAngajat;
    int NrTaskuriRezolvate = 0;

    int TaskuriRestante = 0;


public:
    Angajat(const string &nume, const std::vector<Task> &TaskuriAngajat, int TaskRez = 0, int TaskuriRestante = 0);

    friend std::ostream &operator<<(std::ostream &afisare, Angajat &angajat);

    Angajat &operator=(const Angajat &altul);

    Angajat(const Angajat &altul);

    void CalculeazaTaskAngajat();

    void AfisareTaskRestant();

    void SetTaskRestant();


    float GetProfitAngajat() const;

    int GetNrTaskRestante() const;

    string GetNume();


    ~Angajat() = default;





};



#endif //OOP_ANGAJAT_H
