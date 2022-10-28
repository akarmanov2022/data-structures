//
// Created by akarmanoff on 30.09.22.
//
//TODO: RSDN - doxygen
/**
 * Представляет объект - динамический массив целых чисел.
 * */
class DynamicIntArray
{
    static const int DEFAULT_CAPACITY = 8;

private:
    //TODO: RSDN
    int _length = 0;
    int _capacity = 0;
    int *_array;

public:
    DynamicIntArray();

    /**
     *  Добавит элемент в конец массива.
     *  @param value - значение элемента.
     * */
    bool AddToEnd(int value);

    /**
     * Удалит элемент из массива по его позиции.
     * @param index - позиция элемента в массива
     * */
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

    /**
     * Расширяет массив относительно его минимальной вместимости по формуле:
     * @code oldCapacity + (oldCapacity / 2) @endcode
     * где oldCapacity - текущая вместимость массива, если oldCapacity < minCapacity.
     *
     * @param minCapacity - минимальная необходимая вместимость массива.
     * */
    void CheckCapacity(int newLength);

    //TODO: RSDN - сокращения
    static int *ArrayCopyOf(const int *sourceArray, int length, int newCapacity);

    /**
     * Копирует массив из указанного исходного массива, начиная с указанной позиции, в указанную позицию целевого массива.
     * Подпоследовательность компонентов массива копируется из исходного массива, на который ссылается "sourceArray", в целевой массив, на который ссылается "destinationArray".
     * Количество скопированных компонентов равно аргументу длины - "_length".
     * Компоненты в позициях от "sourcePosition" до "sourcePosition + _length - 1" в исходном массиве копируются в позиции от "destinationPosition" до destinationPosition + _length - 1", соответственно, массива назначения.
     * Если аргументы "sourceArray" и "destinationArray" ссылаются на один и тот же объект-массив, то копирование выполняется так,
     * как если бы компоненты в позициях от "sourcePosition" до "sourcePosition + _length - 1" были сначала скопированы во временный массив с компонентами длины
     * и затем содержимое временного массива копировалось в позиции от "destinationPosition" до destinationPosition + _length - 1" целевого массива.
     *
     * @param sourceArray - исходный массив.
     * @param sourcePosition - позиция в исходном массиве.
     * @param destinationArray - целевой массив.
     * @param destinationPosition - позиция в целевом массиве.
     * @param length - количество копируемых элементов массива.
     * */
    static void ArrayCopy(const int *sourceArray, int sourcePosition,
                          int *destinationArray, int destinationPosition, int length);

    int *grow(int minCapacity);
};
