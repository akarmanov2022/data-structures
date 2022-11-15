//
// Created by akarmanov on 06-11-2022.
//

#include "ListItem.h"

ListItem *ListItem::GetNext()
{
    return _next;
}

void ListItem::SetNext(ListItem *item)
{
    this->_next = item;
}

ListItem *ListItem::GetPrevious()
{
    return _previous;
}

void ListItem::SetPrevious(ListItem *item)
{
    this->_previous = item;
}

int ListItem::GetData() const
{
    return _data;
}

void ListItem::SetData(int value)
{
    this->_data = value;
}

bool ListItem::HasNext()
{
    return _next != nullptr;
}

bool ListItem::HasPrevious()
{
    return _previous != nullptr;
}

bool ListItem::operator<(const ListItem &item) const
{
    return _data < item._data;
}

bool ListItem::operator>(const ListItem &item) const
{
    return item < *this;
}

bool ListItem::operator<=(const ListItem &item) const
{
    return !(item < *this);
}

bool ListItem::operator>=(const ListItem &rhs) const
{
    return !(*this < rhs);
}


