//
// Created by akarmanov on 10-12-2022.
//

#ifndef DATA_STRUCTURES_BINARYTREE_H
#define DATA_STRUCTURES_BINARYTREE_H

/**
 * Клаас, реализующий бинарное дерево поиска.
 * Дерево хранит в себе узлы, которые в свою очередь хранят в себе значение и указатели на левое и правое поддеревья.
 *
 * @author akarmanov
 * @date 10-12-2022
 */
class BinaryTree
{
private:
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
     *
     * @param value Значение, которое необходимо вставить.
     * @param node Узел, в который необходимо вставить значение.
     */
    void AddNode(int value, Node *node);

    /**
     * Рекурсивная функция, реализующая очистку дерева.
     * Начинает очистку с указанного узла.
     *
     * @param node Узел-начало, с которого необходимо начать очистку.
     */
    void DeleteTree(Node *node);

    /**
     * Вычисляет высоту дерева, начиная с указанного узла.
     *
     * @param node Узел, с которого необходимо начать вычисление высоты.
     * @return высота дерева.
     */
    int GetHeight(Node *node);

    /**
     * Возвращает указатель на узел с минимальным значением, начиная с указанного узла.
     *
     * @param node Вершина, с которой необходимо начать поиск.
     * @return значение узла.
     */
    int GetMin(Node *node);

    /**
     * Возвращает указатель на узел с максимальным значением, начиная с указанного узла.
     *
     * @param node Вершина, с которой необходимо начать поиск.
     * @return значение узла.
     */
    int GetMax(Node *node);

    /**
     * Рекурсивная функция, реализующая поиск узла в дереве.
     *
     * @param value Значение узла, который необходимо найти.
     * @param node Верхний узел поддерева, в котором необходимо найти узел.
     * @return Узел, если он найден, иначе nullptr.
     */
    Node *Find(int value, Node *node);

    /**
     * Рекурсивная функция, реализующая удаление узла из дерева.
     *
     * @param value Значение узла, который необходимо удалить.
     * @param node Верхний узел поддерева, в котором необходимо удалить узел.
     * @return Уделанный узел.
     */
    Node *Remove(int value, Node *node);

    void PrintInOrder(Node *node);

    void PrintPreOrder(Node *node);

    void PrintPostOrder(Node *node);

    void PrintTreeLevel(Node *node, int level);

public:
    /**
     * Конструктор.
     */
    BinaryTree(int rootValue);

    /**
     * Деструктор.
     */
    ~BinaryTree();

    /**
     * Добавляет новый узел в дерево.
     *
     * @param value Значение, которое необходимо вставить.
     */
    void AddNode(int value);

    /**
     * Вернуть высоту дерева.
     *
     * @return высота дерева.
     */
    int GetHeight();

    /**
     * Возвращает значение узла с минимальным значением.
     *
     * @return значение узла.
     */
    int GetMin();

    /**
     * Возвращает значение узла с максимальным значением.
     *
     * @return значение узла.
     */
    int GetMax();

    /**
     * Удаляет узел с указанным значением.
     *
     * @param value Значение узла, который необходимо удалить.
     */
    BinaryTree::Node *Remove(int value);


    /**
     * Поиск узла с указанным значением.
     *
     * @param value Значение узла, который необходимо найти.
     * @return Узел, если он найден, иначе nullptr.
     */
    Node *Find(int value);

    /**
     * Вывод дерева в консоль. Обход поперечным ходом.
     */
    void PrintInOrder();

    /**
     * Вывод дерева в консоль. Обход прямым ходом.
     */
    void PrintPreOrder();

    /**
     * Вывод дерева в консоль. Обход обратным ходом.
     */
    void PrintPostOrder();

    void PrintTreeLevel(int level);
};


#endif //DATA_STRUCTURES_BINARYTREE_H
