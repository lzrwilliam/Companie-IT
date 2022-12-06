//
// Created by lazar on 11/30/2022.
//

#ifndef OOP_ANGAJAT_H
#define OOP_ANGAJAT_H

#include <iostream>
#include <memory>
#include "Taskuri.h"
#include <vector>
using std::string;

class Angajat {

    string NumeAngajat;
    std::vector<std::shared_ptr<Task>>TaskAng;
    float Salariu;
    int PenalizariPentruTaskuriIntarziate;
    virtual void afisare(std::ostream &) const {}
    static int Id;
    const int IdAngajat;


public:
    Angajat(const string &nume,const std::vector<std::shared_ptr<Task>>&TaskAng ,float salariu, int Penalizari);

    virtual std::shared_ptr<Angajat> clone() const = 0;

    friend std::ostream &operator<<(std::ostream &afis, const Angajat &angajat);

    string getnumeangajat(){return NumeAngajat;}
    virtual ~Angajat() = default;
    void AdaugaTask(const std::shared_ptr<Task>TaskAng1);

protected:
    Angajat &operator=(const Angajat &altul);

    Angajat(const Angajat &other);

};

class NetworkEngineer : public Angajat {
    int ReteleRezolvate;
    int EchipamenteDistruse;
    int ClientiMultumiti;


    void afisare(std::ostream &afis) const override;


public:
  explicit NetworkEngineer(const string &Nume, const std::vector<std::shared_ptr<Task>>&TaskAng,float Salariu = 400, int Penalizari = 0, int ReteleRez = 0,
                           int EchipamenteDis = 0,
                           int ClientiMultu = 0);

    std::shared_ptr<Angajat> clone() const override;

    int getnrretele(){return ReteleRezolvate;}




};

class OperatorCallCenter : public Angajat {
    int NrApeluriPeUltimaLuna; // functie sa calculez nr asta din task-uri
    int NrPentruTargetLunar;// nr minim pe care trebuie sa il aiba de apeluri
    float ProcentTarget; //cat a indeplinit din target
    void afisare(std::ostream &afis) const override;

public:
    std::shared_ptr<Angajat> clone() const override;

    explicit OperatorCallCenter(const string& Nume, const std::vector<std::shared_ptr<Task>>&TaskAng,float Salariu = 400, int Penalizari = 0, int NrApeluriPeUltimaLuna = 0,
                                int NrPentruTargetLunar = 0, float ProcentTarget = 0);


};


#endif //OOP_ANGAJAT_H
