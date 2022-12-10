//
// Created by akarmanov on 10-12-2022.
//

#ifndef DATA_STRUCTURES_BINARYTREE_H
#define DATA_STRUCTURES_BINARYTREE_H


class BinaryTree
{
private:
    struct Node
    {
        int value;
        Node *left;
        Node *right;
    };
    Node *root;

    void AddNode(int value, Node *node);

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

public:
    BinaryTree();

    ~BinaryTree();

    void AddNode(int value);

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

    Node *RemoveNode(int value);

    BinaryTree(int rootValue);
};


#endif //DATA_STRUCTURES_BINARYTREE_H
