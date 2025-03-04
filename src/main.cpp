#include "Task.h"
#include <iostream>
#include <string>

int main()
{
    std::cout << "Welcome in CLI Task Manager!\n";
    while (true)
    {
        std::cout << "1) Show tasks list\n";
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
                // TODO: Show tasks list
                break;
            }
            else if (input == "2")
            {
                // TODO: Add
                break;
            }
            else if (input == "3")
            {
                // TODO: Edit
                break;
            }
            else if (input == "4")
            {
                // TODO: Delete
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
