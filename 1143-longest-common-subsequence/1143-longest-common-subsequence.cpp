class Solution {
    int solve(int i,int j,string& t1,string& t2,vector<vector<int>>& dp){
        if(i < 0 || j < 0) return 0;
        if(i == 0 && j == 0){
            return t1[i] == t2[j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        if(t1[i] == t2[j]){
            return dp[i][j] = 1+solve(i-1,j-1,t1,t2,dp);
        }
        
        int one = solve(i-1,j,t1,t2,dp);
        int two = solve(i,j-1,t1,t2,dp);
        return dp[i][j] = max(one,two);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,text1,text2,dp);
    }
};