#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>

class CityMap {
private:
    // Adjacency list: maps a building to its connected neighboring buildings
    std::map<std::string, std::vector<std::string>> adjList;

    // Helper recursive function for DFS
    void dfsHelper(const std::string& current, std::set<std::string>& visited) {
        // Mark the current building as visited and print it
        visited.insert(current);
        std::cout << current << " -> ";

        // Go deep into each connected road/building
        for (const std::string& neighbor : adjList[current]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsHelper(neighbor, visited);
            }
        }
    }

public:
    // Function to add a two-way road between two buildings
    void addRoad(const std::string& b1, const std::string& b2) {
        adjList[b1].push_back(b2);
        adjList[b2].push_back(b1); // Since roads are two-way (undirected graph)
    }

    // Strategy 1: Depth-First Search (Team goes deep before backtracking)
    void exploreDeepDFS(const std::string& startBuilding) {
        std::set<std::string> visited;
        std::cout << "Team 1 Inspection Order (DFS):\n";
        
        if (adjList.find(startBuilding) == adjList.end()) {
            std::cout << "Starting building not found!\n";
            return;
        }
        
        dfsHelper(startBuilding, visited);
        std::cout << "Done\n";
    }

    // Strategy 2: Breadth-First Search (Team spreads out level-by-level)
    void exploreLevelBFS(const std::string& startBuilding) {
        std::cout << "Team 2 Inspection Order (BFS):\n";
        
        if (adjList.find(startBuilding) == adjList.end()) {
            std::cout << "Starting building not found!\n";
            return;
        }

        std::set<std::string> visited;
        std::queue<std::string> q;

        // Start from the initial building
        q.push(startBuilding);
        visited.insert(startBuilding);

        while (!q.empty()) {
            std::string current = q.front();
            q.pop();

            std::cout << current << " -> ";

            // Check all immediate neighboring buildings first
            for (const std::string& neighbor : adjList[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        std::cout << "Done\n";
    }
};

int main() {
    CityMap city;

    // Setting up a sample city layout
    // BuildingA is connected to BuildingB and BuildingC
    // BuildingB is connected to BuildingD
    // BuildingC is connected to BuildingE
    city.addRoad("BuildingA", "BuildingB");
    city.addRoad("BuildingA", "BuildingC");
    city.addRoad("BuildingB", "BuildingD");
    city.addRoad("BuildingC", "BuildingE");
    city.addRoad("BuildingD", "BuildingE"); // Completing a loop

    std::string startNode = "BuildingA";
    std::cout << "--- Earthquake Disaster Relief Inspection Map ---\n";
    std::cout << "Starting point: " << startNode << "\n\n";

    // Run Strategy 1 (DFS)
    city.exploreDeepDFS(startNode);
    std::cout << "\n";

    // Run Strategy 2 (BFS)
    city.exploreLevelBFS(startNode);
    std::cout << "\n";

    return 0;
}
