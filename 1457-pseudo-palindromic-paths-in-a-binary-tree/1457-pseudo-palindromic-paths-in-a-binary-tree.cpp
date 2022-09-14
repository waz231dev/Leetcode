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
        if(!root->left && !root->right){
            // cout<<root->val<<" ";
            freq[root->val]++;
            int f1 = 0;
            for(int i = 0 ; i < 10 ; i++){
                // cout<<freq[i]<<" ";
                if(freq[i]%2==1){
                    f1++;
                }
            }
            // cout<<endl;
            if(f1<=1)ans++;
            freq[root->val]--;
            return;
        }
        freq[root->val]++;
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