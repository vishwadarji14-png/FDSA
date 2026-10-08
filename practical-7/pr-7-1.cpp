#include <iostream>
#include <queue>
#include <string>

class TokenCounter {
private:
    std::queue<int> q;
    size_t capacity;

public:

    TokenCounter(size_t n) : capacity(n) {}

    void join(int tokenNumber) {

        if (q.size() >= capacity) {
            std::cout << "Error: Counter is full. Cannot issue token " << tokenNumber << ".\n";
            return;
        }
        
        q.push(tokenNumber);
        
        std::cout << "Successfully Joined. Front token is: " << q.front() << "\n";
    }


    void serve() {
       
        if (q.empty()) {
            std::cout << "Error: Counter is empty. No one to serve.\n";
            return;
        }
 
        q.pop();
        
       
        if (!q.empty()) {
            std::cout << "Successfully Served. New front token is: " << q.front() << "\n";
        } else {
            std::cout << "Successfully Served. Counter is now empty.\n";
        }
    }
};

int main() {

    std::cout << "--- Token Counter System (Capacity: 3) ---\n";
    TokenCounter counter(3);

   
    counter.join(101); 
    counter.join(102); 
    counter.join(103); 
    counter.join(104); 

    counter.serve();   
    counter.join(105); 
    
    counter.serve();    
    counter.serve();    
    counter.serve();    
    counter.serve();    

    return 0;
}
