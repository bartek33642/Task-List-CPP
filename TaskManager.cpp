#include "TaskManager.h"
#include <iostream>

TaskManager* TaskManager::instance = nullptr;

// Konstruktor klasy TaskManager
TaskManager::TaskManager() {}

// Metoda zwracaj¹ca instancjê singletona
TaskManager* TaskManager::getInstance() {
    if (instance == nullptr) {
        instance = new TaskManager();
    }
    return instance;
}

// Dodawanie zadania do listy zadañ
void TaskManager::addTask(Task* task) {
    tasks.push_back(task);
    notifyObservers(task, "Dodano");
}

// Usuwanie zadania z listy zadañ
void TaskManager::deleteTask(int index) {
    if (index < 0 || index >= tasks.size()) {
        std::cout << "Nieprawidlowy indeks zadania. \n" << std::endl;
        return;
    }
    notifyObservers(tasks[index], "Usunieto");
    tasks.erase(tasks.begin() + index);
}

// Edycja zadania
void TaskManager::editTask(int index, std::string newName) {
    if (index < 0 || index >= tasks.size()) {
        std::cout << "Nieprawidlowy indeks zadania. \n" << std::endl;
        return;
    }
    tasks[index]->name = newName;
    notifyObservers(tasks[index], "Edytowano");
}

// Dodawanie obserwatora do listy obserwatorów
void TaskManager::addObserver(Observer* observer) {
    observers.push_back(observer);
}

// Powiadamianie obserwatorów o zmianie stanu
void TaskManager::notifyObservers(Task* task, std::string operation) {
    for (Observer* observer : observers) {
        observer->update(task, operation);
    }
}

// Wyœwietlanie listy zadañ
void TaskManager::displayTasks() {
    std::cout << "Lista zadan:" << std::endl;
    for (int i = 0; i < tasks.size(); i++) {
        std::cout << i << ": " << tasks[i]->name << std::endl;
    }
}


