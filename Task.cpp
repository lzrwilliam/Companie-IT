//
// Created by lazar on 10/25/2022.
//

#include "Task.h"

Task::Task(int IdTask, const string &DenumireTask, float ProfitTask, bool StatusTask, int an,int luna,int zi)
        :
        IdTask{IdTask},
        DenumireTask{DenumireTask},
        ProfitTask{ProfitTask},
        StatusTask{StatusTask}


{

    std::tm tm={};
    tm.tm_year=an-1900;
    tm.tm_mon=luna-1;
    tm.tm_mday=zi;
std::time_t  time1= mktime(&tm);
Deadline=time1;




}

Task::Task(const Task &other) :
        IdTask{other.IdTask},
        DenumireTask{other.DenumireTask},

        ProfitTask{other.ProfitTask},
        StatusTask{other.StatusTask},
        Deadline{other.Deadline}{
    //cout<<"Constructor copiere task \n";
}

Task &Task::operator=(const Task &other) {
    IdTask = other.IdTask;
    DenumireTask = other.DenumireTask;

    ProfitTask = other.ProfitTask;
    StatusTask = other.StatusTask;
    Deadline=other.Deadline;
    // cout<<"Operator = de copiere clasa task \n";
    return *this;
}

std::ostream &operator<<(std::ostream &cout1, const Task &task) {

    cout1 << "Id Task:" << task.IdTask << std::endl <<
          "Denumire Task : " << task.DenumireTask << '\n'
          << "Profit Task " << task.ProfitTask <<
          "\n Status: " << task.StatusTask <<
          '\n' << "Deadline :" << ConvertireData(task.Deadline);

    return cout1;

}

int Task::GetStatusTask() const {
    if (this->StatusTask == 1) return 1;
    return 0;

}


int Task::GetTaskId() const {
    return this->IdTask;


}

bool Task::TaskRestant() const {


    double DiferentaIntreDati = std::difftime(DataCurenta(), this->Deadline) / (60 * 60 * 24); //nr secunde intr-o zi
    return DiferentaIntreDati > 0;
}

int Task::GetProfitTask() const {
    return this->ProfitTask;
}



