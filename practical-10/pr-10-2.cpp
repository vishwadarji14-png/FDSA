#include <iostream>
#include <vector>

class LibraryShelves {
private:
    std::vector<std::vector<int>> shelves;
    const int TOTAL_SHELVES = 10;

public:
    LibraryShelves() : shelves(TOTAL_SHELVES) {}

    // Place book on the shelf
    void placeBook(int bookCode) {
        int shelfIndex = bookCode % 10;
        shelves[shelfIndex].push_back(bookCode);
    }

    // Display all shelves and their respective stacks
    void displayContents() {
        std::cout << "\n--- Library Shelves Stack Layout ---\n";
        for (int i = 0; i < TOTAL_SHELVES; i++) {
            std::cout << "Shelf " << i << ": ";
            if (shelves[i].empty()) {
                std::cout << "[ Empty ]";
            } else {
                for (int book : shelves[i]) {
                    std::cout << book << " -> ";
                }
                std::cout << "End";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    LibraryShelves library;
    std::vector<int> books = {105, 235, 892, 442, 710, 555};

    for (int code : books) {
        library.placeBook(code);
    }

    library.displayContents();
    return 0;
}
