//
// Created by akarmanov on 28-11-2022.
//

#ifndef DATA_STRUCTURES_STACKQUEUE_H
#define DATA_STRUCTURES_STACKQUEUE_H


#include "../stack/Stack.h"

/**
 * Очередь на двух стеках.
 */
class StackQueue
{
private:
    /**
     * Первый стек.
     */
    Stack *_stack1;
    /**
     * Второй стек.
     */
    Stack *_stack2;
    /**
     * Size of the queue.
     */
    int _size;
public:
    /**
     * Конструктор.
     */
    StackQueue();

    /**
     * Добавить элемент в очередь.
     * @param value значение элемента.
     */
    void Enqueue(int value);

    /**
     * Удалить элемент из очереди.
     * @return значение элемента.
     */
    int Dequeue();

    /**
     * Очистить очередь.
     */
    void Clear();

    /**
     * Получить размер очереди.
     * @return размер очереди.
     */
    int GetSize() const;
};


#endif //DATA_STRUCTURES_STACKQUEUE_H
