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
    float ProfitAngajat;
public:
    Angajat(const string &nume, const std::vector<Task> &TaskuriAngajat, int TaskRez = 0,float ProfitAngajat=0);

    friend std::ostream &operator<<(std::ostream&cout,const Angajat&angajat);

    Angajat &operator=(const Angajat &altul);

    Angajat(const Angajat &altul);

    static void CalculeazaTaskAngajat(Angajat &a);

    static void AfisareTaskRestant(const Angajat &a);
    static void CalcProfitAngajat(Angajat &a);
//    static float GetAngajatProfit(const Angajat &a);





    ~Angajat()= default;





};



#endif //OOP_ANGAJAT_H
