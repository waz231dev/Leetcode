class Solution {
public:
    // int dp[4001][4001];
    vector<vector<int>> dp;
    int mod = 1e9+7;
    int solve(int s,int e,int k){
        if(abs(s-e)>k)
            return 0;
        if(k == 0){
            if(s == e)
                return 1;
            
            return 0;
        }
        
        if(dp[s][k] != -1){
            return dp[s][k]%mod;
        }
        
        return dp[s][k] = (solve(s+1,e,k-1)%mod + solve(s-1,e,k-1)%mod)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        dp.resize(4001,vector<int>(k+1,-1));
        
        return solve(startPos+1000,endPos+1000,k);
    }
};