#include "TaskManager.h"
#include "Observer.h"
#include <iostream>

int main() {
	// Tworzenie instancji TaskManagera i obserwatora
    TaskManager* taskManager = TaskManager::getInstance();
    TaskObserver observer;
    taskManager->addObserver(&observer);
	
	std::cout << "Witaj w aplikacji konsolowej do zarzadzania zadaniami!\n\n";
    // Wyœwietlanie menu u¿ytkownikowi
    while (true) {
    	std::cout << "Podaj numer operacji: \n";
        std::cout << "1. Dodaj zadanie\n2. Usun zadanie\n3. Edytuj zadanie\n4. Wyswietl zadania\n5. Wyjdz\n\n";
        int option;
        std::cout << "Wybieram numer: ";
        std::cin >> option;
        std::cout << "----------------------- \n";
        
        // Obs³uga wyboru u¿ytkownika
        if (option == 1) {
        	// Dodawanie nowego zadania
            std::cout << "Podaj nazwe zadania: \n";
            std::string name;
            std::cin >> name;
            Task* task = new Task(name);
            taskManager->addTask(task);
        } else if (option == 2) {
        	// Usuwanie zadania
            std::cout << "Podaj indeks zadania do usuniecia: \n";
            int index;
            std::cin >> index;
            taskManager->deleteTask(index);
        } else if (option == 3) {
        	// Edycja zadania
            std::cout << "Podaj indeks zadania do edycji: \n";
            int index;
            std::cin >> index;
            std::cout << "Podaj nowa nazwe zadania: \n";
            std::string newName;
            std::cin >> newName;
            taskManager->editTask(index, newName);
        } else if (option == 4) {
        	// Wyœwietlanie zadañ
            taskManager->displayTasks();
            std::cout << "\n";
        } else if (option == 5) {
        	// Wyjœcie z programu
            break;
        }
    }

    return 0;
}


