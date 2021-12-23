/*
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
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) 
            return node;
        unordered_map<Node*, Node*> visited;
        queue<Node*> q;
        q.push(node);
        visited[node] = new Node(node->val, {});
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for (auto n : curr->neighbors) {
                if (visited.count(n) == 0) {
                    q.push(n);
                    visited[n] = new Node(n->val, {});
                }
                visited[curr]->neighbors.push_back(visited[n]);
            } 
        }
        return visited[node];
    }
};
