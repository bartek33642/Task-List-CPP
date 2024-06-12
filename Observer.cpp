#include "Observer.h"
#include <iostream>

// Metoda update wywo³ywana, gdy stan obserwowanego obiektu siê zmienia
void TaskObserver::update(Task* task, std::string operation) {
    std::cout << operation << " zadanie: " << task->name << "\n" << std::endl;
}


