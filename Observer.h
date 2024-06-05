#ifndef OBSERVER_H
#define OBSERVER_H

#include "Task.h"
#include <string>

class Observer {
public:
    virtual void update(Task* task, std::string operation) = 0;
};

class TaskObserver : public Observer {
public:
    void update(Task* task, std::string operation) override;
};

#endif // OBSERVER_H

