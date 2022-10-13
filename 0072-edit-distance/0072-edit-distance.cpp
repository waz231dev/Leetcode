class Solution {
    /*Memoization
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
    */
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        //Tabulation
        vector<int> prev(m+1),curr(m+1);
        
        for(int j = 0 ; j <= m ; j++){
            prev[j] = j;
        }
        
        // for(int i = 0 ; i <= n ; i++){
        //     curr[0] = i;
        // }
        
        for(int i = 1 ; i <= n ; i++){
            curr[0] = i;
            for(int j = 1 ; j <= m ; j++){
                if(word1[i-1] == word2[j-1]) curr[j] = prev[j-1];
                else{
                    int insert = 1 + curr[j-1];
                    int replace = 1 + prev[j-1];
                    int remove = 1 + prev[j];

                    curr[j] = min(insert,min(replace,remove));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};