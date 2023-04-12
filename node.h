#ifndef TASK3_NODE_H
#define TASK3_NODE_H

#include <iostream>

using namespace std;

/// Класс Node (Узел)
template <typename T>
class Node
{
private:
    T value;
    Node* next;

public:
    Node(): next(nullptr) {}

    Node(T value): value(value), next(nullptr) {}

    Node(T value, Node* next): value(value), next(next) {}

    T get_value();

    void set_value(T value);

    Node<T>* get_next();

    void set_next(Node<T>* next);

    ~Node();

};


template<typename T>
T Node<T>::get_value()
{
    return value;
}

template<typename T>
void Node<T>::set_value(T value)
{
    this->value = value;
}

template<typename T>
Node<T>* Node<T>::get_next()
{
    return this->next;
}

template<typename T>
void Node<T>::set_next(Node<T>* next)
{
    this->next = next;
}

template<typename T>
Node<T>::~Node() {
    cout << "Deleting node!" << endl;
}


#endif //TASK3_NODE_H
