//
// Created by lazar on 11/27/2022.
//

#ifndef OOP_DEPARTAMENTE_H
#define OOP_DEPARTAMENTE_H


#include <iostream>
#include <typeinfo>

using std::cout;
using std::string;

#include <vector>
#include <memory>
#include "Angajat.h"

class Departament {
    string NumeDepartament;

    virtual void afisare(std::ostream &) const;

  std::vector<std::shared_ptr<Angajat>> AngajatiiDinDepartamente;

public:
  // virtual void CalculeazaPierderiDepartament() const;

    Departament(string Nume, std::vector<std::shared_ptr<Angajat>> AngajatiiDinDepartamente);
  void AdaugaAngajat(std::shared_ptr<Angajat>Ang);

    virtual std::shared_ptr<Departament> clone() const = 0;

    friend std::ostream &operator<<(std::ostream &afisare, const Departament &departament);


    virtual  ~Departament() = default;


protected:
    Departament &operator=(const Departament&altul);
    Departament(const Departament &altul);


};


class DepartamenteTehnice : public Departament {
private:
    float ProfitTotal;
    int NrTaskuriTotale;


    void afisare(std::ostream &afis) const override;


public:
    DepartamenteTehnice(const std::string &NumeDepartament,
                        const std::vector<std::shared_ptr<Angajat>> &AngajatiiDinDepartamente, float profit,
                        int nrtaskuri);

    std::shared_ptr<Departament> clone() const override {
        return std::make_shared<DepartamenteTehnice>(*this);
    }
 //   void CalculeazaPierderiDepartament() const override;


   // DepartamenteTehnice &operator=(DepartamenteTehnice altul);

  //  ~DepartamenteTehnice();


   // friend void swap(DepartamenteTehnice &d1, DepartamenteTehnice &d2);


};

class DepartamentRelatiiClienti : public Departament {
    int Target;

    void afisare(std::ostream &afis) const override;

public:
    DepartamentRelatiiClienti(const std::string &NumeDepartament,
                              const std::vector<std::shared_ptr<Angajat>> &AngajatiDepartamente, int Target);

 //   ~DepartamentRelatiiClienti() {}

    std::shared_ptr<Departament> clone() const override;



};



#endif //OOP_DEPARTAMENTE_H
