//
// Created by akarmanov on 11-12-2022.
//

#include <iostream>
#include "RingBuffer.h"

RingBuffer::RingBuffer(int size)
{
    _firstIndex = 0;
    _lastIndex = 0;
    _count = 0;
    _size = size;
    _buffer = new char *[_size];
    for (int i = 0; i < _size; i++)
    {
        _buffer[i] = nullptr;
    }
}

void RingBuffer::Add(char *value)
{
    if (_count == _size)
    {
        _buffer[_firstIndex] = value;
        _firstIndex = (_firstIndex + 1) % _size;
        _lastIndex = (_lastIndex + 1) % _size;
        return;
    }
    _buffer[_lastIndex] = value;
    _lastIndex = (_lastIndex + 1) % _size;
    _count++;
}

char *RingBuffer::Get()
{
    if (_count == 0)
    {
        return nullptr;
    }
    char *value = _buffer[_firstIndex];
    _buffer[_firstIndex] = nullptr;
    _firstIndex = (_firstIndex + 1) % _size;
    _count--;
    return value;
}

int RingBuffer::GetSize() const
{
    return _size;
}

int RingBuffer::GetFreeSize() const
{
    return _size - _count;
}

int RingBuffer::GetCount() const
{
    return _count;
}

//TODO: remove from model
//void RingBuffer::Print()
//{
//    std::cout << "RingBuffer: " << std::endl;
//    std::cout << "Size: " << _size << std::endl;
//    std::cout << "Count: " << _count << std::endl;
//    std::cout << "Free size: " << GetFreeSize() << std::endl;
//    std::cout << "First index: " << _firstIndex << std::endl;
//    std::cout << "Last index: " << _lastIndex << std::endl;
//    std::cout << "Buffer: " << std::endl;
//    std::cout << "[";
//    for (int i = 0; i < _size; i++)
//    {
//        if (_buffer[i] == nullptr)
//        {
//            std::cout << "null";
//        }
//        else
//        {
//            std::cout << _buffer[i];
//        }
//        if (i != _size - 1)
//        {
//            std::cout << ", ";
//        }
//    }
//    std::cout << "]" << std::endl;
//    std::cout << std::endl;
//}

void RingBuffer::Resize(int size)
{
    if (size < _count)
    {
        return;
    }
    char **newBuffer = new char *[size];
    for (int i = 0; i < size; i++)
    {
        newBuffer[i] = nullptr;
    }
    for (int i = 0; i < _count; i++)
    {
        newBuffer[i] = _buffer[(_firstIndex + i) % _size];
    }
    delete[] _buffer;
    _buffer = newBuffer;
    _size = size;
    _firstIndex = 0;
    _lastIndex = _count;
}

RingBuffer::~RingBuffer()
{
    delete[] _buffer;
}

char **RingBuffer::GetBuffer() const
{
    return _buffer;
}

int RingBuffer::GetFirstIndex() const
{
    return _firstIndex;
}

int RingBuffer::GetLastIndex() const
{
    return _lastIndex;
}
