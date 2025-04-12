/*
implementation of DFS search
*/

#include <iostream>
#include <vector>

class Tree {
private:
    std::vector<std::vector<int>> adjList; // Adjacency list representation of the tree
    std::vector<int> dfsOrder;            // Stores the DFS order

    // Helper function for DFS traversal
    void dfs(int node, int parent) {
        dfsOrder.push_back(node); // Add the current node to the DFS order (entering the node)

        // Visit all children of the current node
        for (int child : adjList[node]) {
            if (child != parent) { // Avoid revisiting the parent node
                dfs(child, node);
            }
        }

        dfsOrder.push_back(node); // Add the current node to the DFS order again (leaving the node)
    }

public:
    // Constructor to initialize the tree with n nodes
    Tree(int n) {
        adjList.resize(n + 1); // Nodes are 1-indexed
    }

    // Add an edge to the tree
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Since it's an undirected tree
    }

    // Perform DFS and return the DFS order
    std::vector<int> getDFSOrder(int root) {
        dfsOrder.clear(); // Clear any previous DFS order
        dfs(root, -1);    // Start DFS from the root node
        return dfsOrder;
    }
};

int main() {
    // Create a tree with 7 nodes
    Tree tree(10);

    // Add edges to the tree
    tree.addEdge(1, 2);
    tree.addEdge(1, 3);
    tree.addEdge(2, 4);
    tree.addEdge(2, 5);
    tree.addEdge(3, 6);
    tree.addEdge(3, 7);
    tree.addEdge(4,8);
    tree.addEdge(6,9);
    tree.addEdge(6,10);

    // Get the DFS order starting from node 1
    std::cout << "DFS Order (with enter and leave) starting from node 1:" << std::endl;
    std::vector<int> dfsOrder = tree.getDFSOrder(1);

    // Print the DFS order
    for (int node : dfsOrder) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    return 0;
}