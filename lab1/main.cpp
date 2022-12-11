#include <iostream>
#include <regex>
#include "DynamicIntArray.h"

int InputInt(const char *message)
{
    std::string input;
    while (true)
    {
        std::cout << message;
        std::cin >> input;
        if (regex_match(input, std::regex("(-|)[0-9]+")))
        {
            return std::stoi(input);
        }
        else
        {
            std::cout << "Invalid input" << std::endl;
        }
    }
}


void PrintArrayInfo(DynamicIntArray *dynamicIntArray)
{
    std::cout << "Capacity: " << dynamicIntArray->GetCapacity() << std::endl;
    std::cout << "Length: " << dynamicIntArray->GetLength() << std::endl;
    for (int i = 0; i < dynamicIntArray->GetLength(); ++i)
    {
        std::cout << dynamicIntArray->Get(i) << " ";
    }
    std::cout << std::endl << std::endl;
}

void CheckIndex(int index)
{
    if (index != -1)
    {
        std::cout << "Index: " << index << std::endl;
    }
    else
    {
        std::cout << "Index not found!" << std::endl;
    }
}

void CreateRandomArray(DynamicIntArray *array, int length)
{
    array->Clear();
    if (length < 0)
    {
        throw std::invalid_argument("Incorrect value!");
    }
    for (int i = 0; i < length; ++i)
    {
        array->AddToEnd(rand() % 20 - 10);
    }
}

int main()
{
    srand(time(nullptr));
    auto dynamicIntArray = new DynamicIntArray();

    while (true)
    {
        std::cout << "Lab 1: Dynamic Array" << std::endl;
        std::cout << "1. Create an _array of random values." << std::endl;
        std::cout << "2. Adding an element to an _array." << std::endl;
        std::cout << "3. Removing an element from an _array." << std::endl;
        std::cout << "4. Inserting an element at the beginning." << std::endl;
        std::cout << "5. Inserting an element at the end." << std::endl;
        std::cout << "6. Insert after a specific element." << std::endl;
        std::cout << "7. Array sort." << std::endl;
        std::cout << "8. Linear search for an element in an _array." << std::endl;
        std::cout << "9. Binary search for an element in an _array." << std::endl;
        std::cout << "10. Exit." << std::endl;

        int choice = InputInt("Enter your choice: ");
        switch (choice)
        {
            case 1:
            {
                int length = InputInt("Enter the length of the _array: ");
                CreateRandomArray(dynamicIntArray, length);
                PrintArrayInfo(dynamicIntArray);
                break;
            }
            case 2:
            {
                int value = InputInt("Enter the value to add: ");
                dynamicIntArray->AddToEnd(value);
                PrintArrayInfo(dynamicIntArray);
                break;
            }
            case 3:
            {
                int index = InputInt("Enter the index of the element to remove: ");
                CheckIndex(index);
                dynamicIntArray->Remove(index);
                PrintArrayInfo(dynamicIntArray);
                break;
            }
            case 4:
            {
                int value = InputInt("Enter the value to add: ");
                dynamicIntArray->AddToStart(value);
                PrintArrayInfo(dynamicIntArray);
                break;
            }
            case 5:
            {
                int value = InputInt("Enter the value to add: ");
                dynamicIntArray->AddToEnd(value);
                PrintArrayInfo(dynamicIntArray);
                break;
            }
            case 6:
            {
                int index = InputInt("Enter the index of the element after which to insert: ");
                CheckIndex(index);
                int value = InputInt("Enter the value to add: ");
                dynamicIntArray->AddAfter(index, value);
                PrintArrayInfo(dynamicIntArray);
                break;
            }
            case 7:
            {
                dynamicIntArray->Sort();
                PrintArrayInfo(dynamicIntArray);
                break;
            }
            case 8:
            {
                int value = InputInt("Enter the value to search: ");
                int index = dynamicIntArray->LinearSearch(value);
                CheckIndex(index);
                break;
            }
            case 9:
            {
                int value = InputInt("Enter the value to search: ");
                int index = dynamicIntArray->BinarySearch(value);
                CheckIndex(index);
                break;
            }
            case 10:
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
