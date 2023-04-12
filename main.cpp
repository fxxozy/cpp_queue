#include <iostream>
#include "my_queue.h"

int main() {
    MyQueue<int>* q = new MyQueue<int>();
    q->push(6);
    q->push(8);
    q->push(4);
    q->push(1);
    q->push(7);

    cout << q->front();
    cout << "\n-------------------------------\n";


    cout << q->front();
    cout << "\n-------------------------------\n";
    cout << q->back();
    cout << "\n-------------------------------\n";
    cout << q->get_size();
    cout << "\n-------------------------------\n";
    q->print();
    q->clear();


    MyQueue<string>* q2 = new MyQueue<string>();
    q2->push("aaaa");
    q2->push("bbbb");
    q2->push("cccc");
    q2->push("dddd");
    q2->push("eeee");
    cout << "\n-------------------------------\n";
}
