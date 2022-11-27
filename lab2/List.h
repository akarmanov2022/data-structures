//
// Created by akarmanov on 06-11-2022.
//


#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "Node.h"
#include "MergeSort.h"

/**
 * Представляет структуру данных - "Двусвязный список".
 */
class List
{
private:
    /**
     * Указатель на первый элемент списка.
     */
    Node *_head{};

    /**
     * Указатель на последний элемент списка.
     */
    Node *_last{};

    /**
     * Длинна списка (количество элементов).
     */
    int _length = 0;

    /**
     * Создает первый элемент (голову) списка.
     * @param value - значение первого элемента.
     * @return Первый элемент списка.
     */
    Node *InitHead(int value);

    /**
     * Добавляет элемент в позицию после указанного.
     * @param itemAfter - элемент, после которого вставляется новый.
     * @param value - значение нового элемента.
     * @return Новый элемент списка.
     */
    Node *AddAfter(Node *itemAfter, int value);

    /**
     * Добавляет элемент в позицию перед указанным.
     * @param itemAfter - элемент, перед которым вставляется новый.
     * @param value - значение нового элемента.
     * @return Новый элемент списка.
     */
    Node *AddBefore(Node *itemBefore, int value);

    /**
     * Проверка входной позиции на нахождение в границах списка.
     * @param index - индекс элемента.
     */
    void CheckIndex(int index) const;

public:

    /**
     * Удаляет входной элемент из списка.
     * @param item - входной элемент.
     * @return Предыдущий от удаленного элемент списка.
     */
    Node *Remove(Node *item);

    /**
     * Добавляет элемент в список.
     * @param value - значение элемента.
     * @return Добавленный элемент списка.
     */
    Node *Add(int value);

    /**
     * Вставляет новый элемент в определенную позицию списка.
     * @param index - позиция элемента.
     * @param value - значение элемента.
     * @return Добавленный элемент списка.
     */
    Node *Insert(int index, int value);

    /**
     * Вставляет новый элемент в начало списка.
     * @param value - значение элемента.
     * @return Добавленный элемент списка.
     */
    Node *AddToBegin(int value);

    /**
     * Вставляет новый элемент в конец списка.
     * @param value - значение элемента.
     * @return Добавленный элемент списка.
     */
    Node *AddToEnd(int value);

    /**
     * Удаляет элемент из списка.
     * @param index - позиция элемента.
     * @return Предыдущий элемент от удаленного.
     */
    Node *Remove(int index);

    /**
     * Очищает список.
     */
    void Clear();

    /**
     * Сортировка списка.
     */
    void Sort();

    /**
     * Возвращает первый элемент списка.
     */
    Node *GetHead() const;

    /**
     * Возвращает последний элемент списка.
     */
    Node *GetLast() const;

    /**
     * Возвращает длину списка.
     */
    int GetLength() const;

    /**
     * Возвращает элемент списка по его позиции.
     * @param index - позиция элемента.
     */
    Node *GetItem(int index) const;
};

#endif
