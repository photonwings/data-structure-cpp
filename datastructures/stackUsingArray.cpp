#include <iostream>
using namespace std;

// Number of elements in stack
int const SIZE = 5;

// Class for stack
class Stack {
private:
    // Array to store stack
    int s[SIZE];
    // Top of the stack
    int top;

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
    // Maximum number of elements can be stored
    void maxSize();
    // Clear all elements of stack
    void clear();
};

Stack::Stack()
{
    // Initializing top to -1 at the begining
    top = -1;
}

void Stack::push(int ele)
{ // Check if satack is full
    if (top == SIZE - 1) {
        cout << "Stack is full, " << ele << " not pushed to stack" << endl;
    } else {
        // Increment top and assign new value at the top
        s[++top] = ele;
        cout << ele << " Pushed to stack" << endl;
    }
}

void Stack::pop()
{
    // Check if stack is empty
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        // Display top element and decrement top
        cout << s[top--] << " poped from stack" << endl;
    }
}

void Stack::display()
{
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        // Loop from top to display elements
        for (int i = top; i > 0; i--) {
            cout << s[i] << " <- ";
        }
        cout << s[0];
        cout << endl;
    }
}

void Stack::peak()
{
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Top element of stack is " << s[top] << endl;
    }
}

void Stack::size()
{
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        // Display number of elements, which is one more than top
        cout << "Number of elements in stack is " << top + 1 << endl;
    }
}

void Stack::maxSize()
{
    cout << "Max size of stack is " << SIZE << endl;
}

void Stack::clear()
{
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        // Loop the stack and initialize every value to zero
        for (int i = top; i >= 0; i--) {
            s[i] = -1;
        }
        // Making stack empty
        top = -1;
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
                "6. Max Size\n7. Clear\n0. Exit\nEnter your choice: ";
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
            stack.maxSize();
            break;
        case 7:
            stack.clear();
            break;
        default:
            cout << "Wrong option.. Retry.." << endl;
        }
    } while (ch != 0);

    return 0;
}