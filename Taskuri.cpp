//
// Created by lazar on 12/1/2022.
//

#include "Taskuri.h"

#include <utility>


int Task::Id=1;

std::ostream &operator<<(std::ostream &afis, const Task &task) {
    afis<<"Id task:"<<task.IdTask<<'\n';
    afis << "Numele task-ului: " << task.DenumireTask << '\n';
    afis << "Data deadline: " << ConvertireData(task.Deadline);
    afis << "Status task:" << task.StatusCurent << '\n';
    afis<<"Taskul a fost terminat?: "<<task.Terminat<<'\n';
    task.afisare(afis);
    afis << '\n';
    return afis;

}

Task::Task(string Denumire, int zi, int luna, int an, bool StatusCurent,bool Terminat) : DenumireTask(std::move(Denumire)),
                                                                                    StatusCurent(StatusCurent),Terminat(Terminat),IdTask(Id) { Id++;

    std::tm tm = {};
    tm.tm_year = an - 1900;
    tm.tm_mon = luna - 1;
    tm.tm_mday = zi;
    std::time_t time1 = mktime(&tm);
    Deadline = time1;
    
    ApelareFunctiiTask();
}

Task &Task::operator=(const Task &altul) {
    auto copie=altul.clone();
    DenumireTask=altul.DenumireTask;
    Deadline=altul.Deadline;
    StatusCurent= altul.StatusCurent;
    Terminat=altul.Terminat;
    return *this;
}

void Task::SetStatusTask() {
    if(DiferentaIntreDouaDati(DataCurenta(), Deadline)== false && this->GetTerminatTask()== false)
        StatusCurent= false;

}

 bool Task::GetStatusTask() const {
     return StatusCurent;
 }

time_t Task::GetDeadlineTask() const {
    return Deadline;
}

bool Task::GetTerminatTask() const {
    return Terminat;
}

void Task::SetTerminatTask() {
    if ((StatusCurent == true && Terminat == false) &&
        DiferentaIntreDouaDati(DataCurenta(), Deadline) == false) { StatusCurent = false; }  // terminat dupa deadline
    if (StatusCurent == false && DiferentaIntreDouaDati(DataCurenta(), Deadline) == false) Terminat = false;
    if (StatusCurent == true && DiferentaIntreDouaDati(DataCurenta(), Deadline)) Terminat = true;
    // am acoperit cazul in care angajatul terminat task-ul dupa data de deadline, pentru a putea face diferenta intre cele terminate la timp si cu intarziere

}

void Task::SetTask() {

    StatusCurent = true;
}

void Task::ApelareFunctiiTask() {
    SetTask();
    SetStatusTask();
    SetTerminatTask();

}

int Task::GetIdTask() const {
    return IdTask;
}

shared_ptr<Task> TaskRetelistica::clone() const {
    return std::make_shared<TaskRetelistica>(*this);
}

TaskRetelistica::TaskRetelistica(string Denumire, int zi, int luna, int an,
                                 int NrEchipinMentenanta,
                                 int NrReteleimplicate, float ValoareTask) : Task(std::move(Denumire), zi, luna, an,
                                                                                  false, false),
                                                                             NrEchipInMentenanta(NrEchipinMentenanta),
                                                                             ReteleImplicate(NrReteleimplicate),
                                                                             ValoareTask(ValoareTask) {

}


void TaskRetelistica::afisare(std::ostream &afis) const {

    afis << "Echipamente in mentenanta : " << NrEchipInMentenanta << '\n';
    afis << "Retele implicate: " << ReteleImplicate << '\n';
    afis<<"Valoare task:"<<ValoareTask<<'\n';
    afis << '\n';

}

int TaskRetelistica::GetEchipamente() const {
    return NrEchipInMentenanta;
}

int TaskRetelistica::GetReteleImplicate() const {
    return ReteleImplicate;
}

float TaskRetelistica::GetValoareTask() const {
    return ValoareTask;
}


TaskRelatiiClienti::TaskRelatiiClienti(string Denumire, int zi, int luna, int an, int ImportantaApel) :
        Task(std::move(Denumire), zi, luna, an, false, false), ImportantaApel(ImportantaApel)

{

}

shared_ptr<Task> TaskRelatiiClienti::clone() const {
    return std::make_shared<TaskRelatiiClienti>(*this);
}

void TaskRelatiiClienti::afisare(std::ostream &afis) const {

    afis<<"Apelul valoreaza cat "<<ImportantaApel<<" apeluri!";
    afis<<'\n';

}
