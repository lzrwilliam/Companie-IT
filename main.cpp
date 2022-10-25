#include <iostream>
#include  <vector>
#include <ctime>
#include "angajat.h"
using std::cout;
using std::string;



class Task{
    int IdTask;
    string DenumireTask;
    string Angajat; // cine se ocupa de task-ul respectiv
    float ProfitTask=0;
    bool StatusTask=0;
    // time_t DeadLine;
public:
    Task(int IdTask,const string &DenumireTask,const string &Angajat,float ProfitTask,bool StatusTask)://time_t Deadline):
            IdTask{IdTask},
            DenumireTask{DenumireTask},
            Angajat{Angajat},
            ProfitTask{ProfitTask},
            StatusTask{StatusTask}
    // Deadline{Deadline}
    { //cout<<"Constructor initializare Task! \n";

    }


    Task(const Task&other):
            IdTask{other.IdTask},
            DenumireTask{other.DenumireTask},
            Angajat{other.Angajat},
            ProfitTask{other.ProfitTask},
            StatusTask{other.StatusTask}

    {
        //cout<<"Constructor copiere task \n";
    }

    friend std::ostream & operator<<(std::ostream&cout,const Task& task);
    Task &operator=(const Task&other){
        IdTask=other.IdTask;
        DenumireTask=other.DenumireTask;
        Angajat=other.Angajat;
        ProfitTask=other.ProfitTask;
        StatusTask=other.StatusTask;
        // cout<<"Operator = de copiere clasa task \n";
        return *this;
    }



    ~Task(){}
};

class Departament{
    string NumeDepartament;
    std::vector<Angajat>AngajatiDepartament;
    float ProfitDepartament=0;

public:
    Departament(const string &Nume, const std::vector<Angajat> &Angajati, float Profit = 0) :
            NumeDepartament{Nume},
            AngajatiDepartament{Angajati},
            ProfitDepartament{Profit}
    {}

    Departament(const Departament &other) :
            NumeDepartament{other.NumeDepartament},
            AngajatiDepartament{other.AngajatiDepartament},
            ProfitDepartament{other.ProfitDepartament}
    {}

    Departament &operator=(const Departament&altul)

    {NumeDepartament=altul.NumeDepartament;
        AngajatiDepartament=altul.AngajatiDepartament;
        ProfitDepartament=altul.ProfitDepartament;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream&afisare, const Departament&departament){

        afisare<<"Numele departamentului: "<<departament.NumeDepartament<<std::endl;
        afisare<<"Profit departament: "<<departament.ProfitDepartament<<std::endl;
        afisare<<"Angajatii din departament:"<<std::endl;
        for( const auto&i:departament.AngajatiDepartament)
            afisare<<i;
        return afisare;

    }


    ~Departament(){}




};

class Companie{
private:
    string DenumireCompanie;
    std::vector<Departament>Departamente;
    std::vector<Task>TaskuriCompanie;


public:
    Companie(const string &Denumire, const std::vector<Departament> &Departamente1,
             const std::vector<Task> &TaskuriCompanie) :
            DenumireCompanie{Denumire},
            Departamente{Departamente1},
            TaskuriCompanie{TaskuriCompanie}
    {}




    Companie&operator=(const Companie&altul)

    {
        DenumireCompanie=altul.DenumireCompanie;
        TaskuriCompanie=altul.TaskuriCompanie;
        // cout<<"operator= de copiere compani "<<'\n';
        return *this;



    }
    Companie(Companie&other):
            DenumireCompanie{other.DenumireCompanie},
            //Departamente{other.Departamente},
            TaskuriCompanie{other.TaskuriCompanie}

    {cout<<"CC Companie"<<std::endl;}



    ~Companie()= default;
    friend std::ostream &operator <<(std::ostream&cout,const Companie&companie);

};

std::ostream &operator <<(std::ostream&cout1, const Task &task){

    cout<<"Id Task:"<<task.IdTask<<std::endl<<"Denumire Task : "<<task.DenumireTask<<'\n'<<"Responsabil: "<<task.Angajat<<'\n'
        <<"Profit Task "<<task.ProfitTask<<"\n Status: "<<task.StatusTask<<'\n';
    return cout1;

}

std::ostream &operator<<(std::ostream&cout1,const Angajat&angajat){

    cout1<<"Nume angajat: "<<angajat.nume<<'\n';
    cout1<<"Task-uri rezolvate: "<<angajat.NrTaskuriRezolvate<<std::endl;
    cout1<<"Task-urile pe care le are angajatul:\n";

    for(int i : angajat.TaskuriAngajat)
        cout1<<"Id task: "<<i<<" \n";

    cout1<<std::endl;
    return cout1;
}
std::ostream &operator<<(std::ostream&cout1, const Companie& companie){
    cout1<<"Numele companiei: "<<companie.DenumireCompanie<<'\n'<<"Departamentele companiei:"<<'\n';
    for( const auto & i : companie.Departamente){
        cout1<<i;
        cout1<<std::endl;}
    cout1<<"---TASK-URILE COMPANIEI---"<<"\n";
    for(const auto &   i : companie.TaskuriCompanie){
        cout1<<i;
        cout1<<std::endl;}
    return cout1;



}

int main() {
    Task t1(1,"Configurare router principal","William",900,true);
    Angajat a1("William",{1});
    std::vector<Task>Taskuri;
    std::vector<Angajat> Angajati;
    std::vector<Departament> Departamente;
    Taskuri.push_back(t1);
    Angajati.push_back(a1);

    Angajat a2("Turis", {1, 2});
    Task t2(2, "Reparare ip", "Turis", 200, false);
    Taskuri.push_back(t2);
    Angajati.push_back(a2);

    Departament d1("HR", Angajati);
    Departamente.push_back(d1);
    //cout<<d1;


    Companie c1("IBM", Departamente, Taskuri);
    cout << c1;
    // Companie c2("Microsoft",Angajati,Taskuri);
    // Companie c2=c1;

    // cout<<c2;



    return 0;
}