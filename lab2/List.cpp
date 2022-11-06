//
// Created by akarmanov on 06-11-2022.
//

#include "List.h"

ListItem *List::Init(int firstValue)
{
    auto *item = new ListItem();
    item->SetData(firstValue);
    item->SetNext(nullptr);
    item->SetPrevious(nullptr);
    return item;
}

ListItem *List::Add(ListItem *itemAfter, int value)
{
    auto *temp = new ListItem();
    auto *next = itemAfter->GetNext();

    itemAfter->SetNext(temp);
    temp->SetPrevious(itemAfter);

    temp->SetData(value);
    temp->SetNext(next);
    temp->SetPrevious(itemAfter);

    if (next != nullptr)
    {
        next->SetPrevious(temp);
        this->last = next;
    }
    else
    {
        this->last = temp;
    }

    length++;
    return temp;
}

ListItem *List::Add(int value)
{
    if (length == 0)
    {
        first->SetData(value);
        length++;
        return first;
    }
    else
    {
        return Add(last, value);
    }
}

List::List()
{
    this->first = Init(0);
}

bool List::HasNext()
{
    return first->GetNext() != nullptr;
}

ListItem *List::Remove(ListItem *item)
{
    auto next = item->GetNext();
    auto previous = item->GetPrevious();

    if (previous != nullptr)
    {
        previous->SetNext(item->GetNext());
    }
    else
    {
        first = next;
    }

    if (next != nullptr)
    {
        next->SetPrevious(item->GetPrevious());
    }
    else
    {
        last = previous;
    }

    delete item;
    return previous;
}
