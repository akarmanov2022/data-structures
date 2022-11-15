#include <iostream>
#include <chrono>
#include <stdlib.h>
#include "List.h"


void FillListRandomValues(List *list, int count)
{
//    list->Clear();
    for (int i = 0; i < count; ++i)
    {
        list->Add(rand() % 20 - 10);
    }
}

void PrintList(List *list)
{
    auto next = list->GetHead();
    int length = list->GetLength();
    std::cout << std::endl;
    std::cout << "=== List Output ===" << std::endl;
    std::cout << "Length\t- " << length << std::endl;
    std::cout << "Data\t- [";
    if (next != nullptr)
    {
        while (next->HasNext())
        {
            std::cout << next->GetData() << " ";
            next = next->GetNext();
        }
        std::cout << next->GetData();
    }
    std::cout << "]" << std::endl;

}

int main()
{
    srand(time(nullptr));
    auto list = new List();

    FillListRandomValues(list, 100000);
    PrintList(list);
    list->Sort();
    PrintList(list);

    /*while (true)
    {
        std::cout << "Lab 2. A doubly linked list." << std::endl;
        std::cout << "1. Fill the list with random values." << std::endl;
        std::cout << "2. Add an item to the list." << std::endl;
        std::cout << "3. Remove an item from the list." << std::endl;
        std::cout << "4. Insert an element at the beginning." << std::endl;
        std::cout << "5. Insert an element at the end." << std::endl;
        std::cout << "6. Insert after the element." << std::endl;
        std::cout << "7. Insert before element." << std::endl;
        std::cout << "8. Sorting the list." << std::endl;
        std::cout << "9. Linear search." << std::endl;
        std::cout << "0. Exit." << std::endl;
    }*/
}
