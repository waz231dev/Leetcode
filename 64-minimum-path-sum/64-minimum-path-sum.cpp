class Solution {
public:
    int m,n;
    int solve(vector<vector<int>>& grid,int i, int j,vector<vector<int>>& dp){
        if(i >= m || j >= n){
            return INT_MAX;
        }
        if(i == m-1 && j == n-1){
            return dp[i][j] = grid[i][j];
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = grid[i][j] + min(solve(grid,i,j+1,dp),solve(grid,i+1,j,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        solve(grid,0,0,dp);
        return dp[0][0];
    }
};