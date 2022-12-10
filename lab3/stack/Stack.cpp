//
// Created by akarmanov on 27-11-2022.
//

#include <iostream>
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

int Stack::Pop()
{
    if (_size == 0)
    {
        return 0;
    }
    auto *node = _last;
    _last = _last->GetNext();
    _size--;
    int data = node->GetData();
    delete node;
    return data;
}

int Stack::Peek()
{
    if (_size == 0)
    {
        return 0;
    }
    return _last->GetData();
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

void Stack::Print()
{
    Node *current = _last;
    std::cout << "=== Stack ===" << std::endl;
    std::cout << "Size: " << _size << std::endl;
    std::cout << "[";
    while (current != nullptr)
    {
        std::cout << current->GetData() << ", ";
        current = current->GetNext();
    }
    std::cout << "]" << std::endl;
}
