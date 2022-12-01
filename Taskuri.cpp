//
// Created by lazar on 12/1/2022.
//

#include "Taskuri.h"


std::ostream &operator<<(std::ostream &afis, const Task &task) {
    afis << "Numele task-ului: " << task.DenumireTask << '\n';
    afis << "Valoare task: " << task.DenumireTask << '\n';
    task.afisare(afis);
    afis << '\n';
    return afis;

}

Task::Task(string Denumire, float Valoare) : DenumireTask(Denumire), ValoareTask(Valoare) {}
