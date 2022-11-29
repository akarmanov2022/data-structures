//
// Created by akarmanov on 29-11-2022.
//
#include <iostream>
#include "lab3/stack/Stack.h"
#include "lab3/queue/StackQueue.h"
#include "lab3/buffer/RingBuffer.h"
#include "lab3/queue/RingBufferQueue.h"
#include "Menu.h"

int Menu::Input()
{
    //TODO: внести ввод в метод
    int value = 0;
    while (true)
    {
        std::cin >> value;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Invalid input!" << std::endl;
        }
        else
        {
            break;
        }
    }
    return value;
}

void Menu::PrintStack(Stack *stack)
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

void Menu::PrintStackQueue(StackQueue *queue)
{
    std::cout << "Stack queue: " << std::endl;
    std::cout << "Size: " << queue->GetSize() << std::endl;
    std::cout << "Stack 1: " << std::endl;
    PrintStack(queue->GetStack1());
    std::cout << "Stack 2: " << std::endl;
    PrintStack(queue->GetStack2());
}

void Menu::PrintBuffer(RingBuffer *buffer)
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

void Menu::PrintRingBufferQueue(RingBufferQueue *queue)
{
    std::cout << "Ring buffer queue: " << std::endl;
    std::cout << "Size: " << queue->GetSize() << std::endl;
    std::cout << "Is empty: " << queue->IsEmpty() << std::endl;
    std::cout << "Is full: " << queue->IsFull() << std::endl;
    std::cout << "Buffer: " << std::endl;
    PrintBuffer(queue->GetBuffer());
}

void Menu::MenuRingBufferQueue(RingBufferQueue *queue)
{
    while (true)
    {
        std::cout << " --- Ring buffer queue menu --- " << std::endl;
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Get size" << std::endl;
        std::cout << "4. Is empty" << std::endl;
        std::cout << "5. Is full" << std::endl;
        std::cout << "6. Print" << std::endl;
        std::cout << "7. Exit" << std::endl;
        int choice = Input();
        switch (choice)
        {
            case 1:
            {
                std::cout << "Enter value: " << std::endl;
                int value = Input();
                queue->Enqueue(value);
                break;
            }
            case 2:
            {
                int value = queue->Dequeue();
                if (value == -1)
                {
                    std::cout << "Queue is empty!" << std::endl;
                }
                else
                {
                    std::cout << "Dequeued value: " << value << std::endl;
                }
                break;
            }
            case 3:
            {
                std::cout << "Size: " << queue->GetSize() << std::endl;
                break;
            }
            case 4:
            {
                std::cout << "Is empty: " << queue->IsEmpty() << std::endl;
                break;
            }
            case 5:
            {
                std::cout << "Is full: " << queue->IsFull() << std::endl;
                break;
            }
            case 6:
            {
                PrintRingBufferQueue(queue);
                break;
            }
            case 7:
            {
                return;
            }
            default:
            {
                std::cout << "Invalid input!" << std::endl;
                break;
            }
        }
    }
}

void Menu::MenuStackQueue(StackQueue *queue)
{
    while (true)
    {
        std::cout << " --- Stack queue menu --- " << std::endl;
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Get size" << std::endl;
        std::cout << "4. Print" << std::endl;
        std::cout << "5. Exit" << std::endl;
        int choice = Input();
        switch (choice)
        {
            case 1:
            {
                std::cout << "Enter value: " << std::endl;
                int value = Input();
                queue->Enqueue(value);
                break;
            }
            case 2:
            {
                int value = queue->Dequeue();
                if (value == -1)
                {
                    std::cout << "Queue is empty!" << std::endl;
                }
                else
                {
                    std::cout << "Dequeued value: " << value << std::endl;
                }
                break;
            }
            case 3:
            {
                std::cout << "Size: " << queue->GetSize() << std::endl;
                break;
            }
            case 4:
            {
                PrintStackQueue(queue);
                break;
            }
            case 5:
            {
                return;
            }
            default:
            {
                std::cout << "Invalid input!" << std::endl;
                break;
            }
        }
    }
}

void Menu::MenuBuffer(RingBuffer *buffer)
{
    while (true)
    {
        std::cout << " --- Buffer menu --- " << std::endl;
        std::cout << "1. Put" << std::endl;
        std::cout << "2. Get" << std::endl;
        std::cout << "3. Print" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        int choice = Input();
        switch (choice)
        {
            case 1:
            {
                std::cout << "Enter value: ";
                int value = Input();
                buffer->Put(value);
                PrintBuffer(buffer);
                break;
            }
            case 2:
            {
                std::cout << "Enter index: ";
                int index = Input();
                RingBufferNode *node = buffer->Get(index);
                if (node == nullptr)
                {
                    std::cout << "Node not found!" << std::endl;
                }
                else
                {
                    std::cout << "Node: " << node->GetData() << std::endl;
                }
                break;
            }
            case 3:
            {
                PrintBuffer(buffer);
                break;
            }
            case 4:
            {
                return;
            }
            default:
            {
                std::cout << "Invalid input!" << std::endl;
                break;
            }
        }
    }
}

void Menu::MenuStack(Stack *stack)
{
    while (true)
    {
        std::cout << " -- Stack menu ---" << std::endl;
        std::cout << "1. Push" << std::endl;
        std::cout << "2. Pop" << std::endl;
        std::cout << "3. Peek" << std::endl;
        std::cout << "4. Clear" << std::endl;
        std::cout << "5. Print" << std::endl;
        std::cout << "6. Back" << std::endl;
        std::cout << "Enter your choice: ";
        int choice = Input();
        switch (choice)
        {
            case 1:
            {
                std::cout << "Enter value: ";
                int value = Input();
                stack->Push(value);
                break;
            }
            case 2:
            {
                Node *node = stack->Pop();
                if (node == nullptr)
                {
                    std::cout << "Stack is empty!" << std::endl;
                }
                else
                {
                    std::cout << "Popped value: " << node->GetData() << std::endl;
                    delete node;
                }
                break;
            }
            case 3:
            {
                Node *node = stack->Peek();
                if (node == nullptr)
                {
                    std::cout << "Stack is empty!" << std::endl;
                }
                else
                {
                    std::cout << "Peeked value: " << node->GetData() << std::endl;
                }
                break;
            }
            case 4:
            {
                stack->Clear();
                break;
            }
            case 5:
            {
                PrintStack(stack);
                break;
            }
            case 6:
            {
                return;
            }
            default:
            {
                std::cout << "Invalid input!" << std::endl;
                break;
            }
        }
    }
}