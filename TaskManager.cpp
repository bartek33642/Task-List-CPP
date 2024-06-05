#include "TaskManager.h"
#include <iostream>

TaskManager* TaskManager::instance = nullptr;

TaskManager::TaskManager() {}

TaskManager* TaskManager::getInstance() {
    if (instance == nullptr) {
        instance = new TaskManager();
    }
    return instance;
}

void TaskManager::addTask(Task* task) {
    tasks.push_back(task);
    notifyObservers(task, "Dodano");
}

void TaskManager::deleteTask(int index) {
    if (index < 0 || index >= tasks.size()) {
        std::cout << "Nieprawidlowy indeks zadania." << std::endl;
        return;
    }
    notifyObservers(tasks[index], "Usunieto");
    tasks.erase(tasks.begin() + index);
}

void TaskManager::editTask(int index, std::string newName) {
    if (index < 0 || index >= tasks.size()) {
        std::cout << "Nieprawidlowy indeks zadania." << std::endl;
        return;
    }
    tasks[index]->name = newName;
    notifyObservers(tasks[index], "Edytowano");
}

void TaskManager::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void TaskManager::notifyObservers(Task* task, std::string operation) {
    for (Observer* observer : observers) {
        observer->update(task, operation);
    }
}

void TaskManager::displayTasks() {
    std::cout << "Lista zadan:" << std::endl;
    for (int i = 0; i < tasks.size(); i++) {
        std::cout << i << ": " << tasks[i]->name << std::endl;
    }
}


