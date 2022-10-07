class Solution {
    int CountSubsetsWithSumK(int ind,int tar,vector<int>& nums,vector<vector<int>>& dp){
        if(ind == 0){
            if(nums[0] == 0 && tar == 0) return 2;
            return tar == 0 || tar == nums[0];
        }
        if(dp[ind][tar] != -1) return dp[ind][tar];
        int notTake = CountSubsetsWithSumK(ind-1,tar,nums,dp);
        int take = 0;
        if(tar >= nums[ind]) take = CountSubsetsWithSumK(ind-1,tar-nums[ind],nums,dp);
        
        return dp[ind][tar] = take + notTake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }
        
        if((totalSum + target) % 2 || totalSum + target < 0) return 0;
        
        int tar = (totalSum + target)/2;
        vector<vector<int>> dp(n,vector<int>(tar+1,-1));
        return CountSubsetsWithSumK(n-1,tar,nums,dp);
    }
};