#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top; 

public:
    Stack() {
        top = 0; 
    }

    bool isFull() {
        return top >= MAX_SIZE;
    }

    bool isEmpty() {
        return top == 0;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow." << endl;
            return;
        }
        arr[top] = val;
        top++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow." << endl;
            return -1;
        }
        top--;
        return arr[top]; 
    }

    int getMin() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        int smallest = arr[0];
        for (int i = 0; i < top; i++) {
            if (arr[i] < smallest) {
                smallest = arr[i];
            }
        }
        return smallest; 
    }
};

int main() {
    Stack s;
    int choice;
    int input;

    cout << "--- Stack Implementation ---" << endl;

    do {
        cout << "\n MENU " << endl;
        cout << "1. PUSH " << endl;
        cout << "2. POP " << endl;
        cout << "3. Minimum element " << endl;
        cout << "4. Exit " << endl;
        cout << "Enter choice (1-4): ";
        
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value: ";
                cin >> input;
                s.push(input);
                cout << "Inserted value: " << input << endl;
                break;

            case 2: {
                int del = s.pop();
                if (del != -1) {
                    cout << "Popped value: " << del << endl;
                }
                break;
            }

            case 3: {
                int minVal = s.getMin();
                if (minVal != -1) {
                    cout << "Minimum element in stack: " << minVal << endl;
                }
                break;
            }

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Enter valid choice (1-4)." << endl;
                break;
        }
    } while (choice != 4); 

    return 0;
}
