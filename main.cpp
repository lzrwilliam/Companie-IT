#include <iostream>
#include  <vector>
#include <ctime>
#include "Companie.h"
#include "Departamente.h"
#include "Angajat.h"
#include "Taskuri.h"
#include <memory>

int main() {

//std::vector<std::shared_ptr<Departament>>Departamente;
//auto d=std::make_shared<DepartamenteTehnice>("hr");
//    Departamente.push_back(d);
//    Companie c1("IBM",Departamente);
//
//    cout<<c1;

    NetworkEngineer n("William", 100, 1, 1, 3, 4);
    OperatorCallCenter n1("William12", 0, 1, 1, 1, 1);
    DepartamenteTehnice d1("Retele", {n.clone(), n1.clone()}, 100, 3);
    DepartamentRelatiiClienti d3("Call Center", {n1.clone()}, 5);


    //cout << d3;

    TaskRetelistica t1("Dd", 2, 3, 2022, true, 2, 2,900);
cout << t1;

    return 0;
}