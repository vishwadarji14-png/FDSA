#include <iostream>
#include <string>
using namespace std;

// Node structure for doubly linked list
struct Node {
    string song;
    Node* prev;
    Node* next;
    Node(string s) : song(s), prev(nullptr), next(nullptr) {}
};

// Playlist class using doubly linked list
class Playlist {
private:
    Node* head;      // First song
    Node* tail;      // Last song
    Node* current;   // Currently playing song
    int count;       // Number of songs

public:
    Playlist() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
        count = 0;
    }

    // Add song to the beginning
    void addFirst(string song) {
        Node* newNode = new Node(song);
        if (head == nullptr) {
            head = tail = current = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;
        cout << "Added to beginning: " << song << endl;
        display();
    }

    // Add song to the end
    void addLast(string song) {
        Node* newNode = new Node(song);
        if (tail == nullptr) {
            head = tail = current = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
        cout << "Added to end: " << song << endl;
        display();
    }

    // Insert song after current playing song
    void insertAfterCurrent(string song) {
        if (current == nullptr) {
            cout << "No song is currently playing!" << endl;
            return;
        }
        Node* newNode = new Node(song);
        newNode->prev = current;
        newNode->next = current->next;
        
        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
        count++;
        cout << "Inserted after current: " << song << endl;
        display();
    }

    // Remove first song
    void removeFirst() {
        if (head == nullptr) {
            cout << "Playlist is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        
        if (current == temp) {
            current = head;
        }
        
        cout << "Removed first: " << temp->song << endl;
        delete temp;
        count--;
        display();
    }

    int getCount() {
        cout << "Total songs: " << count << endl;
        return count;
    }

    void display() {
        cout << "Playlist: ";
        if (head == nullptr) {
            cout << "(empty)";
        } else {
            Node* temp = head;
            while (temp != nullptr) {
                if (temp == current) {
                    cout << "[" << temp->song << "]* ";
                } else {
                    cout << temp->song << " ";
                }
                temp = temp->next;
            }
        }
        cout << endl;
        cout << "---" << endl;
    }

    void nextSong() {
        if (current != nullptr && current->next != nullptr) {
            current = current->next;
            cout << "Now playing: " << current->song << endl;
            display();
        } else if (current != nullptr) {
            cout << "Already at last song!" << endl;
        } else {
            cout << "No songs in playlist!" << endl;
        }
    }

    ~Playlist() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Playlist player;

    cout << "=== Music Player Playlist Demo ===" << endl << endl;

    player.addLast("Song A");
    player.addLast("Song B");
    player.addFirst("Song Start");
    player.insertAfterCurrent("Song After A");
    player.nextSong();
    player.insertAfterCurrent("Song After Start");
    player.getCount();
    player.removeFirst();
    player.addLast("Song End");
    player.display();

    return 0;
}