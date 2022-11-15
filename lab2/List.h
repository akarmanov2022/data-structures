//
// Created by akarmanov on 06-11-2022.
//

#include "ListItem.h"

static const char *const NULL_POINTER_EXCEPTION = "Null Pointer Exception!";

class List
{
private:
    ListItem *_head{};
    ListItem *_previous{};
    int _length = 0;

    ListItem *InitHead(int value);

    ListItem *AddAfter(ListItem *itemAfter, int value);

    ListItem *AddBefore(ListItem *itemBefore, int value);

    void CheckIndex(int index) const;

public:

    explicit List(int length, ListItem &head, ListItem &previous);

    ListItem *Remove(ListItem *item);

    ListItem *Add(int value);

    ListItem *Insert(int index, int value);

    ListItem *AddToBegin(int value);

    ListItem *AddToEnd(int value);

    ListItem *Remove(int index);

    void Clear();

    void Sort();

    ListItem *GetHead() const;

    ListItem *GetPrevious() const;

    int GetLength() const;

    ListItem *GetItem(int index) const;

    void Swap(ListItem *first, ListItem *second);
};
