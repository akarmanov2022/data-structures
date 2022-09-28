#include <iostream>

struct DynamicIntArray
{
    static const int DEFAULT_CAPACITY = 10;

private:
    int EMPTY_ELEMENTDATA[0] = {};

    int length = 0;
    int capacity = 0;
    int *array;

public:
    explicit DynamicIntArray(int capacity)
    {
        if (capacity <= 0)
        {
            this->array = EMPTY_ELEMENTDATA;
            this->capacity = DEFAULT_CAPACITY;
        } else
        {
            this->capacity = capacity;
            this->array = new int[capacity];
        }
    }

    bool Add(int value)
    {
        if (length + 1 == capacity) {
            grow(length + 1);
        }
        array[length++] = value;
        return true;
    }

    int Get(int indexOf)
    {
        return this->array[indexOf];
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
    static int *ArrayCopyOf(const int *oldArray, int length, int newCapacity)
    {
        int *newArray = new int[newCapacity];
        for (int i = 0; i < length; ++i)
        {
            newArray[i] = oldArray[i];
        }
        delete[] oldArray;
        return newArray;
    }

    void grow(int minCapacity)
    {
        int oldCapacity = length;
        int newCapacity = oldCapacity + (oldCapacity >> 1);
        if (newCapacity - minCapacity < 0)
            newCapacity = minCapacity;
        this->array = ArrayCopyOf(array, oldCapacity, newCapacity);
        this->capacity = newCapacity;
    }
};

int main()
{
    auto *pArray = new DynamicIntArray(5);

    for (int i = 0; i < 10; ++i)
    {
        pArray->Add(rand() % 100 + 1);
    }

    for (int i = 0; i < pArray->getLength(); ++i)
    {
        std::cout << pArray->Get(i) << " ";
    }
}
