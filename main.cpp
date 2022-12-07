#include <iostream>
#include  <vector>
#include <ctime>
#include "Companie.h"
#include "Departamente.h"
#include "Angajat.h"
#include "Taskuri.h"
#include <memory>

int main() {

//
//    TaskRetelistica n2("Configurare switch1",10,10,2020, true,3,3,2);
//    TaskRetelistica n3("Configurare switch",10,10,2023, false,3,3,90000);
//    //std::shared_ptr<TaskRetelistica>n= std::make_shared<TaskRetelistica>("Configurare switch",10,10,2020,true,3,3,2);
//    NetworkEngineer n1("William",{n2.clone(),n3.clone()},500,0,5,0,0);
//    DepartamenteTehnice d1("Cisco",{n1.clone()},0,0);
//    n2.SetStatusTask();
//    n3.SetStatusTask();
//    // d1.SetNrTaskuriTotale();
//    //  d1.SetProfitDepartament();
////    cout<<d1.CalculeazaPierderiDepartament();
//
//    cout<<n2;
//   // cout<<d1;



std::vector<std::shared_ptr<Task>> TaskuriAng1;
std::shared_ptr<Task>t1 = std::make_shared<TaskRetelistica>("Configurare Router",10,10,2020,true,0,0,100);
TaskuriAng1.emplace_back(t1);
std::shared_ptr<NetworkEngineer>n123= std::make_shared<NetworkEngineer>("William",TaskuriAng1,1,1,1,0,0);
DepartamenteTehnice d123("csico",{n123},0,0);
t1->SetStatusTask();
cout<<d123;
return 0;
}