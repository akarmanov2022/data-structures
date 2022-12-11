//
// Created by akarmanov on 10-12-2022.
//

#include <iostream>
#include "BinaryTree.h"

void BinaryTree::AddNode(int value, BinaryTree::Node *node)
{
    if (value < node->value)
    {
        if (node->left != nullptr)
        {
            AddNode(value, node->left);
        }
        else
        {
            node->left = new Node{value, nullptr, nullptr};
        }
    }
    else
    {
        if (value > node->value)
        {
            if (node->right != nullptr)
            {
                AddNode(value, node->right);
            }
            else
            {
                node->right = new Node{value, nullptr, nullptr};
            }
        }
    }
}

void BinaryTree::DeleteTree(BinaryTree::Node *node)
{
    if (node != nullptr)
    {
        DeleteTree(node->left);
        DeleteTree(node->right);
        delete node;
    }
}

int BinaryTree::GetHeight(BinaryTree::Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        int leftHeight = GetHeight(node->left);
        int rightHeight = GetHeight(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }
}

int BinaryTree::GetMin(BinaryTree::Node *node)
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

int BinaryTree::GetMax(BinaryTree::Node *node)
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

BinaryTree::Node *BinaryTree::Find(int value, BinaryTree::Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (value < node->value)
        {
            return Find(value, node->left);
        }
        else
        {
            if (value > node->value)
            {
                return Find(value, node->right);
            }
            else
            {
                return node;
            }
        }
    }
}

BinaryTree::Node *BinaryTree::Remove(int value, BinaryTree::Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (value < node->value)
        {
            node->left = Remove(value, node->left);
        }
        else
        {
            if (value > node->value)
            {
                node->right = Remove(value, node->right);
            }
            else
            {
                if (node->left != nullptr && node->right != nullptr)
                {
                    node->value = GetMin(node->right);
                    node->right = Remove(node->value, node->right);
                }
                else
                {
                    Node *temp = node;
                    if (node->left != nullptr)
                    {
                        node = node->left;
                    }
                    else
                    {
                        node = node->right;
                    }
                    delete temp;
                }
            }
        }
        return node;
    }
}

BinaryTree::~BinaryTree()
{
    DeleteTree(root);
}

void BinaryTree::AddNode(int value)
{
    if (root != nullptr)
    {
        AddNode(value, root);
    }
    else
    {
        root = new Node{value, nullptr, nullptr};
    }
}

int BinaryTree::GetHeight()
{
    return GetHeight(root);
}

int BinaryTree::GetMin()
{
    return GetMin(root);
}

int BinaryTree::GetMax()
{
    return GetMax(root);
}

BinaryTree::Node *BinaryTree::Remove(int value)
{
    return Remove(value, root);
}

BinaryTree::Node *BinaryTree::Find(int value)
{
    return Find(value, root);
}

BinaryTree::BinaryTree(int rootValue)
{
    root = new Node{rootValue, nullptr, nullptr};
}
