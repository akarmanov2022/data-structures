//
// Created by akarmanov on 28-11-2022.
//

#include <iostream>
#include "RingBuffer.h"

int RingBufferNode::GetData() const
{
    return _data;
}

RingBufferNode *RingBufferNode::GetNext() const
{
    return _next;
}

void RingBufferNode::SetNext(RingBufferNode *next)
{
    this->_next = next;
}

RingBufferNode::RingBufferNode(int value, int index)
{
    this->_data = value;
    this->_index = index;
}

int RingBufferNode::GetIndex() const
{
    return _index;
}

int RingBuffer::GetSize() const
{
    return _size;
}

RingBufferNode *RingBuffer::Put(int value)
{
    if (_size == 0)
    {
        _last = new RingBufferNode(value, 0);
        _last->SetNext(_last);
        _size++;
        return _last;
    }
    auto *node = new RingBufferNode(value, _last->GetIndex() + 1);
    node->SetNext(_last->GetNext());
    _last->SetNext(node);
    _last = node;
    _size++;
    return node;
}

int RingBuffer::Get(int index)
{
    if (_size == 0)
    {
        return 0;
    }
    auto *node = _last->GetNext();
    while (node->GetIndex() != index)
    {
        node = node->GetNext();
    }
    return node->GetData();
}

RingBufferNode *RingBuffer::Remove(int index)
{
    if (_size == 0)
    {
        return nullptr;
    }
    auto *node = _last->GetNext();
    if (node->GetIndex() == index)
    {
        _last->SetNext(node->GetNext());
        _size--;
        return node;
    }
    while (node->GetNext()->GetIndex() != index)
    {
        node = node->GetNext();
    }
    auto *removed = node->GetNext();
    node->SetNext(removed->GetNext());
    _size--;
    return removed;
}

void RingBuffer::Clear()
{
    if (_size == 0)
    {
        return;
    }
    auto *node = _last->GetNext();
    while (node != _last)
    {
        auto *next = node->GetNext();
        delete node;
        node = next;
    }
    delete _last;
    _size = 0;
}

RingBufferNode *RingBuffer::GetFirst() const
{
    return _last;
}

RingBuffer::RingBuffer(int size)
{
    _size = 0;
    _last = nullptr;
}

void RingBuffer::Print()
{
    std::cout << "RingBuffer: ";
    std::cout << "Size: " << _size << std::endl;
    if (_size == 0)
    {
        std::cout << "Empty" << std::endl;
        return;
    }
    std::cout << "First: " << _last->GetNext()->GetData() << std::endl;
    std::cout << "Last: " << _last->GetData() << std::endl;
    std::cout << "Data: ";
    std::cout << "[";
    RingBufferNode *current = _last;
    for (int i = 0; i < _size; i++)
    {
        std::cout << current->GetData() << ", ";
        current = current->GetNext();
    }
    std::cout << "]" << std::endl;
    std::cout << std::endl;
}
