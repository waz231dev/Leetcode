class Solution {
public:
    int countVowelPermutation(int n) {
        
        vector<vector<long long>> dp(5,vector<long long>(n+1,0));
        
        for(int i = 0 ; i < 5 ;  i++){
            dp[i][1] = 1;
        }
        int mod = 1e9+7;
        for(int i = 2 ; i <= n ; i++){
            dp[0][i] = (dp[1][i-1]+dp[2][i-1]+dp[4][i-1])%mod;
            dp[1][i] = (dp[0][i-1]+dp[2][i-1])%mod;
            dp[2][i] = (dp[1][i-1]+dp[3][i-1])%mod;
            dp[3][i] = (dp[2][i-1])%mod;
            dp[4][i] = (dp[2][i-1]+dp[3][i-1])%mod;
        }
        
        long long ans = 0;
        
        for(int i = 0 ; i < 5 ; i++){
            ans = (ans + dp[i][n])%mod;
        }
        
        return ans;
    }
};