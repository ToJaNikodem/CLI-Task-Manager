#ifndef TASK_H
#define TASK_H

#include <chrono>
#include <iostream>
#include <string>

enum class Priority
{
    LOW,
    MEDIUM,
    HIGH
};

class Task
{
private:
    std::string m_title = "";
    std::string m_description = "";
    Priority m_priority = Priority::LOW;
    std::chrono::system_clock::time_point m_deadline = std::chrono::system_clock::now();
    std::string m_category = "";
    bool m_completed = false;

public:
    Task(
        const std::string &title,
        const std::string &description,
        Priority priority,
        std::chrono::system_clock::time_point deadline,
        const std::string &category);

    void editTask(
        const std::string &newTitle,
        const std::string &newDescription,
        Priority newPriority,
        std::chrono::system_clock::time_point newDeadline,
        const std::string &newCategory);

    void printTask();
    void completeTask();
};

#endif
