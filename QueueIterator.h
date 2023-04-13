#ifndef TASK3_QUEUEITERATOR_H
#define TASK3_QUEUEITERATOR_H

#include "node.h"

template<typename T>
class MyQueue;

template<typename T>
class QueueIterator
{
    friend class MyQueue<T>;
private:
    Node<T>* curr_node;

    QueueIterator(Node<T>* node): curr_node(node) {}
public:

    QueueIterator<T> operator++();

    QueueIterator<T> operator++(int);

    T operator*();

    bool operator==(const QueueIterator<T> queueIterator);
};


template<typename T>
bool QueueIterator<T>::operator==(QueueIterator<T> queueIterator)
{
    return queueIterator.curr_node == curr_node;
}

template<typename T>
T QueueIterator<T>::operator*()
{
    return curr_node->value;
}

template<typename T>
QueueIterator<T> QueueIterator<T>::operator++()
{
    curr_node = curr_node->next;
    return *this;
}

template<typename T>
QueueIterator<T> QueueIterator<T>::operator++(int)
{
    QueueIterator<T> init = QueueIterator<T>(curr_node);
    curr_node = curr_node->next;
    return init;
}

#endif //TASK3_QUEUEITERATOR_H