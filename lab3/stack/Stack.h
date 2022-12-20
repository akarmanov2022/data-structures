//
// Created by akarmanov on 27-11-2022.
//

#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#include <ostream>

/**
 * Элемент стека.
 */
class Node
{
private:
    /**
     * Данные, хранимые в элементе.
     */
    int _data;
    /**
     * Указатель на следующий элемент.
     */
    Node *_next{};
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
    Node *GetNext() const;

    /**
     * Установить указатель на следующий элемент.
     * @param next указатель на следующий элемент.
     */
    void SetNext(Node *next);

    /**
     * Конструктор.
     * @param value значение элемента.
     */
    Node(int value);
};

/**
 * Реализация стека.
 */
class Stack
{
private:
    /**
     * Указатель на последний элемент.
     */
    Node *_last;
    /**
     * Размер стека.
     */
    int _size;

public:
    /**
     * Добавить элемент в стек.
     * @param value - значение элемента.
     * @return указатель на добавленный элемент.
     */
    Node *Push(int value);

    /**
     * Удалить элемент из стека.
     * @return указатель на следующий элемент.
     */
    int Pop();

    /**
     * Вернуть указатель на последний элемент.
     * @return указатель на последний элемент.
     */
    int Peek();

    /**
     * Очистить стек.
     */
    void Clear();

    /**
     * Вернуть размер стека.
     */
    int GetSize() const;

    /**
     * Вернуть указатель на последний элемент.
     *
     * @return указатель на последний элемент.
     */
    Node *GetLast() const;

    /**
     * Перегрузка оператора вывода.
     *
     * @param os поток вывода.
     * @param stack ссылка на стек.
     * @return поток вывода.
     */
    friend std::ostream &operator<<(std::ostream &os, const Stack &stack);
};


#endif //DATA_STRUCTURES_STACK_H
