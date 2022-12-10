//
// Created by akarmanov on 10-12-2022.
//

#include <iostream>
#include "Menu.h"

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

void Menu::DescartesTreeMenu(DescartesTree *tree)
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
                std::cout << "Enter priority: ";
                int priority;
                std::cin >> priority;
                tree->AddNodeNonOptimized(value, priority);
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
