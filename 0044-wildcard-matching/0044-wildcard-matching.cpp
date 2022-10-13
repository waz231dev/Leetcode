class Solution {
    bool solve(int i, int j,string& s,string& p,vector<vector<int>>& dp){
        
        if(i == 0 && j == 0) return true;
        if(j == 0 && i > 0) return false;
        
        if(i == 0 && j > 0){
            for(int it = 0 ; it < j ; it++){
                if(p[it] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i-1] == p[j-1] || p[j-1] == '?')
            return dp[i][j] = solve(i-1,j-1,s,p,dp);
        
        if(p[j-1] == '*'){
            return dp[i][j] = solve(i-1,j,s,p,dp) || solve(i,j-1,s,p,dp);
        }
        
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        
        //Base Case
        dp[0][0] = 1;
        for(int j = 1 ; j <= m ; j++){
            dp[0][j] = 1;
            for(int it = 0 ; it < j ; it++){
                if(p[it] != '*') dp[0][j] = 0;
            }
        }
        
        for(int i = 1; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else 
                    dp[i][j] = false;
            }
            
        }
        return dp[n][m];
    }
};