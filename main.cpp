#include "TaskManager.h"
#include "Observer.h"
#include <iostream>

int main() {
    TaskManager* taskManager = TaskManager::getInstance();
    TaskObserver observer;
    taskManager->addObserver(&observer);

    while (true) {
        std::cout << "1. Dodaj zadanie\n2. Usun zadanie\n3. Edytuj zadanie\n4. Wyswietl zadania\n5. Wyjdz\n";
        int option;
        std::cin >> option;

        if (option == 1) {
            std::cout << "Podaj nazwe zadania: ";
            std::string name;
            std::cin >> name;
            Task* task = new Task(name);
            taskManager->addTask(task);
        } else if (option == 2) {
            std::cout << "Podaj indeks zadania do usuniecia: ";
            int index;
            std::cin >> index;
            taskManager->deleteTask(index);
        } else if (option == 3) {
            std::cout << "Podaj indeks zadania do edycji: ";
            int index;
            std::cin >> index;
            std::cout << "Podaj nowa nazwe zadania: ";
            std::string newName;
            std::cin >> newName;
            taskManager->editTask(index, newName);
        } else if (option == 4) {
            taskManager->displayTasks();
        } else if (option == 5) {
            break;
        }
    }

    return 0;
}


