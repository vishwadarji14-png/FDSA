#include <iostream>
#include <string>
#include <queue>

// Define the Node representing an employee
struct EmployeeNode {
    std::string name;
    EmployeeNode* left;
    EmployeeNode* right;

    EmployeeNode(std::string empName) {
        name = empName;
        left = nullptr;
        right = nullptr;
    }
};

class CompanyHierarchy {
public:
    // 1. Archive Department: Pre-order (Manager, Left Team, Right Team)
    void printArchive(EmployeeNode* root) {
        if (root == nullptr) return;
        std::cout << root->name << "  ";
        printArchive(root->left);
        printArchive(root->right);
    }

    // 2. HR Department: In-order (Left Team, Manager, Right Team)
    void printHR(EmployeeNode* root) {
        if (root == nullptr) return;
        printHR(root->left);
        std::cout << root->name << "  ";
        printHR(root->right);
    }

    // 3. Payroll Department: Post-order (Left Team, Right Team, Manager)
    void printPayroll(EmployeeNode* root) {
        if (root == nullptr) return;
        printPayroll(root->left);
        printPayroll(root->right);
        std::cout << root->name << "  ";
    }

    // 4. Floor Manager: Level-order (Top to Bottom, Level by level)
    void printFloorManager(EmployeeNode* root) {
        if (root == nullptr) return;
        
        std::queue<EmployeeNode*> q;
        q.push(root);

        while (!q.empty()) {
            EmployeeNode* current = q.front();
            q.pop();

            std::cout << current->name << "  ";

            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
    }
};

int main() {
    // Creating a sample corporate binary tree hierarchy
    //               CEO
    //             /     \
    //        ManagerA   ManagerB
    //          /   \
    //       Emp1   Emp2
    EmployeeNode* root = new EmployeeNode("CEO");
    root->left = new EmployeeNode("ManagerA");
    root->right = new EmployeeNode("ManagerB");
    root->left->left = new EmployeeNode("Emp1");
    root->left->right = new EmployeeNode("Emp2");

    CompanyHierarchy hierarchy;

    std::cout << "--- Corporate Hierarchy Tree Traversals ---\n\n";

    std::cout << "Archive Department (Pre-order): \n";
    hierarchy.printArchive(root);
    std::cout << "\n\n";

    std::cout << "HR Department (In-order): \n";
    hierarchy.printHR(root);
    std::cout << "\n\n";

    std::cout << "Payroll Department (Post-order): \n";
    hierarchy.printPayroll(root);
    std::cout << "\n\n";

    std::cout << "Floor Manager (Level-order): \n";
    hierarchy.printFloorManager(root);
    std::cout << "\n";

    return 0;
}
