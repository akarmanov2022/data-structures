//
// Created by akarmanov on 28-11-2022.
//

#include <iostream>
#include "StackQueue.h"


StackQueue::StackQueue()
{
    _stackIn = new Stack();
    _stackOut = new Stack();
    _size = 0;
}

void StackQueue::Enqueue(int value)
{
    _stackIn->Push(value);
    _size++;
}

int StackQueue::Dequeue()
{
    if (_size == 0)
    {
        return -1;
    }
    if (_stackOut->GetSize() == 0)
    {
        while (_stackIn->GetSize() > 0)
        {
            _stackOut->Push(_stackIn->Pop()->GetData());
        }
    }
    _size--;
    return _stackOut->Pop()->GetData();
}


void StackQueue::Clear()
{
    _stackIn->Clear();
    _stackOut->Clear();
    _size = 0;
}

int StackQueue::GetSize() const
{
    return _size;
}

Stack *StackQueue::GetStackIn() const
{
    return _stackIn;
}

Stack *StackQueue::GetStackOut() const
{
    return _stackOut;
}

void StackQueue::Print()
{
    std::cout << "=== Queue ===" << std::endl;
    std::cout << "Stack In: ";
    _stackIn->Print();
    std::cout << "Stack Out: ";
    _stackOut->Print();
}
