class Solution {
    int mod = 1000000007;
//     int solve(int n,int k,int target,vector<vector<int>>& dp){
//         if(n == 1){
//             if(target >= 1 && target <= k) return 1;
//             else return 0;
//         }
//         if(target < 0) return 0;
//         if(dp[n][target] != -1) return dp[n][target];
//         int count = 0;
//         for(int i = 1 ; i <= k ; i++){
//             count = (count%mod + solve(n-1,k,target-i,dp)%mod)%mod;
//         }
        
//         return dp[n][target] = count;
//     }
public:
    int numRollsToTarget(int n, int f, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= target ; j++){
                for(int k = 1 ; k <= f ; k++){
                    if(i == 0){
                        if(j == 0) dp[i][j] = 1;
                        else dp[i][j] = 0;
                    } 
                    else if(j>=k)dp[i][j] = (dp[i][j]%mod + dp[i-1][j-k]%mod)%mod;
                }
            }
        }
        return dp[n][target];
    }
};