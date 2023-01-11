#include <iostream>
#include  <vector>
#include "Companie.h"
#include "Departamente.h"
#include "Angajat.h"
#include "Taskuri.h"
#include <memory>
#include "Exceptii.h"

int main() {

    std::vector<std::shared_ptr<Task>> TaskuriAngajat;

    auto Task1 = TaskRetelistica("Configurare router", 10, 10, 2020, 5, 10, 500).clone();
    auto Task2 = TaskRetelistica("Inlocuire switch", 10, 10, 2021, 1, 24, 200).clone();
    auto Task3 = TaskRetelistica("Schimbare placa de retea", 10, 12, 2020, 5, 10,
                                 99).clone();
    TaskuriAngajat.emplace_back(Task1);
    TaskuriAngajat.emplace_back(Task2);
    TaskuriAngajat.emplace_back(Task3);
    auto AngajatNet1 = NetworkEngineer("William1", TaskuriAngajat, 5000, 0, 0, 0).clone();

    TaskuriAngajat.clear();

    auto Task4 = TaskRetelistica("Configurare router", 10, 10, 2020, 5, 10, 500).clone();
    auto Task5 = TaskRetelistica("Inlocuire switch", 10, 10, 2023, 1, 24, 200).clone();
    auto Task6 = TaskRetelistica("Schimbare placa de retea", 10, 12, 2023, 5, 10,
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

    try {
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


        auto c1 = Companie("Indeco GROUP", {d1.clone(), d2.clone()});

        c1.ManagementDepartamente();


        try {
            d1.AdaugaAngajat(AngajatNet2);

            cout << d1;

        } catch (ResursaLipsa &err) { std::cout << err.what() << '\n'; }
        d1.AfisareAngajatDupaNume("Catalin");


        cout << d1 << d2;


    }

    catch (ArgumentInvalid &err) {
        std::cout << err.what();
    }
    catch (ResursaLipsa &err) {
        std::cout << err.what();

    }
    catch (EroareAplicatie &err) {
        std::cout << err.what();
    }


}


