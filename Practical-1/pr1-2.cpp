#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n, bookId;
    map<int, int> count;
    vector<int> books;

    cout << "Enter number of borrow records: ";
    cin >> n;

    cout << "Enter book IDs:\n";
    for (int i = 0; i < n; i++) {
        cin >> bookId;

        books.push_back(bookId); // Store all entered IDs
        count[bookId]++;         // Count each book ID
    }

    cout << "All book IDs: ";
    for (int i = 0; i < books.size(); i++) {
        cout << books[i] << " ";
    }

    cout << "\nBooks borrowed more than once: ";
    for (auto item : count) {
        if (item.second > 1) {
            cout << item.first << " ";
        }
    }

    return 0;
}