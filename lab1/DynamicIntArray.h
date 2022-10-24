//
// Created by akarmanoff on 30.09.22.
//
//TODO: RSDN - doxygen
class DynamicIntArray
{
    static const int DEFAULT_CAPACITY = 8;

private:
    //TODO: RSDN
    int length = 0;
    int capacity = 0;
    int *array;

public:
    DynamicIntArray();

    explicit DynamicIntArray(int capacity);

    bool AddToEnd(int value);

    bool Remove(int index);

    int Get(int indexOf);

    bool AddToStart(int value);

    bool AddAfter(int indexAfter, int value);

    void Sort();

    //TODO: RSDN
    int FindLinear(int value);

    int GetLength() const;

    int GetCapacity() const;

    int FindBinary(int value, int left, int right);

    void Clear();

private:

    void CheckCapacity(int newLength);

    //TODO: RSDN - сокращения
    static int *ArrayCopyOf(const int *sourceArray, int length, int newCapacity);

    static void ArrayCopy(const int *sourceArray, int sourcePosition,
                          int *newArray, int destinationPosition, int length);

    int *grow(int minCapacity);
};
