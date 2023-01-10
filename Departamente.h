//
// Created by lazar on 11/27/2022.
//

#ifndef OOP_DEPARTAMENTE_H
#define OOP_DEPARTAMENTE_H


#include <iostream>
#include <typeinfo>
#include "Exceptii.h"
#include <set>
using std::cout;
using std::string;

#include <vector>
#include <memory>
#include "Angajat.h"

class Departament {
    string NumeDepartament;

    virtual void afisare(std::ostream &) const;
protected:
  std::vector<std::shared_ptr<Angajat>> AngajatiiDinDepartamente;

public:

    Departament(string Nume, std::vector<std::shared_ptr<Angajat>> AngajatiiDinDepartamente);
  void AdaugaAngajat(std::shared_ptr<Angajat>Ang);

    virtual std::shared_ptr<Departament> clone() const = 0;

    friend std::ostream &operator<<(std::ostream &afisare, const Departament &departament);

    virtual float CalculareProcentReusitaDepartament() const = 0;

    virtual  ~Departament() = default;

    virtual void ConcediereAngajatiIneficienti() = 0;

    std::vector<std::shared_ptr<Angajat>> GetVectAng() const;

    std::shared_ptr<Angajat> AfisareAngajatDupaNume(const string &nume);


    string GetNumeDepartament() const {
        return NumeDepartament;
    }


protected:
    Departament &operator=(const Departament &altul);

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

    float CalculareProcentReusitaDepartament() const override;



   void SetProfitDepartament();
   void SetNrTaskuriTotale();
   void ConcediereAngajatiIneficienti() override;



};

class DepartamentRelatiiClienti : public Departament {
    int Target;


    void afisare(std::ostream &afis) const override;

public:
    DepartamentRelatiiClienti(const std::string &NumeDepartament,
                              const std::vector<std::shared_ptr<Angajat>> &AngajatiDepartamente, int Target);


    std::shared_ptr<Departament> clone() const override;

    float CalculareProcentReusitaDepartament() const override;

    void ConcediereAngajatiIneficienti() override;




};




#endif //OOP_DEPARTAMENTE_H
