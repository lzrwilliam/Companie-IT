//
// Created by lazar on 10/27/2022.
//

#ifndef OOP_ALTEFUNCTII_H
#define OOP_ALTEFUNCTII_H
#include <iostream>
#include <ctime>
#include "time.h"
#include <cstdio>


char * ConvertireData(const time_t time1);
std::tm CreazaData(int zi,int luna,int an);
time_t  ObtineDataCurentaPentruDiferenta();
#endif //OOP_ALTEFUNCTII_H
