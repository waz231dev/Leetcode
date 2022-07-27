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
    TreeNode* solve(TreeNode* root){
        if(!root)
            return NULL;
        if(root ->left == NULL and root->right == NULL)
            return root;
        TreeNode* rightTail = solve(root->right);
        TreeNode* right = root->right;
        TreeNode* leftTail = solve(root->left);
        TreeNode* left = root->left;
        root->left = NULL;
        if(leftTail){
            leftTail -> right = right;
            root->right = left;
        }else{
            root->right = right;
        }
        
        if(rightTail)
            return rightTail;
        
        return leftTail;
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};