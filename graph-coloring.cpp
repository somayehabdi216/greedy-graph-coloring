#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform the greedy coloring
void greedyGraphColoring(const vector<vector<int>>& graph, int V) {
    // Initialize the result array where color[i] is the color assigned to vertex i
    vector<int> result(V, -1);

    // Assign the first color to the first vertex
    result[0] = 0;

    // Array to store the available colors, initially all are available (false means available)
    vector<bool> available(V, false);

    // Assign colors to the remaining V-1 vertices
    for (int u = 1; u < V; u++) {
        // Mark the colors of adjacent vertices as unavailable
        for (int i = 0; i < graph[u].size(); i++) {
            int adjVertex = graph[u][i];
            if (result[adjVertex] != -1) {
                available[result[adjVertex]] = true; // Mark color as unavailable
            }
        }

        // Find the first available color
        int color;
        for (color = 0; color < V; color++) {
            if (!available[color]) {
                break;
            }
        }

        // Assign the found color to the current vertex u
        result[u] = color;

        // Reset the available array for the next iteration
        for (int i = 0; i < graph[u].size(); i++) {
            int adjVertex = graph[u][i];
            if (result[adjVertex] != -1) {
                available[result[adjVertex]] = false; // Reset color as available
            }
        }
    }

    // Output the result
    for (int u = 0; u < V; u++) {
        cout << "Vertex " << u << " ---> Color " << result[u] << endl;
    }
}

int main() {
    int V = 5;  // Number of vertices
    vector<vector<int>> graph(V);

    // Adding edges to the graph (Undirected graph)
    graph[0] = {1, 2};
    graph[1] = {0, 2, 3};
    graph[2] = {0, 1, 3, 4};
    graph[3] = {1, 2, 4};
    graph[4] = {2, 3};

    // Perform greedy coloring
    greedyGraphColoring(graph, V);

    return 0;
}
