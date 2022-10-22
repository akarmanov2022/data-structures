#include <iostream>
#include "DynamicIntArray.h"

void PrintArrayInfo(DynamicIntArray *ints)
{
    std::cout << "Capacity: " << ints->getCapacity() << std::endl;
    std::cout << "Length: " << ints->getLength() << std::endl;
    for (int i = 0; i < ints->getLength(); ++i)
    {
        std::cout << ints->Get(i) << " ";
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
    srand(time(NULL));
    auto ints = new DynamicIntArray();

    while (true)
    {
        std::cout << "Lab 1:" << std::endl;
        std::cout << "1. Create an array of random values." << std::endl;
        std::cout << "2. Adding an element to an array." << std::endl;
        std::cout << "3. Removing an element from an array." << std::endl;
        std::cout << "4. Inserting an element at the beginning." << std::endl;
        std::cout << "5. Inserting an element at the end." << std::endl;
        std::cout << "6. Insert after a specific element." << std::endl;
        std::cout << "7. Array sort." << std::endl;
        std::cout << "8. Linear search for an element in an array." << std::endl;
        std::cout << "9. Binary search for an element in an array." << std::endl;

        int number = 0;
        int length = 0;
        int value = 0;
        int index = 0;
        std::cout << "Enter the number: ";
        std::cin >> number;
        switch (number)
        {
            case 0:
                return number;
            case 1:
                std::cout << "Enter the length of the array: ";
                std::cin >> length;
                CreateRandomArray(ints, length);
                PrintArrayInfo(ints);
                break;
            case 2:
                std::cout << "Enter the value: ";
                std::cin >> value;
                ints->AddToEnd(value);
                PrintArrayInfo(ints);
                break;
            case 3:
                std::cout << "Enter the index: ";
                std::cin >> index;
                ints->Remove(index);
                PrintArrayInfo(ints);
                break;
            case 4:
                std::cout << "Enter the value: ";
                std::cin >> value;
                ints->AddToStart(value);
                PrintArrayInfo(ints);
                break;
            case 5:
                std::cout << "Enter the value: ";
                std::cin >> value;
                ints->AddToEnd(value);
                PrintArrayInfo(ints);
                break;
            case 6:
                std::cout << "Enter the index: ";
                std::cin >> index;
                std::cout << "Enter the value: ";
                std::cin >> value;
                ints->AddAfter(index, value);
                PrintArrayInfo(ints);
                break;
            case 7:
                ints->Sort();
                PrintArrayInfo(ints);
                break;
            case 8:
                std::cout << "Enter the value: ";
                std::cin >> value;
                index = ints->FindLinear(value);
                if (index != -1)
                {
                    std::cout << "Index: " << index << std::endl;
                }
                else
                {
                    std::cout << "Index not found!" << std::endl;
                }
                break;
            case 9:
                std::cout << "Enter the value: ";
                std::cin >> value;
                index = ints->FindBinary(value, 0, ints->getLength());
                PrintArrayInfo(ints);
                if (index != -1)
                {
                    std::cout << "Index: " << index << std::endl;
                }
                else
                {
                    std::cout << "Index not found!" << std::endl;
                }
                break;
            default:
                throw std::invalid_argument("Incorrect number!");
        }
    }
}
