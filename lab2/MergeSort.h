#include "Node.h"

//
// Created by aka on 11/21/22.
//
class MergeSort
{

    static Node *Split(Node *node);

    static Node *Merge(Node *a, Node *b);

public:
    static Node *Sort(Node *head);
};
