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
//    for (int step = 10000; step <= 1000000; step += 10000)
//    {
//        int randomValue = rand() % 20 - 10;
//        FillListRandomValues(list, step);
//        auto begin = std::chrono::steady_clock::now();
//        list->Add(randomValue);
//        auto end = std::chrono::steady_clock::now();
//        std::cout << "Add: " << "Length: " << list->GetLength() << "; Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << ", " << step << std::endl;
//    }

    for (int step = 100000; step <= 1000000; step += 100000)
    {
        std::cout << "--- Step: " << step << " ---" << std::endl;
        for (int i = 0; i < 100; ++i)
        {
            FillListRandomValues(list, step);
            int index = list->GetLength() / 2;
            auto begin = std::chrono::steady_clock::now();
            list->Remove(index);
            auto end = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << ", " << step
                      << std::endl;
        }
    }
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
        if (std::cin.fail())
        {
            std::cout << "Incorrect value!" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            continue;
        }

        switch (number)
        {
            case 0:
                int value;
                int index;
                return 0;
            case 1:
                value = 0;
                std::cout << "Enter index values: ";
                std::cin >> value;
                FillListRandomValues(list, value);
                break;
            case 2:
                value = 0;
                std::cout << "Enter the value: ";
                std::cin >> value;
                list->Add(value);
                break;
            case 3:
                index = 0;
                std::cout << "Enter the index: ";
                std::cin >> index;
                list->Remove(index);
                break;
            case 4:
                std::cout << "Enter the value: ";
                std::cin >> value;
                list->AddToEnd(value);
                break;
            case 5:
                value = 0;
                std::cout << "Enter the value: ";
                std::cin >> value;
                list->AddToBegin(value);
                break;
            case 6:
                value = 0;
                index = 0;
                std::cout << "Enter the value: ";
                std::cin >> value;
                std::cout << "Enter the index: ";
                std::cin >> index;
                list->Insert(index + 1, value);
                break;
            case 7:
                value = 0;
                std::cout << "Enter the value: ";
                std::cin >> value;
                std::cout << "Enter the index: ";
                std::cin >> index;
                list->Insert(index, value);
                break;
            case 8:
                std::cout << "Sorting list..." << std::endl;
                list->Sort();
                break;
            case 9:
                index = 0;
                std::cout << "Enter the index: ";
                std::cin >> index;
                value = list->GetItem(index)->GetData();
                std::cout << "Found by index: " << value << std::endl;
                break;
            case 10:
                PrintTestResult();
            default:
                std::cout << "Incorrect value!" << std::endl;
                return 0;
        }
        PrintList(list);
    }
}
