#ifndef DATA_STRUCTURES_MERGE_SORT_H
#define DATA_STRUCTURES_MERGE_SORT_H

#include "Node.h"

//
// Created by aka on 11/21/22.
//
/**
 * Представляет сортировку слиянием.
 */
class MergeSort
{
    /**
     * Разделяет список на две части относительно указанного элемента.
     * @param node - Элемента списка.
     */
    static Node *Split(Node *node);

    /**
     *
     * @param left
     * @param right
     * @return
     */
    static Node *Merge(Node *left, Node *right);

public:
    /**
     * Сортирует список
     * @param head
     * @return
     */
    static Node *Sort(Node *head);
};

#endif