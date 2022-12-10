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
        list->Sort();
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

int InputInt(const char *string)
{
    std::string input;
    bool valid;
    while (true)
    {
        valid = true;
        std::cout << string;
        std::cin >> input;
        for (char c : input)
        {
            if (c < '0' || c > '9')
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            break;
        }
        std::cout << "Invalid input" << std::endl;
    }
    return std::stoi(input);
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

        int choice = InputInt("Enter your choice: ");
        switch (choice)
        {
            case 1:
            {
                int count = InputInt("Enter the number of elements: ");
                FillListRandomValues(list, count);
                PrintList(list);
                break;
            }
            case 2:
            {
                int value = InputInt("Enter the value: ");
                list->Add(value);
                PrintList(list);
                break;
            }
            case 3:
            {
                int index = InputInt("Enter the index: ");
                list->Remove(index);
                PrintList(list);
                break;
            }
            case 4:
            {
                int value = InputInt("Enter the value: ");
                list->AddToBegin(value);
                PrintList(list);
                break;
            }
            case 5:
            {
                int value = InputInt("Enter the value: ");
                list->Add(value);
                PrintList(list);
                break;
            }
            case 6:
            {
                int index = InputInt("Enter the index: ");
                int value = InputInt("Enter the value: ");
                list->Insert(index + 1, value);
                PrintList(list);
                break;
            }
            case 7:
            {
                int index = InputInt("Enter the index: ");
                int value = InputInt("Enter the value: ");
                list->Insert(index + 1, value);
                PrintList(list);
                break;
            }
            case 8:
            {
                list->Sort();
                PrintList(list);
                break;
            }
            case 9:
            {
                int value = InputInt("Enter the value: ");
                int index = list->LinearSearch(value);
                if (index == -1)
                {
                    std::cout << "Value not found" << std::endl;
                }
                else
                {
                    std::cout << "Value found at index " << index << std::endl;
                }
                break;
            }
            case 10:
            {
                PrintTestResult();
                break;
            }
            case 0:
            {
                return 0;
            }
            default:
            {
                std::cout << "Invalid input" << std::endl;
                break;
            }
        }

    }
}
