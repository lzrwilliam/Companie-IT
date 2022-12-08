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

    std::shared_ptr<TaskRetelistica>Task1=std::make_shared<TaskRetelistica>("Configurare router",10,10,2020,false,false,5,10,500);
    std::shared_ptr<TaskRetelistica>Task2=std::make_shared<TaskRetelistica>("Inlocuire switch",10,10,2021,true,true,1,24,200);
    std::shared_ptr<TaskRetelistica>Task3=std::make_shared<TaskRetelistica>("Schimbare placa de retea",10,12,2020,true,true,5,10,99);
 TaskuriAngajat.emplace_back(Task1);TaskuriAngajat.emplace_back(Task2);TaskuriAngajat.emplace_back(Task3);
    std::shared_ptr<NetworkEngineer>AngajatNet1=std::make_shared<NetworkEngineer>("William",TaskuriAngajat,5000,0,0,0);

    TaskuriAngajat.clear();

    std::shared_ptr<TaskRetelistica>Task4=std::make_shared<TaskRetelistica>("Configurare router",10,10,2020,false,false,5,10,500);
    std::shared_ptr<TaskRetelistica>Task5=std::make_shared<TaskRetelistica>("Inlocuire switch",10,10,2020,false,false,1,24,200);
    std::shared_ptr<TaskRetelistica>Task6=std::make_shared<TaskRetelistica>("Schimbare placa de retea",10,12,2020,false,false,5,10,99);
    TaskuriAngajat.emplace_back(Task4);TaskuriAngajat.emplace_back(Task5);TaskuriAngajat.emplace_back(Task6);
    std::shared_ptr<NetworkEngineer>AngajatNet2=std::make_shared<NetworkEngineer>("William",TaskuriAngajat,5000,0,0,0);

    TaskuriAngajat.clear();


    std::shared_ptr<TaskRelatiiClienti>TaskRel1=std::make_shared<TaskRelatiiClienti>("Convins client sa vina sa semneze",10,10,2010,false,false,100);
    std::shared_ptr<TaskRelatiiClienti>TaskRel2=std::make_shared<TaskRelatiiClienti>("Lamurire problema client",10,10,2010,false,false,300);
    std::shared_ptr<TaskRelatiiClienti>TaskRel3=std::make_shared<TaskRelatiiClienti>("Recuperat echipamente",10,2,2010,false,false,3000);
    TaskuriAngajat.emplace_back(TaskRel1);TaskuriAngajat.emplace_back(TaskRel2);TaskuriAngajat.emplace_back(TaskRel3);
    std::shared_ptr<OperatorCallCenter> AngajatCall1=std::make_shared<OperatorCallCenter>("Turis",TaskuriAngajat,10000,0,0,0,0);



    TaskuriAngajat.clear();


    std::shared_ptr<TaskRelatiiClienti>TaskRel4=std::make_shared<TaskRelatiiClienti>("Convins client sa vina sa semneze",10,10,2010,true,true,100);
    std::shared_ptr<TaskRelatiiClienti>TaskRel5=std::make_shared<TaskRelatiiClienti>("Lamurire problema client",10,10,2010,true,true,300);
    std::shared_ptr<TaskRelatiiClienti>TaskRel6=std::make_shared<TaskRelatiiClienti>("Recuperat echipamente",10,2,2010,true,true,3000);
    TaskuriAngajat.emplace_back(TaskRel4);TaskuriAngajat.emplace_back(TaskRel5);
    std::shared_ptr<OperatorCallCenter> AngajatCall2=std::make_shared<OperatorCallCenter>("Catalin",TaskuriAngajat,10000,0,0,0,0);
    AngajatCall2->AdaugaTask(TaskRel6);

DepartamenteTehnice d1("Cisco",{AngajatNet1,AngajatNet2},0,0);
DepartamentRelatiiClienti d2("HR",{AngajatCall2,AngajatCall1},30);
   // Companie c1("Companie privata",);

   for(auto &angajat:d1.GetVectAng()){
       angajat->ApelareComenzi();
   }
    for(auto &angajat:d2.GetVectAng()){
        angajat->ApelareComenzi();
    }


    d1.ConcediereAngajatiIneficienti();
   d1.SetProfitDepartament();
   d1.SetNrTaskuriTotale();
   d1.AfisareProcentReusitaDepartament();
   try{
   d1.AdaugaAngajat(AngajatNet2);} catch(EroarePointer &err){std::cout<<err.what()<<'\n';}
   d1.AfisareAngajatDupaNume("Tudor");


cout<<d1<<d2;



}
catch(EroareLaConstructor &err){
    std::cout<<err.what();
}
catch (EroarePointer &err){
    std::cout<<err.what();}



}
