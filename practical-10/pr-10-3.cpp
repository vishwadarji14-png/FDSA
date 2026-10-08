#include <iostream>
#include <vector>

class StorageSystem {
private:
    std::vector<int> storage;
    const int CAPACITY = 10;
    const int EMPTY_MARKER = -1;

    // First hash function for initial index
    int hash1(int id) {
        return id % CAPACITY;
    }

    // Second hash function to calculate custom stride/jump size
    int hash2(int id) {
        // Must return a non-zero value less than table size
        return 7 - (id % 7);
    }

public:
    StorageSystem() : storage(CAPACITY, EMPTY_MARKER) {}

    // Assign slot using Double Hashing
    void assignSlot(int studentID) {
        int initialIdx = hash1(studentID);
        int stepSize = hash2(studentID);
        int currentIdx = initialIdx;
        int i = 1;

        while (storage[currentIdx] != EMPTY_MARKER) {
            // Calculate next slot to probe based on the unique stride/step size
            currentIdx = (initialIdx + i * stepSize) % CAPACITY;
            i++;

            // If we have checked all capacity slots, table is full
            if (i > CAPACITY) {
                std::cout << "Storage is full! Cannot assign student ID: " << studentID << "\n";
                return;
            }
        }

        storage[currentIdx] = studentID;
        std::cout << "Student ID " << studentID << " assigned to Slot " << currentIdx 
                  << " (Step size used: " << stepSize << ")\n";
    }

    // Display table contents
    void displayTable() {
        std::cout << "\n--- Final Storage Slots Assignments ---\n";
        for (int i = 0; i < CAPACITY; i++) {
            std::cout << "Slot " << i << ": ";
            if (storage[i] == EMPTY_MARKER) {
                std::cout << "Empty\n";
            } else {
                std::cout << storage[i] << "\n";
            }
        }
    }
};

int main() {
    StorageSystem system;
    // IDs designed to create deliberate initial slot collisions (all map to slot 3 initially)
    std::vector<int> studentIDs = {43, 73, 23, 93};

    std::cout << "--- Student Storage System ---\n";
    for (int id : studentIDs) {
        system.assignSlot(id);
    }

    system.displayTable();
    return 0;
}
