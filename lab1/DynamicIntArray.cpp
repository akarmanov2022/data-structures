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
    this->capacity = DEFAULT_CAPACITY;
    this->array = new int[DEFAULT_CAPACITY];
}

DynamicIntArray::DynamicIntArray(int capacity)
{
    if (capacity < 0)
    {
        throw std::invalid_argument("Incorrect value!");
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
    {
        throw std::invalid_argument("Incorrect value!");
    }
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
    //TODO:
    if (indexOf >= length)
    {
        throw std::invalid_argument("Incorrect value!");
    }
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
    //TODO: скобочки
    if (indexAfter >= length)
    {
        throw std::invalid_argument("Incorrect value!");
    }
    int newLength = length + 1;
    CheckCapacity(newLength);
    ArrayCopy(array, index, array, index + 1, newLength - indexAfter);
    array[index] = value;
    length++;
    return true;
}

void DynamicIntArray::CheckCapacity(int newLength)
{
    if (newLength == capacity)
    {
        array = grow(newLength);
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

/**
 * Копирует массив из указанного исходного массива, начиная с указанной позиции, в указанную позицию целевого массива.
 * Подпоследовательность компонентов массива копируется из исходного массива, на который ссылается "sourceArray", в целевой массив, на который ссылается "destinationArray".
 * Количество скопированных компонентов равно аргументу длины - "length".
 * Компоненты в позициях от "sourcePosition" до "sourcePosition + length - 1" в исходном массиве копируются в позиции от "destinationPosition" до destinationPosition + length - 1", соответственно, массива назначения.
 * Если аргументы "sourceArray" и "destinationArray" ссылаются на один и тот же объект-массив, то копирование выполняется так,
 * как если бы компоненты в позициях от "sourcePosition" до "sourcePosition + length - 1" были сначала скопированы во временный массив с компонентами длины
 * и затем содержимое временного массива копировалось в позиции от "destinationPosition" до destinationPosition + length - 1" целевого массива.
 *
 * @param sourceArray - исходный массив.
 * @param sourcePosition - позиция в исходном массиве.
 * @param destinationArray - целевой массив.
 * @param destinationPosition - позиция в целевом массиве.
 * @param length - количество копируемых элементов массива.
 * */
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

/**
 * Расширяет массив относительно его минимальной вместимости по формуле:
 * @code oldCapacity + (oldCapacity / 2) @endcode
 * где oldCapacity - текущая вместимость массива.
 *
 * @param minCapacity - минимальная необходимая вместимость массива.
 * */
int *DynamicIntArray::grow(int minCapacity)
{
    int oldCapacity = length;
    //TODO: сложно и не нужно
    int newCapacity = oldCapacity + (oldCapacity / 2);
    //TODO: скобочки
    if (newCapacity - minCapacity < 0)
    {
        newCapacity = minCapacity;
    }
    this->capacity = newCapacity;
    return ArrayCopyOf(array, length, newCapacity);
}

int DynamicIntArray::GetLength() const
{
    return length;
}

int DynamicIntArray::GetCapacity() const
{
    return capacity;
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

        if (left > right) return -1;
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

