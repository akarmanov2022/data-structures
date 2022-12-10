//
// Created by aka on 12/8/22.
//

#include <iostream>
#include "Dictionary.h"

Dictionary::Dictionary()
{
    table = new HashTable;
}

Dictionary::~Dictionary()
{
    delete table;
}

void Dictionary::Add(const char *key, const char *value)
{
    table->Add(key, value);
}

void Dictionary::Remove(const char *key)
{
    table->Remove(key);
}

const char *Dictionary::Get(const char *key)
{
    return table->Find(key);
}

void Dictionary::Print()
{
    table->Print();
}
