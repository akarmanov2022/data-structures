#include <iostream>
#include <chrono>
#include <cstdlib>
#include "List.h"

void FillListRandomValues(List *list, int count)
{
    list->Clear();
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

void PrintTestResult()
{
    auto list = new List();
    for (int step = 100000; step <= 5000000; step += 100000)
    {
        int randomValue = rand() % 20 - 10;
        FillListRandomValues(list, step);
        int index = list->GetLength() / 2;
        auto begin = std::chrono::steady_clock::now();
        list->Remove(index);
        auto end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << ", " << step
                  << std::endl;
    }
//
//    for (int step = 100000; step <= 1000000; step += 100000)
//    {
//        std::cout << "--- Step: " << step << " ---" << std::endl;
//        for (int i = 0; i < 100; ++i)
//        {
//            FillListRandomValues(list, step);
//            int index = list->GetLength() / 2;
//            auto begin = std::chrono::steady_clock::now();
//            list->Remove(index);
//            auto end = std::chrono::steady_clock::now();
//            std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << ", " << step
//                      << std::endl;
//        }
//    }
}

bool CheckEnter()
{
    if (std::cin.good())
        return true;
    std::cout << "Incorrect value!" << std::endl;
    while (!std::cin.good())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return false;
}

int main()
{
//    srand(time(nullptr));
    auto list = new List();

//    FillListRandomValues(list, 100000);
//    PrintList(list);
//    list->Sort();
//    PrintList(list);

    while (true)
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
        std::cout << "10. Output test result." << std::endl;
        std::cout << "0. Exit." << std::endl;

        int number = 0;
        std::cout << "Enter the task number or 0 for exit: " << std::endl;
        std::cin >> number;
        if (!CheckEnter())
            continue;

        switch (number)
        {
            case 0:
            {
                return 0;
            }
            case 1:
            {
                int value = 0;
                std::cout << "Enter index values: ";
                std::cin >> value;
                if (!CheckEnter())
                    continue;
                FillListRandomValues(list, value);
                break;
            }
            case 2:
            {
                int value = 0;
                std::cout << "Enter the value: ";
                std::cin >> value;
                if (!CheckEnter())
                    continue;
                list->Add(value);
                break;
            }
            case 3:
            {
                int index = 0;
                std::cout << "Enter the index: ";
                std::cin >> index;
                if (!CheckEnter())
                    continue;
                list->Remove(index);
                break;
            }
            case 4:
            {
                int value = 0;
                std::cout << "Enter the value: ";
                std::cin >> value;
                if (!CheckEnter())
                    continue;
                list->AddToEnd(value);
                break;
            }
            case 5:
            {
                int value = 0;
                std::cout << "Enter the value: ";
                std::cin >> value;
                if (!CheckEnter())
                    continue;
                list->AddToBegin(value);
                break;
            }
            case 6:
            {
                int value = 0;
                int index = 0;
                std::cout << "Enter the value: ";
                std::cin >> value;
                if (!CheckEnter())
                    continue;
                std::cout << "Enter the index: ";
                std::cin >> index;
                if (!CheckEnter())
                    continue;
                list->Insert(index + 1, value);
                break;
            }
            case 7:
            {
                int value = 0;
                int index = 0;
                std::cout << "Enter the value: ";
                std::cin >> value;
                if (!CheckEnter())
                    continue;
                std::cout << "Enter the index: ";
                std::cin >> index;
                if (!CheckEnter())
                    continue;
                list->Insert(index, value);
                break;
            }
            case 8:
            {
                std::cout << "Sorting list..." << std::endl;
                list->Sort();
                break;
            }
            case 9:
            {
                int index = 0;
                std::cout << "Enter the index: ";
                std::cin >> index;
                if (!CheckEnter())
                    continue;
                int value = list->GetItem(index)->GetData();
                std::cout << "Found by index: " << value << std::endl;
                break;
            }
            case 10:
            {
                PrintTestResult();
                break;
            }
            default:
            {
                std::cout << "Incorrect value!" << std::endl;
                return 0;
            }
        }
        PrintList(list);
    }
}
