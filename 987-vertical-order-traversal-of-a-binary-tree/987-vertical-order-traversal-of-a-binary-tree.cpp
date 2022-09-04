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
    pair<int,int> width(TreeNode* root,int hl){
        if(root==NULL){
            return{0,0};
        }
        pair<int,int> left = width(root->left,hl-1);
        pair<int,int> right = width(root->right,hl+1);
        
        pair<int,int> ans;
        ans.first = min(hl,min(left.first,right.first));
        ans.second = max(hl,max(left.second,right.second));
        return ans;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        auto [left,right] = width(root,0);
        int level = abs(left);
        int width = right-left+1;
        vector<vector<int>> ans(width);
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,level});
        
        while(!q.empty()){
            int len = q.size();
            multiset<pair<int,int>> tmp;
            for(int i = 0 ; i < len ; i++){
                auto [curr,level] = q.front();
                q.pop();
                tmp.insert({level,curr->val});
            
                if(curr->left){
                    q.push({curr->left,level-1});
                }
                if(curr->right){
                    q.push({curr->right,level+1});
                }
            }
            
            for(auto p : tmp){
                ans[p.first].push_back(p.second);
            }
            
        }
        return ans;
    }
};