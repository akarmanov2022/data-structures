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

int Input()
{
    int value = 0;
    while (true)
    {
        std::cin >> value;
        if (std::cin.bad())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Invalid input!" << std::endl;
            std::cout << "Repeat entering:" << std::endl;
        }
        else
        {
            break;
        }
    }
    return value;
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

        std::cout << "Enter the task number or 0 for exit: " << std::endl;
        int number = Input();

        switch (number)
        {
            case 0:
            {
                return 0;
            }
            case 1:
            {
                std::cout << "Enter the number of elements: ";
                int value = Input();
                FillListRandomValues(list, value);
                break;
            }
            case 2:
            {
                std::cout << "Enter the value: ";
                int value = Input();
                list->Add(value);
                break;
            }
            case 3:
            {
                std::cout << "Enter the index: ";
                int index = Input();
                try
                {
                    list->Remove(index);
                } catch (const char *mes)
                {
                    std::cout << mes << std::endl;
                    break;
                }
                break;
            }
            case 4:
            {
                std::cout << "Enter the value: ";
                int value = Input();
                list->AddToEnd(value);
                break;
            }
            case 5:
            {
                std::cout << "Enter the value: ";
                int value = Input();
                list->AddToBegin(value);
                break;
            }
            case 6:
            {
                std::cout << "Enter the value: ";
                int value = Input();
                std::cout << "Enter the index: ";
                int index = Input();
                try
                {
                    list->Insert(index + 1, value);
                } catch (const char *mes)
                {
                    std::cout << mes << std::endl;
                    break;
                }
                break;
            }
            case 7:
            {
                std::cout << "Enter the value: ";
                int value = Input();
                std::cout << "Enter the index: ";
                int index = Input();
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
                std::cout << "Enter the index: ";
                int index = Input();
                try
                {
                    int value = list->GetItem(index)->GetData();
                    std::cout << "Found by index: " << value << std::endl;
                } catch (const char *mes)
                {
                    std::cout << mes << std::endl;
                    break;
                }
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
