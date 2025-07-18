#include<iostream>
using namespace std;

class stack {
public:
    int* arr;
    int size;
    int top;

    // Constructor
    stack(int size) {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    // Push data to stack
    void push(int data) {
        if (size - top > 1) {
            top++;
            arr[top] = data;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    // Pop data from stack
    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
        } else {
            top--;
        }
    }

    // Get top element
    int getTop() {
        if (top == -1) {
            cout << "Empty" << endl;
            return -1;  // Return -1 to avoid garbage
        } else {
            return arr[top];
        }
    }

    // Get current size of stack
    int getSize() {
        return top + 1;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

// ✅ Main function
int main() {
    stack s(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    while (!s.isEmpty()) {
        cout << s.getTop() << " ";
        s.pop();
    }

    return 0;
}
