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
    int kthSmallest(TreeNode* root, int k) {
        
        stack<TreeNode*> st;
        TreeNode* curr = root;
        int ans;
        while(!st.empty() || curr){
            if(curr){
                st.push(curr);
                curr = curr->left;
            }else{
                curr = st.top();
                st.pop();
                if(!--k){
                    ans = curr->val;
                    break;
                }
                curr = curr->right;
            }
        }
        return ans;
    }
};