class Solution {
    void solve(int ind,int target,vector<int>& candidates,vector<int> subans,vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(subans);
            return;
        }
        
        for(int i = ind ; i < candidates.size() ; i++){
            if(target < candidates[i]) break;
            
            if(i == ind || candidates[i] != candidates[i-1]){
                subans.push_back(candidates[i]);
                solve(i+1,target-candidates[i],candidates,subans,ans);
                subans.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subans;
        sort(candidates.begin(),candidates.end());
        solve(0,target,candidates,subans,ans);
        return ans;
    }
};