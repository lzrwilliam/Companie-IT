//
// Created by lazar on 11/30/2022.
//

#ifndef OOP_ANGAJAT_H
#define OOP_ANGAJAT_H

#include <iostream>
#include <memory>

using std::string;

class Angajat {

    string NumeAngajat;
    float Salariu;
    int PenalizariPentruTaskuriIntarziate;

    // vect task-uri
    virtual void afisare(std::ostream &) const {}


public:
    Angajat(const string &nume, float salariu, int Penalizari);

    virtual std::shared_ptr<Angajat> clone() const = 0;

    friend std::ostream &operator<<(std::ostream &afis, const Angajat &angajat);

    virtual ~Angajat() = default;

protected:
    Angajat &operator=(const Angajat &other) = default; // trebuie cu swap daca o sa fac cu pointeri
    Angajat(const Angajat &other) = default;

};

class NetworkEngineer : public Angajat {
    int ReteleRezolvate;
    int EchipamenteDistruse;
    int ClientiMultumiti;


    void afisare(std::ostream &afis) const override;


public:
  explicit NetworkEngineer(string Nume, float Salariu = 400, int Penalizari = 0, int ReteleRez = 0,
                           int EchipamenteDis = 0,
                           int ClientiMultu = 0);

    std::shared_ptr<Angajat> clone() const override;


};

class OperatorCallCenter : public Angajat {
    int NrApeluriPeUltimaLuna; // functie sa calculez nr asta din task-uri
    int NrPentruTargetLunar;// nr minim pe care trebuie sa il aiba de apeluri
    float ProcentTarget; //cat a indeplinit din target
//vect task-uri o sa trebuiasca operator = cu swap
    void afisare(std::ostream &afis) const override;

public:
    std::shared_ptr<Angajat> clone() const override;

    explicit OperatorCallCenter(string Nume, float Salariu = 400, int Penalizari = 0, int NrApeluriPeUltimaLuna = 0,
                                int NrPentruTargetLunar = 0, float ProcentTarget = 0);


};


#endif //OOP_ANGAJAT_H
