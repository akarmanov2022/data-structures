#include <iostream>
#include "DynamicIntArray.h"

void CheckIndex(int index);

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
        std::cout << "Lab 1:" << std::endl;
        std::cout << "1. Create an _array of random values." << std::endl;
        std::cout << "2. Adding an element to an _array." << std::endl;
        std::cout << "3. Removing an element from an _array." << std::endl;
        std::cout << "4. Inserting an element at the beginning." << std::endl;
        std::cout << "5. Inserting an element at the end." << std::endl;
        std::cout << "6. Insert after a specific element." << std::endl;
        std::cout << "7. Array sort." << std::endl;
        std::cout << "8. Linear search for an element in an _array." << std::endl;
        std::cout << "9. Binary search for an element in an _array." << std::endl;

        int number = 0;
        int length;
        int value;
        int index;
        std::cout << "Enter the number: ";
        std::cin >> number;
        switch (number)
        {
            case 0:
                return number;
            case 1:
                length = 0;
                std::cout << "Enter the _length of the _array: ";
                std::cin >> length;
                CreateRandomArray(dynamicIntArray, length);
                PrintArrayInfo(dynamicIntArray);
                break;
            case 2:
                value = 0;
                std::cout << "Enter the value: ";
                std::cin >> value;
                dynamicIntArray->AddToEnd(value);
                PrintArrayInfo(dynamicIntArray);
                break;
            case 3:
                index = 0;
                std::cout << "Enter the index: ";
                std::cin >> index;
                dynamicIntArray->Remove(index);
                PrintArrayInfo(dynamicIntArray);
                break;
            case 4:
                value = 0;
                std::cout << "Enter the value: ";
                std::cin >> value;
                dynamicIntArray->AddToStart(value);
                PrintArrayInfo(dynamicIntArray);
                break;
            case 5:
                std::cout << "Enter the value: ";
                std::cin >> value;
                dynamicIntArray->AddToEnd(value);
                PrintArrayInfo(dynamicIntArray);
                break;
            case 6:
                index = 0;
                value = 0;
                std::cout << "Enter the index: ";
                std::cin >> index;
                std::cout << "Enter the value: ";
                std::cin >> value;
                dynamicIntArray->AddAfter(index, value);
                PrintArrayInfo(dynamicIntArray);
                break;
            case 7:
                dynamicIntArray->Sort();
                PrintArrayInfo(dynamicIntArray);
                break;
            case 8:
                value = 0;
                index = 0;
                std::cout << "Enter the value: ";
                std::cin >> value;
                index = dynamicIntArray->FindLinear(value);
                CheckIndex(index);
                break;
            case 9:
                value = 0;
                index = 0;
                std::cout << "Enter the value: ";
                std::cin >> value;
                index = dynamicIntArray->FindBinary(value, 0, dynamicIntArray->GetLength());
                PrintArrayInfo(dynamicIntArray);
                CheckIndex(index);
                break;
            default:
                throw std::invalid_argument("Incorrect number!");
        }
    }
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
