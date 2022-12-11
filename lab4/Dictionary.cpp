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

void Dictionary::Add(const char *key, const char *value)
{
    _table->Add(key, value);
}

void Dictionary::Remove(const char *key)
{
    _table->Remove(key);
}

const char *Dictionary::Get(const char *key)
{
    return _table->Find(key);
}

void Dictionary::Print()
{
    _table->Print();
}
