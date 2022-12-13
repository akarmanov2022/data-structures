//
// Created by akarmanov on 27-11-2022.
//

#include <iostream>
#include "lab3/stack/Stack.h"
#include "lab3/buffer/RingBuffer.h"
#include "lab3/queue/StackQueue.h"
#include "lab3/queue/RingBufferQueue.h"
#include "Menu.h"

int main()
{
    auto *stack = new Stack();
    auto *stackQueue = new StackQueue();
    auto *ringBufferQueue = new RingBufferQueue();

    while (true)
    {
        std::cout << "1. Stack" << std::endl;
        std::cout << "2. Buffer" << std::endl;
        std::cout << "3. StackQueue" << std::endl;
        std::cout << "4. RingBufferQueue" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice = Menu::InputInt("Enter your choice: ");
        switch (choice)
        {
            case 1:
            {
                Menu::MenuStack(stack);
                break;
            }
            case 2:
            {
                int size = Menu::InputInt("Enter buffer size: ");
                auto *buffer = new RingBuffer(size);
                Menu::MenuBuffer(buffer);
                break;
            }
            case 3:
            {
                Menu::MenuStackQueue(stackQueue);
                break;
            }
            case 4:
            {
                Menu::MenuRingBufferQueue(ringBufferQueue);
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
