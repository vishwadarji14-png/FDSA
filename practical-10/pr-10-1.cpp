#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Initialize all 10 slots with "Empty"
    vector<string> parking_lot(10, "Empty");

    // Example sequence of vehicle registration numbers
    vector<string> vehicles = {"KA-01-1234", "DL-02-5678", "MH-03-9994", "HR-04-1114"};

    // Process each vehicle
    for (const string& vehicle : vehicles) {
        // 1. Get the last character and convert it to an integer slot number
        char last_char = vehicle.back();
        int slot = last_char - '0'; 

        // 2. Linear probing: find the next available slot if already taken
        while (parking_lot[slot] != "Empty") {
            slot = (slot + 1) % 10; // Wraps around from 9 back to 0
        }

        // 3. Assign the vehicle to the found slot
        parking_lot[slot] = vehicle;
    }

    // Display the final state of the parking lot
    cout << "Final Parking Lot State:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << ": " << parking_lot[i] << "\n";
    }

    return 0;
}
