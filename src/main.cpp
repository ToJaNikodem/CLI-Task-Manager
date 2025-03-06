#include "Task.h"
#include "TaskManager.h"
#include <iostream>
#include <string>
#include <map>
#include <array>

int main()
{
    std::cout << "Welcome in CLI Task Manager!\n";
    while (true)
    {
        std::cout << "\n1) Show tasks list\n";
        std::cout << "2) Add new task\n";
        std::cout << "3) Edit task\n";
        std::cout << "4) Delete task\n";
        std::cout << "5) Mark completed\n";
        std::cout << "6) Exit\n";

        while (true)
        {
            std::cout << "> ";
            std::string input = "";
            std::cin >> input;

            if (input == "1")
            {
                TaskManager::showTasks();
                break;
            }
            else if (input == "2")
            {
                TaskManager::addTask();
                break;
            }
            else if (input == "3")
            {
                // TODO: Edit
                break;
            }
            else if (input == "4")
            {
                TaskManager::deleteTask();
                break;
            }
            else if (input == "5")
            {
                TaskManager::markCompleted();
                break;
            }
            else if (input == "6")
            {
                exit(0);
            }
            else
            {
                std::cout << "Invalid input. Try again.\n";
            }
        }
    }
}
