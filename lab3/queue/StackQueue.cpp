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
        return 0;
    }
    if (_stackOut->GetSize() == 0)
    {
        while (_stackIn->GetSize() > 0)
        {
            _stackOut->Push(_stackIn->Pop());
        }
    }
    _size--;
    return _stackOut->Pop();
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

std::ostream &operator<<(std::ostream &os, const StackQueue &queue)
{
    os << "StackIn: " << *queue.GetStackIn() << std::endl;
    os << "StackOut: " << *queue.GetStackOut() << std::endl;
    return os;
}

//TODO: remove from model
//void StackQueue::Print()
//{
//    std::cout << "=== Queue ===" << std::endl;
//    std::cout << "Stack In: ";
//    _stackIn->Print();
//    std::cout << "Stack Out: ";
//    _stackOut->Print();
//}
