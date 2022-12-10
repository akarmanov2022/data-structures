//
// Created by aka on 12/8/22.
//

#ifndef DATA_STRUCTURES_HASHTABLE_H
#define DATA_STRUCTURES_HASHTABLE_H

/**
 * Класс хэш-таблицы
 * @author aka
 * @date 12/8/22
 */
class HashTable
{
public:
    /**
     * Конструктор по умолчанию
     */
    HashTable();

    /**
     * Деструктор
     */
    ~HashTable();

    /**
     * Добавление элемента в таблицу
     * @param key ключ
     * @param value значение
     */
    void Add(const char *key, const char *value);

    /**
     * Удаление элемента из таблицы
     * @param key ключ
     */
    void Remove(const char *key);

    /**
     * Поиск элемента в таблице
     * @param key ключ
     * @return значение
     */
    const char *Find(const char *key);

    /**
     * Вывод таблицы на экран
     */
    void Print();

private:
    /**
     * Структура элемента таблицы
     */
    struct Item
    {
        /**
         * Ключ
         */
        char *key;

        /**
         * Значение
         */
        char *value;

        /**
         * Указатель на следующий элемент. Если элемент последний, то указатель равен nullptr.
         */
        Item *next;
    };

    /**
     * Таблица. Массив указателей на элементы таблицы.
     */
    Item **items;

    /**
     * Размер таблицы
     */
    int size;

    /**
     * Количество элементов
     */
    int count = 0;

    /**
     * Коэффициент заполнения таблицы.
     */
    double loadFactor = 0;

    /**
     * Хэш-функция. Возвращает индекс элемента в хэш-таблице по ключу.
     * @param key ключ
     * @return индекс элемента
     */
    int Hash(const char *key) const;

    /**
     * Перехэширование таблицы. Вызывается при превышении коэффициента заполнения.
     */
    void Rehash();

};


#endif //DATA_STRUCTURES_HASHTABLE_H
