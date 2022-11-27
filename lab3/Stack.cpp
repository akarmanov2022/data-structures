//
// Created by akarmanov on 27-11-2022.
//

#include "Stack.h"

Node *Node::GetNext() const
{
    return _next;
}

void Node::SetNext(Node *next)
{
    _next = next;
}

Node::Node(int value)
{
    this->_data = value;
}

Node *Stack::Push(int value)
{
    if (_size == 0)
    {
        _size++;
        return _last = new Node(value);
    }
    Node *next = new Node(value);
    next->SetNext(_last);
    _size++;
    return _last = next;
}

Node *Stack::Pop()
{
    if (_size == 0)
    {
        return _last = nullptr;
    }
    Node *next = _last->GetNext();
    _size--;
    delete _last;
    return _last = next;
}

Node *Stack::Peek()
{
    return _last;
}

void Stack::Clear()
{
    while (_last != nullptr)
    {
        _last = Pop();
    }
}
