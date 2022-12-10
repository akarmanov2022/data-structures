//
// Created by akarmanoff on 30.09.22.
//
/**
 * Представляет объект - динамический массив целых чисел.
 * @anchor Arseniy Karmanov
 * */
class DynamicIntArray
{
    static const int DEFAULT_CAPACITY = 8;

private:
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

    /**
     * Вернет элемент массива по его позиции.
     * @param indexOf - позиция элемента в массиве.
     * */
    int Get(int indexOf);

    /**
     * Добавит элемент в начало массива.
     * @param value - значение.
     * */
    bool AddToStart(int value);

    /**
     * Добавит элемент в массив после указанной позиции.
     * @param indexAfter - позиция, после которой добавить элемент.
     * @param value - значение.
     * */
    bool AddAfter(int indexAfter, int value);

    /**
     * Линейная сортировка массива.
     * */
    void Sort();

    /**
     * Линейный поиск позиции элемента в массиве.
     * @param value - значение.
     * @return - позиция элемента в массиве.
     * */
    int LinearSearch(int value);

    /**
     * Вернет длину массива.
     * @return длина массива.
     */
    int GetLength() const;

    /**
     * Вернуть вместимость массива.
     * @return вместимость массива.
     */
    int GetCapacity() const;

    /**
     * Линейный поиск позиции элемента в массиве относительно левой и правой границы.
     * @param value - значение.
     * @param left - левая граница.
     * @param right - правая граница.
     *
     * @return позиция элемента в массиве.
     * */
    int BinarySearch(int value, int left, int right);

    /**
     * Очистка массива.
     * */
    void Clear();

    /**
     * Бинарный поиск позиции элемента в массиве. Массив должен быть отсортирован.
     * @param value значение.
     * @return позиция элемента в массиве.
     */
    int BinarySearch(int value);

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
    static int *ArrayCopyOf(int *sourceArray, int length, int newCapacity);

    /**
     * Смещает элементы массива относительно указанной позиции.
     * @param position позиция, относительно которой смещаются элементы.
     * @param directionShift флаг, определяющий направление смещения.
     */
    void Shift(int position, bool directionShift) const;

    /**
     * Увеличивает массив относительно его минимальной вместимости.
     * @param minCapacity - значение минимальной вместимости.
     * */
    int *Grow(int minCapacity);
};
