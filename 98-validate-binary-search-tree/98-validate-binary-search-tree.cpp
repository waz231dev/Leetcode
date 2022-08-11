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
    bool isValidLeft(TreeNode* left,int node){
        if(!left)
            return true;
        if(left->val >= node)
            return false;
        
        return isValidLeft(left->left,node) && isValidLeft(left->right,node);
    }
    
    bool isValidRight(TreeNode* right,int node){
        if(!right)
            return true;
        if(right->val <= node)
            return false;
        
        return isValidRight(right->left,node) && isValidRight(right->right,node);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        
        if(!isValidLeft(root->left,root->val) || !isValidRight(root->right,root->val))
            return false;
        
        return isValidBST(root->left) && isValidBST(root->right);
    }
};