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
    int newLength = _length - 1;
    if (newLength > index)
    {
        Shift(index, false);
    }
    _array[_length = newLength] = 0;
    return true;
}

int DynamicIntArray::Get(int indexOf)
{
    if (indexOf >= _length)
    {
        throw std::invalid_argument("Incorrect value!");
    }
    return _array[indexOf];
}

bool DynamicIntArray::AddToStart(int value)
{
    CheckCapacity(_length + 1);
    Shift(0, true);
    _array[0] = value;
    _length++;
    return true;
}

bool DynamicIntArray::AddAfter(int indexAfter, int value)
{
    int index = indexAfter + 1;
    if (indexAfter >= _length)
    {
        throw std::invalid_argument("Incorrect value!");
    }
    int newLength = _length + 1;
    CheckCapacity(newLength);
    Shift(index, true);
    _array[index] = value;
    _length++;
    return true;
}

void DynamicIntArray::CheckCapacity(int newLength)
{
    if (newLength == _capacity)
    {
        _array = Grow(newLength);
    }
}

int *DynamicIntArray::ArrayCopyOf(int *sourceArray, int length, int newCapacity)
{
    int *newArray = new int[newCapacity];
    for (int i = 0; i < length; ++i)
    {
        newArray[i] = sourceArray[i];
    }
    delete[] sourceArray;
    return newArray;
}

void DynamicIntArray::Shift(int position, bool directionShift) const
{
    if (directionShift)
    {
        for (int i = _length - 1; i >= position; --i)
        {
            _array[i + 1] = _array[i];
        }
    }
    else
    {
        for (int i = position; i < _length; ++i)
        {
            _array[i - 1] = _array[i];
        }
    }
}

int *DynamicIntArray::Grow(int minCapacity)
{
    int oldCapacity = _length;
    int newCapacity = oldCapacity + (oldCapacity / 2);
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

int DynamicIntArray::LinearSearch(int value)
{
    for (int i = 0; i < _length; ++i)
    {
        if (_array[i] == value)
            return i;
    }
    return -1;
}

int DynamicIntArray::BinarySearch(int value, int left, int right)
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

int DynamicIntArray::BinarySearch(int value)
{
    return BinarySearch(value, 0, _length - 1);
}

