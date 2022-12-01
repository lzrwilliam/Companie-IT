//
// Created by lazar on 11/30/2022.
//

#include "Angajat.h"

Angajat::Angajat(const string &nume, float salariu, int Penalizari) : NumeAngajat(nume), Salariu(salariu),
                                                                      PenalizariPentruTaskuriIntarziate(Penalizari) {

}

std::ostream &operator<<(std::ostream &afis, const Angajat &angajat) {
    afis << "Numele angajatului: " << angajat.NumeAngajat << '\n';
    afis << "Salariul:" << angajat.Salariu << '\n';
    afis << "Penalitati:" << angajat.PenalizariPentruTaskuriIntarziate << '\n';
    angajat.afisare(afis);
    return afis;
}

NetworkEngineer::NetworkEngineer(string Nume, float Salariu, int Penalizari, int ReteleRez, int EchipamenteDis,
                                 int ClientiMultu) : Angajat(Nume, Salariu, Penalizari),
                                                     ReteleRezolvate(ReteleRez), EchipamenteDistruse(EchipamenteDis),
                                                     ClientiMultumiti(ClientiMultu) {

}

std::shared_ptr<Angajat> NetworkEngineer::clone() const {
    return std::make_shared<NetworkEngineer>(*this);
}

void NetworkEngineer::afisare(std::ostream &afis) const {
    afis << "Nr de retele rezolvate: " << ReteleRezolvate << '\n';
    afis << "Echipamente Distruse:" << EchipamenteDistruse << '\n';
    afis << "Clienti care s-au declarat multumiti: " << ClientiMultumiti << '\n';
}

void OperatorCallCenter::afisare(std::ostream &afis) const {
    afis << "Apelurile din ultima luna: " << NrApeluriPeUltimaLuna << '\n';
    afis << "NrNecesarPtTarget:" << NrPentruTargetLunar << '\n';
    afis << "Procentul realizat din target: " << ProcentTarget << '\n';
}

std::shared_ptr<Angajat> OperatorCallCenter::clone() const {
    return std::make_shared<OperatorCallCenter>(*this);
}

OperatorCallCenter::OperatorCallCenter(string Nume, float Salariu, int Penalizari, int NrApeluriPeUltimaLuna,
                                       int NrPentruTargetLunar, float ProcentTarget) : Angajat(Nume, Salariu,
                                                                                               Penalizari),
                                                                                       NrApeluriPeUltimaLuna(
                                                                                               NrApeluriPeUltimaLuna),
                                                                                       NrPentruTargetLunar(
                                                                                               NrPentruTargetLunar),
                                                                                       ProcentTarget(ProcentTarget) {}
