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
    this->_capacity = DEFAULT_CAPACITY;
    this->_array = new int[DEFAULT_CAPACITY];
}

bool DynamicIntArray::AddToEnd(int value)
{
    CheckCapacity(_length + 1);
    _array[_length++] = value;
    return true;
}

bool DynamicIntArray::Remove(int index)
{
    if (index >= _length)
    {
        throw std::invalid_argument("Incorrect value!");
    }
    int newLength;
    if ((newLength = _length - 1) > index)
    {
        ArrayCopy(_array, index + 1,
                  _array, index, newLength - index);
    }
    _array[_length = newLength] = 0;
    return true;
}

int DynamicIntArray::Get(int indexOf)
{
    //TODO:
    if (indexOf >= _length)
    {
        throw std::invalid_argument("Incorrect value!");
    }
    return _array[indexOf];
}

bool DynamicIntArray::AddToStart(int value)
{
    CheckCapacity(_length + 1);
    ArrayCopy(_array, 0, _array, 1, _length);
    _array[0] = value;
    _length++;
    return true;
}

bool DynamicIntArray::AddAfter(int indexAfter, int value)
{
    int index = indexAfter + 1;
    //TODO: скобочки
    if (indexAfter >= _length)
    {
        throw std::invalid_argument("Incorrect value!");
    }
    int newLength = _length + 1;
    CheckCapacity(newLength);
    ArrayCopy(_array, index, _array, index + 1, newLength - indexAfter);
    _array[index] = value;
    _length++;
    return true;
}

void DynamicIntArray::CheckCapacity(int newLength)
{
    if (newLength == _capacity)
    {
        _array = grow(newLength);
    }
}

int *DynamicIntArray::ArrayCopyOf(const int *sourceArray, int length, int newCapacity)
{
    int *newArray = new int[newCapacity];
    for (int i = 0; i < length; ++i)
    {
        newArray[i] = sourceArray[i];
    }
    delete[] sourceArray;
    return newArray;
}

void DynamicIntArray::ArrayCopy(const int *sourceArray, int sourcePosition,
                                int *destinationArray, int destinationPosition, int length)
{
    if (sourceArray == destinationArray)
    {
        //TODO: сложно
        int *tempArray = new int[length];
        for (int i = 0, j = sourcePosition; j < sourcePosition + length; j++, i++)
        {
            tempArray[i] = sourceArray[j];
        }
        for (int i = 0, j = destinationPosition; j < destinationPosition + length; j++, i++)
        {
            destinationArray[j] = tempArray[i];
        }
        delete[] tempArray;
    }
    else
    {
        for (int i = sourcePosition, j = destinationPosition; i < sourcePosition + length; i++, j++)
        {
            destinationArray[j] = sourceArray[i];
        }
    }
}

int *DynamicIntArray::grow(int minCapacity)
{
    int oldCapacity = _length;
    //TODO: сложно и не нужно
    int newCapacity = oldCapacity + (oldCapacity / 2);
    //TODO: скобочки
    if (newCapacity - minCapacity < 0)
    {
        newCapacity = minCapacity;
    }
    this->_capacity = newCapacity;
    return ArrayCopyOf(_array, _length, newCapacity);
}

int DynamicIntArray::GetLength() const
{
    return _length;
}

int DynamicIntArray::GetCapacity() const
{
    return _capacity;
}

void DynamicIntArray::Sort()
{
    if (_length <= 1) return;
    for (int i = 1; i < _length; ++i)
    {
        for (int j = 0; j < _length; ++j)
        {
            if (_array[i] < _array[j])
            {
                int temp = _array[i];
                _array[i] = _array[j];
                _array[j] = temp;
            }
        }
    }
}

int DynamicIntArray::FindLinear(int value)
{
    for (int i = 0; i < _length; ++i)
    {
        if (_array[i] == value)
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
        if (value < _array[middle])
        {
            right = middle - 1;
        }
        else if (value > _array[middle])
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }

        if (left > right) return -1;
    }
}

void DynamicIntArray::Clear()
{
    int tempLength = _length;
    for (int i = 0; i < tempLength; ++i)
    {
        _array[i] = 0;
        _length--;
    }
}

