#include <iostream>
#include <string>
using namespace std;

struct PageNode {
    string url;
    PageNode* next;
    PageNode(string u) : url(u), next(nullptr) {}
};

class BrowserHistory {
private:
    PageNode* topPage; 
    int pageCount;        

public:
    BrowserHistory() {
        topPage = nullptr;
        pageCount = 0;
        cout << "Browser history initialized" << endl;
        cout << "---" << endl;
    }

    void visit(string url) {
        PageNode* newPage = new PageNode(url);
        newPage->next = topPage;
        topPage = newPage;
        pageCount++;
        
        cout << "Visited: " << url << endl;
        cout << "Current page: " << topPage->url << endl;
        cout << "History size: " << pageCount << " pages" << endl;
        cout << "---" << endl;
    }

    void back() {
        if (topPage == nullptr) {
            cout << "ERROR: No pages in history!" << endl;
            cout << "Current page: (none)" << endl;
        } else {
            string leftPage = topPage->url;
            PageNode* temp = topPage;
            topPage = topPage->next;
            delete temp;
            pageCount--;
            
            cout << "Went back from: " << leftPage << endl;
            if (topPage == nullptr) {
                cout << "Current page: (no history)" << endl;
            } else {
                cout << "Current page: " << topPage->url << endl;
            }
            cout << "History size: " << pageCount << " pages" << endl;
        }
        cout << "---" << endl;
    }

    string currentPage() {
        if (topPage == nullptr) {
            return "(none)";
        }
        return topPage->url;
    }

    bool isEmpty() {
        return topPage == nullptr;
    }

    int size() {
        return pageCount;
    }

    void displayHistory() {
        cout << "Page History (current to oldest): ";
        if (topPage == nullptr) {
            cout << "(empty)";
        } else {
            PageNode* temp = topPage;
            while (temp != nullptr) {
                cout << temp->url << " -> ";
                temp = temp->next;
            }
            cout << "(start)";
        }
        cout << endl;
        cout << "---" << endl;
    }

    ~BrowserHistory() {
        while (topPage != nullptr) {
            PageNode* temp = topPage;
            topPage = topPage->next;
            delete temp;
        }
    }
};

// ==================== MAIN ====================

int main() {
    cout << "=== WEB BROWSER HISTORY ===" << endl << endl;

    BrowserHistory browser;

    cout << endl << "--- Visiting pages ---" << endl;
    browser.visit("google.com");
    browser.visit("youtube.com");
    browser.visit("github.com");
    browser.visit("stackoverflow.com");

    cout << endl << "--- Going back ---" << endl;
    browser.back();
    browser.back();

    cout << endl << "--- Visit more pages ---" << endl;
    browser.visit("reddit.com");
    browser.visit("twitter.com");

    cout << endl << "--- Go back multiple times ---" << endl;
    browser.back();
    browser.back();
    browser.back();
    browser.back();

    cout << endl << "--- Try to go back when empty ---" << endl;
    browser.back();

    cout << endl << "--- Fresh browsing session ---" << endl;
    browser.visit("amazon.com");
    browser.visit("flipkart.com");
    browser.visit("myntra.com");

    cout << endl << "--- Final history ---" << endl;
    browser.displayHistory();

    return 0;
}