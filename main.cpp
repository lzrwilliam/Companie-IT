#include <iostream>
#include  <vector>
#include "Companie.h"
#include "Departamente.h"
#include "Angajat.h"
#include "Taskuri.h"
#include <memory>

int main() {

std::vector<std::shared_ptr<Task>> TaskuriAng1;

std::shared_ptr<Task>t1 = std::make_shared<TaskRetelistica>("Configurare Router",9,12,2020, false,false,1,1,100);
    std::shared_ptr<Task>t2 = std::make_shared<TaskRetelistica>("Configurare Router",9,12,2020, false,false,1,1,100);
    std::shared_ptr<Task>t3 = std::make_shared<TaskRetelistica>("Configurare Router",9,12,2020, false,false,1,1,100);

    TaskuriAng1.emplace_back(t1);
    TaskuriAng1.emplace_back(t2);
    TaskuriAng1.emplace_back(t3);

    std::shared_ptr<Task>t234 = std::make_shared<TaskRetelistica>("Configurare Router",9,12,2022, false,false,1,1,100);

    std::shared_ptr<NetworkEngineer>n123= std::make_shared<NetworkEngineer>("William",TaskuriAng1,1,1,1,0,0);

    DepartamenteTehnice d123("csico",{n123},0,4);
n123->SetPenalizariTaskIntarziat();
d123.SetNrTaskuriTotale();
d123.AfisareProcentReusitaDepartament();
t1->SetStatusTask();
n123->SetClientiNemultumiti();
cout<<d123;
return 0;
}