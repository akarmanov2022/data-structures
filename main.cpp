//
// Created by akarmanov on 27-11-2022.
//

#include <string>
#include <iostream>
#include "lab5/BinaryTree.h"
#include "lab5/Treap.h"
#include "Menu.h"

int main()
{
    std::cout << "Binary tree configuration:" << std::endl;
    auto binaryTree = new BinaryTree(Menu::InputInt("Enter root value for binary tree: "));
    std::cout << "Descartes tree configuration:" << std::endl;
    auto treap = new Treap(Menu::InputInt("Enter root value for descartes tree: "),
                           Menu::InputInt("Enter root priority for descartes tree: "));

    while (true)
    {
        std::cout << "=== Tree menu ===" << std::endl;
        std::cout << "1. Binary tree" << std::endl;
        std::cout << "2. Descartes tree" << std::endl;
        std::cout << "3. Exit" << std::endl;

        int choice = Menu::InputInt("Enter your choice: ");
        switch (choice)
        {
            case 1:
            {
                Menu::BinaryTreeMenu(binaryTree);
                break;
            }
            case 2:
            {
                Menu::TreapMenu(treap);
                break;
            }
            case 3:
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