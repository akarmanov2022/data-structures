//
// Created by aka on 12/8/22.
//
#include <cstring>
#include <iostream>
#include "HashTable.h"
#include "Dictionary.h"

double MAX_LOAD_FACTOR = 0.75;

HashTable::HashTable()
{
    _size = DEFAULT_SIZE;
    _items = new Item * [_size];
    //TODO:
    for (int i = 0; i < _size; i++)
        _items[i] = nullptr;
}

HashTable::~HashTable()
{
    //TODO:
    for (int i = 0; i < _size; i++)
        if (_items[i] != nullptr)
            delete _items[i];
    delete[] _items;
}

void HashTable::Add(const char *key, const char *value)
{
    int index = Hash(key);
    if (_items[index] == nullptr)
    {
        _items[index] = new Item;
        _items[index]->_key = new char[strlen(key) + 1];
        strcpy(_items[index]->_key, key);
        _items[index]->_value = new char[strlen(value) + 1];
        strcpy(_items[index]->_value, value);
        _items[index]->_next = nullptr;
        _count++;
    } else
    {
        Item *item = _items[index];
        while (item->_next != nullptr)
        {
            if (strcmp(item->_key, key) == 0)
            {
                delete[] item->_value;
                item->_value = new char[strlen(value) + 1];
                strcpy(item->_value, value);
                return;
            }
            item = item->_next;
        }
        if (strcmp(item->_key, key) == 0)
        {
            delete[] item->_value;
            item->_value = new char[strlen(value) + 1];
            strcpy(item->_value, value);
            return;
        }
        item->_next = new Item;
        item->_next->_key = new char[strlen(key) + 1];
        strcpy(item->_next->_key, key);
        item->_next->_value = new char[strlen(value) + 1];
        strcpy(item->_next->_value, value);
        item->_next->_next = nullptr;
    }
    _loadFactor = _count / (double) _size;
    if (_loadFactor > MAX_LOAD_FACTOR)
    {
        Rehash();
    }
}

void HashTable::Remove(const char *key)
{
    int index = Hash(key);
    if (_items[index] != nullptr)
    {
        Item *item = _items[index];
        if (strcmp(item->_key, key) == 0)
        {
            _items[index] = item->_next;
            delete item;
        }
        else
        {
            while (item->_next != nullptr)
            {
                if (strcmp(item->_next->_key, key) == 0)
                {
                    Item *temp = item->_next;
                    item->_next = item->_next->_next;
                    delete temp;
                    break;
                }
                item = item->_next;
            }
        }
        _count--;
    }
}

const char *HashTable::Find(const char *key)
{
    int index = Hash(key);
    if (_items[index] != nullptr)
    {
        Item *item = _items[index];
        while (item != nullptr)
        {
            //TODO:
            if (strcmp(item->_key, key) == 0)
                return item->_value;
            item = item->_next;
        }
    }
    return nullptr;
}

//TODO:
void HashTable::Print()
{
    std::cout << "=== Hash Table ===" << std::endl;
    std::cout << "Size: " << _size << std::endl;
    std::cout << "Items: " << _count << std::endl;
    std::cout << "Load factor: " << _loadFactor << std::endl;
    for (int i = 0; i < _size; i++)
    {
        if (_items[i] != nullptr)
        {
            Item *item = _items[i];
            std::cout << "i: " << i << std::endl;
            while (item != nullptr)
            {
                std::cout << "\t" << item->_key << " -> " << item->_value << std::endl;
                item = item->_next;
            }
        }
    }
    std::cout << "==================" << std::endl;
}

int HashTable::Hash(const char *key) const
{
    int hash = 0;
    //TODO:
    for (int i = 0; i < strlen(key); i++)
        hash += key[i];
    return hash % _size;
}

void HashTable::Rehash()
{
    //TODO:
    std::cout << "Rehashing..." << std::endl;
    int oldSize = _size;
    _size *= 2;
    _count = 0;
    Item **oldItems = _items;
    _items = new Item * [_size];
    //TODO:
    for (int i = 0; i < _size; i++)
        _items[i] = nullptr;
    for (int i = 0; i < oldSize; i++)
    {
        if (oldItems[i] != nullptr)
        {
            Item *item = oldItems[i];
            while (item != nullptr)
            {
                Add(item->_key, item->_value);
                item = item->_next;
            }
        }
    }
    //TODO:
    for (int i = 0; i < oldSize; i++)
        if (oldItems[i] != nullptr)
            delete oldItems[i];
    delete[] oldItems;
    std::cout << "Rehashing complete." << std::endl;
}