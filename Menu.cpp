//
// Created by akarmanov on 10-12-2022.
//

#include <iostream>
#include <regex>
#include "Menu.h"

int Menu::InputInt(const char *message)
{
    return InputInt(message, "-?[0-9]+");
}

int Menu::InputPositiveInt(const char *message)
{
    return InputInt(message, "[0-9]+");
}

int Menu::InputInt(const char *message, const char *regex)
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

void Menu::BinaryTreeMenu(BinaryTree *tree)
{
    while (true)
    {
        std::cout << "=== Binary tree menu ===" << std::endl;
        std::cout << "1. Add node" << std::endl;
        std::cout << "2. Get height" << std::endl;
        std::cout << "3. Get min value" << std::endl;
        std::cout << "4. Get max value" << std::endl;
        std::cout << "5. Remove node" << std::endl;
        std::cout << "6. Find node" << std::endl;
        std::cout << "7. Print tree" << std::endl;
        std::cout << "8. Exit" << std::endl;

        int choice = InputPositiveInt("Enter your choice: ");
        switch (choice)
        {
            case 1:
            {
                tree->AddNode(InputInt("Enter value to add: "));
                break;
            }
            case 2:
            {
                std::cout << "Height: " << tree->GetHeight() << std::endl;
                break;
            }
            case 3:
            {
                std::cout << "Min value: " << tree->GetMin() << std::endl;
                break;
            }
            case 4:
            {
                std::cout << "Max value: " << tree->GetMax() << std::endl;
                break;
            }
            case 5:
            {
                if (tree->Remove(InputInt("Enter value to remove: ")))
                {
                    std::cout << "Node removed" << std::endl;
                }
                else
                {
                    std::cout << "Node not found" << std::endl;
                }
                break;
            }
            case 6:
            {
                int value = InputInt("Enter value to find: ");
                std::cout << "Node found: " << (tree->Find(value) ? "true" : "false")
                          << std::endl;
                break;
            }
            case 7:
            {
                std::cout << "Tree: " << std::endl;
                std::cout << *tree << std::endl;
                break;
            }
            case 8:
            {
                return;
            }
        }
    }
}

void Menu::TreapMenu(Treap *treap)
{
    while (true)
    {
        std::cout << "=== Treap menu ===" << std::endl;
        std::cout << "1. Add node (Optimized)" << std::endl;
        std::cout << "2. Add node (Non-optimized)" << std::endl;
        std::cout << "3. Remove node (Optimized)" << std::endl;
        std::cout << "4. Remove node (Non-optimized)" << std::endl;
        std::cout << "5. Find node" << std::endl;
        std::cout << "6. Get Height" << std::endl;
        std::cout << "7. Print tree" << std::endl;
        std::cout << "8. Exit" << std::endl;

        int choice = InputPositiveInt("Enter your choice: ");
        switch (choice)
        {
            case 1:
            {
                treap->InsertOptimized(InputInt("Enter value to add: "),
                        //TODO: duplication
                                       GetRandomInt());
                break;
            }
            case 2:
            {
                treap->InsertNonOptimized(InputInt("Enter value to add: "),
                        //TODO: duplication
                                          GetRandomInt());
                break;
            }
            case 3:
            {
                //TODO: duplication
                CheckRemove(treap->RemoveOptimized(InputInt("Enter value to remove: ")));
                break;
            }
            case 4:
            {
                //TODO: duplication
                CheckRemove(treap->RemoveNonOptimized(InputInt("Enter value to remove: ")));
                break;
            }
            case 5:
            {
                int value = InputInt("Enter value to find: ");
                std::cout << "Node found: "
                          << (treap->Find(value) ? "true" : "false")
                          << std::endl;
                break;
            }
            case 6:
            {
                std::cout << "Height: " << treap->GetHeight() << std::endl;
                break;
            }
            case 7:
            {
                std::cout << "Treap: " << std::endl;
                std::cout << *treap << std::endl;
                break;
            }
            case 8:
            {
                return;
            }
            default:
            {
                std::cout << "Invalid choice" << std::endl;
                break;
            }
        }
    }
}

void Menu::CheckRemove(bool check)
{
    if (check)
    {
        std::cout << "Node removed" << std::endl;
    }
    else
    {
        std::cout << "Node not found" << std::endl;
    }
}

int Menu::GetRandomInt()
{
    return rand() % 100;
}
