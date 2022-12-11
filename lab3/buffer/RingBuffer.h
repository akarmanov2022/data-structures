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
     * Строка, хранящая элементы буфера.
     */
    struct Node
    {
        /**
         * Данные, хранимые в элементе.
         */
        int _data;
        /**
         * Указатель на следующий элемент.
         */
        Node *_next;
    };
    /**
     * Указатель на последний элемент.
     */
    Node *_last;

    /**
     * Размер буфера.
     */
    int _size;

public:
    /**
     * Вернуть размер буфера.
     * @return размер буфера.
     */
    int GetSize() const;

    /**
     * Проверить, пуст ли буфер.
     * @return true, если буфер пуст, иначе false.
     */
    bool IsEmpty() const;

    /**
     * Добавить элемент в буфер.
     * @param value значение элемента.
     */
    void Put(int value);

    /**
     * Удалить элемент из буфера.
     * @return значение элемента.
     */
    Node *Remove();

    /**
     * Конструктор.
     */
    RingBuffer();

    /**
     * Деструктор.
     */
    ~RingBuffer();

    void Print();
};


#endif //DATA_STRUCTURES_RINGBUFFER_H
