class Solution {
//     int solve(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
//         if(i > j) return 0;
        
//         if(dp[i][j] != -1) return dp[i][j];
//         int ans = -1e9;
//         for(int k = i ; k <= j ; k++){
//             int coins = nums[k] * nums[i-1] * nums[j+1];
//             coins += solve(i,k-1,nums,dp) + solve(k+1,j,nums,dp);
//             ans = max(ans,coins);
//         }
        
//         return dp[i][j] = ans;
//     }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        
        for(int i = n ; i >= 1 ; i--){
            for(int j = i ; j <= n ; j++){
                int ans = -1e9;
                for(int k = i ; k <= j ; k++){
                    int coins = nums[k] * nums[i-1] * nums[j+1];
                    coins += dp[i][k-1] + dp[k+1][j];
                    ans = max(ans,coins);
                }

                dp[i][j] = ans;
            }
        }
        return dp[1][n];
    }
};