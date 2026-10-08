#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<int> shelves[10];

    
    vector<int> book_codes = {104, 258, 344, 89, 504, 12, 78};

    for (int code : book_codes) {
        int shelf_index = code % 10;
        
        shelves[shelf_index].push_back(code);
    }

    cout << "Final Library Shelves State:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << ": ";
        
        if (shelves[i].empty()) {
            cout << "[Empty]";
        } else {
            for (int code : shelves[i]) {
                cout << code << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
