//C++ program to check an array is sorted and rotated
#include <bits/stdc++.h>
using namespace std;

// Function to check if arr[] is rotated and sorted
bool check(vector<int>& arr, int n)
{
    // Initialize count of the number of times the sequence
    // is out of order
    int count = 0;

    // Iterate through the vector
    for (int i = 0; i < n; i++) {
        // Check if the current element is greater than the
        // next element
        if (arr[i] > arr[(i + 1) % n]) {
            // Increment count if the sequence is out of
            // order
            count++;
        }
    }

    // Return true if there is at most one point where the
    // sequence is out of order
    return count <= 1;
}

// Driver Code
int main()
{
    // Sample Input
  	// Example of a rotated and sorted array
    vector<int> arr = { 3, 4, 5, 1, 2,1 }; 

    // Get the size of the vector
    int n = arr.size();

    // Call the check function and determine if the array is
    // rotated and sorted
    if (check(arr, n))
        // Print YES if the array is rotated and sorted
        cout << "YES" << endl;
    else
        // Print NO if the array is not rotated and sorted
        cout << "NO" << endl;

    return 0;
}