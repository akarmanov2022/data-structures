//
// Created by akarmanov on 27-11-2022.
//

#include "lab4/Dictionary.h"
#include <iostream>
#include <limits>

int ReadInt(const char *string);

int main()
{
    auto dictionary = new Dictionary;

    while (true)
    {
        std::cout << "=== Dictionary ===" << std::endl;
        std::cout << "1. Add" << std::endl;
        std::cout << "2. Remove" << std::endl;
        std::cout << "3. Get" << std::endl;
        std::cout << "4. Print" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice = ReadInt("Enter your choice: ");

        switch (choice)
        {
            case 1:
            {
                std::cout << "=== Add ===" << std::endl;
                char key[256];
                char value[256];
                std::cout << "Enter key: ";
                std::cin >> key;
                std::cout << "Enter value: ";
                std::cin >> value;
                dictionary->Add(key, value);
                std::cout << "=== Added ===" << std::endl;
                break;
            }
            case 2:
            {
                std::cout << "=== Remove ===" << std::endl;
                char key[256];
                std::cout << "Enter key: ";
                std::cin >> key;
                dictionary->Remove(key);
                std::cout << "=== Removed ===" << std::endl;
                break;
            }
            case 3:
            {
                std::cout << "=== Get ===" << std::endl;
                char key[256];
                std::cout << "Enter key: ";
                std::cin >> key;
                const char *value = dictionary->Get(key);
                if (value == nullptr)
                {
                    std::cout << "Key not found" << std::endl;
                }
                else
                {
                    std::cout << "Value: " << value << std::endl;
                }
                std::cout << "=== Got ===" << std::endl;
                break;
            }
            case 4:
            {
                dictionary->Print();
                break;
            }
            case 5:
            {
                return 0;
            }
            default:
            {
                std::cout << "Invalid choice" << std::endl;
                break;
            }
        }
    }
}

int ReadInt(const char *string)
{
    std::string value;
    std::cout << string;
    bool fail = false;
    while (true)
    {
        std::cin >> value;
        for (char i : value)
        {
            if (!isdigit(i))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Try again: ";
                fail = true;
                break;
            }
        }
        if (!fail)
        {
            break;
        }
    }
    return std::stoi(value);
}
