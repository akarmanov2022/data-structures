//
// Created by aka on 12/8/22.
//

#ifndef DATA_STRUCTURES_DICTIONARY_H
#define DATA_STRUCTURES_DICTIONARY_H


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
    void Add(const char *key, const char *value);

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
     * Вывод словаря на экран
     */
    void Print();

private:
    /**
     * Таблица
     */
    HashTable *table;
};


#endif //DATA_STRUCTURES_DICTIONARY_H
