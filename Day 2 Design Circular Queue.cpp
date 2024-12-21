#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> queue;
    int head, tail, size;

public:
    MyCircularQueue(int k) : queue(k), head(-1), tail(-1), size(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        if (isEmpty()) head = 0;
        tail = (tail + 1) % size;
        queue[tail] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        if (head == tail) {
            head = tail = -1;
        } else {
            head = (head + 1) % size;
        }
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : queue[head];
    }

    int Rear() {
        return isEmpty() ? -1 : queue[tail];
    }

    bool isEmpty() {
        return head == -1;
    }

    bool isFull() {
        return (tail + 1) % size == head;
    }
};

int main() {
    MyCircularQueue circularQueue(3);
    circularQueue.enQueue(1);
    circularQueue.enQueue(2);
    circularQueue.enQueue(3);
    cout << "Enqueue 4: " << circularQueue.enQueue(4) << endl;
    cout << "Rear: " << circularQueue.Rear() << endl;
    circularQueue.deQueue();
    cout << "Front after dequeue: " << circularQueue.Front() << endl;

}
