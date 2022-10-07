class Solution {
    bool solve(int ind,int tar,vector<int>& nums,vector<vector<int>>& dp){
        if(tar == 0) return true;
        if(ind == 0) return tar == nums[0];
        
        if(dp[ind][tar] != -1) return dp[ind][tar];
        bool notTake = solve(ind-1,tar,nums,dp);
        bool take = false;
        if(tar >= nums[ind]) take = solve(ind-1,tar-nums[ind],nums,dp);
        
        return dp[ind][tar] = take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int num : nums){
            total += num;
        }
        if(total%2) return false;
        vector<vector<int>> dp(n,vector<int>(total/2 + 1,-1));
        return solve(n-1,total/2,nums,dp);
    }
};