
#include "List.h"
#include "MergeSort.h"
#include <stdexcept>
#include <unordered_set>

Node *List::AddAfter(Node *itemAfter, int value)
{
    auto *temp = new Node();
    auto next = itemAfter->GetNext();

    itemAfter->SetNext(temp);
    temp->SetData(value);
    temp->SetNext(next);
    temp->SetPrevious(itemAfter);

    if (next != nullptr)
    {
        next->SetPrevious(temp);
    }
    if (itemAfter == _last)
    {
        _last = temp;
    }
    _length++;
    return temp;
}

Node *List::InitHead(int value)
{
    auto *head = new Node();
    head->SetData(value);
    head->SetNext(nullptr);
    head->SetPrevious(nullptr);
    _length++;
    return _head = _last = head;
}

Node *List::Remove(Node *item)
{
    if (item == nullptr)
    {
        throw std::invalid_argument("Incorrect value");
    }
    auto next = item->GetNext();
    auto previous = item->GetPrevious();

    if (previous != nullptr)
    {
        previous->SetNext(item->GetNext());
    }

    if (next != nullptr)
    {
        next->SetPrevious(item->GetPrevious());
    }

    if (item == _head)
    {
        _head = next;
    }

    if (item == _last)
    {
        _last = previous;
    }

    _length--;
    delete item;
    return previous;
}

Node *List::Add(int value)
{
    if (_length == 0)
    {
        return InitHead(value);
    }
    return AddAfter(_last, value);
}

void List::Clear()
{
    auto temp = _last;
    while (temp != nullptr)
    {
        temp = this->Remove(temp);
    }
    _last = nullptr;
    _head = nullptr;
}

Node *List::Remove(int index)
{
    Node *temp = GetItem(index);
    return this->Remove(temp);
}

Node *List::GetItem(int index) const
{
    CheckIndex(index);

    if (index < _length / 2)
    {
        Node *node = _head;
        for (int i = 0; i < index; ++i)
        {
            node = node->GetNext();
        }
        return node;
    }
    else
    {
        Node *node = _last;
        for (int i = _length - 1; i > index; i--)
        {
            node = node->GetPrevious();
        }
        return node;
    }
}

int List::GetLength() const
{
    return _length;
}

Node *List::GetHead() const
{
    return _head;
}

Node *List::GetLast() const
{
    return _last;
}

Node *List::AddToEnd(int value)
{
    return this->AddAfter(_last, value);
}

Node *List::AddToBegin(int value)
{
    return this->AddBefore(_head, value);
}

Node *List::AddBefore(Node *itemBefore, int value)
{
    auto previous = itemBefore->GetPrevious();

    auto *temp = new Node();
    temp->SetData(value);
    temp->SetNext(itemBefore);
    temp->SetPrevious(previous);
    itemBefore->SetPrevious(temp);

    if (previous != nullptr)
    {
        previous->SetNext(temp);
    }
    if (itemBefore == _head)
    {
        _head = temp;
    }
    _length++;
    return temp;
}

Node *List::Insert(int index, int value)
{
    CheckIndex(index);
    if (_length == 0)
    {
        return Add(value);
    }
    if (index == 0)
    {
        return AddBefore(_head, value);
    }
    if (index == _length - 1)
    {
        return AddAfter(_last, value);
    }
    auto temp = GetItem(index);
    return AddBefore(temp, value);
}

void List::CheckIndex(int index) const
{
    if (0 > index || index >= _length)
    {
        throw "Incorrect index!";
    }
}

void List::Sort()
{
    _head = MergeSort::Sort(_head);
    auto node = _head;
    for (int i = 0; i < _length - 1; ++i)
    {
        node = node->GetNext();
    }
    _last = node;
}

int List::LinearSearch(int value)
{
    auto node = _head;
    for (int i = 0; i < _length; ++i)
    {
        if (node->GetData() == value)
        {
            return i;
        }
        node = node->GetNext();
    }
    return -1;
}
