//
// Created by aka on 12/8/22.
//

#ifndef DATA_STRUCTURES_HASHTABLE_H
#define DATA_STRUCTURES_HASHTABLE_H

#include <ostream>

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
    bool Add(const char *key, const char *value);

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

    int GetCount();

/**
 * Размер таблицы
 */
    int _size;

    double GetLoadFactor();

    friend std::ostream &operator<<(std::ostream &os, const HashTable &table);

private:
    /**
     * Структура элемента таблицы
     */
    struct Item
    {
        /**
         * Ключ
         */
        char *_key;

        /**
         * Значение
         */
        char *_value;

        /**
         * Указатель на следующий элемент. Если элемент последний, то указатель равен nullptr.
         */
        Item *_next;
    };

    /**
     * Таблица. Массив указателей на элементы таблицы.
     */
    Item **_items;

    /**
     * Количество элементов
     */
    int _count = 0;

    /**
     * Коэффициент заполнения таблицы.
     */
    double _loadFactor = 0;

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
