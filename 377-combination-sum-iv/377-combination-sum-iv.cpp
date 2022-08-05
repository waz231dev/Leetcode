class Solution {
public:
    int solve(vector<int>& nums,int target,vector<int>& dp){
        if(target < 0)
            return 0;
        if(target == 0)
            return dp[target] = 1;
        if(dp[target] != -1)
            return dp[target];
        int ans = 0;
        for(int num : nums){
            ans += solve(nums,target - num,dp);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return solve(nums,target,dp);
    }
};