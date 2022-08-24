#include <iostream>
using namespace std;

// Class for Node
class Node {
public:
    int data;
    Node* next;
};

// Class for stack
class Stack {
private:
    // Top of the stack
    Node* top;
    // Creating new node with data
    Node* newNode(int ele);

public:
    // Constructor
    Stack();
    // Push new element to stack
    void push(int ele);
    // Pop top element of stack
    void pop();
    // Display all elements of stack
    void display();
    // Display top element of stack
    void peak();
    // Number of elements in stack
    void size();
    // Clear all elements of stack
    void clear();
};

Stack::Stack()
{
    // Initializing top to NULL at the begining
    top = NULL;
}

Node* Stack::newNode(int ele)
{
    // Creating new instance of Node class
    Node* node = new Node();
    // Initializing data with value of ele
    node->data = ele;
    // Making next pointer equal to NULL
    node->next = NULL;
    return node;
}

void Stack::push(int ele)
{
    // Creating new node with given element
    Node* temp = newNode(ele);
    // Making current top to point to new node
    temp->next = top;
    // Making new node as top
    top = temp;
    cout << ele << " Pushed to stack" << endl;
}

void Stack::pop()
{
    // Check if stack is empty
    if (top == NULL) {
        cout << "Stack is empty" << endl;
    } else {
        // Displaying top element
        cout << top->data << " poped from stack" << endl;
        // Stroing it in temp variable
        Node* temp = top;
        // Making the element next to top as new top
        top = top->next;
        // Freeing memeory of top node
        free(temp);
    }
}

void Stack::display()
{
    if (top == NULL) {
        cout << "Stack is empty" << endl;
    } else {
        // Taking temp for looping
        Node* temp = top;
        // Stop looping when next of the node points to NULL
        while (temp->next != NULL) {
            // While loop stops at last but one element which is printed outside
            // the loop
            cout << temp->data << " <- ";
            // Going to next node
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
}

void Stack::peak()
{
    if (top == NULL) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Top element of stack is " << top->data << endl;
    }
}

void Stack::size()
{
    if (top == NULL) {
        cout << "Stack is empty" << endl;
    } else {
        int n = 0;
        Node* temp = top;
        // Stop looping when next of the node points to NULL
        while (temp != NULL) {
            // Incrementing the size
            n++;
            // Going to next node
            temp = temp->next;
        }
        cout << "Number of elements in stack is " << n << endl;
    }
}

void Stack::clear()
{
    if (top == NULL) {
        cout << "Stack is empty" << endl;
    } else {
        while (top != NULL) {
            // Storing current node in temp variable
            Node* temp = top;
            // Moving to next node
            top = top->next;
            // Freeing up the space of current node
            free(temp);
        }
        top = NULL;
        cout << "Stack cleared" << endl;
    }
}

int main()
{
    Stack stack;
    int ch;
    do {
        cout << "*********************************************" << endl;
        cout << "1. Push\n2. Pop\n3. Display\n4. Peak\n5. Size\n"
                "6. Clear\n0. Exit\nEnter your choice: ";
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
            stack.push(ele);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.display();
            break;
        case 4:
            stack.peak();
            break;
        case 5:
            stack.size();
            break;
        case 6:
            stack.clear();
            break;
        default:
            cout << "Wrong option.. Retry.." << endl;
        }
    } while (ch != 0);

    return 0;
}