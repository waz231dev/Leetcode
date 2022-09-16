class Solution{
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums,int i,int j,vector<int>& multipliers,int ind){
        if(ind == multipliers.size() || i>j){
            return 0;
        }
        if(dp[ind][i] != INT_MIN)
            return dp[ind][i];
        
        int left= nums[i]*multipliers[ind]+solve(nums,i+1,j,multipliers,ind+1);
        int right = nums[j]*multipliers[ind]+solve(nums,i,j-1,multipliers,ind+1);
        
        return dp[ind][i] = max(left,right);
        
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        dp.resize(multipliers.size(),vector<int>(multipliers.size(),INT_MIN));
        return solve(nums,0,nums.size()-1,multipliers,0);
        // return maxScore;
    }
};