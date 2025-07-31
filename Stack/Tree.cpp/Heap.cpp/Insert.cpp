#include <iostream>
using namespace std;

class MaxHeap {
private:
    int heap[100]; // fixed-size heap array
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    void insert(int value) {
        heap[size] = value;
        int index = size;
        size++;

        // Heapify up (no separate heapify function)
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    int arr[] = {50, 55, 53, 52, 54};
    int n = sizeof(arr) / sizeof(arr[0]);
    MaxHeap h;
    cout << "Inserting elements one by one...\n";
    for (int i = 0; i < n; i++) {
        h.insert(arr[i]);
    }
    cout << "Max-Heap after insertions: ";
    h.printHeap();

    return 0;
}
