//
// Created by lazar on 11/27/2022.
//

#ifndef OOP_DEPARTAMENTE_H
#define OOP_DEPARTAMENTE_H


#include <iostream>

using std::cout;
using std::string;

#include <vector>
#include <memory>
#include "Angajat.h"

class Departament {
    // de facut IdDepartament cu incrementare automata
    string NumeDepartament;

    virtual void afisare(std::ostream &) const;

public:

    explicit Departament(const string &Nume);

    virtual std::shared_ptr<Departament> clone() const = 0;

    friend std::ostream &operator<<(std::ostream &afisare, const Departament &departament);


    virtual  ~Departament() = default;

protected:
    Departament(const Departament &other) = default;

    Departament &operator=(const Departament &altul) = default;

};


class DepartamenteTehnice : public Departament {
private:
    float ProfitTotal;
    int NrTaskuriTotale;
    std::vector<std::shared_ptr<Angajat>> AngajatiTehnic;

    //vect task-uri cred sau nu
    void afisare(std::ostream &afis) const override;


public:
    DepartamenteTehnice(const std::string &NumeDepartament, float profit, int nrtaskuri,
                        std::vector<std::shared_ptr<Angajat>> AngajatiTehnic);

    std::shared_ptr<Departament> clone() const override {
        return std::make_shared<DepartamenteTehnice>(*this);
    }


    DepartamenteTehnice &operator=(DepartamenteTehnice altul);

    // DepartamenteTehnice(const DepartamenteTehnice&altul);
    ~DepartamenteTehnice();


    friend void swap(DepartamenteTehnice &d1, DepartamenteTehnice &d2);


};
// sa vad daca mai fac alt departament, automat mai trebuie si alta derivata pt angajati, cred
//class DepartamentDeCatering:public Departament{
//
//   std::vector<std::shared_ptr<std::pair<string ,float>>>MeniuDisponibil;
//    std::vector<std::shared_ptr<Angajat>>AngajatiCatering;
//    void afisare(std::ostream&afis) const override;
//
//
//
//
//};



#endif //OOP_DEPARTAMENTE_H
