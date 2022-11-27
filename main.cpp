//
// Created by akarmanov on 27-11-2022.
//

#include <iostream>
#include "lab3/Stack.h"

bool CheckInput()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Invalid input!" << std::endl;
        return false;
    }
    return true;
}

void PrintStack(Stack *stack)
{
    std::cout << "Stack: ";
    Node *node = stack->Peek();
    while (node != nullptr)
    {
        std::cout << node->GetData() << " ";
        node = node->GetNext();
    }
    std::cout << std::endl;
}

int main()
{
    auto *stack = new Stack();

    while (true)
    {
        std::cout << "Enter a number:" << std::endl;
        std::cout << "1. Push" << std::endl;
        std::cout << "2. Pop" << std::endl;
        std::cout << "3. Peek" << std::endl;
        std::cout << "4. Clear" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice;
        std::cin >> choice;

        if (!CheckInput())
            continue;

        switch (choice)
        {
            case -1:
            {
                return 0;
            }
            case 1:
            {
                std::cout << "Enter a number to push to stack" << std::endl;
                int value;
                std::cin >> value;
                if (!CheckInput())
                    continue;
                stack->Push(value);
                PrintStack(stack);
                break;
            }
            case 2:
            {
                stack->Pop();
                PrintStack(stack);
                break;
            }
            case 3:
            {
                std::cout << "Peek: " << stack->Peek()->GetData() << std::endl;
                break;
            }
            case 4:
            {
                stack->Clear();
                PrintStack(stack);
                break;
            }
            default:
            {
                std::cout << "Invalid choice!" << std::endl;
                break;
            }
        }
    }
}
