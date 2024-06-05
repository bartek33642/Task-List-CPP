#include "Observer.h"
#include <iostream>

void TaskObserver::update(Task* task, std::string operation) {
    std::cout << operation << " zadanie: " << task->name << std::endl;
}


