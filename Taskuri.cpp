//
// Created by lazar on 12/1/2022.
//

#include "Taskuri.h"

#include <utility>


std::ostream &operator<<(std::ostream &afis, const Task &task) {
    afis << "Numele task-ului: " << task.DenumireTask << '\n';
    afis << "Valoare task: " << task.ValoareTask << '\n';
    afis << "Data deadline: " << ConvertireData(task.Deadline);
    afis << "Status task:" << task.Status << '\n';
    task.afisare(afis);
    afis << '\n';
    return afis;

}

Task::Task(string Denumire, float Valoare, int zi, int luna, int an, bool Status) : DenumireTask(std::move(Denumire)),
                                                                                    ValoareTask(Valoare),
                                                                                    Status(Status) {

    std::tm tm = {};
    tm.tm_year = an - 1900;
    tm.tm_mon = luna - 1;
    tm.tm_mday = zi;
    std::time_t time1 = mktime(&tm);
    Deadline = time1;
}

shared_ptr<Task> TaskRetelistica::clone() const {
    return std::make_shared<TaskRetelistica>(*this);
}

TaskRetelistica::TaskRetelistica(string Denumire, float Valoare, int zi, int luna, int an, bool Status,
                                 int NrEchipinMentenanta,
                                 int NrReteleimplicate) : Task(std::move(Denumire), Valoare, zi, luna, an, Status),
                                                          NrEchipInMentenanta(NrEchipinMentenanta),
                                                          ReteleImplicate(NrReteleimplicate) {

}


void TaskRetelistica::afisare(std::ostream &afis) const {

    afis << "Echipamente in mentenanta : " << NrEchipInMentenanta << '\n';
    afis << "Retele implicate: " << ReteleImplicate << '\n';
    afis << '\n';

}


