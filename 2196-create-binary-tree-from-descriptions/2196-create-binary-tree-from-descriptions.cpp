/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> nodeMap;
        unordered_set<int> child;
        
        for(auto vec : descriptions){
            if(nodeMap.find(vec[0]) == nodeMap.end()){
                nodeMap[vec[0]] = new TreeNode(vec[0]);
            }
            if(nodeMap.find(vec[1]) == nodeMap.end()){
                nodeMap[vec[1]] = new TreeNode(vec[1]);
            }
            
            if(vec[2] == 1) nodeMap[vec[0]]->left = nodeMap[vec[1]];
            else nodeMap[vec[0]]->right = nodeMap[vec[1]];
            child.insert(vec[1]);
        }
        
        for(auto vec : descriptions){
            if(child.find(vec[0]) == child.end()){
                return nodeMap[vec[0]];
            }
        }
        return NULL;
    }
};