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
    size = DEFAULT_SIZE;
    items = new Item*[size];
    for (int i = 0; i < size; i++)
        items[i] = nullptr;
}

HashTable::~HashTable()
{
    for (int i = 0; i < size; i++)
        if (items[i] != nullptr)
            delete items[i];
    delete[] items;
}

void HashTable::Add(const char *key, const char *value)
{
    int index = Hash(key);
    if (items[index] == nullptr)
    {
        items[index] = new Item;
        items[index]->key = new char[strlen(key) + 1];
        strcpy(items[index]->key, key);
        items[index]->value = new char[strlen(value) + 1];
        strcpy(items[index]->value, value);
        items[index]->next = nullptr;
    }
    else
    {
        Item *item = items[index];
        while (item->next != nullptr)
            item = item->next;
        item->next = new Item;
        item->next->key = new char[strlen(key) + 1];
        strcpy(item->next->key, key);
        item->next->value = new char[strlen(value) + 1];
        strcpy(item->next->value, value);
        item->next->next = nullptr;
    }
    count++;
    if (count / (double) size > MAX_LOAD_FACTOR)
        Rehash();
}

void HashTable::Remove(const char *key)
{
    int index = Hash(key);
    if (items[index] != nullptr)
    {
        Item *item = items[index];
        if (strcmp(item->key, key) == 0)
        {
            items[index] = item->next;
            delete item;
        }
        else
        {
            while (item->next != nullptr)
            {
                if (strcmp(item->next->key, key) == 0)
                {
                    Item *temp = item->next;
                    item->next = item->next->next;
                    delete temp;
                    break;
                }
                item = item->next;
            }
        }
        count--;
    }
}

const char *HashTable::Find(const char *key)
{
    int index = Hash(key);
    if (items[index] != nullptr)
    {
        Item *item = items[index];
        while (item != nullptr)
        {
            if (strcmp(item->key, key) == 0)
                while (item->next != nullptr)
            item = item->next;
        }
    }
    return nullptr;
}

void HashTable::Print()
{
    std::cout << "=== Hash Table ===" << std::endl;
    for (int i = 0; i < size; i++)
    {
        if (items[i] != nullptr)
        {
            Item *item = items[i];
            std::cout << "i: " << i << std::endl;
            while (item != nullptr)
            {
                std::cout << "\t" << item->key << " -> " << item->value << std::endl;
                item = item->next;
            }
        }
    }
}

int HashTable::Hash(const char *key)
{
    int hash = 0;
    for (int i = 0; i < strlen(key); i++)
        hash += key[i];
    return hash % size;
}

void HashTable::Rehash()
{
    int oldSize = size;
    size *= 2;
    Item **oldItems = items;
    items = new Item*[size];
    for (int i = 0; i < size; i++)
        items[i] = nullptr;
    for (int i = 0; i < oldSize; i++)
    {
        if (oldItems[i] != nullptr)
        {
            Item *item = oldItems[i];
            while (item != nullptr)
            {
                Add(item->key, item->value);
                item = item->next;
            }
        }
    }
    for (int i = 0; i < oldSize; i++)
        if (oldItems[i] != nullptr)
            delete oldItems[i];
    delete[] oldItems;
}

void HashTable::ResolvedCollision(HashTable::Item *item, HashTable::Item *newItem)
{
    while (item->next != nullptr)
        item = item->next;
    item->next = newItem;
}

