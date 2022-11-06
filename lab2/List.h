//
// Created by akarmanov on 06-11-2022.
//

#ifndef DATA_STRUCTURES_LIST_H
#define DATA_STRUCTURES_LIST_H


#include "ListItem.h"

class List
{
    ListItem *first;
    ListItem *last;
    int length;
private:
    static ListItem *Init(int firstValue);

    ListItem *Add(ListItem *itemAfter, int value);

public:

    List();

    ListItem *Add(int value);

    ListItem *Remove(ListItem *item);

    bool HasNext();
};


#endif //DATA_STRUCTURES_LIST_H
