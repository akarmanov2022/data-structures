//
// Created by akarmanov on 06-11-2022.
//

#ifndef DATA_STRUCTURES_NODE_H
#define DATA_STRUCTURES_NODE_H


class Node
{
private:
    Node* _next{};
    Node* _previous{};
    int _data = 0;
public:
    bool HasNext();

    bool HasPrevious();

    Node *GetNext();

    void SetNext(Node *item);

    Node *GetPrevious();

    void SetPrevious(Node *item);

    int GetData() const;

    void SetData(int value);

    bool operator<(const Node &rhs) const;

    bool operator>(const Node &rhs) const;

    bool operator<=(const Node &rhs) const;

    bool operator>=(const Node &rhs) const;
};


#endif //DATA_STRUCTURES_NODE_H
