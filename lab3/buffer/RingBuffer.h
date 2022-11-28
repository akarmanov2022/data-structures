//
// Created by akarmanov on 28-11-2022.
//

#ifndef DATA_STRUCTURES_RINGBUFFER_H
#define DATA_STRUCTURES_RINGBUFFER_H

/**
 * Ring buffer implementation
 */
class RingBufferNode
{
private:
    /**
     * Data stored in the node
     */
    int _data;
    /**
     * Pointer to the next node
     */
    RingBufferNode *_next{};
public:
    /**
     * Get data stored in the node
     * @return data stored in the node
     */
    int GetData() const;

    /**
     * Get pointer to the next node
     * @return pointer to the next node
     */
    RingBufferNode *GetNext() const;

    /**
     * Set pointer to the next node
     * @param next pointer to the next node
     */
    void SetNext(RingBufferNode *next);

    /**
     * Constructor
     * @param value data to store in the node
     */
    RingBufferNode(int value);
};

/**
 * Ring buffer implementation
 */
class RingBuffer
{
private:
    /**
     * Pointer to the last node
     */
    RingBufferNode *_first;
    /**
     * Size of the buffer
     */
    int _size;
public:
    /**
     * Get size of the buffer
     * @return size of the buffer
     */
    int GetSize() const;

    /**
     * Put data into the buffer
     * @param value data to put into the buffer
     * @return pointer to the node containing the data
     */
    RingBufferNode *Put(int value);

    /**
     * Get data from the buffer
     * @param index index of the data to get
     * @return pointer to the node containing the data
     */
    RingBufferNode *Get(int index);

    /**
     * Remove data from the buffer
     * @param index index of the data to remove
     * @return pointer to the node containing the data
     */
    RingBufferNode *Remove(int index);

    /**
     * Clear the buffer
     */
    void Clear();

    /**
     * Get first node in the buffer
     * @return pointer to the first node in the buffer
     */
    RingBufferNode *GetFirst() const;
};


#endif //DATA_STRUCTURES_RINGBUFFER_H
