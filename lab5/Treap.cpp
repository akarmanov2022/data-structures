//
// Created by akarmanov on 10-12-2022.
//

#include <cstdlib>
#include <iostream>
#include "Treap.h"

void Treap::InsertNonOptimized(int value, int priority)
{
    if (root == nullptr)
    {
        root = new Node{value, priority, nullptr, nullptr};
    }
    else
    {
        InsertNonOptimized(value, priority, root);
    }
}

void Treap::InsertOptimized(int value, int priority)
{
    if (root == nullptr)
    {
        root = new Node{value, priority, nullptr, nullptr};
    }
    else
    {
        InsertOptimized(value, priority, root);
    }
}

void Treap::Split(Treap::Node *node, int key, Treap::Node *&left, Treap::Node *&right)
{
    if (node == nullptr)
    {
        left = right = nullptr;
    }
    else
    {
        if (key < node->value)
        {
            Split(node->left, key, left, node->left);
            right = node;
        }
        else
        {
            Split(node->right, key, node->right, right);
            left = node;
        }
    }
}

Treap::Node *Treap::Merge(Treap::Node *left, Treap::Node *right)
{
    if (left == nullptr)
    {
        return right;
    }
    if (right == nullptr)
    {
        return left;
    }
    if (left->priority > right->priority)
    {
        left->right = Merge(left->right, right);
        return left;
    }
    else
    {
        right->left = Merge(left, right->left);
        return right;
    }
}

Treap::Treap(int rootValue, int rootPriority)
{
    root = new Node{rootValue, rootPriority, nullptr, nullptr};
}

Treap::~Treap()
{
    DeleteTree(root);
}

int Treap::GetHeight()
{
    return GetHeight(root);
}

Treap::Node *Treap::RemoveNonOptimized(int value)
{
    return RemoveNonOptimized(value, root);
}

Treap::Node *Treap::Find(int value)
{
    return Find(value, root);
}

void Treap::DeleteTree(Treap::Node *node)
{
    if (node != nullptr)
    {
        DeleteTree(node->left);
        DeleteTree(node->right);
        delete node;
    }
}

Treap::Node *Treap::Find(int value, Treap::Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (value == node->value)
    {
        return node;
    }
    if (value < node->value)
    {
        return Find(value, node->left);
    }
    else
    {
        return Find(value, node->right);
    }
}

int Treap::GetHeight(Treap::Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int leftHeight = GetHeight(node->left);
    int rightHeight = GetHeight(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void Treap::InsertNonOptimized(int value, int priority, Treap::Node *&node)
{
    Node *newNode = new Node{value, priority, nullptr, nullptr};
    Node *left = nullptr;
    Node *right = nullptr;
    Split(node, value, left, right);
    node = Merge(Merge(left, newNode), right);
}

void Treap::InsertOptimized(int value, int priority, Treap::Node *&node)
{
    Node *newNode = new Node{value, priority, nullptr, nullptr};
    if (priority > node->priority)
    {
        Split(node, value, newNode->left, newNode->right);
        node = newNode;
    }
    else
    {
        if (value < node->value)
        {
            InsertOptimized(value, priority, node->left);
        }
        else
        {
            InsertOptimized(value, priority, node->right);
        }
    }
}

Treap::Node * Treap::RemoveNonOptimized(int value, Treap::Node *&node)
{
    Node *left = nullptr;
    Node *right = nullptr;
    Split(node, value, left, right);
    Node *temp = nullptr;
    Split(right, value + 1, temp, right);
    delete temp;
    node = Merge(left, right);
    return node;
}

Treap::Node *Treap::RemoveOptimized(int value, Treap::Node *&node)
{
    Node *find = Find(value, node);
    if (find == nullptr)
    {
        return nullptr;
    }
    node = Merge(find->left, find->right);
    delete find;
    return node;
}

Treap::Node *Treap::RemoveOptimized(int value)
{
    return RemoveOptimized(value, root);
}

void Treap::PrintTree(Treap::Node *node, int level)
{
if (node != nullptr)
    {
        PrintTree(node->right, level + 1);
        for (int i = 0; i < level; i++)
        {
            std::cout << "    ";
        }
        std::cout << node->value << std::endl;
        PrintTree(node->left, level + 1);
    }
}

void Treap::PrintInOrder(Treap::Node *node)
{
    if (node != nullptr)
    {
        PrintInOrder(node->left);
        std::cout << node->value << " ";
        PrintInOrder(node->right);
    }
}

void Treap::PrintPreOrder(Treap::Node *node)
{
    if (node != nullptr)
    {
        std::cout << node->value << " ";
        PrintPreOrder(node->left);
        PrintPreOrder(node->right);
    }
}

void Treap::PrintPostOrder(Treap::Node *node)
{
    if (node != nullptr)
    {
        PrintPostOrder(node->left);
        PrintPostOrder(node->right);
        std::cout << node->value << " ";
    }
}

void Treap::PrintTree(int level)
{
    std::cout << "Tree:" << std::endl;
    PrintTree(root, level);
}

void Treap::PrintInOrder()
{
    std::cout << "In order:" << std::endl;
    PrintInOrder(root);
    std::cout << std::endl;
}

void Treap::PrintPreOrder()
{
    std::cout << "Pre order:" << std::endl;
    PrintPreOrder(root);
    std::cout << std::endl;
}

void Treap::PrintPostOrder()
{
    std::cout << "Post order:" << std::endl;
    PrintPostOrder(root);
    std::cout << std::endl;
}

