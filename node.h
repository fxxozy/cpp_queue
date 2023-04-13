#ifndef TASK3_NODE_H
#define TASK3_NODE_H

#include <iostream>

using namespace std;

template<typename T>
class MyQueue;

template<typename T>
class QueueIterator;

template <typename T>
class Node
{
    friend class MyQueue<T>;
    friend class QueueIterator<T>;
private:
    T value;
    Node* next;

    Node(T value): value(value), next(nullptr) {}

    Node(T value, Node* next): value(value), next(next) {}

public:
    ~Node();
};


template<typename T>
Node<T>::~Node()
{
    cout <<  "Deleting node!" <<  endl;
}


#endif //TASK3_NODE_H