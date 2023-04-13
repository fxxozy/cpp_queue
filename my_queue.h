#ifndef TASK3_MY_QUEUE_H
#define TASK3_MY_QUEUE_H

#include <iostream>
#include "node.h"

using namespace std;


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

    QueueIterator<T> begin();

    QueueIterator<T> end();

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
        tail->next = new_node;
        tail = new_node;
    }
    size++;
}

template<typename T>
T MyQueue<T>::pop()
{
    if (is_empty()) {
        throw out_of_range("The are no items in queue!");
    }
    Node<T>* curr_node = head;
    T value = curr_node->value;
    if (head == tail)
    {
        head = tail = nullptr;
        delete curr_node;
    }
    else
    {
        head = head->next;
        delete curr_node;
    }
    size--;
    return value;
}

template<typename T>
T MyQueue<T>::front()
{
    if (is_empty()) {
        throw out_of_range("Queue is empty!");
    }
    return head->value;
}

template<typename T>
T MyQueue<T>::back()
{
    if (is_empty())
    {
        throw out_of_range("Queue is empty!");
    }
    return tail->value;
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
MyQueue<T>::~MyQueue()
{
    if (head != nullptr)
    {
        while(head != tail)
        {
            Node<T>* curr_node = head;
            head = head->next;
            delete curr_node;
        }
        delete head;
    }
    cout << "Deleting queue!" << endl;
}

template<typename T>
void MyQueue<T>::print()
{
    cout <<  "Queue: ";
    if (is_empty())
    {
        cout <<  "empty!\n";
        return;
    }
    Node<T>* curr_node = head;
    while (curr_node != nullptr)
    {
        cout << curr_node->value << " ";
        curr_node = curr_node->next;
    }
    cout << endl;
}

template<typename T>
QueueIterator<T> MyQueue<T>::begin()
{
    return QueueIterator<T>(head);
}

template<typename T>
QueueIterator<T> MyQueue<T>::end()
{
    return QueueIterator<T>(tail);
}


#endif //TASK3_MY_QUEUE_H