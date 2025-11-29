#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    void DFS(Node* node, Node* clone_node, vector<Node*>& visited) {
        visited[node->val] = clone_node;
        
        for (Node* x : node->neighbors) {
            if (visited[x->val] == NULL) {
                Node* clone = new Node(x->val);
                clone_node->neighbors.push_back(clone);
                DFS(x, clone, visited);
            } else {
                clone_node->neighbors.push_back(visited[x->val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;
        
        // Clone the starting node
        Node* clone_node = new Node(node->val);
        
        // Visited array to store already-created clone nodes
        // (constraints say node values are in [1,100])
        vector<Node*> visited(101, NULL);
        visited[node->val] = clone_node;

        DFS(node, clone_node, visited);
        
        return clone_node;
    }
};

/// --- Helper functions for testing ---

void printGraph(Node* node) {
    if (!node) return;

    unordered_set<int> seen;
    queue<Node*> q;
    q.push(node);
    seen.insert(node->val);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << "Node " << curr->val << " -> ";
        for (auto nei : curr->neighbors) {
            cout << nei->val << " ";
            if (!seen.count(nei->val)) {
                seen.insert(nei->val);
                q.push(nei);
            }
        }
        cout << "\n";
    }
}

int main() {
    // Build a simple graph:
    // 1 -- 2
    // |    |
    // 4 -- 3

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    cout << "Original graph:\n";
    printGraph(n1);

    Solution sol;
    Node* cloned = sol.cloneGraph(n1);

    cout << "\nCloned graph:\n";
    printGraph(cloned);

    return 0;
}
