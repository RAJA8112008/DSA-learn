#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Heapify down from index i
    void heapify(int i) {
        int n = heap.size();
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[largest])
            largest = left;
        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

public:
    // Constructor: build heap from array
    MaxHeap(vector<int>& arr) {
        heap = arr;
        buildHeap();
    }

    // Build heap (heapify all non-leaf nodes)
    void buildHeap() {
        int n = heap.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    // Print heap
    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> arr = {3, 5, 1, 10, 2, 7};

    cout << "Original array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    MaxHeap h(arr);

    cout << "Max-Heap created: ";
    h.printHeap();

    return 0;
}
