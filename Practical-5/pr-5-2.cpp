#include <iostream>
#include <string>
using namespace std;

// ==================== SINGLY CIRCULAR LINKED LIST ====================

struct SNode {
    string name;
    SNode* next;
    SNode(string n) : name(n), next(nullptr) {}
};

class SinglyCircularCircle {
private:
    SNode* head;      // First student
    SNode* token;     // Current token position
    int count;

public:
    SinglyCircularCircle() {
        head = nullptr;
        token = nullptr;
        count = 0;
    }

    // Join at position (1-indexed)
    void join(string name, int pos) {
        SNode* newNode = new SNode(name);
        
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            token = head;
        } else if (pos == 1) {
            // Insert at beginning
            SNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
            if (token == nullptr) token = head;
        } else {
            // Insert at position
            SNode* temp = head;
            for (int i = 1; i < pos - 1 && temp->next != head; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        count++;
        cout << "[Singly] " << name << " joined at position " << pos << endl;
        display();
    }

    // Leave from position (1-indexed)
    void leave(int pos) {
        if (head == nullptr) {
            cout << "[Singly] Circle is empty!" << endl;
            return;
        }
        
        SNode* toDelete = nullptr;
        
        if (pos == 1) {
            // Remove first
            SNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            toDelete = head;
            if (head->next == head) {
                head = nullptr;
                token = nullptr;
            } else {
                head = head->next;
                temp->next = head;
                if (token == toDelete) token = head;
            }
        } else {
            // Remove at position
            SNode* temp = head;
            for (int i = 1; i < pos - 1 && temp->next != head; i++) {
                temp = temp->next;
            }
            if (temp->next == head) {
                cout << "[Singly] Invalid position!" << endl;
                return;
            }
            toDelete = temp->next;
            temp->next = toDelete->next;
            if (token == toDelete) {
                token = temp->next == head ? head : temp->next;
            }
        }
        
        cout << "[Singly] Student at position " << pos << " left" << endl;
        delete toDelete;
        count--;
        display();
    }

    // Pass token to next student
    void pass() {
        if (token != nullptr) {
            token = token->next;
            cout << "[Singly] Token passed to: " << token->name << endl;
            display();
        } else {
            cout << "[Singly] No token in circle!" << endl;
        }
    }

    void display() {
        cout << "Circle: ";
        if (head == nullptr) {
            cout << "(empty)";
        } else {
            SNode* temp = head;
            int pos = 1;
            do {
                if (temp == token) {
                    cout << "[" << temp->name << "]* ";
                } else {
                    cout << temp->name << " ";
                }
                temp = temp->next;
                pos++;
            } while (temp != head);
        }
        cout << " (Total: " << count << ")" << endl;
        cout << "---" << endl;
    }

    ~SinglyCircularCircle() {
        if (head != nullptr) {
            SNode* temp = head;
            do {
                SNode* next = temp->next;
                delete temp;
                temp = next;
            } while (temp != head);
        }
    }
};

// ==================== DOUBLY CIRCULAR LINKED LIST ====================

struct DNode {
    string name;
    DNode* prev;
    DNode* next;
    DNode(string n) : name(n), prev(nullptr), next(nullptr) {}
};

class DoublyCircularCircle {
private:
    DNode* head;      // First student
    DNode* token;     // Current token position
    int count;

public:
    DoublyCircularCircle() {
        head = nullptr;
        token = nullptr;
        count = 0;
    }

    // Join at position (1-indexed)
    void join(string name, int pos) {
        DNode* newNode = new DNode(name);
        
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            token = head;
        } else if (pos == 1) {
            // Insert at beginning
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
            if (token == nullptr) token = head;
        } else {
            // Insert at position
            DNode* temp = head;
            for (int i = 1; i < pos - 1 && temp->next != head; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
        count++;
        cout << "[Doubly] " << name << " joined at position " << pos << endl;
        display();
    }

    // Leave from position (1-indexed)
    void leave(int pos) {
        if (head == nullptr) {
            cout << "[Doubly] Circle is empty!" << endl;
            return;
        }
        
        DNode* toDelete = nullptr;
        
        if (pos == 1) {
            // Remove first
            toDelete = head;
            if (head->next == head) {
                head = nullptr;
                token = nullptr;
            } else {
                head = head->next;
                head->prev = toDelete->prev;
                toDelete->prev->next = head;
                if (token == toDelete) token = head;
            }
        } else {
            // Remove at position
            DNode* temp = head;
            for (int i = 1; i < pos && temp->next != head; i++) {
                temp = temp->next;
            }
            if (temp == head && pos > 1) {
                cout << "[Doubly] Invalid position!" << endl;
                return;
            }
            toDelete = temp;
            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;
            if (token == toDelete) {
                token = toDelete->next == head ? head : toDelete->next;
            }
            if (toDelete == head) {
                head = toDelete->next;
            }
        }
        
        cout << "[Doubly] Student at position " << pos << " left" << endl;
        delete toDelete;
        count--;
        display();
    }

    // Pass token to next student
    void pass() {
        if (token != nullptr) {
            token = token->next;
            cout << "[Doubly] Token passed to: " << token->name << endl;
            display();
        } else {
            cout << "[Doubly] No token in circle!" << endl;
        }
    }

    // Pass token backwards (extra feature!)
    void passBack() {
        if (token != nullptr) {
            token = token->prev;
            cout << "[Doubly] Token passed back to: " << token->name << endl;
            display();
        } else {
            cout << "[Doubly] No token in circle!" << endl;
        }
    }

    void display() {
        cout << "Circle: ";
        if (head == nullptr) {
            cout << "(empty)";
        } else {
            DNode* temp = head;
            int pos = 1;
            do {
                if (temp == token) {
                    cout << "[" << temp->name << "]* ";
                } else {
                    cout << temp->name << " ";
                }
                temp = temp->next;
                pos++;
            } while (temp != head);
        }
        cout << " (Total: " << count << ")" << endl;
        cout << "---" << endl;
    }

    ~DoublyCircularCircle() {
        if (head != nullptr) {
            DNode* temp = head;
            do {
                DNode* next = temp->next;
                delete temp;
                temp = next;
            } while (temp != head);
        }
    }
};

// ==================== MAIN ====================

int main() {
    cout << "=== SINGLY CIRCULAR LINKED LIST ===" << endl << endl;
    SinglyCircularCircle singly;
    
    singly.join("Alice", 1);
    singly.join("Bob", 2);
    singly.join("Charlie", 3);
    singly.pass();
    singly.join("David", 2);
    singly.pass();
    singly.leave(2);
    singly.pass();
    
    cout << endl << "=== DOUBLY CIRCULAR LINKED LIST ===" << endl << endl;
    DoublyCircularCircle doubly;
    
    doubly.join("Alice", 1);
    doubly.join("Bob", 2);
    doubly.join("Charlie", 3);
    doubly.pass();
    doubly.join("David", 2);
    doubly.pass();
    doubly.leave(2);
    doubly.pass();
    doubly.passBack();  
    
    return 0;
}