//
// Created by akarmanov on 06-11-2022.
//

#include "Node.h"

Node *Node::GetNext()
{
    return _next;
}

void Node::SetNext(Node *item)
{
    this->_next = item;
}

Node *Node::GetPrevious()
{
    return _previous;
}

void Node::SetPrevious(Node *item)
{
    this->_previous = item;
}

int Node::GetData() const
{
    return _data;
}

void Node::SetData(int value)
{
    this->_data = value;
}

bool Node::HasNext()
{
    return _next != nullptr;
}

bool Node::HasPrevious()
{
    return _previous != nullptr;
}

bool Node::operator<(const Node &item) const
{
    return _data < item._data;
}

bool Node::operator>(const Node &item) const
{
    return item < *this;
}

bool Node::operator<=(const Node &item) const
{
    return !(item < *this);
}

bool Node::operator>=(const Node &rhs) const
{
    return !(*this < rhs);
}


