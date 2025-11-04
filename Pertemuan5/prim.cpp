// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph
#include <bits/stdc++.h>
using namespace std;

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(vector<int> &key, vector<bool> &mstSet) {
  
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < mstSet.size(); v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMST(vector<int> &parent, vector<vector<int>> &graph) {
    cout << "Edge \tWeight\n";
    int totalWeight = 0;
    for (int i = 1; i < graph.size(); i++) {
        cout << parent[i] << " - " << i << " \t" << graph[parent[i]][i] << endl;
        totalWeight += graph[parent[i]][i];
    }
    cout << "Total weight of MST = " << totalWeight << endl;
}


// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(vector<vector<int>> &graph) {
    
    int V = graph.size();
  
    // Array to store constructed MST
    vector<int> parent(V);

    // Key values used to pick minimum weight edge in cut
    vector<int> key(V);

    // To represent set of vertices included in MST
    vector<bool> mstSet(V);

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first
    // vertex.
    key[0] = 0;
  
    // First node is always root of MST
    parent[0] = -1;

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        
        // TODO (Step 1): Choose the vertex 'u' with the smallest key value
        // that is not yet included in the MST
        int u = minKey(key, mstSet);

        // TODO (Step 2): Mark the chosen vertex 'u' as part of the MST
            mstSet[u] = true;

        // TODO (Step 3): Update the key values and parent indexes
        for (int v = 0; v < V; v++)
        if(graph[u][v] && mstSet[V] == false && graph[u][v] < key[v]) 
        parent[v] = u, key[v] = graph[u][v];
    }

    // Print the constructed MST
    printMST(parent, graph);
}

// Driver's code
int main() {
  	 vector<vector<int>> graph = {
        // 0   1   2   3   4   5   6   7   8
        { 0,  4,  0,  0,  0,  0,  0,  8,  0 }, // 0
        { 4,  0,  8,  0,  0,  0,  0, 11,  0 }, // 1
        { 0,  8,  0,  7,  0,  4,  0,  0,  2 }, // 2
        { 0,  0,  7,  0,  9, 14,  0,  0,  0 }, // 3
        { 0,  0,  0,  9,  0, 10,  0,  0,  0 }, // 4
        { 0,  0,  4, 14, 10,  0,  2,  0,  0 }, // 5
        { 0,  0,  0,  0,  0,  2,  0,  1,  6 }, // 6
        { 8, 11,  0,  0,  0,  0,  1,  0,  7 }, // 7
        { 0,  0,  2,  0,  0,  0,  6,  7,  0 }  // 8
    };

    // Print the solution
    primMST(graph);

    return 0;
}