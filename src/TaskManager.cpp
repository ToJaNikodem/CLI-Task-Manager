#include "TaskManager.h"
#include "Task.h"
#include <iostream>
#include <string>
#include <map>
#include <array>
#include <iomanip>
#include <sstream>

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
        std::chrono::system_clock::time_point deadline{};
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

    void markCompleted()
    {
        int taskId = -1;
        std::cout << "Enter task ID to mark as completed: ";
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
        tasks[taskId].completeTask();
        std::cout << "Task marked as completed!\n";
    }
}
