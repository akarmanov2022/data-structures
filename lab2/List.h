//
// Created by akarmanov on 06-11-2022.
//

#include "Node.h"

static const char *const NULL_POINTER_EXCEPTION = "Null Pointer Exception!";

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

    static Node *MergeSort(Node *head);

    static Node *Split(Node *node);

    static Node *Merge(Node *a, Node *b);

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
