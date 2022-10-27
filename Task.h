//
// Created by lazar on 10/25/2022.
//

#ifndef OOP_TASK_H
#define OOP_TASK_H

#include <iostream>
#include  <vector>
#include <ctime>
#include "AlteFunctii.h"

using std::cout;
using std::string;


class Task {
    int IdTask;
    string DenumireTask;
    float ProfitTask = 0;
    bool StatusTask = 0;
   time_t Deadline;

public:
    Task(int IdTask, const string &DenumireTask,

         float ProfitTask,
         bool StatusTask,
         int an,
         int luna,
         int zi
    );


    Task(const Task &other);

    friend std::ostream &operator<<(std::ostream &cout, const Task &task);

    friend class Angajat;

    Task &operator=(const Task &other);


    ~Task() {}
};


#endif //OOP_TASK_H
