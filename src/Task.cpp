#include "Task.h"
#include <iostream>
#include <string>
#include <chrono>
#include <array>
#include <iomanip>
#include <ctime>

std::string formatCurrentTime(std::chrono::system_clock::time_point time)
{
    std::time_t timeT = std::chrono::system_clock::to_time_t(time);
    std::tm *structuredTime = std::localtime(&timeT);

    std::ostringstream outputStream;
    outputStream << std::put_time(structuredTime, "%Y-%m-%d %H:%M:%S");
    return outputStream.str();
}

Task::Task(const std::string &title, const std::string &description, Priority priority,
           std::chrono::system_clock::time_point deadline, const std::string &category)
    : m_title{title}, m_description{description}, m_priority{priority},
      m_deadline{deadline}, m_category{category}
{
}

void Task::completeTask()
{
    m_completed = true;
}

void Task::editTask(const std::string &newTitle, const std::string &newDescription, Priority newPriority,
                    std::chrono::system_clock::time_point newDeadline, const std::string &newCategory)
{
    m_title = newTitle;
    m_description = newDescription;
    m_priority = newPriority;
    m_deadline = newDeadline;
    m_category = newCategory;
}

void Task::printTask() const
{
    std::cout << "Title: " << m_title << '\n';
    std::cout << "Description: " << m_description << '\n';
    std::cout << "Priority: " << static_cast<int>(m_priority) << '\n';
    std::cout << "Deadline: " << formatCurrentTime(m_deadline) << '\n';
    std::cout << "Category: " << m_category << '\n';
    std::cout << "Completed: " << (m_completed ? "Yes" : "No") << '\n';
}
