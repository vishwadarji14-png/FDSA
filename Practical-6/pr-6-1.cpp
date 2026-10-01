#include <iostream>
#include <string>
using namespace std;

class TrayStack {
private:
    string* trays;   
    int capacity;    
    int topIndex;     

public:

    TrayStack(int n) {
        capacity = n;
        trays = new string[capacity];
        topIndex = -1;  // Stack is initially empty
        cout << "Tray counter created with capacity: " << capacity << endl;
        cout << "---" << endl;
    }

    void place(string trayId) {
        if (topIndex == capacity - 1) {
            cout << "ERROR: Cannot place tray - counter is FULL!" << endl;
            cout << "Top tray: (none)" << endl;
        } else {
            topIndex++;
            trays[topIndex] = trayId;
            cout << "Placed tray: " << trayId << endl;
            cout << "Top tray: " << trays[topIndex] << endl;
        }
        cout << "---" << endl;
    }

    void take() {
        if (topIndex == -1) {
            cout << "ERROR: Cannot take tray - counter is EMPTY!" << endl;
            cout << "Top tray: (none)" << endl;
        } else {
            cout << "Took tray: " << trays[topIndex] << endl;
            topIndex--;
            if (topIndex == -1) {
                cout << "Top tray: (none)" << endl;
            } else {
                cout << "Top tray: " << trays[topIndex] << endl;
            }
        }
        cout << "---" << endl;
    }

    bool isFull() {
        return topIndex == capacity - 1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    int count() {
        return topIndex + 1;
    }

    void display() {
        cout << "Stack (bottom to top): ";
        if (isEmpty()) {
            cout << "(empty)";
        } else {
            for (int i = 0; i <= topIndex; i++) {
                cout << trays[i] << " ";
            }
        }
        cout << endl;
        cout << "---" << endl;
    }

    ~TrayStack() {
        delete[] trays;
    }
};


int main() {
    cout << "=== CAFETERIA TRAY STACK ===" << endl << endl;

    TrayStack counter(5);

    cout << endl << "--- Placing trays ---" << endl;
    counter.place("Tray-1");
    counter.place("Tray-2");
    counter.place("Tray-3");

    cout << endl << "--- Taking trays ---" << endl;
    counter.take();
    counter.take();

    cout << endl << "--- More operations ---" << endl;
    counter.place("Tray-4");
    counter.place("Tray-5");
    counter.place("Tray-6");
    counter.place("Tray-7");

    cout << endl << "--- Try to overflow ---" << endl;
    counter.place("Tray-8");  

    cout << endl << "--- Taking all trays ---" << endl;
    counter.take();
    counter.take();
    counter.take();
    counter.take();
    counter.take();

    cout << endl << "--- Try to underflow ---" << endl;
    counter.take(); 

    cout << endl << "--- Final operations ---" << endl;
    counter.place("Tray-A");
    counter.place("Tray-B");
    counter.display();

    return 0;
}