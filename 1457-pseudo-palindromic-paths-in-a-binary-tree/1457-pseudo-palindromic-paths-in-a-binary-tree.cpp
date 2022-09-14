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
    void solve(TreeNode* root,vector<int>& freq,int& ans){
        if(!root) return;
        
        freq[root->val]++;
        if(!root->left && !root->right){
            int odd = 0;
            for(int i = 0 ; i < 10 ; i++){
                if(freq[i]%2==1){
                    odd++;
                }
            }
            if(odd<=1)ans++;
        }
        
        solve(root->left,freq,ans);
        solve(root->right,freq,ans);
        
        freq[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10,0);
        int ans = 0;
        solve(root,freq,ans);
        return ans;
    }
};