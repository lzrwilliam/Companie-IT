//
// Created by lazar on 12/1/2022.
//

#ifndef OOP_ALTEFUNCTII_H
#define OOP_ALTEFUNCTII_H


#include <iostream>
#include <ctime>
#include <cstdio>


char *ConvertireData(const time_t time1);

//std::tm CreazaData(int zi, int luna, int an);

time_t DataCurenta();

bool DiferentaIntreDouaDati(time_t t1,time_t t2);
float DiferentaIntreDouaDatiInZile(time_t t1,time_t t2);



#endif //OOP_ALTEFUNCTII_H
