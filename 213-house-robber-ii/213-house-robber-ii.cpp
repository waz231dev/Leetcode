class Solution {
    int solve(vector<int>& nums,int ind,int base,vector<int>& dp){
        if(ind == base) return nums[ind];
        if(ind < base) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + solve(nums,ind-2,base,dp);
        int notpick = solve(nums,ind-1,base,dp);
        
        return dp[ind] = max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n,-1);
        int ans1 = solve(nums,n-2,0,dp);
        fill(dp.begin(),dp.end(),-1);
        int ans2 = solve(nums,n-1,1,dp);
        return max(ans1,ans2);
    }
};