#include <iostream>
#include <algorithm> // For swap
using namespace std;

class MinHeap {
private:
    int arr[100];
    int size;

public:
    MinHeap() {
        size = 0;
    }

    void insert(int value) {
        int index = size;
        arr[index] = value;
        size++;

        // Bubble up: While index is not root and parent > child
        while (index != 0 && arr[(index - 1) / 2] > arr[index]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void deleteRoot() {
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }

        // Replace root with the last element
        arr[0] = arr[size - 1];
        size--;

        // Restore MinHeap property
        heapifyDown(0);
    }

    // Standard MinHeapify logic (looking for smaller children)
    void heapifyDown(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check if left child exists and is smaller than current smallest
        if (left < size && arr[left] < arr[smallest])
            smallest = left;

        // Check if right child exists and is smaller than current smallest
        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        // If the smallest is not the root, swap and continue
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapifyDown(smallest);
        }
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;
    
    // Insert elements
    h.insert(5);
    h.insert(2);
    h.insert(9);
    h.insert(1);
    h.insert(7);
    h.insert(3);

    cout << "Heap elements: ";
    h.display();

    // Delete root (which should be 1)
    h.deleteRoot();
    
    cout << "After deleting root: ";
    h.display();

    return 0;
}
