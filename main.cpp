//
// Created by akarmanov on 27-11-2022.
//

#include "lab4/Dictionary.h"
#include <iostream>
#include <regex>

int InputInt(const char *message, const char *regex)
{
    std::string input;
    while (true)
    {
        std::cout << message;
        std::cin >> input;
        if (regex_match(input, std::regex(regex)))
        {
            return std::stoi(input);
        }
        else
        {
            std::cout << "Invalid input" << std::endl;
        }
    }
}

int InputInt(const char *message)
{
    return InputInt(message, "-?[0-9]+");
}

int InputPositiveInt(const char *message)
{
    return InputInt(message, "[0-9]+");
}

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

        int choice = InputPositiveInt("Enter your choice: ");

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
