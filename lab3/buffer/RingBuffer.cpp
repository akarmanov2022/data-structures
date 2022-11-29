//
// Created by akarmanov on 28-11-2022.
//

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
    auto *node = new RingBufferNode(value, _size);
    if (_size == 0)
    {
        _first = node;
        node->SetNext(node);
    }
    else
    {
        node->SetNext(_first->GetNext());
        _first->SetNext(node);
    }
    _size++;
    return node;
}

RingBufferNode *RingBuffer::Get(int index)
{
    if (index >= _size)
    {
        return nullptr;
    }
    RingBufferNode *current = _first;
    for (int i = 0; i < index; i++)
    {
        current = current->GetNext();
    }
    return current;
}

RingBufferNode *RingBuffer::Remove(int index)
{
    if (index >= _size)
    {
        return nullptr;
    }
    RingBufferNode *current = _first;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->GetNext();
    }
    RingBufferNode *next = current->GetNext()->GetNext();
    RingBufferNode *removed = current->GetNext();
    current->SetNext(next);
    _size--;
    return removed;
}

void RingBuffer::Clear()
{
    while (_size > 0)
    {
        delete Remove(0);
    }

}

RingBufferNode *RingBuffer::GetFirst() const
{
    return _first;
}

RingBuffer::RingBuffer(int size)
{
    _size = size;
    _first = nullptr;
}
