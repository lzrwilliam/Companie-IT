#include <iostream>
#include  <vector>
#include <ctime>
#include "Companie.h"
#include "Departamente.h"
#include "Angajat.h"

#include <memory>

int main() {

//std::vector<std::shared_ptr<Departament>>Departamente;
//auto d=std::make_shared<DepartamenteTehnice>("hr");
//    Departamente.push_back(d);
//    Companie c1("IBM",Departamente);
//
//    cout<<c1;

    NetworkEngineer n("William", 100, 1, 1, 3, 4);
//cout<<n;
    OperatorCallCenter n1("William12", 0, 1, 1, 1, 1);

    DepartamenteTehnice d1("Retele", 100, 3, {n.clone(), n1.clone()});
    cout << d1;


    return 0;
}