#include <iostream>
#include "my_queue.h"
#include "QueueIterator.h"

int main() {
    auto q = new MyQueue<int>();
    q->push(6);
    q->push(8);
    q->push(4);
    q->push(1);
    q->push(7);

    QueueIterator<int> iterator = q->begin();
    while(!(iterator == q->end()))
    {
        cout << *iterator++ << endl;
    }
    cout << *iterator << endl;

    q->pop();
    cout << q->front() << endl;
    cout << q->back() << endl;
    cout << q->get_size() << endl;
    delete q;
}