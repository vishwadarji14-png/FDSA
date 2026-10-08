#include <iostream>
#include <queue>
#include <string>

class EmergencyWard {
private:
    std::queue<std::string> patientQueue;

public:

    void arrive(const std::string& patientName) {

        patientQueue.push(patientName);
        
        std::cout << "Patient '" << patientName << "' arrived. Next to be attended: " << patientQueue.front() << "\n";
    }

    void attend() {

        if (patientQueue.empty()) {
            std::cout << "Error: No patients in the waiting ward.\n";
            return;
        }
        
        std::string attendedPatient = patientQueue.front();
      
        patientQueue.pop();
        
        if (!patientQueue.empty()) {
            std::cout << "Attended to '" << attendedPatient << "'. Next to be attended: " << patientQueue.front() << "\n";
        } else {
            std::cout << "Attended to '" << attendedPatient << "'. The ward is now empty.\n";
        }
    }
};

int main() {
    std::cout << "--- Hospital Emergency Ward System ---\n";
    EmergencyWard ward;

    // Test Operations
    ward.arrive("Alice"); 
    ward.arrive("Bob");   
    ward.arrive("Charlie");
    
    ward.attend();     
    ward.arrive("David"); 
    
    ward.attend();         
    ward.attend();        
    ward.attend();     
    ward.attend();        

    return 0;
}
