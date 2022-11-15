
#include "List.h"
#include <stdexcept>
#include <unordered_set>

ListItem *List::AddAfter(ListItem *itemAfter, int value)
{
    auto *temp = new ListItem();
    auto next = itemAfter->GetNext();

    itemAfter->SetNext(temp);
    temp->SetData(value);
    temp->SetNext(next);
    temp->SetPrevious(itemAfter);

    if (next != nullptr)
    {
        next->SetPrevious(temp);
    }
    if (itemAfter == _previous)
    {
        _previous = temp;
    }
    _length++;
    return temp;
}

ListItem *List::InitHead(int value)
{
    auto *head = new ListItem();
    head->SetData(value);
    head->SetNext(nullptr);
    head->SetPrevious(nullptr);
    _length++;
    return _head = _previous = head;
}

ListItem *List::Remove(ListItem *item)
{
    if (item == nullptr)
    {
        throw std::invalid_argument(NULL_POINTER_EXCEPTION);
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

    if (item == _previous)
    {
        _previous = previous;
    }

    _length--;
    delete item;
    return previous;
}

ListItem *List::Add(int value)
{
    if (_length == 0)
    {
        return InitHead(value);
    }
    return AddAfter(_previous, value);
}

void List::Clear()
{
    auto temp = _previous;
    do
    {
        temp = this->Remove(temp);
    }
    while (temp != nullptr);
    _previous = nullptr;
    _head = nullptr;
}

ListItem *List::Remove(int index)
{
    ListItem *temp = GetItem(index);
    return this->Remove(temp);
}

ListItem *List::GetItem(int index) const
{
    CheckIndex(index);

    int id = 0;
    ListItem *item = _head;
    for (; item; item = item->GetNext())
    {
        if (index == id)
        {
            return item;
        }
        id++;
    }
    return item;
}

int List::GetLength() const
{
    return _length;
}

ListItem *List::GetHead() const
{
    return _head;
}

ListItem *List::GetPrevious() const
{
    return _previous;
}

ListItem *List::AddToBegin(int value)
{
    return this->AddAfter(_previous, value);
}

ListItem *List::AddToEnd(int value)
{
    return this->AddBefore(_head, value);
}

ListItem *List::AddBefore(ListItem *itemBefore, int value)
{
    auto previous = itemBefore->GetPrevious();

    auto *temp = new ListItem();
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

ListItem *List::Insert(int index, int value)
{
    if (index == 0)
    {
        return AddBefore(_head, value);
    }
    if (index == _length - 1)
    {
        return AddAfter(_previous, value);
    }
    auto temp = GetItem(index);
    return AddBefore(temp, value);
}

void List::CheckIndex(int index) const
{
    if (0 > index || index >= _length)
    {
        throw std::invalid_argument("Incorrect index!");
    }
}

void List::Sort()
{

}

void List::Swap(ListItem *first, ListItem *second)
{
    ListItem *firstNext = first->GetNext();
    ListItem *firstPrevious = first->GetPrevious();

    ListItem *secondNext = second->GetNext();
    ListItem *secondPrevious = second->GetPrevious();

    first->SetNext(secondNext);
    first->SetPrevious(secondPrevious);
    second->SetNext(firstNext);
    second->SetPrevious(firstPrevious);

}

List::List(int length, ListItem &head, ListItem &previous) : _length(length), _head(head), _previous(previous)
{}

