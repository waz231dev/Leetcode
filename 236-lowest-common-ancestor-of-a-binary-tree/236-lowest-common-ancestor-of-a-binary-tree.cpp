/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool rootToNodePath(TreeNode* root,TreeNode* node,vector<TreeNode*>& path){
        if(root == NULL){
            return false;
        }
        
        path.push_back(root);
        
        if(root->val == node->val){
            return true;
        }
        
        if(rootToNodePath(root->left,node,path) || rootToNodePath(root->right,node,path))
            return true;
        
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a;
        vector<TreeNode*> b;
        rootToNodePath(root,p,a);
        rootToNodePath(root,q,b);
        TreeNode* ans = NULL;
        for(int i = 0, j = 0; i < a.size() && j < b.size() ; i++,j++){
            if(a[i] == b[j]){
                ans = a[i];
            }else{
                break;
            }
        }
        return ans;
    }
};