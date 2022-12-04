#include <iostream>
#include  <vector>
#include <ctime>
#include "Companie.h"
#include "Departamente.h"
#include "Angajat.h"
#include "Taskuri.h"
#include <memory>

int main() {

    TaskRetelistica t1("Dd", 2, 3, 2022, true, 2, 2,900);
   // TaskRelatiiClienti t2("Recuperat bani",3,4,2005,false,3);
TaskRetelistica t2("Task principal",2,3,2002,true,2,3,1);

//    std::shared_ptr<Task>Ttest=t2.clone();
//   Ttest=t1.clone();
//   cout<<*Ttest;
   NetworkEngineer n("William",{t1.clone()}, 100, 1, 1, 3, 4);
  //  NetworkEngineer n2("Williamdasda",{t1.clone()}, 100, 1, 1, 3, 4);
n.AdaugaTask(t2.clone());
      OperatorCallCenter n1("Andreea",{t2.clone()},100,1,1,1,1);


    DepartamenteTehnice d1("Retele", {n.clone()}, 100, 3);
  //  DepartamentRelatiiClienti d3("Call Center", {n1.clone()}, 5);
   // Companie c1("Cisco",{d1.clone()});

   d1.AdaugaAngajat(n1.clone());
cout<<d1;
//cout << t2;
//cout<<n;

    return 0;
}