#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include "Observer.h"
#include <vector>

// Klasa TaskManager zarz¹dza list¹ zadañ i obserwatorów
class TaskManager {
private:
    static TaskManager* instance;
    std::vector<Task*> tasks;
    std::vector<Observer*> observers;
    TaskManager();

public:
    static TaskManager* getInstance();
    void addTask(Task* task);
    void deleteTask(int index);
    void editTask(int index, std::string newName);
    void addObserver(Observer* observer);
    void notifyObservers(Task* task, std::string operation);
    void displayTasks();
};

#endif // TASKMANAGER_H

