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

int Node::GetData() const
{
    return _data;
}

Node *Stack::Push(int value)
{
    auto *node = new Node(value);
    node->SetNext(_last);
    _last = node;
    _size++;
    return node;
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
    while (_size > 0)
    {
        Pop();
    }
}

int Stack::GetSize() const
{
    return _size;
}
