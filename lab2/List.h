//
// Created by akarmanov on 06-11-2022.
//


#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "Node.h"
#include "MergeSort.h"

class List
{
private:
    Node *_head{};
    Node *_previous{};
    int _length = 0;

    Node *InitHead(int value);

    Node *AddAfter(Node *itemAfter, int value);

    Node *AddBefore(Node *itemBefore, int value);

    void CheckIndex(int index) const;

public:

    Node *Remove(Node *item);

    Node *Add(int value);

    Node *Insert(int index, int value);

    Node *AddToBegin(int value);

    Node *AddToEnd(int value);

    Node *Remove(int index);

    void Clear();

    void Sort();

    Node *GetHead() const;

    Node *GetPrevious() const;

    int GetLength() const;

    Node *GetItem(int index) const;
};

#endif
