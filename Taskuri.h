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
// id task automat
    string DenumireTask;
    float ValoareTask;
    time_t Deadline;
    bool Status;

    virtual void afisare(std::ostream &) const {}

public:

    virtual  ~Task() = default;

    virtual shared_ptr<Task> clone() const = 0;

    friend std::ostream &operator<<(std::ostream &afis, const Task &task);

    Task(string Denumire, float Valoare, int zi, int luna, int an, bool Status);

protected:
    Task &operator=(const Task &altul) = default;

    Task(const Task &altul) = default;
};

class TaskRetelistica : public Task {

    int NrEchipInMentenanta;
    int ReteleImplicate;

    void afisare(std::ostream &afis) const override;

public:
    TaskRetelistica(string Denumire, float valoare, int zi, int luna, int an, bool Status,
                    int nrEchipamenteInMentenanta,
                    int ReteleImplicate);

    shared_ptr<Task> clone() const override;

};


#endif //OOP_TASKURI_H
