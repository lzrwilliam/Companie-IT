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
    std::vector<std::shared_ptr<Angajat>> AngajatiiDinDepartamente;

    virtual void afisare(std::ostream &) const;

public:

    Departament(string Nume, std::vector<std::shared_ptr<Angajat>> AngajatiiDinDepartamente);

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


    //vect task-uri cred sau nu
    void afisare(std::ostream &afis) const override;


public:
    DepartamenteTehnice(const std::string &NumeDepartament,
                        const std::vector<std::shared_ptr<Angajat>> &AngajatiiDinDepartamente, float profit,
                        int nrtaskuri);

    std::shared_ptr<Departament> clone() const override {
        return std::make_shared<DepartamenteTehnice>(*this);
    }


    DepartamenteTehnice &operator=(DepartamenteTehnice altul);

    ~DepartamenteTehnice();


    friend void swap(DepartamenteTehnice &d1, DepartamenteTehnice &d2);


};

class DepartamentRelatiiClienti : public Departament {
    int Target;

    void afisare(std::ostream &afis) const override;

public:
    DepartamentRelatiiClienti(const std::string &NumeDepartament,
                              const std::vector<std::shared_ptr<Angajat>> &AngajatiDepartamente, int Target);

    ~DepartamentRelatiiClienti() {}

    std::shared_ptr<Departament> clone() const override;

    DepartamentRelatiiClienti &operator=(DepartamentRelatiiClienti altul);


    friend void swap1(DepartamentRelatiiClienti &d1, DepartamentRelatiiClienti &d2);


};



#endif //OOP_DEPARTAMENTE_H
