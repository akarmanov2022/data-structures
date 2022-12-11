//
// Created by akarmanov on 10-12-2022.
//

#ifndef DATA_STRUCTURES_TREAP_H
#define DATA_STRUCTURES_TREAP_H

class Treap
{
private:
    struct Node
    {
        int value;
        int priority;
        Node *left;
        Node *right;
    };
    Node *root;

    void InsertNonOptimized(int value, int priority, Node *&node);

    void InsertOptimized(int value, int priority, Node *&node);

    void RemoveNonOptimized(int value, Node *&node);

    void RemoveOptimized(int value, Node *&node);

    void Split(Node *node, int key, Node *&left, Node *&right);

    Node *Merge(Node *left, Node *right);

    Node *Find(int value, Node *node);

    Node *FindMin(Node *node);

    Node *FindMax(Node *node);

    int GetMin(Node *node);

    int GetMax(Node *node);

    int GetHeight(Node *node);

    void DeleteTree(Node *node);

    bool Contains(int value, Node *node);

public:
    Treap(int rootValue, int rootPriority);

    ~Treap();

    void InsertNonOptimized(int value, int priority);

    void InsertOptimized(int value, int priority);

    void RemoveNonOptimized(int value);

    void RemoveOptimized(int value);

    int GetHeight();

    int GetMin();

    int GetMax();

    bool Contains(int value);

    Node *FindMin();

    Node *FindMax();

    Node *Find(int value);

};


#endif //DATA_STRUCTURES_TREAP_H
