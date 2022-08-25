#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
private:
    Node *front, *rear;
    // Private method to create new node
    Node* newNode(int ele);

public:
    Queue();
    // Enter element at the back of the queue
    void enqueue(int ele);
    // Remove element from the front of the queue
    void dequeue();
    // Check if the queue is empty
    bool isEmpty();
    // Prints the number of elements in the queue
    void size();
    // Prints the front element of the queue
    void peak();
    // Display all the elements of the queue
    void display();
    // Clear the queue
    void clear();
};

Queue::Queue()
{
    front = rear = NULL;
}

Node* Queue::newNode(int ele)
{
    Node* node = new Node();
    node->data = ele;
    node->next = NULL;
    return node;
}

bool Queue::isEmpty()
{
    return front == NULL;
}

void Queue::enqueue(int ele)
{
    Node* node = newNode(ele);
    if (front == NULL) {
        front = rear = node;
    } else {
        rear->next = node;
        rear = rear->next;
    }
    cout << ele << " Enqueued" << endl;
}

void Queue::dequeue()
{
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        // Storing front value in temp variable and performing dequeue
        int tempEle = front->data;
        Node* tempNode = front;
        front = front->next;
        cout << tempEle << " removed from queue" << endl;
        free(tempNode);
    }
}

void Queue::peak()
{
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        // Prints front element of queueue
        cout << front->data << " is the front element in the queue" << endl;
    }
}

void Queue::display()
{
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        Node* temp = front;
        // Loops from fornt to rear and prints elements of the queue
        while (temp->next != NULL) {
            cout << temp->data << " <- ";
            temp = temp->next;
        }
        cout << temp->data;
        cout << endl;
    }
}

void Queue::size()
{
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        Node* temp = front;
        int n = 0;
        // Loops from fornt to rear and calculate the size of the Queue
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }
        cout << "Size of the Queue is " << n << endl;
    }
}

void Queue::clear()
{
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        Node* temp = front;
        // Loops from fornt to rear and frees the memeory
        while (temp != NULL) {
            Node* t = temp;
            temp = temp->next;
            free(t);
        }
        front = rear = NULL;
        cout << "Queue is cleared" << endl;
    }
}

int main()
{
    Queue queue;
    int ch;
    do {
        cout << "*********************************************" << endl;
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Peak\n5. Size\n"
                "6. Clear\n0. Exit\nEnter your choice: ";
        cin >> ch;
        cout << "*********************************************" << endl;
        switch (ch) {
        case 0:
            cout << "Exiting..." << endl;
            break;
        case 1:
            int ele;
            cout << "Enter the element to enqueue: ";
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
            queue.size();
            break;
        case 6:
            queue.clear();
            break;
        default:
            cout << "Wrong option.. Retry.." << endl;
        }
    } while (ch != 0);

    return 0;
}