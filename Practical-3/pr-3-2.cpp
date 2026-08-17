#include <iostream>
using namespace std;

void sortColors(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else // arr[mid] == 2
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of buckets: ";
    cin >> n;

    int arr[n];

    cout << "Enter the colour codes (0, 1, 2): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sortColors(arr, n);

    cout << "Sorted colour codes: ";
    printArray(arr, n);

    return 0;
}