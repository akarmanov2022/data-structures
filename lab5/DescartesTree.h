//
// Created by akarmanov on 10-12-2022.
//

#ifndef DATA_STRUCTURES_DESCARTESTREE_H
#define DATA_STRUCTURES_DESCARTESTREE_H


class DescartesTree
{
private:
    struct Node
    {
        Node();

        Node(int value, int priority);

        int value;
        int priority;
        Node *left;
        Node *right;
    };
    Node *root;

    void AddNode(int value, int priority, Node *node);

    void PrintInOrder(Node *node);

    void PrintPreOrder(Node *node);

    void PrintPostOrder(Node *node);

    void DeleteTree(Node *node);

    int GetHeight(Node *node);

    int GetMin(Node *node);

    int GetMax(Node *node);

    bool Contains(int value, Node *node);

    void Remove(int value, Node *node);

    Node *FindMin(Node *node);

    Node *FindMax(Node *node);

    Node *Find(int value, Node *node);

    Node *RemoveNode(int value, Node *node);

    Node *Split(Node *node, int value);

    Node *Merge(Node *left, Node *right);

    void Clear(Node *node);
public:

    DescartesTree();

    ~DescartesTree();

    void AddNodeNonOptimized(int value, int priority);

    void AddNodeOptimized(int value, int priority);

    void PrintInOrder();

    void PrintPreOrder();

    void PrintPostOrder();

    int GetHeight();

    int GetMin();

    int GetMax();

    bool Contains(int value);

    void Remove(int value);

    Node *FindMin();

    Node *FindMax();

    Node *Find(int value);

    void Clear();

    DescartesTree(int value, int priority);
};


#endif //DATA_STRUCTURES_DESCARTESTREE_H
