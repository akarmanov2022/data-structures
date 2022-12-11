//
// Created by akarmanov on 11-12-2022.
//

#include <iostream>
#include "RingBuffer.h"

int RingBuffer::GetSize() const
{
    return _size;
}

bool RingBuffer::IsEmpty() const
{
    return _size == 0;
}

void RingBuffer::Put(int value)
{
    Node *node = new Node{value, nullptr};
    if (_last == nullptr)
    {
        node->_next = node;
        _last = node;
    }
    else
    {
        node->_next = _last->_next;
        _last->_next = node;
        _last = node;
    }
    _size++;
}

RingBuffer::Node *RingBuffer::Remove()
{
    if (_last == nullptr)
    {
        return nullptr;
    }
    Node *node = _last->_next;
    if (node == _last)
    {
        _last = nullptr;
    }
    else
    {
        _last->_next = node->_next;
    }
    _size--;
    return node;
}

void RingBuffer::Print()
{
    std::cout << "=== RingBuffer ===" << std::endl;
    if (_last == nullptr)
    {
        std::cout << "Empty buffer" << std::endl;
        return;
    }
    Node *node = _last->_next;
    std::cout << "Size: " << _size << std::endl;
    std::cout << "First: " << node->_data << std::endl;
    std::cout << "Last: " << _last->_data << std::endl;
    std::cout << "Elements: ";
    std::cout << "[";
    do
    {
        std::cout << node->_data << ", ";
        node = node->_next;
    } while (node != _last->_next);
    std::cout << "]" << std::endl;
}

RingBuffer::RingBuffer()
{
    _last = nullptr;
    _size = 0;
}

RingBuffer::~RingBuffer()
{
    while (_last != nullptr)
    {
        Remove();
    }
}
