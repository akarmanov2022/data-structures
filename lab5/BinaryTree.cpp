 //
// Created by akarmanov on 10-12-2022.
//

#include "BinaryTree.h"

void BinaryTree::AddNode(int value, BinaryTree::Node *node)
{
    if (value < node->_value)
    {
        if (node->_left != nullptr)
        {
            AddNode(value, node->_left);
        }
        else
        {
            node->_left = new Node{value, nullptr, nullptr};
        }
    }
    else
    {
        if (value > node->_value)
        {
            if (node->_right != nullptr)
            {
                AddNode(value, node->_right);
            }
            else
            {
                node->_right = new Node{value, nullptr, nullptr};
            }
        }
    }
}

void BinaryTree::DeleteTree(BinaryTree::Node *node)
{
    if (node != nullptr)
    {
        DeleteTree(node->_left);
        DeleteTree(node->_right);
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
        int leftHeight = GetHeight(node->_left);
        int rightHeight = GetHeight(node->_right);
        return std::max(leftHeight, rightHeight) + 1;
    }
}

int BinaryTree::GetMin(BinaryTree::Node *node)
{
    if (node->_left == nullptr)
    {
        return node->_value;
    }
    else
    {
        return GetMin(node->_left);
    }
}

int BinaryTree::GetMax(BinaryTree::Node *node)
{
    if (node->_right == nullptr)
    {
        return node->_value;
    }
    else
    {
        return GetMax(node->_right);
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
        if (value < node->_value)
        {
            return Find(value, node->_left);
        }
        else
        {
            if (value > node->_value)
            {
                return Find(value, node->_right);
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
        if (value < node->_value)
        {
            node->_left = Remove(value, node->_left);
        }
        else
        {
            if (value > node->_value)
            {
                node->_right = Remove(value, node->_right);
            }
            else
            {
                if (node->_left != nullptr && node->_right != nullptr)
                {
                    node->_value = GetMin(node->_right);
                    node->_right = Remove(node->_value, node->_right);
                }
                else
                {
                    Node *temp = node;
                    if (node->_left != nullptr)
                    {
                        node = node->_left;
                    }
                    else
                    {
                        node = node->_right;
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
    DeleteTree(_root);
}

void BinaryTree::AddNode(int value)
{
    if (_root != nullptr)
    {
        AddNode(value, _root);
    }
    else
    {
        _root = new Node{value, nullptr, nullptr};
    }
}

int BinaryTree::GetHeight()
{
    return GetHeight(_root);
}

int BinaryTree::GetMin()
{
    return GetMin(_root);
}

int BinaryTree::GetMax()
{
    return GetMax(_root);
}

BinaryTree::Node *BinaryTree::Remove(int value)
{
    return Remove(value, _root);
}

BinaryTree::Node *BinaryTree::Find(int value)
{
    return Find(value, _root);
}

BinaryTree::BinaryTree(int rootValue)
{
    _root = new Node{rootValue, nullptr, nullptr};
}

std::ostream &operator<<(std::ostream &os, BinaryTree &tree)
{

    tree.Dump(os, tree.GetRoot(), "", false);
    return os;
}

void BinaryTree::Dump(std::ostream &ostream, BinaryTree::Node *node, std::string prefix = "", bool last = true)
{
    if (node != nullptr)
    {
        ostream << prefix;
        if (node != _root)
        {
            if (last)
            {
                ostream << "\\--";
                prefix += "   ";
            }
            else
            {
                ostream << "|--";
                prefix += "|  ";
            }
        }
        else
        {
            prefix  += "   ";
        }
        ostream << node->_value << std::endl;
        Dump(ostream, node->_left, prefix, false);
        Dump(ostream, node->_right, prefix, true);
    }
}

BinaryTree::Node *BinaryTree::GetRoot() const
{
    return _root;
}
