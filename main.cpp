#include <iostream>
#include  <vector>
//#include "Companie.h"
#include "Departamente.h"
#include "Angajat.h"
#include "Taskuri.h"
#include <memory>
#include "Exceptii.h"

int main() {
try {
    std::vector<std::shared_ptr<Task>> TaskuriAngajat;

    auto Task1 = TaskRetelistica("Configurare router", 10, 10, 2020, 5, 10, 500).clone();
    auto Task2 = TaskRetelistica("Inlocuire switch", 10, 10, 2021, 1, 24, 200).clone();
    auto Task3 = TaskRetelistica("Schimbare placa de retea", 10, 12, 2020, 5, 10,
                                 99).clone();
    TaskuriAngajat.emplace_back(Task1);
    TaskuriAngajat.emplace_back(Task2);
    TaskuriAngajat.emplace_back(Task3);
    // std::shared_ptr<Angajat> AngajatNet1 = std::make_shared<NetworkEngineer>("William", TaskuriAngajat, 5000, 0, 0, 0);
    auto AngajatNet1 = NetworkEngineer("William", TaskuriAngajat, 5000, 0, 0, 0).clone();

    TaskuriAngajat.clear();

    auto Task4 = TaskRetelistica("Configurare router", 10, 10, 2020, 5, 10, 500).clone();
    auto Task5 = TaskRetelistica("Inlocuire switch", 10, 10, 2020, 1, 24, 200).clone();
    auto Task6 = TaskRetelistica("Schimbare placa de retea", 10, 12, 2020, 5, 10,
                                 99).clone();
    TaskuriAngajat.emplace_back(Task4);
    TaskuriAngajat.emplace_back(Task5);
    TaskuriAngajat.emplace_back(Task6);
    auto AngajatNet2 = NetworkEngineer("William", TaskuriAngajat, 5000, 0, 0, 0).clone();

    TaskuriAngajat.clear();


    auto TaskRel1 = TaskRelatiiClienti("Convins client sa vina sa semneze", 10, 10,
                                       2010, 100).clone();
    auto TaskRel2 = TaskRelatiiClienti("Lamurire problema client", 10, 10, 2010,
                                       300).clone();
    auto TaskRel3 = TaskRelatiiClienti("Recuperat echipamente", 10, 2, 2010, 3000).clone();
    TaskuriAngajat.emplace_back(TaskRel1);
    TaskuriAngajat.emplace_back(TaskRel2);
    TaskuriAngajat.emplace_back(TaskRel3);
    auto AngajatCall1 = OperatorCallCenter("Turis", TaskuriAngajat, 10000, 0, 0,
                                           0, 0).clone();


    TaskuriAngajat.clear();


    auto TaskRel4 = TaskRelatiiClienti("Convins client sa vina sa semneze", 10, 10,
                                       2010, 100).clone();
    auto TaskRel5 = TaskRelatiiClienti("Lamurire problema client", 10, 10, 2010,
                                       300).clone();
    auto TaskRel6 = TaskRelatiiClienti("Recuperat echipamente", 10, 2, 2010, 3000).clone();
    TaskuriAngajat.emplace_back(TaskRel4);
    TaskuriAngajat.emplace_back(TaskRel5);
    auto AngajatCall2 = OperatorCallCenter("Catalin", TaskuriAngajat, 10000, 0, 0,
                                           0, 0).clone();
    AngajatCall2->AdaugaTask(TaskRel6);

    DepartamenteTehnice d1("Cisco", {AngajatNet1, AngajatNet2}, 0, 0);
    DepartamentRelatiiClienti d2("HR", {AngajatCall2, AngajatCall1}, 30);


    //  std::vector<std::shared_ptr<Angajat>> Ang;
//   Ang.emplace_back(AngajatNet1);
    // Ang.emplace_back(AngajatNet2);



    for (auto &angajat: d1.GetVectAng()) {
        angajat->ApelareComenzi();
    }
    for (auto &angajat: d2.GetVectAng()) {
        angajat->ApelareComenzi();
    }


     d1.ConcediereAngajatiIneficienti();
    d1.SetProfitDepartament();
    d1.SetNrTaskuriTotale();

    cout << "Procentul de reusita al departamentului " << d1.GetNumeDepartament() << " este de : "
         << d1.CalculareProcentReusitaDepartament() << "% \n";
    try {
        d1.AdaugaAngajat(AngajatNet2);
        //  cout<<d1;

    } catch (EroarePointer &err) { std::cout << err.what() << '\n'; }
    d1.AfisareAngajatDupaNume("Catalin");


    cout << d1 << d2;


}
catch(EroareLaConstructor &err){
    std::cout<<err.what();
}
catch (EroarePointer &err) {
    std::cout << err.what();

}


}


//// de facyt functie pt setat status task!!!