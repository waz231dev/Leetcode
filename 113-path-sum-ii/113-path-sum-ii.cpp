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
    void solve(TreeNode* root,int target,vector<int>& sub,vector<vector<int>>& ans){
        if(!root) return;
        
        if(!root->left && !root->right){
            target -= root->val;
            sub.push_back(root->val);
            if(target == 0){
                ans.push_back(sub);
            }
            target += root->val;
            sub.pop_back();
            return;
        }
        
        target -= root->val;
        sub.push_back(root->val);
        
        solve(root->left,target,sub,ans);
        solve(root->right,target,sub,ans);
        
        target += root->val;
        sub.pop_back();
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> sub;
        solve(root,targetSum,sub,ans);
        return ans;
    }
};