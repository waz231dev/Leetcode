class Solution {
    int solve(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
        if(i == 0) return j;
        if(j == 0) return i;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        //Matched
        if(s1[i-1] == s2[j-1]) return solve(i-1,j-1,s1,s2,dp);
        
        //Not Matched
        int insert = 1 + solve(i,j-1,s1,s2,dp);
        int replace = 1 + solve(i-1,j-1,s1,s2,dp);
        int remove = 1 + solve(i-1,j,s1,s2,dp);
        
        
        return dp[i][j] = min(insert,min(replace,remove));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,word1,word2,dp);
    }
};