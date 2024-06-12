#include "Observer.h"
#include <iostream>

// Metoda update wywo�ywana, gdy stan obserwowanego obiektu si� zmienia
void TaskObserver::update(Task* task, std::string operation) {
    std::cout << operation << " zadanie: " << task->name << "\n" << std::endl;
}


