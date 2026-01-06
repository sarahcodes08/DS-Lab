#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int priority;
    Node* next;
    Node* prev;

    Node(int d, int p) {
        data = d;
        priority = p;
        next = nullptr;
        prev = nullptr;
    }
};

// Main Priority Queue Class using Doubly Linked List
class DLL {
private:
    Node* head;
    Node* tail;

public:
    DLL() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert based on Priority (Higher number = Higher Priority)
    void enqueue(int data, int priority) {
        Node* newNode = new Node(data, priority);

        // Case 1: List is Empty
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        // Case 2: Insert at Head (New Node has higher priority than current head)
        if (priority > head->priority) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        // Traverse to find the correct position
        Node* temp = head;
        // Keep moving as long as current node's priority is >= new priority
        while (temp != nullptr && temp->priority >= priority) {
            temp = temp->next;
        }

        // Case 3: Insert at Rear (if temp reached the end)
        if (temp == nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        // Case 4: Insert in the Middle (Insert before temp)
        else {
            Node* previousNode = temp->prev;
            
            previousNode->next = newNode;
            newNode->prev = previousNode;
            
            newNode->next = temp;
            temp->prev = newNode;
        }
    }

    // Remove the highest priority element (Head)
    void dequeue() {
        if (head == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* toDelete = head;
        cout << "Processed Data: " << head->data 
             << " (Priority: " << head->priority << ")" << endl;

        head = head->next;

        // If list becomes empty after deletion
        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }

        delete toDelete;
    }

    void display() {
        Node* temp = head;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << "[P:" << temp->priority << " | ID:" << temp->data << "] -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DLL d;
    
    // Enqueue elements (Data, Priority)
    d.enqueue(1, 1);
    d.enqueue(2, 3); // High priority
    d.enqueue(3, 2);
    d.enqueue(4, 2); // Same priority as ID 3, should appear after ID 3

    cout << "--- Current Queue Status ---" << endl;
    d.display();
    
    cout << "\n--- Dequeue Operation ---" << endl;
    d.dequeue(); // Should remove ID 2 (Priority 3)
    
    cout << "\n--- Status After Dequeue ---" << endl;
    d.display();

    return 0;
}
