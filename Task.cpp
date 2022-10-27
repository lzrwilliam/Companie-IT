//
// Created by lazar on 10/25/2022.
//

#include "Task.h"

Task::Task(int IdTask, const string &DenumireTask, float ProfitTask, bool StatusTask, tm*deadline)
        :
        IdTask{IdTask},
        DenumireTask{DenumireTask},
        ProfitTask{ProfitTask},
        StatusTask{StatusTask},
       Deadline{deadline}

{ //cout<<"Constructor initializare Task! \n";

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

    cout << "Id Task:" << task.IdTask << std::endl << "Denumire Task : " << task.DenumireTask << '\n' << "Responsabil: "
         << "de afisat numele angajatului" << '\n'
         << "Profit Task " << task.ProfitTask << "\n Status: " << task.StatusTask << '\n'<<"Deadline :";
    return cout1;

}
