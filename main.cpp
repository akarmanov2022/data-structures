#include <iostream>
#include "DynamicIntArray.h"


void PrintArrayInfo(DynamicIntArray *ints);

int main()
{
    auto *ints = new DynamicIntArray(3);

    for (int i = 0; i < 10; ++i)
    {
        ints->AddToEnd(rand() % 10 + 1);
    }

    PrintArrayInfo(ints);

    ints->Remove(2);

    PrintArrayInfo(ints);

    ints->AddToStart(99);
    ints->AddToStart(11);

    PrintArrayInfo(ints);

    ints->AddAfter(0, 100);
    ints->AddAfter(8, 5);
    ints->AddAfter(3, 66);
    ints->AddAfter(4, 8);

    PrintArrayInfo(ints);
}

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
