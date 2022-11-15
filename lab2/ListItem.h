//
// Created by akarmanov on 06-11-2022.
//

#ifndef DATA_STRUCTURES_LISTITEM_H
#define DATA_STRUCTURES_LISTITEM_H


class ListItem
{
private:
    ListItem* _next{};
    ListItem* _previous{};
    int _data = 0;
public:
    bool HasNext();

    bool HasPrevious();

    ListItem *GetNext();

    void SetNext(ListItem *item);

    ListItem *GetPrevious();

    void SetPrevious(ListItem *item);

    int GetData() const;

    void SetData(int value);

    bool operator<(const ListItem &rhs) const;

    bool operator>(const ListItem &rhs) const;

    bool operator<=(const ListItem &rhs) const;

    bool operator>=(const ListItem &rhs) const;
};


#endif //DATA_STRUCTURES_LISTITEM_H
