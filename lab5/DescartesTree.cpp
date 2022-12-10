//
// Created by akarmanov on 10-12-2022.
//

#include <iostream>
#include "DescartesTree.h"

void DescartesTree::AddNode(int value, int priority, DescartesTree::Node *node)
{
    if (value < node->value)
    {
        if (node->left != nullptr)
        {
            AddNode(value, priority, node->left);
        }
        else
        {
            node->left = new Node{value, priority};
        }
    }
    else
    {
        if (value > node->value)
        {
            if (node->right != nullptr)
            {
                AddNode(value, priority, node->right);
            }
            else
            {
                node->right = new Node{value, priority};
            }
        }
    }
}

void DescartesTree::PrintInOrder(DescartesTree::Node *node)
{
    if (node != nullptr)
    {
        PrintInOrder(node->left);
        std::cout << node->value << std::endl;
        PrintInOrder(node->right);
    }
}

void DescartesTree::PrintPreOrder(DescartesTree::Node *node)
{
    if (node != nullptr)
    {
        std::cout << node->value << std::endl;
        PrintPreOrder(node->left);
        PrintPreOrder(node->right);
    }
}

void DescartesTree::PrintPostOrder(DescartesTree::Node *node)
{
    if (node != nullptr)
    {
        PrintPostOrder(node->left);
        PrintPostOrder(node->right);
        std::cout << node->value << std::endl;
    }
}

void DescartesTree::DeleteTree(DescartesTree::Node *node)
{
    if (node != nullptr)
    {
        DeleteTree(node->left);
        DeleteTree(node->right);
        delete node;
    }
}

int DescartesTree::GetHeight(DescartesTree::Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        int leftHeight = GetHeight(node->left);
        int rightHeight = GetHeight(node->right);
        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }
}

int DescartesTree::GetMin(DescartesTree::Node *node)
{
    if (node->left == nullptr)
    {
        return node->value;
    }
    else
    {
        return GetMin(node->left);
    }
}

int DescartesTree::GetMax(DescartesTree::Node *node)
{
    if (node->right == nullptr)
    {
        return node->value;
    }
    else
    {
        return GetMax(node->right);
    }
}

bool DescartesTree::Contains(int value, DescartesTree::Node *node)
{
    if (node == nullptr)
    {
        return false;
    }
    else
    {
        if (value == node->value)
        {
            return true;
        }
        else
        {
            if (value < node->value)
            {
                return Contains(value, node->left);
            }
            else
            {
                return Contains(value, node->right);
            }
        }
    }
}

void DescartesTree::Remove(int value, DescartesTree::Node *node)
{
    if (node != nullptr)
    {
        if (value == node->value)
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
            }
            else
            {
                if (node->left == nullptr)
                {
                    Node *temp = node->right;
                    delete node;
                    node = temp;
                }
                else
                {
                    if (node->right == nullptr)
                    {
                        Node *temp = node->left;
                        delete node;
                        node = temp;
                    }
                    else
                    {
                        Node *temp = node->right;
                        while (temp->left != nullptr)
                        {
                            temp = temp->left;
                        }
                        node->value = temp->value;
                        Remove(temp->value, node->right);
                    }
                }
            }
        }
        else
        {
            if (value < node->value)
            {
                Remove(value, node->left);
            }
            else
            {
                Remove(value, node->right);
            }
        }
    }
}

DescartesTree::Node *DescartesTree::FindMin(DescartesTree::Node *node)
{
    if (node->left == nullptr)
    {
        return node;
    }
    else
    {
        return FindMin(node->left);
    }
}

DescartesTree::Node *DescartesTree::FindMax(DescartesTree::Node *node)
{
    if (node->right == nullptr)
    {
        return node;
    }
    else
    {
        return FindMax(node->right);
    }
}

DescartesTree::Node *DescartesTree::Find(int value, DescartesTree::Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (value == node->value)
        {
            return node;
        }
        else
        {
            if (value < node->value)
            {
                return Find(value, node->left);
            }
            else
            {
                return Find(value, node->right);
            }
        }
    }
}

DescartesTree::Node *DescartesTree::RemoveNode(int value, DescartesTree::Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (value == node->value)
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
            else
            {
                if (node->left == nullptr)
                {
                    Node *temp = node->right;
                    delete node;
                    return temp;
                }
                else
                {
                    if (node->right == nullptr)
                    {
                        Node *temp = node->left;
                        delete node;
                        return temp;
                    }
                    else
                    {
                        Node *temp = node->right;
                        while (temp->left != nullptr)
                        {
                            temp = temp->left;
                        }
                        node->value = temp->value;
                        node->right = RemoveNode(temp->value, node->right);
                        return node;
                    }
                }
            }
        }
        else
        {
            if (value < node->value)
            {
                node->left = RemoveNode(value, node->left);
                return node;
            }
            else
            {
                node->right = RemoveNode(value, node->right);
                return node;
            }
        }
    }
}

DescartesTree::Node *DescartesTree::Split(DescartesTree::Node *node, int value)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (value < node->value)
        {
            Node *temp = Split(node->left, value);
            node->left = temp->right;
            temp->right = node;
            return temp;
        }
        else
        {
            Node *temp = Split(node->right, value);
            node->right = temp->left;
            temp->left = node;
            return temp;
        }
    }
}

DescartesTree::Node *DescartesTree::Merge(DescartesTree::Node *left, DescartesTree::Node *right)
{
    if (left == nullptr)
    {
        return right;
    }
    else
    {
        if (right == nullptr)
        {
            return left;
        }
        else
        {
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
    }
}

DescartesTree::DescartesTree()
{
    root = nullptr;
}

DescartesTree::~DescartesTree()
{
    Clear();
}

void DescartesTree::AddNode(int value, int priority)
{
    Node *node = new Node(value, priority);
    if (root == nullptr)
    {
        root = node;
    }
    else
    {
        Node *temp = Split(root, value);
        root = Merge(Merge(temp->left, node), temp->right);
        delete temp;
    }
}

void DescartesTree::PrintInOrder()
{
    PrintInOrder(root);
}

void DescartesTree::PrintPreOrder()
{
    PrintPreOrder(root);
}

void DescartesTree::PrintPostOrder()
{
    PrintPostOrder(root);
}

int DescartesTree::GetHeight()
{
    return GetHeight(root);
}

int DescartesTree::GetMin()
{
    return FindMin(root)->value;
}

int DescartesTree::GetMax()
{
    return FindMax(root)->value;
}

bool DescartesTree::Contains(int value)
{
    return Find(value, root) != nullptr;
}

void DescartesTree::Remove(int value)
{
    root = RemoveNode(value, root);
}

DescartesTree::Node *DescartesTree::FindMin()
{
    return FindMin(root);
}

DescartesTree::Node *DescartesTree::FindMax()
{
    return FindMax(root);
}

DescartesTree::Node *DescartesTree::Find(int value)
{
    return Find(value, root);
}

void DescartesTree::Clear()
{
    if (root != nullptr)
    {
        Clear(root);
        root = nullptr;
    }
}

void DescartesTree::Clear(DescartesTree::Node *node)
{
    if (node != nullptr)
    {
        Clear(node->left);
        Clear(node->right);
        delete node;
    }
}

DescartesTree::Node::Node(int value, int priority)
{
    this->value = value;
    this->priority = priority;
    left = nullptr;
    right = nullptr;
}

DescartesTree::Node::Node()
{
    value = 0;
    priority = 0;
    left = nullptr;
    right = nullptr;
}
