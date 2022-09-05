/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr == NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                ans.push_back(v);
                v = {};
            }else{
                v.push_back(curr->val);
                for(auto child : curr->children){
                    q.push(child);
                }
            }
        }
        return ans;
    }
};