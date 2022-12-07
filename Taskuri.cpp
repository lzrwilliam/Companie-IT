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

bool Task::GetStatusTask() {
    return StatusCurent;
}

time_t Task::GetDeadlineTask() {
    return Deadline;
}

bool Task::GetTerminatTask() {
    return  Terminat;
}

void Task::SetTerminatTask() {
    if((StatusCurent==true &&Terminat==false) && DiferentaIntreDouaDati(DataCurenta(),Deadline)==false){StatusCurent= false;}  // terminat dupa deadline
        if(StatusCurent==false && DiferentaIntreDouaDati(DataCurenta(),Deadline)==false) Terminat= false;
        if(StatusCurent==true && DiferentaIntreDouaDati(DataCurenta(),Deadline))  Terminat=true;
                // am acoperit cazul in care angajatul terminat task-ul dupa data de deadline, pentru a putea face diferenta intre cele terminate la timp si cu intarziere

}

shared_ptr<Task> TaskRetelistica::clone() const {
    return std::make_shared<TaskRetelistica>(*this);
}

TaskRetelistica::TaskRetelistica(string Denumire, int zi, int luna, int an, bool StatusCurent,bool Terminat,
                                 int NrEchipinMentenanta,
                                 int NrReteleimplicate,float  ValoareTask) : Task(std::move(Denumire), zi, luna, an, StatusCurent,Terminat),
                                                          NrEchipInMentenanta(NrEchipinMentenanta),
                                                          ReteleImplicate(NrReteleimplicate),ValoareTask(ValoareTask) {

}


void TaskRetelistica::afisare(std::ostream &afis) const {

    afis << "Echipamente in mentenanta : " << NrEchipInMentenanta << '\n';
    afis << "Retele implicate: " << ReteleImplicate << '\n';
    afis<<"Valoare task:"<<ValoareTask<<'\n';
    afis << '\n';

}

int TaskRetelistica::GetEchipamente() {
    return NrEchipInMentenanta;
}

int TaskRetelistica::GetReteleImplicate() {
    return ReteleImplicate;
}

float TaskRetelistica::GetValoareTask() {
    return ValoareTask;
}


TaskRelatiiClienti::TaskRelatiiClienti(string Denumire, int zi, int luna, int an, bool StatusCurent,bool Terminat,int ImportantaApel):
        Task(std::move(Denumire), zi, luna, an, StatusCurent,Terminat),ImportantaApel(ImportantaApel)

{

}

shared_ptr<Task> TaskRelatiiClienti::clone() const {
    return std::make_shared<TaskRelatiiClienti>(*this);
}

void TaskRelatiiClienti::afisare(std::ostream &afis) const {

    afis<<"Apelul valoreaza cat "<<ImportantaApel<<" apeluri!";
    afis<<'\n';

}
