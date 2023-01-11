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


class ArgumentInvalid : public EroareAplicatie {

public:
    explicit ArgumentInvalid(const std::string &string) : EroareAplicatie("Eroare la constructor:" + string) {}
};

class ResursaLipsa : public EroareAplicatie {
public:
    explicit ResursaLipsa(const std::string &string) : EroareAplicatie("Problema la pointer: " + string) {}
};

class PointerInvalid : public EroareAplicatie {
public:
    explicit PointerInvalid(const std::string &string) : EroareAplicatie("Pointerul nu exista : " + string) {}
};

#endif //OOP_EXCEPTII_H
