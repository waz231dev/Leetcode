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
    void solve(TreeNode* root,string& res){
        if(!root)
            return;
        res += to_string(root->val);
        
        if(root->left){
            res += '(';
            solve(root->left,res);
            res += ')';
        }else if(root->right){
            res += "()";
        }
        
        if(root->right){
            res += '(';
            solve(root->right,res);
            res += ')';
        }
    }
public:
    string tree2str(TreeNode* root) {
        string res = "";
        solve(root,res);
        return res;
    }
};