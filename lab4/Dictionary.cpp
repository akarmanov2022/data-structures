//
// Created by aka on 12/8/22.
//

#include <iostream>
#include "Dictionary.h"

Dictionary::Dictionary()
{
    _table = new HashTable;
}

Dictionary::~Dictionary()
{
    delete _table;
}

bool Dictionary::Add(const char *key, const char *value)
{
    //TODO:
    if (Get(key) != nullptr)
    {
        return false;
    }
    return _table->Add(key, value);
}

void Dictionary::Remove(const char *key)
{
    _table->Remove(key);
}

const char *Dictionary::Get(const char *key)
{
    return _table->Find(key);
}

long Dictionary::GetSize()
{
    return _table->_size;
}

HashTable *Dictionary::GetTable() const
{
    return _table;
}

std::ostream &operator<<(std::ostream &os, Dictionary &dictionary)
{
    os << "=== Dictionary ===" << std::endl;
    os << "Size: " << dictionary.GetSize() << std::endl;
    os << *dictionary.GetTable();
    return os;
}
