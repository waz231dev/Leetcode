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
    Node* dfs(Node* node,unordered_map<Node*,Node*>& vis){
        if(vis[node]) return vis[node];
        Node* copy = new Node(node->val);
        vis[node] = copy;
        vector<Node*> currNeighbors;
        
        for(auto adj : node->neighbors){
            currNeighbors.push_back(dfs(adj,vis));
        }
        
        copy->neighbors = currNeighbors;
        return copy;        
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        unordered_map<Node*,Node*> vis;
        
        return dfs(node,vis);
    }
};