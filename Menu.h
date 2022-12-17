//
// Created by akarmanov on 10-12-2022.
//

#ifndef DATA_STRUCTURES_MENU_H
#define DATA_STRUCTURES_MENU_H


#include "lab5/BinaryTree.h"
#include "lab5/Treap.h"

/**
 * Класс, реализующий меню.
 *
 * @author akarmanov
 * @date 10-12-2022
 */
class Menu
{
public:
    /**
     * Запускает меню бинарного дерева.
     * @param tree бинарное дерево.
     */
    static void BinaryTreeMenu(BinaryTree *tree);

    /**
     * Запускает меню дека.
     * @param treap дек.
     */
    static void TreapMenu(Treap *treap);

    /**
     * Функция, реализующая ввод целого числа.
     *
     * @param message Выводимое сообщение.
     * @return Целое число.
     */
    static int InputInt(const char *message);

    /**
     * Функция, реализующая ввод положительного целого числа.
     *
     * @param message Выводимое сообщение.
     * @return Положительное целое число.
     */
    static int InputPositiveInt(const char *message);

    /**
     * Функция, реализующая ввод целого числа с проверкой по регулярному выражению.
     *
     * @param message Выводимое сообщение.
     * @param regex регулярное выражение.
     * @return Целое число.
     */
    static int InputInt(const char *message, const char *regex);

    /**
     * Генерирует случайное число.
     *
     * @return случайное число.
     */
    static int GetRandomInt();

    /**
     * Проверка на успешное удаление.
     *
     * @param check условие удаления.
     */
    static void CheckRemove(bool check);
};


#endif //DATA_STRUCTURES_MENU_H
