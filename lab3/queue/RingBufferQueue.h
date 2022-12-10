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
     * Кольцевой буфер.
     */
    RingBuffer *_buffer;
    /**
     * Размер очереди.
     */
    int _size;
public:
    /**
     * Конструктор.
     * @param size размер очереди.
     */
    RingBufferQueue(int size);

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

    /**
     * Вернуть буфер.
     * @return буфер.
     */
    RingBuffer *GetBuffer() const;

    void Print() const;
};


#endif //DATA_STRUCTURES_RINGBUFFERQUEUE_H
