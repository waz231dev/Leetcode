class Solution {
public:
    // int m,n;
    // int solve(vector<vector<int>>& grid,int i, int j,vector<vector<int>>& dp){
    //     if(i >= m || j >= n){
    //         return INT_MAX;
    //     }
    //     if(i == m-1 && j == n-1){
    //         return dp[i][j] = grid[i][j];
    //     }
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     return dp[i][j] = grid[i][j] + min(solve(grid,i,j+1,dp),solve(grid,i+1,j,dp));
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(2,vector<int>(n));
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                }else{
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if(i>0) up = dp[(i-1)%2][j];
                    if(j>0) left = dp[i%2][j-1];
                    dp[i%2][j] = min(left,up) + grid[i][j];
                }
            }
        }
        
        return dp[(m-1)%2][n-1];
    }
};