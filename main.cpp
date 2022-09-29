#include <iostream>

struct DynamicIntArray
{
    static const int DEFAULT_CAPACITY = 8;

private:
    int EMPTY_ELEMENTDATA[0] = {};
    int length = 0;
    int capacity = 0;
    int *array;

public:
    explicit DynamicIntArray(int capacity)
    {
        if (capacity < 0)
        {
            throw std::invalid_argument("Incorrect value!");
        }
        if (capacity == 0)
        {
            this->array = EMPTY_ELEMENTDATA;
            this->capacity = DEFAULT_CAPACITY;
        }
        else
        {
            this->capacity = capacity;
            this->array = new int[capacity];
        }
    }

    bool AddToEnd(int value)
    {
        CheckCapacity(length + 1);
        array[length++] = value;
        return true;
    }

    bool Remove(int index)
    {
        if (index >= length)
            throw std::invalid_argument("Incorrect value!");
        int newLength;
        if ((newLength = length - 1) > index)
        {
            ArrayCopy(array, index + 1,
                      array, index, newLength - index);
        }
        array[length = newLength] = 0;
        return true;
    }

    int Get(int indexOf)
    {
        if (indexOf > length)
            throw std::invalid_argument("Incorrect value!");
        return array[indexOf];
    }

    bool AddToStart(int value)
    {
        CheckCapacity(length + 1);
        ArrayCopy(array, 0, array, 1, length);
        array[0] = value;
        length++;
        return true;
    }

    bool AddAfter(int indexAfter, int value)
    {
        int index = indexAfter + 1;
        if (indexAfter >= length)
            throw std::invalid_argument("Incorrect value!");
        int newLength;
        if ((newLength = length + 1) == indexAfter)
        {
            array = grow(newLength);
            ArrayCopy(array, index, array, index + 1, newLength - indexAfter);
        }
        array[index] = value;
        length++;
        return true;
    }

    int getLength() const
    {
        return length;
    }

    int getCapacity() const
    {
        return capacity;
    }

private:

    void CheckCapacity(int newLength)
    {
        if (newLength == capacity)
            array = grow(newLength);
    }

    static int *ArrayCopyOf(const int *srcArray, int length, int newCapacity)
    {
        int *newArray = new int[newCapacity];
        for (int i = 0; i < length; ++i)
        {
            newArray[i] = srcArray[i];
        }
        delete[] srcArray;
        return newArray;
    }

    static void ArrayCopy(const int *srcArray, int srcPos,
                          int *newArray, int destPos, int length)
    {
        int *tempArray = new int[length];
        for (int i = 0, j = srcPos; j < srcPos + length; j++, i++)
        {
            tempArray[i] = srcArray[j];
        }
        for (int i = 0, j = destPos; j < destPos + length; j++, i++)
        {
            newArray[j] = tempArray[i];
        }
        delete[] tempArray;
    }

    int *grow(int minCapacity)
    {
        int oldCapacity = length;
        int newCapacity = oldCapacity + (oldCapacity << 1);
        if (newCapacity - minCapacity < 0)
            newCapacity = minCapacity;
        this->capacity = newCapacity;
        return ArrayCopyOf(array, length, newCapacity);
    }
};

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

    PrintArrayInfo(ints);

    ints->AddAfter(9, 7);

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
