//
// Created by akarmanov on 29-11-2022.
//
#include <iostream>
#include <limits>
#include <regex>
#include "lab3/stack/Stack.h"
#include "lab3/queue/StackQueue.h"
#include "lab3/buffer/RingBuffer.h"
#include "lab3/queue/RingBufferQueue.h"

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

void Menu::MenuRingBufferQueue(RingBufferQueue *queue)
{
    while (true)
    {
        std::cout << " --- Ring buffer queue menu --- " << std::endl;
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Get size" << std::endl;
        std::cout << "4. Is empty" << std::endl;
        std::cout << "5. Print" << std::endl;
        std::cout << "6. Back" << std::endl;

        int choice = InputPositiveInt("Enter your choice: ");
        switch (choice)
        {
            case 1:
            {
                int value = InputInt("Enter _value: ");
                queue->Enqueue(value);
                break;
            }
            case 2:
            {
                int value = queue->Dequeue();
                if (value == 0)
                {
                    std::cout << "Queue is empty" << std::endl;
                }
                else
                {
                    std::cout << "Dequeued _value: " << value << std::endl;
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
                std::cout << "Is empty: " << (queue->IsEmpty() ? "true" : "false") << std::endl;
                break;
            }
            case 5:
            {
                queue->Print();
                break;
            }
            case 6:
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

        int choice = InputPositiveInt("Enter your choice: ");
        switch (choice)
        {
            case 1:
            {
                int value = InputInt("Enter _value: ");
                queue->Enqueue(value);
                break;
            }
            case 2:
            {
                int value = queue->Dequeue();
                if (value == 0)
                {
                    std::cout << "Queue is empty" << std::endl;
                }
                else
                {
                    std::cout << "Dequeued _value: " << value << std::endl;
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
                queue->Print();
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

void Menu::MenuBuffer(RingBuffer *buffer)
{
    while (true)
    {
        std::cout << " --- Buffer menu --- " << std::endl;
        std::cout << "1. Resize buffer" << std::endl;
        std::cout << "2. Add element" << std::endl;
        std::cout << "3. Get element" << std::endl;
        std::cout << "4. Get size" << std::endl;
        std::cout << "5. Print" << std::endl;
        std::cout << "6. Exit" << std::endl;

        int choice = InputPositiveInt("Enter your choice: ");
        switch (choice)
        {
            case 1:
            {
                int size = InputPositiveInt("Enter new size: ");
                if (size < buffer->GetSize())
                {
                    std::cout << "New size is less than current size" << std::endl;
                    break;
                }
                buffer->Resize(size);
                break;
            }
            case 2:
            {
                char *value = new char[256];
                std::cout << "Enter _value: ";
                std::cin >> value;
                buffer->Add(value);
                break;
            }
            case 3:
            {
                char *get = buffer->Get();
                if (get == nullptr)
                {
                    std::cout << "Buffer is empty" << std::endl;
                }
                else
                {
                    std::cout << "Get _value: " << get << std::endl;
                }
                break;
            }
            case 4:
            {
                std::cout << "Size: " << buffer->GetSize() << std::endl;
                break;
            }
            case 5:
            {
                buffer->Print();
                break;
            }
            case 6:
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

        int choice = InputInt("Enter your choice: ");
        switch (choice)
        {
            case 1:
            {
                int value = InputInt("Enter _value: ");
                stack->Push(value);
                break;
            }
            case 2:
            {
                int value = stack->Pop();
                if (value == 0)
                {
                    std::cout << "Stack is empty" << std::endl;
                }
                else
                {
                    std::cout << "Popped _value: " << value << std::endl;
                }
                break;
            }
            case 3:
            {
                int value = stack->Peek();
                if (value == 0)
                {
                    std::cout << "Stack is empty" << std::endl;
                }
                else
                {
                    std::cout << "Peeked _value: " << value << std::endl;
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
                stack->Print();
                break;
            }
            case 6:
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
