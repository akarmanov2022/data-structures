//
// Created by akarmanov on 10-12-2022.
//

#ifndef DATA_STRUCTURES_TREAP_H
#define DATA_STRUCTURES_TREAP_H

#include <ostream>

/**
 * Класс, реализующий декартово дерево.
 *
 * @author akarmanov
 * @date 10-12-2022
 */
class Treap
{
private:

    const std::string ch_hor = "\u2500" /*─*/;
    const std::string ch_ver = "\u2502" /*│*/;
    const std::string ch_ddia = "\u250C" /*┌*/;
    const std::string ch_rddia = "\u2510" /*┐*/;
    const std::string ch_udia = "\u2514" /*└*/;
    const std::string ch_ver_hor = "\u251C\u2500" /*├─*/;
    const std::string ch_udia_hor = "\u2514\u2500" /*└─*/;
    const std::string ch_ddia_hor = "\u250C\u2500" /*┌─*/;
    const std::string ch_ver_spa = "\u2502 " /*│ */;

    /**
     * Структура, описывающая узел дерева.
     */
    struct Node
    {
        /**
         * Значение узла.
         */
        int _value;
        /**
         * Приоритет узла.
         */
        int _priority;
        /**
         * Указатель на левое поддерево.
         */
        Node *_left;
        /**
         * Указатель на правое поддерево.
         */
        Node *_right;
    };
    /**
     * Корень дерева.
     */
    Node *_root;

    /**
     * Рекурсивная функция, реализующая вставку в дерево.
     * Использует неоптимизированный алгоритм.
     *
     * @param value Значение узла, который нужно вставить.
     * @param priority Приоритет, которым необходимо пометить узел.
     * @param node Вершина поддерева, в которое необходимо вставить узел.
     */
    void InsertNonOptimized(int value, int priority, Node *&node);

    /**
     * Рекурсивная функция, реализующая вставку в дерево.
     * Использует оптимизированный алгоритм.
     *
     * @param value Значение, которое необходимо вставить.
     * @param priority Приоритет, которым необходимо пометить узел.
     * @param node Вершина поддерева, в которое необходимо вставить узел.
     */
    void InsertOptimized(int value, int priority, Node *&node);

    /**
     * Рекурсивная функция, реализующая удаление из дерева.
     * Использует неоптимизированный алгоритм.
     *
     * @param value Значение узла, который необходимо удалить.
     * @param node Вершина поддерева, из которого необходимо удалить узел.
     */
    Treap::Node *RemoveNonOptimized(int value, Node *&node);

    /**
     * Рекурсивная функция, реализующая удаление из дерева.
     * Использует оптимизированный алгоритм.
     *
     * @param value Значение узла, который необходимо удалить.
     * @param node Вершина поддерева, из которого необходимо удалить узел.
     */
    Treap::Node *RemoveOptimized(int value, Node *&node);

    /**
     * Рекурсивная функция, реализующая разбиение дерева на левое и правое поддеревья.
     *
     * @param node Вершина поддерева, которое необходимо разбить.
     * @param key Значение, по которому необходимо разбить дерево.
     * @param left Вершина левого поддерева.
     * @param right Вершина правого поддерева.
     */
    void Split(Node *node, int key, Node *&left, Node *&right);

    /**
     * Рекурсивная функция, реализующая слияние двух деревьев.
     *
     * @param left Вершина левого поддерева.
     * @param right Вершина правого поддерева.
     * @return Вершина нового дерева.
     */
    Node *&Merge(Node *&left, Node *&right);

    /**
     * Рекурсивная функция, реализующая поиск узла по значению.
     *
     * @param value Значение узла, который необходимо найти.
     * @param node Вершина поддерева, в котором необходимо найти узел.
     * @return Узел, если он был найден, иначе nullptr.
     */
    Node *Find(int value, Node *node);

    /**
     * Рекурсивная функция, которая возвращает высоту поддерева.
     *
     * @param node Вершина поддерева, высоту которого необходимо определить.
     * @return Значение высоты поддерева.
     */
    int GetHeight(Node *node);

    /**
     * Рекурсивная функция, реализующая удаление поддерева, начиная с указанной вершины.
     *
     * @param node Вершина поддерева, которое необходимо удалить.
     */
    void DeleteTree(Node *node);

    /**
 * Рекурсивная функция, реализующая вывод дерева.
 * @param ostream поток вывода.
 * @param node корень поддерева, которое необходимо вывести.
 * @param prefix первая часть строки, которая выводится перед каждой строкой.
 * @param root условие, которое определяет, является ли текущий узел корнем дерева.
 * @param last условие, которое определяет, является ли текущий узел последним в поддереве.
 */
    void Dump(std::ostream &ostream, Node *node, std::string prefix, bool root, bool last);

public:

    /**
     * Конструктор.
     */
    Treap(int rootValue, int rootPriority);

    /**
     * Деструктор.
     */
    ~Treap();

    /**
     * Функция, реализующая добавление узла в дерево.
     * Использует неоптимизированный алгоритм.
     *
     * @param value Значение узла, который необходимо добавить.
     * @param priority Приоритет узла, который необходимо добавить.
     */
    void InsertNonOptimized(int value, int priority);

    /**
     * Функция, реализующая добавление узла в дерево.
     * Использует оптимизированный алгоритм.
     *
     * @param value Значение узла, который необходимо добавить.
     * @param priority Приоритет узла, который необходимо добавить.
     */
    void InsertOptimized(int value, int priority);

    /**
     * Функция, реализующая удаление узла из дерева.
     * Использует неоптимизированный алгоритм.
     *
     * @param value Значение узла, который необходимо удалить.
     */
    Node *RemoveNonOptimized(int value);

    /**
     * Функция, реализующая удаление узла из дерева.
     * Использует оптимизированный алгоритм.
     *
     * @param value Значение узла, который необходимо удалить.
     */
    Node *RemoveOptimized(int value);

    /**
     * Возвращает высоту дерева.
     * @return Значение высоты дерева.
     */
    int GetHeight();

    /**
     * Функция, реализующая поиск узла в дереве.
     *
     * @param value Значение узла, который необходимо найти.
     * @return Узел, если он был найден, иначе nullptr.
     */
    Node *Find(int value);

    friend std::ostream &operator<<(std::ostream &os, Treap &treap);
};


#endif //DATA_STRUCTURES_TREAP_H
