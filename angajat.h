//
// Created by lazar on 10/25/2022.
//

#ifndef OOP_ANGAJAT_H
#define OOP_ANGAJAT_H

#include <iostream>
#include  <vector>
#include <ctime>

using std::cout;
using std::string;

class Angajat{

    string nume;

    std::vector<int>TaskuriAngajat;
    int NrTaskuriRezolvate=0;
public:
    Angajat(const string &nume, const std::vector <int>&TaskuriAngajat,int TaskRez=0);

public:
    friend std::ostream &operator<<(std::ostream&cout,const Angajat&angajat);

    Angajat &operator=(const Angajat&altul);
    Angajat(const Angajat&altul);


    // void CalculNrTaskRez(){





    ~Angajat()= default;





};



#endif //OOP_ANGAJAT_H
