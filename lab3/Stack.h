//
// Created by akarmanov on 27-11-2022.
//

#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H


class Node
{
private:
    int _data;
    Node *_next{};
public:
    Node *GetNext() const;

    void SetNext(Node *next);

    Node(int value);
};

class Stack
{
private:
    Node *_last;
    int _size;

public:
    Node *Push(int value);

    Node *Pop();

    Node *Peek();

    void Clear();
};


#endif //DATA_STRUCTURES_STACK_H
