//
// Created by akarmanov on 27-11-2022.
//

#include <iostream>
#include "lab3/stack/Stack.h"
#include "lab3/buffer/RingBuffer.h"

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
    std::cout << "Stack: " << std::endl;
    std::cout << "Size: " << stack->GetSize() << std::endl;
    Node *node = stack->Peek();
    while (node != nullptr)
    {
        std::cout << node->GetData() << " ";
        node = node->GetNext();
    }
    std::cout << std::endl;
}

void PrintBuffer(RingBuffer *buffer)
{
    std::cout << "Buffer: " << std::endl;
    RingBufferNode *node = buffer->GetFirst();
    std::cout << "Size: " << buffer->GetSize() << std::endl;
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
    auto *buffer = new RingBuffer();

    while (true)
    {
        std::cout << "1. Push to stack" << std::endl;
        std::cout << "2. Pop from stack" << std::endl;
        std::cout << "3. Print stack" << std::endl;
        std::cout << "4. Put to buffer" << std::endl;
        std::cout << "5. Get from buffer" << std::endl;
        std::cout << "6. Print buffer" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        if (!CheckInput())
        {
            continue;
        }
        switch (choice)
        {
            case 1:
            {
                std::cout << "Enter value: ";
                int value;
                std::cin >> value;
                if (!CheckInput())
                {
                    continue;
                }
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
                PrintStack(stack);
                break;
            }
            case 4:
            {
                std::cout << "Enter value: ";
                int value;
                std::cin >> value;
                if (!CheckInput())
                {
                    continue;
                }
                buffer->Put(value);
                PrintBuffer(buffer);
                break;
            }
            case 5:
            {
                std::cout << "Enter index: ";
                int index;
                std::cin >> index;
                if (!CheckInput())
                {
                    continue;
                }
                auto *node = buffer->Get(index);
                if (node == nullptr)
                {
                    std::cout << "Invalid index!" << std::endl;
                }
                else
                {
                    std::cout << "Value: " << node->GetData() << std::endl;
                }
                break;
            }
            case 6:
            {
                PrintBuffer(buffer);
                break;
            }
            case 7:
            {
                return 0;
            }
            default:
            {
                std::cout << "Invalid choice!" << std::endl;
                break;
            }
        }
    }
}
