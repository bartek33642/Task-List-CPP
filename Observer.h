#ifndef OBSERVER_H
#define OBSERVER_H

#include "Task.h"
#include <string>

// Klasa bazowa dla obserwatorów
class Observer {
public:
	// Metoda update wywo³ywana, gdy stan obserwowanego obiektu siê zmienia
    virtual void update(Task* task, std::string operation) = 0;
};

// Klasa TaskObserver implementuje interfejs Observer
class TaskObserver : public Observer {
public:
    void update(Task* task, std::string operation) override;
};

#endif // OBSERVER_H

