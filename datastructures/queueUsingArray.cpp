#include <iostream>
using namespace std;

// Queuqe with fixed size 5
const int SIZE = 5;

class Queue {
private:
    // Front and rear of the queue
    int front, rear;
    // Array representing the queue
    int q[SIZE];

public:
    Queue();
    // Enter element at the back of the queue
    void enqueue(int ele);
    // Remove element from the front of the queue
    void dequeue();
    // Check if the queue is empty
    bool isEmpty();
    // Check fi the queue is full
    bool isFull();
    // Prints the front element of the queue
    void peak();
    // Display all the elements of the queue
    void display();
    // Clear the queue
    void clear();
};

Queue::Queue()
{
    front = rear = -1;
}

bool Queue::isEmpty()
{
    // front == -1 will be true at the begining
    // front > rear will be true after dequeuing all the element
    return front == -1 || front > rear;
}

bool Queue::isFull()
{
    return rear == SIZE - 1;
}

void Queue::enqueue(int ele)
{
    if (isFull()) {
        cout << "Queue is full" << endl;
    } else {
        // In the begining make front as 0
        if (front == -1) {
            front = 0;
        }
        // Incrementing the reare and assigning the value
        q[++rear] = ele;
        cout << ele << " Enqueued" << endl;
    }
}

void Queue::dequeue()
{
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        // Storing front value in temp variable and performing dequeue
        int temp = q[front++];
        cout << temp << " removed from queue" << endl;
    }
}

void Queue::peak()
{
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        // Prints front element of queueue
        cout << q[front] << " is the front element in the queue" << endl;
    }
}

void Queue::display()
{
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        // Loops from fornt to rear and prints elements of the queue
        for (int i = front; i < rear; i++) {
            cout << q[i] << " <- ";
        }
        cout << q[rear];
        cout << endl;
    }
}

void Queue::clear()
{
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        // Clearing the queue by making front and rear -1
        front = rear = -1;
        cout << "Queue is cleared" << endl;
    }
}

int main()
{

    Queue queue;
    int ch;
    do {
        cout << "*********************************************" << endl;
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Peak\n"
                "5. Clear\n0. Exit\nEnter your choice: ";
        cin >> ch;
        cout << "*********************************************" << endl;
        switch (ch) {
        case 0:
            cout << "Exiting..." << endl;
            break;
        case 1:
            int ele;
            cout << "Enter the element to push: ";
            cin >> ele;
            queue.enqueue(ele);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.display();
            break;
        case 4:
            queue.peak();
            break;
        case 5:
            queue.clear();
            break;
        default:
            cout << "Wrong option.. Retry.." << endl;
        }
    } while (ch != 0);
    return 0;
}