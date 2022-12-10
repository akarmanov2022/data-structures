//
// Created by akarmanov on 27-11-2022.
//

#include <string>
#include <iostream>
#include "lab5/BinaryTree.h"
#include "lab5/DescartesTree.h"

int InputInt(const char *string)
{
    std::string input;
    bool valid;
    while (true)
    {
        valid = true;
        std::cout << string;
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

int main()
{
    std::cout << "Binary tree configuration:" << std::endl;
    auto binaryTree = new BinaryTree(InputInt("Enter root value for binary tree: "));
    std::cout << "Descartes tree configuration:" << std::endl;
    auto descartesTree = new DescartesTree(InputInt("Enter root value for descartes tree: "),
                                           InputInt("Enter root priority for descartes tree: "));

    while (true)
    {
        std::cout << "1. Binary tree" << std::endl;
        std::cout << "2. Descartes tree" << std::endl;

        int choice = InputInt("Enter your choice: ");


    }
}