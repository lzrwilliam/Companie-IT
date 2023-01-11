//
// Created by lazar on 11/30/2022.
//

#ifndef OOP_ANGAJAT_H
#define OOP_ANGAJAT_H

#include <iostream>
#include <memory>
#include "Taskuri.h"
#include <vector>
#include "Exceptii.h"
using std::string;

class Angajat {

    string NumeAngajat;
protected:
    std::vector<std::shared_ptr<Task>>TaskAng;

    float Salariu;
    int PenalizariPentruTaskuriIntarziate; /// la 3 penalizari stergem angajatul din departament, il dam afara
protected:
    virtual void afisare(std::ostream &) const {}
    static int Id;
    const int IdAngajat;


public:
    Angajat(const string &nume, const std::vector<std::shared_ptr<Task>> &TaskAng, float salariu, int Penalizari);

    virtual std::shared_ptr<Angajat> clone() const = 0;

    friend std::ostream &operator<<(std::ostream &afis, const Angajat &angajat);

    int GetSizeOfVectTaskAng() const;

    virtual ~Angajat() = default;

    void AdaugaTask(const std::shared_ptr<Task> TaskAng1);

    int GetPenalizari() const;

    string GetNume() const;

    // int GetId();
    virtual void ApelareComenzi() = 0;


    std::vector<std::shared_ptr<Task>> GetVectorTaskAng() const;

    //void RezolvaTask();


protected:
    Angajat &operator=(const Angajat &altul);

    Angajat(const Angajat &other);

    virtual void MarireSalariu() = 0;

    void SetPenalizariTaskIntarziat();
};

class NetworkEngineer : public Angajat {
    int ReteleRezolvate;
    int EchipamenteDistruse;
    int ClientiNemultumiti; // daca task-ul e rezolvat  in ultimele 2 zile  clientul nu este multumit


    void afisare(std::ostream &afis) const override;

protected:
    void SetEchipDistruseReteleRez();

    void SetClientiNemultumiti();

    void MarireSalariu() override;


public:
    explicit NetworkEngineer(const string &Nume, const std::vector<std::shared_ptr<Task>> &TaskAng, float Salariu = 400,
                             int Penalizari = 0, int ReteleRez = 0,
                             int EchipamenteDis = 0,
                             int ClientiMultu = 0);

    std::shared_ptr<Angajat> clone() const override;

    int GetNrEchipDis() const;

    int GetReteleRez() const;



    void ApelareComenzi() override;


};

class OperatorCallCenter : public Angajat {
    int NrApeluriPeUltimaLuna; // functie sa calculez nr asta din task-uri
    int NrPentruTargetLunar;// nr minim pe care trebuie sa il aiba de apeluri, de preluat de la departamentu angajatului
    float ProcentTarget; //cat a indeplinit din target
    void afisare(std::ostream &afis) const override;

public:
    std::shared_ptr<Angajat> clone() const override;

    explicit OperatorCallCenter(const string& Nume, const std::vector<std::shared_ptr<Task>>&TaskAng,float Salariu = 400, int Penalizari = 0, int NrApeluriPeUltimaLuna = 0,
                                int NrPentruTargetLunar = 0, float ProcentTarget = 0);

    void MarireSalariu() override;

void SetNrTargetLunar(int x);
    void SetNrApeluri();
    void SetProcentTargetRealizat();
    void ApelareComenzi() override;

};



#endif //OOP_ANGAJAT_H
