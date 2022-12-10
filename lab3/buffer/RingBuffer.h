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
     * Индекс элемента в очереди.
     */
    int _index;
    /**
     * Указатель на следующий элемент.
     */
    RingBufferNode *_next{};
public:
    /**
     * Конструктор.
     * @param value значение элемента.
     * @param index значение индекса элемента.
     */
    RingBufferNode(int value, int index);

    /**
     * Вернуть значение элемента.
     * @param value значение элемента.
     */
    int GetData() const;

    /**
     * Вернуть значение индекса элемента.
     * @param value значение индекса элемента.
     */
    int GetIndex() const;

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
    RingBufferNode *_last;
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
    int Get(int index);

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

    /**
     * Конструктор.
     * @param size размер буфера.
     */
    RingBuffer(int size);

    void Print();
};


#endif //DATA_STRUCTURES_RINGBUFFER_H
