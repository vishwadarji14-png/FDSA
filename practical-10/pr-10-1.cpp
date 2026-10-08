#include <iostream>
#include <vector>
#include <string>

class ParkingLot {
private:
    std::vector<std::string> slots;
    const int CAPACITY = 10;

public:
    ParkingLot() : slots(CAPACITY, "Empty") {}

    // Park a vehicle using Linear Probing
    void parkVehicle(int regNumber) {
        int initialSlot = regNumber % 10;
        int currentSlot = initialSlot;

        // Loop to find an open slot
        while (slots[currentSlot] != "Empty") {
            currentSlot = (currentSlot + 1) % CAPACITY;
            
            // If we wrapped all the way back to the start, the lot is full
            if (currentSlot == initialSlot) {
                std::cout << "Parking Lot is Full! Cannot park vehicle: " << regNumber << "\n";
                return;
            }
        }

        slots[currentSlot] = std::to_string(regNumber);
        std::cout << "Vehicle " << regNumber << " assigned to Slot " << currentSlot << "\n";
    }

    // Display the final grid of slots
    void displayState() {
        std::cout << "\n--- Final State of Parking Slots ---\n";
        for (int i = 0; i < CAPACITY; i++) {
            std::cout << "Slot " << i << ": " << slots[i] << "\n";
        }
    }
};

int main() {
    ParkingLot lot;
    std::vector<int> vehicles = {1234, 5674, 8924, 4321, 9870};

    std::cout << "--- Parking Lot System ---\n";
    for (int reg : vehicles) {
        lot.parkVehicle(reg);
    }

    lot.displayState();
    return 0;
}
