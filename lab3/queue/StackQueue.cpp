//
// Created by akarmanov on 28-11-2022.
//

#include "StackQueue.h"


StackQueue::StackQueue()
{
    _stack1 = new Stack();
    _stack2 = new Stack();
    _size = 0;
}

void StackQueue::Enqueue(int value)
{
    _stack1->Push(value);
    _size++;
}

int StackQueue::Dequeue()
{
    if (_size == 0)
    {
        return -1;
    }
    if (_stack2->GetSize() == 0)
    {
        while (_stack1->GetSize() > 0)
        {
            _stack2->Push(_stack1->Pop()->GetData());
        }
    }
    _size--;
    return _stack2->Pop()->GetData();
}


void StackQueue::Clear()
{
    _stack1->Clear();
    _stack2->Clear();
    _size = 0;
}

int StackQueue::GetSize() const
{
    return _size;
}
