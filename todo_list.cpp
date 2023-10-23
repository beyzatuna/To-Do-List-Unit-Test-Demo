#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string name;
    std::string status;

    Task(const std::string& n, const std::string& s) : name(n), status(s) {}
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& name, const std::string& status) {
        tasks.push_back(Task(name, status));
        std::cout << "Gorev eklendi: " << name << std::endl;
    }

    void displayTasks(const std::string& status) {
        std::cout << "***** " << status << " *****" << std::endl;
        for (const Task& task : tasks) {
            if (task.status == status) {
                std::cout << task.name << std::endl;
            }
        }
        std::cout << std::endl;
    }

    void changeTaskStatus(const std::string& name, const std::string& newStatus) {
        for (Task& task : tasks) {
            if (task.name == name) {
                task.status = newStatus;
                std::cout << "Gorev durumu guncellendi: " << name << " -> " << newStatus << std::endl;
                return;
            }
        }
        std::cout << "Gorev bulunamadi: " << name << std::endl;
    }
};

int main() {
    TodoList todoList;
    while (true) {
        std::cout << "********** TO-DO LIST UYGULAMASI **********" << std::endl;
        std::cout << "1. Gorev Ekle" << std::endl;
        std::cout << "2. Gorevleri Goster (To-Do)" << std::endl;
        std::cout << "3. Gorevleri Goster (In Progress)" << std::endl;
        std::cout << "4. Gorevleri Goster (Done)" << std::endl;
        std::cout << "5. Gorev Durumu Degistir" << std::endl;
        std::cout << "0. Cikis" << std::endl;

        int choice;
        std::cout << "Seciminizi yapin: ";
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "Uygulamadan cikiliyor." << std::endl;
            break;
        }

        switch (choice) {
            case 1: {
                std::string name, status;
                std::cout << "Grev adini girin: ";
                std::cin >> name;
                std::cout << "Gorev durumunu girin (To-Do, In Progress, Done): ";
                std::cin >> status;
                todoList.addTask(name, status);
                break;
            }
            case 2:
                todoList.displayTasks("To-Do");
                break;
            case 3:
                todoList.displayTasks("In Progress");
                break;
            case 4:
                todoList.displayTasks("Done");
                break;
            case 5: {
                std::string name, newStatus;
                std::cout << "Gorev adini girin: ";
                std::cin >> name;
                std::cout << "Yeni gorev durumunu girin (To-Do, In Progress, Done): ";
                std::cin >> newStatus;
                todoList.changeTaskStatus(name, newStatus);
                break;
            }
            default:
                std::cout << "Gecersiz secenek." << std::endl;
        }
    }

    return 0;
}

