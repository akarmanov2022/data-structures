//
// Created by akarmanov on 29-11-2022.
//

#ifndef DATA_STRUCTURES_MENU_H
#define DATA_STRUCTURES_MENU_H

class Menu
{
public:
    static int Input();

    static void PrintStack(Stack *stack);

    static void PrintStackQueue(StackQueue *queue);

    static void PrintBuffer(RingBuffer *buffer);

    static void PrintRingBufferQueue(RingBufferQueue *queue);

    static void MenuRingBufferQueue(RingBufferQueue *queue);

    static void MenuStackQueue(StackQueue *queue);

    static void MenuBuffer(RingBuffer *buffer);

    static void MenuStack(Stack *stack);
};

#endif //DATA_STRUCTURES_MENU_H
