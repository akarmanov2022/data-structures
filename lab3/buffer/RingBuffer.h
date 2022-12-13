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

    /**
     * Добавить элемент в буфер.
     * @param value значение элемента.
     */
    void Add(char *value);

    /**
     * Получить элемент из буфера.
     * @return значение элемента.
     */
    char *Get();

    /**
     * Вернуть размер буфера.
     * @return размер буфера.
     */
    int GetSize() const;

    /**
     * Вернуть свободное место в буфере.
     * @return свободное место в буфере.
     */
    int GetFreeSize() const;

    /**
     * Вернуть количество элементов в буфере.
     * @return количество элементов в буфере.
     */
    int GetCount() const;

    /**
     * Вывести информацию о буфере в консоль.
     */
    void Print();

    /**
     * Изменить размер буфера.
     *
     * @param size новый размер буфера.
     */
    void Resize(int size);
};


#endif //DATA_STRUCTURES_RINGBUFFER_H
