#include <iostream>
#include <vector>
#include <numeric> // For iota (optional, for convenience)

using namespace std;

// Standard DFS function to count nodes in a connected component
int dfs(vector<vector<int>> &grafo, vector<bool> &visitados, int atual) {
    int count = 1; // Count the current node
    visitados[atual] = true;

    // Iterate through all neighbors of the current node
    for (int neighbor : grafo[atual]) {
        if (!visitados[neighbor]) {
            count += dfs(grafo, visitados, neighbor);
        }
    }
    return count;
}

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    while (num_test_cases--) {
        int num_nodes;
        cin >> num_nodes; // Renamed 'q' for clarity

        // Adjacency list representation for the graph
        vector<vector<int>> grafo(num_nodes);
        for (int i = 0; i < num_nodes; ++i) {
            int neighbor_node;
            cin >> neighbor_node;
                grafo[i].push_back(neighbor_node);
                grafo[neighbor_node].push_back(i);
        }
        vector<bool> visitados(num_nodes, false); // Reset visitados for each test case

        for (int i = 0; i < num_nodes; ++i) {
            if (!visitados[i]) { // Only start DFS if not already visited
                int component_size = dfs(grafo, visitados, i);
                cout << "Component starting from node " << i << " has size: " << component_size << endl;
            }
        }
        cout << "---" << endl; // Separator for test cases
    }

    return 0;
}