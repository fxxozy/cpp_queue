#ifndef TASK3_MY_QUEUE_H
#define TASK3_MY_QUEUE_H

#include <iostream>
#include "node.h"

using namespace std;


/// Класс Queue (Очередь)
template <typename T>
class MyQueue
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    MyQueue(): head(nullptr), tail(nullptr), size(0) {}

    void push(T value);

    T pop();

    T front();

    T back();

    bool is_empty();

    int get_size();

    void print();

    void clear();

    ~MyQueue();
};



template<typename T>
void MyQueue<T>::push(T value)
{
    Node<T>* new_node = new Node<T>(value, nullptr);
    if (is_empty())
    {
        head = new_node;
        tail = head;
    }
    else
    {
        tail->set_next(new_node);
        tail = new_node;
    }
    size++;
}

template<typename T>
T MyQueue<T>::pop()
{
    if (is_empty()) {
        throw "There are no items in the queue!";
    }
    Node<T>* curr_node = head;
    T value = curr_node->get_value();
    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        head = head->get_next();
        delete curr_node;
    }
    size--;
    return value;
}

template<typename T>
T MyQueue<T>::front() {
    if (is_empty()) {
        throw "There are no items in the queue!";
    }
    return head->get_value();
}

template<typename T>
T MyQueue<T>::back()
{
    if (is_empty())
    {
        throw "There are no items in the queue!";
    }
    return tail->get_value();
}

template<typename T>
bool MyQueue<T>::is_empty()
{
    return size == 0;
}

template<typename T>
int MyQueue<T>::get_size()
{
    return size;
}

template<typename T>
void MyQueue<T>::clear()
{
    if (head != nullptr)
    {
        while (head != tail)
        {
            Node<T>* curr_node = head;
            head = head->get_next();
            delete curr_node;
        }
    }
    delete head;
    size = 0;
}

template<typename T>
MyQueue<T>::~MyQueue() {
    if (head != nullptr)
    {
        while(head != tail)
        {
            Node<T>* curr_node = head;
            head = head->get_next();
            delete curr_node;
        }
        delete head;
    }
}

template<typename T>
void MyQueue<T>::print() {
    cout << "Queue: ";
    if (is_empty())
    {
        cout << "empty!\n";
        return;
    }
    Node<T>* curr_node = head;
    while (curr_node != nullptr)
    {
        cout << curr_node->get_value() << " ";
        curr_node = curr_node->get_next();
    }
    cout << endl;
}


#endif //TASK3_MY_QUEUE_H
