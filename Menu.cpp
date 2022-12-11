//
// Created by akarmanov on 10-12-2022.
//

#include <iostream>
#include "Menu.h"

int Menu::InputInt(const char *message)
{
    std::string input;
    bool valid;
    while (true)
    {
        valid = true;
        std::cout << message;
        std::cin >> input;
        for (char c: input)
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

void Menu::BinaryTreeMenu(BinaryTree *tree)
{
    while (true)
    {
        std::cout << "1. Add node" << std::endl;
        std::cout << "2. Print in order" << std::endl;
        std::cout << "3. Print pre order" << std::endl;
        std::cout << "4. Print post order" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        switch (choice)
        {
            case 1:
            {
                std::cout << "Enter value: ";
                int value;
                std::cin >> value;
                tree->AddNode(value);
                break;
            }
            case 2:
            {
                tree->PrintInOrder();
                break;
            }
            case 3:
            {
                tree->PrintPreOrder();
                break;
            }
            case 4:
            {
                tree->PrintPostOrder();
                break;
            }
            case 5:
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
        std::cout << "7. Get Min" << std::endl;
        std::cout << "8. Get Max" << std::endl;

        int choice = InputInt("Enter your choice: ");
        switch (choice)
        {
            case 1:
            {
                int value = InputInt("Enter value: ");
                int priority = InputInt("Enter priority: ");
                treap->InsertOptimized(value, priority);
                break;
            }
            case 2:
            {
                int value = InputInt("Enter value: ");
                int priority = InputInt("Enter priority: ");
                treap->InsertNonOptimized(value, priority);
                break;
            }
            case 3:
            {
                int value = InputInt("Enter value: ");
                treap->RemoveOptimized(value);
                break;
            }
            case 4:
            {
                int value = InputInt("Enter value: ");
                treap->RemoveNonOptimized(value);
                break;
            }
            case 5:
            {
                int value = InputInt("Enter value: ");
                std::cout << "Node " << (treap->Find(value) ? "found" : "not found") << std::endl;
                break;
            }
            case 6:
            {
                std::cout << "Height: " << treap->GetHeight() << std::endl;
                break;
            }
            case 7:
            {
                std::cout << "Min: " << treap->GetMin() << std::endl;
                break;
            }
            case 8:
            {
                std::cout << "Max: " << treap->GetMax() << std::endl;
                break;
            }
            default:
            {
                std::cout << "Invalid choice" << std::endl;
                break;
            }
        }
    }
}
