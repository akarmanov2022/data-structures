//
// Created by akarmanov on 06-11-2022.
//

#include "ListItem.h"

ListItem *ListItem::GetNext()
{
    return next;
}

void ListItem::SetNext(ListItem *item)
{
    ListItem::next = item;
}

ListItem *ListItem::GetPrevious()
{
    return previous;
}

void ListItem::SetPrevious(ListItem *item)
{
    ListItem::previous = item;
}

int ListItem::GetData() const
{
    return data;
}

void ListItem::SetData(int value)
{
    ListItem::data = value;
}
