#include <iostream>
#include <vector>
using namespace std;

int iterativeSearch(vector<string> plates, string target) {
    for (int i = 0; i < plates.size(); i++) {
        if (plates[i] == target) {
            return i;
        }
    }
    return -1;
}

int recursiveSearch(vector<string> plates, string target, int index) {
    if (index == plates.size()) {
        return -1; //not found
    }

    if (plates[index] == target) {
        return index;
    }

    return recursiveSearch(plates, target, index + 1);
}

int main() {
    int n;
    string target;

    cout << "Enter number of vehicles: ";
    cin >> n;

    vector<string> plates(n);

    cout << "Enter license plates:\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> plates[i];
    }

    cout << "Enter target plate: ";
    cin >> target;

    int result1 = iterativeSearch(plates, target);
    int result2 = recursiveSearch(plates, target, 0);

    if (result1 != -1)
        cout << "Iterative: Found at position " << result1 + 1 << endl;
    
        else
        cout << "Iterative: Plate not found" << endl;

    
        if (result2 != -1)
        cout << "Recursive: Found at position " << result2 + 1 << endl;
   
        else
        cout << "Recursive: Plate not found" << endl;

    
        return 0;
}