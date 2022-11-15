//
// Created by akarmanov on 06-11-2022.
//

#ifndef DATA_STRUCTURES_LISTITEM_H
#define DATA_STRUCTURES_LISTITEM_H


class ListItem
{
private:
    ListItem* next;
    ListItem* previous;
    int data;
public:
    ListItem *GetNext();

    void SetNext(ListItem *item);

    ListItem *GetPrevious();

    void SetPrevious(ListItem *item);

    int GetData() const;

    void SetData(int value);
};


#endif //DATA_STRUCTURES_LISTITEM_H
