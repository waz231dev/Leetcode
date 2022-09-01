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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            // cout<<level<<endl;
            if(level%2 == 0){
                int prev = INT_MIN;
                for(int i = 0 ; i < size ; i++){
                     TreeNode* node = q.front();
                     q.pop();
                     // cout<<node->val<<" ";
                     if(node->val<=prev || !(node->val&1)){
                        return false;
                     }
                     prev = node->val;
                     if(node->left) q.push(node->left);
                     if(node->right) q.push(node->right);
                  }
                
            }else{
                int prev = INT_MAX;
                for(int i = 0 ; i < size ; i++){
                     TreeNode* node = q.front();
                     q.pop();
                     // cout<<node->val<<" ";
                     if(node->val>=prev || node->val&1){
                        return false;
                     }
                     prev = node->val;
                     if(node->left) q.push(node->left);
                     if(node->right) q.push(node->right);
                  }
            }
            level++;
        }
        return true;
    }
};