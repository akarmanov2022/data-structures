//
// Created by akarmanoff on 30.09.22.
//

#include <stdexcept>
#include "DynamicIntArray.h"

/**
 * Конструктор по умолчанию.
 * */
DynamicIntArray::DynamicIntArray()
{
    this->array = new int [DEFAULT_CAPACITY];
    this->capacity = DEFAULT_CAPACITY;
}

DynamicIntArray::DynamicIntArray(int capacity)
{
    if (capacity < 0)
    {
        throw std::invalid_argument("Incorrect value!");
    }
    if (capacity == 0)
    {
        this->array = new int [DEFAULT_CAPACITY];
        this->capacity = DEFAULT_CAPACITY;
    }
    else
    {
        this->capacity = capacity;
        this->array = new int[capacity];
    }
}

bool DynamicIntArray::AddToEnd(int value)
{
    CheckCapacity(length + 1);
    array[length++] = value;
    return true;
}

bool DynamicIntArray::Remove(int index)
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

int DynamicIntArray::Get(int indexOf)
{
    if (indexOf >= length)
        throw std::invalid_argument("Incorrect value!");
    return array[indexOf];
}

bool DynamicIntArray::AddToStart(int value)
{
    CheckCapacity(length + 1);
    ArrayCopy(array, 0, array, 1, length);
    array[0] = value;
    length++;
    return true;
}

bool DynamicIntArray::AddAfter(int indexAfter, int value)
{
    int index = indexAfter + 1;
    if (indexAfter >= length)
        throw std::invalid_argument("Incorrect value!");
    int newLength;
    CheckCapacity(newLength = length + 1);
    ArrayCopy(array, index, array, index + 1, newLength - indexAfter);
    array[index] = value;
    length++;
    return true;
}

void DynamicIntArray::CheckCapacity(int newLength)
{
    if (newLength == capacity)
        array = grow(newLength);
}

int *DynamicIntArray::ArrayCopyOf(const int *srcArray, int length, int newCapacity)
{
    int *newArray = new int[newCapacity];
    for (int i = 0; i < length; ++i)
    {
        newArray[i] = srcArray[i];
    }
    delete[] srcArray;
    return newArray;
}

void DynamicIntArray::ArrayCopy(const int *srcArray, int srcPos,
                                int *newArray, int destPos, int length)
{
    if (srcArray == newArray)
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
    else
    {
        for (int i = srcPos, j = destPos; i < srcPos + length; i++, j++)
        {
            newArray[j] = srcArray[i];
        }
    }
}

int *DynamicIntArray::grow(int minCapacity)
{
    int oldCapacity = length;
    int newCapacity = oldCapacity + (oldCapacity >> 1);
    if (newCapacity - minCapacity < 0)
        newCapacity = minCapacity;
    this->capacity = newCapacity;
    return ArrayCopyOf(array, length, newCapacity);
}

int DynamicIntArray::getLength() const
{
    return length;
}

int DynamicIntArray::getCapacity() const
{
    return capacity;
}

int *DynamicIntArray::getArray()
{
    return ArrayCopyOf(array, length, capacity);
}

void DynamicIntArray::Sort()
{
    if (length <= 1) return;
    for (int i = 1; i < length; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            if (array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int DynamicIntArray::FindLinear(int value)
{
    for (int i = 0; i < length; ++i)
    {
        if (array[i] == value)
            return i;
    }
    return -1;
}

int DynamicIntArray::FindBinary(int value, int left, int right)
{
    Sort();
    int middle;
    while (true)
    {
        middle = (left + right) / 2;
        if (value < array[middle])
        {
            right = middle - 1;
        }
        else if (value > array[middle])
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }

        if (left > right)
            return -1;
    }
}

void DynamicIntArray::Clear()
{
    int tempLength = length;
    for (int i = 0; i < tempLength; ++i)
    {
        array[i] = 0;
        length--;
    }
}

