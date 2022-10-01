//
// Created by akarmanoff on 30.09.22.
//

class DynamicIntArray
{
    static const int DEFAULT_CAPACITY = 10;

private:
    int EMPTY_ELEMENTDATA[0] = {};
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

    int FindLine(int value);

    int FindBinary(int value);

    int getLength() const;

    int getCapacity() const;

    int *getArray();

private:
    void CheckCapacity(int newLength);

    static int *ArrayCopyOf(const int *srcArray, int length, int newCapacity);

    static void ArrayCopy(const int *srcArray, int srcPos,
                          int *newArray, int destPos, int length);

    int *grow(int minCapacity);
};
