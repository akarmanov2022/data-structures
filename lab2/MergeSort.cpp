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
    Node *left = head;
    Node *right;

    Node *slow = Split(head);
    right = slow->GetNext();
    slow->SetNext(nullptr);

    left = Sort(left);
    right = Sort(right);

    head = Merge(left, right);
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

Node *MergeSort::Merge(Node *left, Node *right)
{
    if (left == nullptr)
    {
        return right;
    }
    if (right == nullptr)
    {
        return left;
    }

    if (left->GetData() > right->GetData())
    {
        Node *merge = Merge(left->GetNext(), right);
        merge->SetPrevious(left);
        left->SetNext(merge);
        left->SetPrevious(nullptr);
        return left;
    }
    else
    {
        Node *merge = Merge(left, right->GetNext());
        merge->SetPrevious(right);
        right->SetNext(merge);
        right->SetPrevious(nullptr);
        return right;
    }
}
