#include <iostream>
#include <vector>
using namespace std;

// Iterative binary search
int binarySearchIterative(const vector<int>& arr, int target) {
    int left = 0;
    int right = (int)arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // not found
}

// Recursive binary search
int binarySearchRecursive(const vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1; // not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, target, mid + 1, right);
    } else {
        return binarySearchRecursive(arr, target, left, mid - 1);
    }
}

int main() {
    int n;
    cout << "Enter number of book codes: ";
    cin >> n;

    vector<int> codes(n);
    cout << "Enter " << n << " sorted book codes:\n";
    for (int i = 0; i < n; ++i) {
        cin >> codes[i];
    }

    int target;
    cout << "Enter target book code to search: ";
    cin >> target;

    // Iterative search
    int posIter = binarySearchIterative(codes, target);
    cout << "\nIterative Binary Search:\n";
    if (posIter != -1) {
        cout << "Target found at index: " << posIter << "\n";
    } else {
        cout << "Target not found.\n";
    }

    // Recursive search
    int posRec = binarySearchRecursive(codes, target, 0, n - 1);
    cout << "\nRecursive Binary Search:\n";
    if (posRec != -1) {
        cout << "Target found at index: " << posRec << "\n";
    } else {
        cout << "Target not found.\n";
    }

    return 0;
}