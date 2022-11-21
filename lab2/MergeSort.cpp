//
// Created by aka on 11/21/22.
//

#include "MergeSort.h"

Node *MergeSort::Sort(Node *head)
{
    if (head == nullptr || head->GetNext() == nullptr)
    {
        return head;
    }
    Node *a = head;
    Node *b;

    Node *slow = Split(head);
    b = slow->GetNext();
    slow->SetNext(nullptr);

    a = Sort(a);
    b = Sort(b);

    head = Merge(a, b);
    return head;
}

Node *MergeSort::Split(Node *node)
{
    Node *slow = node;
    Node *fast = node->GetNext();
    while (fast)
    {
        fast = fast->GetNext();
        if (fast)
        {
            slow = slow->GetNext();
            fast = fast->GetNext();
        }
    }
    return slow;
}

Node *MergeSort::Merge(Node *a, Node *b)
{
    if (a == nullptr)
    {
        return b;
    }
    if (b == nullptr)
    {
        return a;
    }

    if (a->GetData() > b->GetData())
    {
        Node *merge = Merge(a->GetNext(), b);
        merge->SetPrevious(a);
        a->SetNext(merge);
        a->SetPrevious(nullptr);
        return a;
    }
    else
    {
        Node *merge = Merge(a, b->GetNext());
        merge->SetPrevious(b);
        b->SetNext(merge);
        b->SetPrevious(nullptr);
        return b;
    }
}
