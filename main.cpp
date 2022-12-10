//
// Created by akarmanov on 27-11-2022.
//

#include "lab4/Dictionary.h"
#include <iostream>
#include <limits>

int InputInt(const char *string);

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

        int choice = InputInt("Enter your choice: ");

        switch (choice)
        {
            case 1:
            {
                std::cout << "=== Add ===" << std::endl;
                std::string key;
                std::string value;
                std::cout << "Enter key: ";
                std::cin >> key;
                std::cout << "Enter value: ";
                std::cin >> value;
                dictionary->Add(key.data(), value.data());
                std::cout << "=== Added ===" << std::endl;
                break;
            }
            case 2:
            {
                std::cout << "=== Remove ===" << std::endl;
                std::string key;
                std::cout << "Enter key: ";
                std::cin >> key;
                dictionary->Remove(key.data());
                std::cout << "=== Removed ===" << std::endl;
                break;
            }
            case 3:
            {
                std::cout << "=== Get ===" << std::endl;
                std::string key;
                std::cout << "Enter key: ";
                std::cin >> key;
                const char *value = dictionary->Get(key.data());
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

int InputInt(const char *string)
{
    std::string input;
    bool valid;
    while (true)
    {
        valid = true;
        std::cout << string;
        std::cin >> input;
        for (char c : input)
        {
            if (c < '0' || c > '9')
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            break;
        }
        std::cout << "Invalid input" << std::endl;
    }
    return std::stoi(input);
}
