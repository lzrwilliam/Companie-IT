//
// Created by lazar on 12/7/2022.
//

#ifndef OOP_EXCEPTII_H
#define OOP_EXCEPTII_H
#include <stdexcept>
#include <string>
#include <vector>
class EroareAplicatie:public std::runtime_error{

    using std::runtime_error::runtime_error;
};
class EroareLaConstructor:public EroareAplicatie{

public:
    explicit  EroareLaConstructor(const std::string &string ):EroareAplicatie("Eroare la constructor:"+ string){}
};

#endif //OOP_EXCEPTII_H
