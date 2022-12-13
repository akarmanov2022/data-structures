//
// Created by akarmanov on 29-11-2022.
//

#ifndef DATA_STRUCTURES_MENU_H
#define DATA_STRUCTURES_MENU_H

/**
 * Класс, реализующий меню.
 */
class Menu
{
public:
    /**
     * Запустить меню очереди на кольцевом буфере.
     *
     * @param queue очередь на кольцевом буфере.
     */
    static void MenuRingBufferQueue(RingBufferQueue *queue);

    /**
     * Запустить меню очереди на двух стеках.
     *
     * @param queue очередь на двух стеках.
     */
    static void MenuStackQueue(StackQueue *queue);

    /**
     * Запустить меню кольцевого буфера.
     *
     * @param buffer кольцевой буфер.
     */
    static void MenuBuffer(RingBuffer *buffer);

    /**
     * Запустить меню стека.
     *
     * @param stack стек.
     */
    static void MenuStack(Stack *stack);

    /**
     * Вернуть значение, введенное пользователем.
     *
     * @param message сообщение, выводимое перед вводом.
     * @param regex регулярное выражение, по которому проверяется ввод.
     * @return значение, введенное пользователем.
     */
    static int InputInt(const char *message, const char *regex);

    /**
     * Вернуть значение, введенное пользователем. Значение должно быть положительным.
     *
     * @param message сообщение, выводимое перед вводом.
     * @return значение, введенное пользователем.
     */
    static int InputPositiveInt(const char *message);

    /**
     * Вернуть значение, введенное пользователем. Значение должно быть натуральным.
     *
     * @param message сообщение, выводимое перед вводом.
     * @return значение, введенное пользователем.
     */
    static int InputInt(const char *message);

    /**
     * Вывести информацию о стеке в консоль.
     *
     * @param stack стек.
     */
    static void Print(Stack *stack);

    /**
     * Вывести информацию о кольцевом буфере в консоль.
     *
     * @param buffer кольцевой буфер.
     */
    static void Print(RingBuffer *buffer);

    /**
     * Вывести информацию о очереди на кольцевом буфере в консоль.
     *
     * @param queue очередь на двух стеках.
     */
    static void Print(RingBufferQueue *queue);

    /**
     * Вывести информацию о очереди на двух стеках в консоль.
     *
     * @param queue очередь на кольцевом буфере.
     */
    static void Print(StackQueue *queue);
};

#endif //DATA_STRUCTURES_MENU_H
