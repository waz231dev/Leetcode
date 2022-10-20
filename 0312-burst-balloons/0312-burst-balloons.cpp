class Solution {
    int solve(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int ans = -1e9;
        for(int k = i ; k <= j ; k++){
            int coins = nums[k] * nums[i-1] * nums[j+1];
            coins += solve(i,k-1,nums,dp) + solve(k+1,j,nums,dp);
            ans = max(ans,coins);
        }
        
        return dp[i][j] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,nums,dp);
    }
};