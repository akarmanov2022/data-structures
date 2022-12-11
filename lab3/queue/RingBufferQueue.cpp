//
// Created by akarmanov on 28-11-2022.
//

#include <iostream>
#include "RingBufferQueue.h"

RingBufferQueue::RingBufferQueue()
{
    _buffer = new RingBuffer();
    _size = 0;
}

void RingBufferQueue::Enqueue(int value)
{
    _buffer->Put(value);
    _size++;
}

int RingBufferQueue::Dequeue()
{
    if (_size == 0)
    {
        return 0;
    }
    _size--;
    return _buffer->Remove()->_data;
}

int RingBufferQueue::GetSize() const
{
    return _size;
}

bool RingBufferQueue::IsEmpty() const
{
    return _size == 0;
}

RingBuffer *RingBufferQueue::GetBuffer() const
{
    return _buffer;
}

void RingBufferQueue::Print() const
{
    std::cout << "=== Queue ===" << std::endl;
    _buffer->Print();
}

RingBufferQueue::~RingBufferQueue()
{
    delete _buffer;
}
