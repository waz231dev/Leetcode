class Solution {
    int solve(int ind,int d,vector<int>& jobDifficulty,vector<vector<int>>& dp){
        if(ind == jobDifficulty.size() && d == 0) return 0;
        if(ind == jobDifficulty.size() || d == 0) return 1e9;
        
        if(dp[ind][d] != -1) return dp[ind][d];
        int mini = 1e9;
        int currMax = jobDifficulty[ind];
        for(int i = ind ; i < jobDifficulty.size() ; i++){
            currMax = max(currMax,jobDifficulty[i]);
            mini = min(mini,currMax + solve(i+1,d-1,jobDifficulty,dp));
        }
        
        return dp[ind][d] = mini;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        vector<vector<int>> dp(jobDifficulty.size(),vector<int>(d+1,-1));
        int ans = solve(0,d,jobDifficulty,dp);
        
        return ans >= 1e9 ? -1 : ans;
    }
};