//
// Created by lazar on 12/1/2022.
//

#include "Taskuri.h"

#include <utility>


std::ostream &operator<<(std::ostream &afis, const Task &task) {
    afis << "Numele task-ului: " << task.DenumireTask << '\n';
  //  afis << "Valoare task: " << task.ValoareTask << '\n';
    afis << "Data deadline: " << ConvertireData(task.Deadline);
    afis << "Status task:" << task.Status << '\n';
    task.afisare(afis);
    afis << '\n';
    return afis;

}

Task::Task(string Denumire, int zi, int luna, int an, bool Status) : DenumireTask(std::move(Denumire)),
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

TaskRetelistica::TaskRetelistica(string Denumire, int zi, int luna, int an, bool Status,
                                 int NrEchipinMentenanta,
                                 int NrReteleimplicate,float  ValoareTask) : Task(std::move(Denumire), zi, luna, an, Status),
                                                          NrEchipInMentenanta(NrEchipinMentenanta),
                                                          ReteleImplicate(NrReteleimplicate),ValoareTask(ValoareTask) {

}


void TaskRetelistica::afisare(std::ostream &afis) const {

    afis << "Echipamente in mentenanta : " << NrEchipInMentenanta << '\n';
    afis << "Retele implicate: " << ReteleImplicate << '\n';
    afis<<"Valoare task:"<<ValoareTask<<'\n';
    afis << '\n';

}


TaskRelatiiClienti::TaskRelatiiClienti(string Denumire, int zi, int luna, int an, bool Status,int ImportantaApel):
        Task(std::move(Denumire), zi, luna, an, Status),ImportantaApel(ImportantaApel)

{

}

shared_ptr<Task> TaskRelatiiClienti::clone() const {
    return std::make_shared<TaskRelatiiClienti>(*this);
}

void TaskRelatiiClienti::afisare(std::ostream &afis) const {

    afis<<"Apelul valoreaza cat "<<ImportantaApel<<" apeluri!";
    afis<<'\n';

}
