//
// Created by akarmanov on 28-11-2022.
//

#ifndef DATA_STRUCTURES_RINGBUFFER_H
#define DATA_STRUCTURES_RINGBUFFER_H

/**
 * Элемент кольцевого буфера.
 */
class RingBufferNode
{
private:
    /**
     * Данные, хранимые в элементе.
     */
    int _data;
    /**
     * Указатель на следующий элемент.
     */
    RingBufferNode *_next{};
public:
    /**
     * Вернуть значение элемента.
     * @param value значение элемента.
     */
    int GetData() const;

    /**
     * Вернуть указатель на следующий элемент.
     * @return указатель на следующий элемент.
     */
    RingBufferNode *GetNext() const;

    /**
     * Установить указатель на следующий элемент.
     * @param next указатель на следующий элемент.
     */
    void SetNext(RingBufferNode *next);

    /**
     * Конструктор.
     * @param value значение элемента.
     */
    RingBufferNode(int value);
};

/**
 * Реализация кольцевого буфера.
 */
class RingBuffer
{
private:
    /**
     * Указатель на последний элемент.
     */
    RingBufferNode *_first;
    /**
     * Размер буфера.
     */
    int _size;
public:
    /**
     * Конструктор.
     * @param size размер буфера.
     */
    int GetSize() const;

    /**
     * Добавить элемент в буфер.
     * @param value значение элемента.
     * @return добавленный элемент.
     */
    RingBufferNode *Put(int value);

    /**
     * Вернуть указатель на элемент по индексу.
     * @param index индекс элемента.
     * @return указатель на элемент.
     */
    RingBufferNode *Get(int index);

    /**
     * Удалить элемент из буфера.
     * @param index индекс элемента.
     * @return удаленный элемент.
     */
    RingBufferNode *Remove(int index);

    /**
     * Очистить буфер.
     */
    void Clear();

    /**
     * Вернуть указатель на первый элемент.
     * @return указатель на первый элемент.
     */
    RingBufferNode *GetFirst() const;

    //TODO:
    RingBuffer(int size);
};


#endif //DATA_STRUCTURES_RINGBUFFER_H
