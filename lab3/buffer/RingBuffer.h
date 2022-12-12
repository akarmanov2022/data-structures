//
// Created by akarmanov on 11-12-2022.
//

#ifndef DATA_STRUCTURES_RINGBUFFER_H
#define DATA_STRUCTURES_RINGBUFFER_H

/**
 * Кольцевой буфер.
 */
class RingBuffer
{
private:
    /**
     * Массив, хранящий элементы буфера.
     */
    char **_buffer;
    /**
     * Размер буфера.
     */
    int _size;
    /**
     * Количество элементов в буфере.
     */
    int _count;
    /**
     * Индекс первого элемента в буфере.
     */
    int _firstIndex;
    /**
     * Индекс последнего элемента в буфере.
     */
    int _lastIndex;
public:
    /**
     * Конструктор.
     * @param size размер буфера.
     */
    RingBuffer(int size);

    /**
     * Деструктор.
     */
    ~RingBuffer();

    void Add(char *value);

    char *Get();

    int GetSize() const;

    int GetFreeSize() const;

    int GetCount() const;

    void Print();

    void Resize(int size);
};


#endif //DATA_STRUCTURES_RINGBUFFER_H
