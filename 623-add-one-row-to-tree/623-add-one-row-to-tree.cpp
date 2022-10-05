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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return root;
        if(depth == 1){
            TreeNode* newnode = new TreeNode(val);
            newnode->left = root;
            return newnode;
        }
        
        if(depth == 2){
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            newLeft->left = left;
            newRight->right = right;
            root->left = newLeft;
            root->right = newRight;
            return root;
        }
        
        root->left = addOneRow(root->left,val,depth-1);
        root->right = addOneRow(root->right,val,depth-1);
        return root;
    }
};