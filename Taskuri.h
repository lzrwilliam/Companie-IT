//
// Created by lazar on 12/1/2022.
//

#ifndef OOP_TASKURI_H
#define OOP_TASKURI_H

#include <utility>
#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;
using std::string;

class Task {

    string DenumireTask;
    float ValoareTask;

    virtual void afisare(std::ostream &) const {}

public:

    virtual  ~Task() = default;

    virtual shared_ptr<Task> clone() const = 0;

    friend std::ostream &operator<<(std::ostream &afis, const Task &task);

    Task(string Denumire, float Valoare);

protected:
    Task &operator=(const Task &altul) = default;

    Task(const Task &altul) = default;
};

class TaskPrincipal : public Task {

public:
    TaskPrincipal(string Denumire, float valoare);

    shared_ptr<Task> clone() const override;

    void afisare(std::ostream &afis) const override;
};


#endif //OOP_TASKURI_H
