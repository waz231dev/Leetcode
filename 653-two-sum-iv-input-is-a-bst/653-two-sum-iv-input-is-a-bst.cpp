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
    bool solve(TreeNode* root, int k, unordered_set<int>& hs){
        if(!root) return false;
        
        if(hs.find(k-root->val) != hs.end()) return true;
        hs.insert(root->val);
        
        return solve(root->left,k,hs) || solve(root->right,k,hs);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> hs;
        return solve(root,k,hs);
    }
};