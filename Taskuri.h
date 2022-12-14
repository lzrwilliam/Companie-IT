//
// Created by lazar on 12/1/2022.
//

#ifndef OOP_TASKURI_H
#define OOP_TASKURI_H

#include <utility>
#include <memory>
#include <vector>
#include <iostream>
#include <ctime>
#include "altefunctii.h"

using std::shared_ptr;
using std::vector;
using std::string;

class Task {
    string DenumireTask;
    time_t Deadline;
    bool StatusCurent;
    bool Terminat;
    static int Id;
    const int IdTask;
    virtual void afisare(std::ostream &) const {}

public:
    void SetStatusTask();

    virtual  ~Task() = default;

    virtual shared_ptr<Task> clone() const = 0;

    friend std::ostream &operator<<(std::ostream &afis, const Task &task);

    Task(string Denumire, int zi, int luna, int an, bool StatusCurent, bool terminat);

    bool GetStatusTask() const;

    bool GetTerminatTask() const;

    int GetIdTask() const;

    void SetTerminatTask();

    time_t GetDeadlineTask() const;

    void ApelareFunctiiTask();

protected:
    Task &operator=(const Task &altul);

    Task(const Task &altul) = default;


    void SetTask();
};

class TaskRetelistica : public Task {

    int NrEchipInMentenanta;
    int ReteleImplicate;
    float ValoareTask;

    void afisare(std::ostream &afis) const override;

public:
    TaskRetelistica(string Denumire, int zi, int luna, int an,
                    int nrEchipamenteInMentenanta,
                    int ReteleImplicate, float ValoareTask);

    shared_ptr<Task> clone() const override;

    int GetEchipamente() const;

    int GetReteleImplicate() const;

    float GetValoareTask() const;

};



class TaskRelatiiClienti:public Task{

    int ImportantaApel;

    void afisare(std::ostream&afis) const override;
public:
    explicit TaskRelatiiClienti(string Denumire, int zi, int luna, int an, int ImportantaApel);

    shared_ptr<Task> clone() const override;





};

#endif //OOP_TASKURI_H
