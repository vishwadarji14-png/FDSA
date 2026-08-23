#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

// 1. INSERT AT FRONT (Critical Patient)
void insertFront(Node* &head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    
    newNode->next = head;
    head = newNode;      
}

// 2. INSERT AT END (Routine Patient)
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


void insertAtPos(Node* &head, int val, int pos) {
    Node* newNode = new Node();
    newNode->data = val;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
 
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next; 
    temp->next = newNode;       
}

// Simple display function
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr; // Start with empty list

    insertEnd(head, 10);   
    insertEnd(head, 20);   
    insertFront(head, 5);  
    insertAtPos(head, 99, 3); 

    display(head); 
    return 0;
}
