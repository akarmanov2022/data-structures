//
// Created by akarmanov on 10-12-2022.
//

#include <cstdlib>
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

int Treap::GetMin()
{
    return FindMin()->value;
}

int Treap::GetMax()
{
    return FindMax()->value;
}

bool Treap::Contains(int value)
{
    return Contains(value, root);
}

void Treap::RemoveNonOptimized(int value)
{
    RemoveNonOptimized(value, root);
}

Treap::Node *Treap::FindMin()
{
    return FindMin(root);
}

Treap::Node *Treap::FindMax()
{
    return FindMax(root);
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

Treap::Node *Treap::FindMin(Treap::Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->left == nullptr)
    {
        return node;
    }
    return FindMin(node->left);
}

Treap::Node *Treap::FindMax(Treap::Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->right == nullptr)
    {
        return node;
    }
    return FindMax(node->right);
}

bool Treap::Contains(int value, Treap::Node *node)
{
    if (node == nullptr)
    {
        return false;
    }
    if (value == node->value)
    {
        return true;
    }
    if (value < node->value)
    {
        return Contains(value, node->left);
    }
    else
    {
        return Contains(value, node->right);
    }
}

int Treap::GetMin(Treap::Node *node)
{
    if (node == nullptr)
    {
        return NULL;
    }
    if (node->left == nullptr)
    {
        return node->value;
    }
    return GetMin(node->left);
}

int Treap::GetMax(Treap::Node *node)
{
    if (node == nullptr)
    {
        return NULL;
    }
    if (node->right == nullptr)
    {
        return node->value;
    }
    return GetMax(node->right);
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

void Treap::RemoveNonOptimized(int value, Treap::Node *&node)
{
    Node *left = nullptr;
    Node *right = nullptr;
    Split(node, value, left, right);
    Node *temp = nullptr;
    Split(right, value + 1, temp, right);
    delete temp;
    node = Merge(left, right);
}

void Treap::RemoveOptimized(int value, Treap::Node *&node)
{
    Node *find = Find(value, node);
    if (find == nullptr)
    {
        return;
    }
    node = Merge(find->left, find->right);
    delete find;
}

void Treap::RemoveOptimized(int value)
{
    RemoveOptimized(value, root);
}

