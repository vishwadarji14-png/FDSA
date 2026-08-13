#include <iostream>
using namespace std;

int main() {
    int n, h;

    cout << "Enter number of items: ";
    cin >> n;

    int arr[n];

    cout << "Enter the items: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of hours: ";
    cin >> h;

    for (int hour = 0; hour < h; hour++) {

        int temp = arr[0];

        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        arr[n - 1] = temp;
    }

    cout << "Final Display Order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}