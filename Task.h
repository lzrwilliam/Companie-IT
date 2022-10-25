//
// Created by lazar on 10/25/2022.
//

#ifndef OOP_TASK_H
#define OOP_TASK_H

#include <iostream>
#include  <vector>
#include <ctime>

using std::cout;
using std::string;


class Task {
    int IdTask;
    string DenumireTask;
    string Angajat; // cine se ocupa de task-ul respectiv
    float ProfitTask = 0;
    bool StatusTask = 0;
    // time_t DeadLine;
public:
    Task(int IdTask, const string &DenumireTask, const string &Angajat, float ProfitTask, bool StatusTask);


    Task(const Task &other);

    friend std::ostream &operator<<(std::ostream &cout, const Task &task);

    Task &operator=(const Task &other);


    ~Task() {}
};


#endif //OOP_TASK_H
