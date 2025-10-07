#include <iostream>
#include <string>
using namespace std;

const int max_size = 5;

class ArrayStack {
private:
    int top;
    char arr[max_size];

public:
    ArrayStack() {
        top = -1;
    }

    void push(char value) {
        if (isFull()) {
            cout << "Stack Overflow." << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack. ";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow." << endl;
            return;
        }
        cout << arr[top] << " popped from stack." << endl;
        top--;
    }

    char peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return ' ';
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " | ";
        }
        cout << endl;
    }

    bool isFull() {
        return top >= max_size - 1;
    }

    bool isEmpty() {
        return top < 0;
    }
};

int main() {
    string value = "Sarah";
    ArrayStack s;

    // Push each character
    for (int i = 0; i < value.length(); i++) {
        s.push(value[i]);
    }

    cout << endl;
    s.display(); // show stack contents

    // Pop all characters (like reverse printing)
    cout << "Popping elements: " << endl;
    while (!s.isEmpty()) {
        s.pop();
    }

    s.display(); // should say "Stack is empty"
    cout << endl;

    return 0;
}
