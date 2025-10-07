#include <iostream>
#include <string>
using namespace std;

const int max_size = 50; // enough space for brackets

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
        cout << "Pushed '" << value << "' onto stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow." << endl;
            return;
        }
        cout << "Popped '" << arr[top] << "' from stack." << endl;
        top--;
    }

    char peek() {
        if (isEmpty()) {
            return '\0';
        }
        return arr[top];
    }

    bool isFull() {
        return top >= max_size - 1;
    }

    bool isEmpty() {
        return top < 0;
    }
};

bool areBracketsBalanced(string expr) {
    ArrayStack a;
    cout << "Checking expression: " << expr << endl;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (ch == '{' || ch == '[' || ch == '(') {
            a.push(ch);
        }
        else if (ch == '}' || ch == ']' || ch == ')') {
            if (a.isEmpty()) {
                cout << "Error: No opening bracket for '" << ch << "'" << endl;
                return false;
            }
            char top = a.peek();
            if ((ch == '}' && top == '{') ||
                (ch == ']' && top == '[') ||
                (ch == ')' && top == '(')) {
                cout << "Matched '" << top << "' with '" << ch << "'" << endl;
                a.pop();
            } else {
                cout << "Mismatch: top of stack is '" << top 
                     << "', but found '" << ch << "'" << endl;
                return false;
            }
        }
    }

    if (a.isEmpty()) {
        cout << "Stack empty — all brackets matched ✅" << endl;
        return true;
    } else {
        cout << "Unmatched opening brackets remain ❌" << endl;
        return false;
    }
}

int main() {
    string expr = "{2+4[9/3](9}";  

    if (areBracketsBalanced(expr))
        cout << "\n✅ Brackets are balanced." << endl;
    else
        cout << "\n❌ Brackets are NOT balanced." << endl;

    return 0;
}
