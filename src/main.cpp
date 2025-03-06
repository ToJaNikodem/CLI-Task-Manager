#include "Task.h"
#include <iostream>
#include <string>
#include <map>
#include <array>
#include <iomanip>

namespace TaskManager
{
    std::map<int, Task> tasks{};
    std::array<std::string, 3> categories = {"Work", "Personal", "School"};

    void showTasks()
    {
        if (tasks.empty())
        {
            std::cout << "No tasks found.\n";
            return;
        }
        for (const auto &task : tasks)
        {
            std::cout << "\nTask ID: " << task.first << '\n';
            task.second.printTask();
        }
    }

    void addTask()
    {
        std::cout << "Enter task title: ";
        std::string title;
        std::getline(std::cin >> std::ws, title);

        std::cout << "Enter task description: ";
        std::string description;
        std::getline(std::cin >> std::ws, description);

        std::cout << "Enter task priority (0 - LOW, 1 - MEDIUM, 2 - HIGH): ";
        Priority priority{};
        while (true)
        {
            int priorityInput;
            std::cin >> priorityInput;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Try again.\n";
                continue;
            }
            if (priorityInput < 0 || priorityInput > 2)
            {
                std::cout << "Invalid input. Try again.\n";
                continue;
            }
            priority = static_cast<Priority>(priorityInput);
            break;
        }

        std::cout << "Enter task deadline (YYYY-MM-DD HH:MM:SS): ";
        std::chrono::_V2::system_clock::time_point deadline{};
        while (true)
        {
            std::string deadlineString;
            std::getline(std::cin >> std::ws, deadlineString);

            std::tm structuredTime{};
            std::istringstream inputStream(deadlineString);
            inputStream >> std::get_time(&structuredTime, "%Y-%m-%d %H:%M:%S");

            if (inputStream.fail())
            {
                std::cout << "Invalid input. Try again.\n";
                continue;
            }

            deadline = std::chrono::system_clock::from_time_t(mktime(&structuredTime));
            break;
        }

        std::cout << "Choose task category\n";
        int category;
        while (true)
        {
            std::cout << "0 - Work\n";
            std::cout << "1 - Personal\n";
            std::cout << "2 - School\n";
            std::cout << "Enter category: ";
            std::cin >> category;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Try again.\n";
                continue;
            }
            if (category < 0 || category > 2)
            {
                std::cout << "Invalid input. Try again.\n";
                continue;
            }
            break;
        }

        static int taskId = 0;
        tasks.emplace(taskId, Task(title, description, priority, deadline, categories[category]));
        taskId++;
        std::cout << "Task added successfully!\n";
    }

    void deleteTask()
    {
        int taskId = -1;
        std::cout << "Enter task ID to delete: ";
        while (true)
        {
            std::cin >> taskId;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Try again.\n";
                continue;
            }
            break;
        }
        if (tasks.find(taskId) == tasks.end())
        {
            std::cout << "Task not found.\n";
            return;
        }
        tasks.erase(taskId);
        std::cout << "Task deleted successfully!\n";
    }
}

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
                // TODO: Mark completed
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
