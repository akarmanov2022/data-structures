//
// Created by akarmanov on 28-11-2022.
//

#include <iostream>
#include "RingBufferQueue.h"

RingBufferQueue::RingBufferQueue()
{
    _last = nullptr;
    _size = 0;
}

RingBufferQueue::~RingBufferQueue()
{
    Clear();
}

void RingBufferQueue::Enqueue(int value)
{
    auto *node = new Node{value, nullptr};
    if (_last == nullptr)
    {
        node->_next = node;
    }
    else
    {
        node->_next = _last->_next;
        _last->_next = node;
    }
    _last = node;
}

int RingBufferQueue::Dequeue()
{
    if (_last == nullptr)
    {
        return 0;
    }
    auto *node = _last->_next;
    if (node == _last)
    {
        _last = nullptr;
    }
    else
    {
        _last->_next = node->_next;
    }
    int data = node->_value;
    delete node;
    return data;
}

int RingBufferQueue::GetSize() const
{
    return _size;
}

bool RingBufferQueue::IsEmpty() const
{
    return _last == nullptr;
}

void RingBufferQueue::Print() const
{
    std::cout << "=== Queue ===" << std::endl;
    if (_last == nullptr)
    {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    auto *node = _last->_next;
    std::cout << "Size: " << _size << std::endl;
    std::cout << "First: " << node->_value << std::endl;
    std::cout << "Last: " << _last->_value << std::endl;
    std::cout << "Elements: ";
    std::cout << "[";
    do
    {
        std::cout << node->_value;
        node = node->_next;
        if (node != _last->_next)
        {
            std::cout << ", ";
        }
    }
    while (node != _last->_next);
    std::cout << "]" << std::endl;
}

void RingBufferQueue::Clear()
{
    if (_last == nullptr)
    {
        return;
    }
    auto *node = _last->_next;
    while (node != _last)
    {
        auto *next = node->_next;
        delete node;
        node = next;
    }
    delete node;
    _last = nullptr;
}