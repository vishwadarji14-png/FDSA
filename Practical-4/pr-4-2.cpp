#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// --- INSERTION OPERATIONS (From before) ---
void insertFront(Node* &head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertEnd(Node* &head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}


// 1. FORWARD TRAVERSAL (Display full queue from front to back)
void displayForward(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// 2. REVERSE PRINTING (Last to First for End-of-Day Audit)
void displayReverse(Node* head) {
    
    if (head == nullptr) {
        return;
    }
    

    displayReverse(head->next);
    
    
    cout << head->data << " <- ";
}

// 3. DELETION BY VALUE (When a patient leaves)
void deletePatient(Node* &head, int targetValue) {
    if (head == nullptr) return; // If queue is empty, do nothing

    
    if (head->data == targetValue) {
        Node* tempToDelete = head;
        head = head->next;     
        delete tempToDelete;     
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != targetValue) {
        temp = temp->next;
    }

  
    if (temp->next != nullptr) {
        Node* tempToDelete = temp->next;   
        temp->next = temp->next->next;     
        delete tempToDelete;               
    } else {
        cout << "Patient token " << targetValue << " not found in the queue!\n";
    }
}

int main() {
    Node* head = nullptr;

   
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertFront(head, 5);
    insertEnd(head, 30);
    
    cout << "1. Current Queue (Front to Back):\n";
    displayForward(head); 

    cout << "\n2. Patient 20 leaves the queue...\n";
    deletePatient(head, 20);
    
    cout << "Queue after deletion:\n";
    displayForward(head); 

    cout << "\n3. End-of-Day Audit (Last to First):\n";
    displayReverse(head); 
    cout << "START\n";

    return 0;
}
