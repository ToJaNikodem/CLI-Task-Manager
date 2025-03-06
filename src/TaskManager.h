#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <array>
#include <iostream>
#include <map>
#include <string>

namespace TaskManager
{
    extern std::map<int, Task> tasks;
    extern std::array<std::string, 3> categories;

    void showTasks();
    void addTask();
    void deleteTask();
    void markCompleted();
}

#endif
