//
// Created by akarmanov on 10-12-2022.
//

#include <iostream>
#include "Treap.h"

void Treap::InsertNonOptimized(int value, int priority)
{
    if (_root == nullptr)
    {
        _root = new Node{value, priority, nullptr, nullptr};
    }
    else
    {
        InsertNonOptimized(value, priority, _root);
    }
}

void Treap::InsertOptimized(int value, int priority)
{
    if (_root == nullptr)
    {
        _root = new Node{value, priority, nullptr, nullptr};
    }
    else
    {
        InsertOptimized(value, priority, _root);
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
        if (key < node->_value)
        {
            Split(node->_left, key, left, node->_left);
            right = node;
        }
        else
        {
            Split(node->_right, key, node->_right, right);
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
    if (left->_priority > right->_priority)
    {
        left->_right = Merge(left->_right, right);
        return left;
    }
    else
    {
        right->_left = Merge(left, right->_left);
        return right;
    }
}

Treap::Treap(int rootValue, int rootPriority)
{
    _root = new Node{rootValue, rootPriority, nullptr, nullptr};
}

Treap::~Treap()
{
    DeleteTree(_root);
}

int Treap::GetHeight()
{
    return GetHeight(_root);
}

Treap::Node *Treap::RemoveNonOptimized(int value)
{
    return RemoveNonOptimized(value, _root);
}

Treap::Node *Treap::Find(int value)
{
    return Find(value, _root);
}

void Treap::DeleteTree(Treap::Node *node)
{
    if (node != nullptr)
    {
        DeleteTree(node->_left);
        DeleteTree(node->_right);
        delete node;
    }
}

Treap::Node *Treap::Find(int value, Treap::Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (value == node->_value)
    {
        return node;
    }
    if (value < node->_value)
    {
        return Find(value, node->_left);
    }
    else
    {
        return Find(value, node->_right);
    }
}

int Treap::GetHeight(Treap::Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int leftHeight = GetHeight(node->_left);
    int rightHeight = GetHeight(node->_right);
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
    if (node == nullptr)
    {
        node = new Node{value, priority, nullptr, nullptr};
    }
    else
    {
        if (priority > node->_priority)
        {
            Node *left = nullptr;
            Node *right = nullptr;
            Split(node, value, left, right);
            node = new Node{value, priority, left, right};
        }
        else
        {
            if (value < node->_value)
            {
                InsertOptimized(value, priority, node->_left);
            }
            else
            {
                InsertOptimized(value, priority, node->_right);
            }
        }
    }
}

Treap::Node *Treap::RemoveNonOptimized(int value, Treap::Node *&node)
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
    node = Merge(find->_left, find->_right);
    delete find;
    return node;
}

Treap::Node *Treap::RemoveOptimized(int value)
{
    return RemoveOptimized(value, _root);
}

void Treap::PrintByLevel(Treap::Node *node, int level)
{
    if (node == nullptr)
    {
        return;
    }
    if (level == 1)
    {
        std::cout << "(v=" << node->_value << ", p=" << node->_priority << ") ";
    }
    else
    {
        PrintByLevel(node->_left, level - 1);
        PrintByLevel(node->_right, level - 1);
    }
}

void Treap::PrintInOrder(Treap::Node *node)
{
    if (node != nullptr)
    {
        PrintInOrder(node->_left);
        std::cout << "(v=" << node->_value << ", p=" << node->_priority << ") -> ";
        PrintInOrder(node->_right);
    }
}

void Treap::PrintPreOrder(Treap::Node *node)
{
    if (node != nullptr)
    {
        std::cout << "(v=" << node->_value << ", p=" << node->_priority << ") -> ";
        PrintPreOrder(node->_left);
        PrintPreOrder(node->_right);
    }
}

void Treap::PrintPostOrder(Treap::Node *node)
{
    if (node != nullptr)
    {
        PrintPostOrder(node->_left);
        PrintPostOrder(node->_right);
        std::cout << "(v=" << node->_value << ", p=" << node->_priority << ") -> ";
    }
}

void Treap::PrintByLevel(int level)
{
    std::cout << "Level " << level << ": ";
    PrintByLevel(_root, level);
    std::cout << std::endl;
}

void Treap::PrintInOrder()
{
    std::cout << "In order:" << std::endl;
    PrintInOrder(_root);
    std::cout << std::endl;
}

void Treap::PrintPreOrder()
{
    std::cout << "Pre order:" << std::endl;
    PrintPreOrder(_root);
    std::cout << std::endl;
}

void Treap::PrintPostOrder()
{
    std::cout << "Post order:" << std::endl;
    PrintPostOrder(_root);
    std::cout << std::endl;
}

