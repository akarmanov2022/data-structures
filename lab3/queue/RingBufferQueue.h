//
// Created by akarmanov on 28-11-2022.
//

#ifndef DATA_STRUCTURES_RINGBUFFERQUEUE_H
#define DATA_STRUCTURES_RINGBUFFERQUEUE_H

#include "../buffer/RingBuffer.h"

/**
 * Очередь на кольцевом буфере.
 */
class RingBufferQueue
{
private:
    /**
     * Структура, описывающая элемент очереди.
     */
    struct Node
    {
        /**
         * Данные, хранимые в элементе.
         */
        int _value;
        /**
         * Указатель на следующий элемент.
         */
        Node *_next;
    };
    /**
     * Указатель на последний элемент очереди.
     */
    Node *_last;

    /**
     * Размер очереди.
     */
    int _size;

public:
    /**
     * Конструктор.
     * @param size размер очереди.
     */
    RingBufferQueue();

    /**
     * Деструктор.
     */
    ~RingBufferQueue();

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
     * Вернуть размер очереди.
     * @return размер очереди.
     */
    int GetSize() const;

    /**
     * Вернуть true, если очередь пуста.
     * @return true, если очередь пуста.
     */
    bool IsEmpty() const;

    void Print() const;

    /**
     * Очистить очередь.
     */
    void Clear();
};


#endif //DATA_STRUCTURES_RINGBUFFERQUEUE_H
