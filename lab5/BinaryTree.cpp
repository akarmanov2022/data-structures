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

void BinaryTree::PrintInOrder(BinaryTree::Node *node)
{
    if (node != nullptr)
    {
        PrintInOrder(node->left);
        std::cout << node->value << std::endl;
        PrintInOrder(node->right);
    }
}

void BinaryTree::PrintPreOrder(BinaryTree::Node *node)
{
    if (node != nullptr)
    {
        std::cout << node->value << std::endl;
        PrintPreOrder(node->left);
        PrintPreOrder(node->right);
    }
}

void BinaryTree::PrintPostOrder(BinaryTree::Node *node)
{
    if (node != nullptr)
    {
        PrintPostOrder(node->left);
        PrintPostOrder(node->right);
        std::cout << node->value << std::endl;
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

bool BinaryTree::Contains(int value, BinaryTree::Node *node)
{
    if (node == nullptr)
    {
        return false;
    }
    else
    {
        if (value < node->value)
        {
            return Contains(value, node->left);
        }
        else
        {
            if (value > node->value)
            {
                return Contains(value, node->right);
            }
            else
            {
                return true;
            }
        }
    }
}

void BinaryTree::Remove(int value, BinaryTree::Node *node)
{
    if (node != nullptr)
    {
        if (value < node->value)
        {
            Remove(value, node->left);
        }
        else
        {
            if (value > node->value)
            {
                Remove(value, node->right);
            }
            else
            {
                RemoveNode(value, node);
            }
        }
    }
}

BinaryTree::Node *BinaryTree::FindMin(BinaryTree::Node *node)
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

BinaryTree::Node *BinaryTree::FindMax(BinaryTree::Node *node)
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

BinaryTree::Node *BinaryTree::RemoveNode(int value, BinaryTree::Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (value < node->value)
        {
            node->left = RemoveNode(value, node->left);
        }
        else
        {
            if (value > node->value)
            {
                node->right = RemoveNode(value, node->right);
            }
            else
            {
                if (node->left != nullptr && node->right != nullptr)
                {
                    node->value = FindMin(node->right)->value;
                    node->right = RemoveNode(node->value, node->right);
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

BinaryTree::BinaryTree()
{
    root = nullptr;
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

void BinaryTree::PrintInOrder()
{
    PrintInOrder(root);
}

void BinaryTree::PrintPreOrder()
{
    PrintPreOrder(root);
}

void BinaryTree::PrintPostOrder()
{
    PrintPostOrder(root);
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

bool BinaryTree::Contains(int value)
{
    return Contains(value, root);
}

void BinaryTree::Remove(int value)
{
    Remove(value, root);
}

BinaryTree::Node *BinaryTree::FindMin()
{
    return FindMin(root);
}

BinaryTree::Node *BinaryTree::FindMax()
{
    return FindMax(root);
}

BinaryTree::Node *BinaryTree::Find(int value)
{
    return Find(value, root);
}

BinaryTree::Node *BinaryTree::RemoveNode(int value)
{
    return RemoveNode(value, root);
}

BinaryTree::BinaryTree(int rootValue)
{
    root = new Node{rootValue, nullptr, nullptr};
}
