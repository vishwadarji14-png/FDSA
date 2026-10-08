#include <iostream>
#include <vector>

// Define the Node representing a Book on the shelf
struct BookNode {
    int bookCode;
    BookNode* left;
    BookNode* right;

    BookNode(int code) {
        bookCode = code;
        left = nullptr;
        right = nullptr;
    }
};

class LibraryShelf {
private:
    BookNode* root;

    // Helper function to insert a code recursively
    BookNode* insertHelper(BookNode* node, int code) {
        // If the position is empty, place the book here
        if (node == nullptr) {
            return new BookNode(code);
        }

        // If the new code is smaller, look/go left
        if (code < node->bookCode) {
            node->left = insertHelper(node->left, code);
        }
        // If the new code is larger, look/go right
        else if (code > node->bookCode) {
            node->right = insertHelper(node->right, code);
        }

        return node;
    }

    // Helper function for in-order traversal
    void inorderHelper(BookNode* node) {
        if (node == nullptr) return;
        
        inorderHelper(node->left);            // Visit Left
        std::cout << node->bookCode << " ";   // Visit Root
        inorderHelper(node->right);           // Visit Right
    }

public:
    LibraryShelf() {
        root = nullptr;
    }

    // Public method to insert a new book code
    void insert(int code) {
        root = insertHelper(root, code);
    }

    // Public method to print all organized books
    void printOrganizedShelf() {
        inorderHelper(root);
        std::cout << "\n";
    }
};

int main() {
    LibraryShelf shelf;
    
    // Simulate book codes arriving one by one
    std::vector<int> arrivingBooks = {45, 20, 70, 10, 30, 60, 85};

    std::cout << "--- School Library Book System ---\n";
    std::cout << "Inserting arriving book codes: ";
    for (int code : arrivingBooks) {
        std::cout << code << " ";
        shelf.insert(code);
    }
    std::cout << "\n\n";

    // Inorder output displays them sorted sequentially
    std::cout << "Final organized shelf sequence (In-order traversal):\n";
    shelf.printOrganizedShelf();

    return 0;
}
