#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> heap;

    // Constructor to build heap from array
    MaxHeap(vector<int> arr) {
        heap = arr;
        buildHeap();
    }

    // Heapify down from index i
    void heapify(int i, int n) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[largest])
            largest = left;

        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest, n);
        }
    }

    // Build max heap from array
    void buildHeap() {
        int n = heap.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(i, n);
        }
    }

    // Insert element
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;

        // Heapify Up
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] < heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else {
                break;
            }
        }
    }

    // Display the heap
    void printHeap() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    vector<int> arr = {10, 20, 15, 30, 40};
    MaxHeap h(arr);

    cout << "Heap after building from array: ";
    h.printHeap();

    h.insert(50);
    h.insert(5);
    cout << "Heap after insertions: ";
    h.printHeap();

    return 0;
}
