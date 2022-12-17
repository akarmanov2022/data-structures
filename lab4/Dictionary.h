//
// Created by aka on 12/8/22.
//

#ifndef DATA_STRUCTURES_DICTIONARY_H
#define DATA_STRUCTURES_DICTIONARY_H


#include <ostream>
#include "HashTable.h"

static const int DEFAULT_SIZE = 10;

/**
 * Класс словаря
 * @author akaramanoff
 * @date 12/8/22
 */
class Dictionary
{
public:
    /**
     * Конструктор по умолчанию
     */
    Dictionary();

    /**
     * Деструктор
     */
    ~Dictionary();

    /**
     * Добавление элемента в словарь
     * @param key ключ
     * @param value значение
     */
    bool Add(const char *key, const char *value);

    /**
     * Удаление элемента из словаря
     * @param key ключ
     */
    void Remove(const char *key);

    /**
     * Получение значения по ключу
     * @param key ключ
     * @return значение
     */
    const char *Get(const char *key);

    /**
     * Получить размер словаря.
     * @return размер словаря.
     */
    long GetSize();

    /**
     * Получить таблицу.
     * @return таблица.
     */
    HashTable *GetTable() const;

    friend std::ostream &operator<<(std::ostream &os, Dictionary &dictionary);

private:
    /**
     * Таблица
     */
    HashTable *_table;
};


#endif //DATA_STRUCTURES_DICTIONARY_H
