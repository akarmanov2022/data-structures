//
// Created by akarmanov on 28-11-2022.
//

#ifndef DATA_STRUCTURES_STACKQUEUE_H
#define DATA_STRUCTURES_STACKQUEUE_H


#include <ostream>
#include "../stack/Stack.h"

/**
 * Очередь на двух стеках.
 */
class StackQueue
{
private:
    /**
     * Стек для входных значений.
     */
    Stack *_stackIn;
    /**
     * Стек для выходных значений.
     */
    Stack *_stackOut;
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

    /**
     * Вернуть стек входных значений.
     * @return
     */
    Stack *GetStackIn() const;

    /**
     * Вернуть стек выходных значений.
     * @return
     */
    Stack *GetStackOut() const;

    friend std::ostream &operator<<(std::ostream &os, const StackQueue &queue);
};


#endif //DATA_STRUCTURES_STACKQUEUE_H
