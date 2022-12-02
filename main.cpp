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
    TaskRelatiiClienti t2("Recuperat bani",3,4,2005,false,3);


//    std::shared_ptr<Task>Ttest=t2.clone();
//    Ttest=t1.clone();
//    cout<<*Ttest;
  //  NetworkEngineer n("William",{t1.clone(),t2.clone()}, 100, 1, 1, 3, 4);
    //OperatorCallCenter n1("William12", 0, 1, 1, 1, 1);

  //  DepartamenteTehnice d1("Retele", {n.clone(), n1.clone()}, 100, 3);
  //  DepartamentRelatiiClienti d3("Call Center", {n1.clone()}, 5);
   // Companie c1("Cisco",{d1.clone(),d3.clone()});


//cout << t2;
//cout<<n;

    return 0;
}