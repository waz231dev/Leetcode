class Solution {
    int solve(int i1,int j1,int i2,int j2,vector<vector<int>>& grid,vector<vector<vector<vector<int>>>>& dp){
        if(i1 < 0 || j1 < 0 || i2 < 0 || j2 < 0 || grid[i1][j1] == -1 || grid[i2][j2] == -1)
            return -1e8;
        
        if(i1 == 0 && j1 == 0){
            return grid[i1][j1];
        }
        if(dp[i1][j1][i2][j2] != -1) return dp[i1][j1][i2][j2];
        int cherries = 0;
        if(i1 == i2 && j1 == j2){
            cherries += grid[i1][j1];
        }else{
            cherries += grid[i1][j1] + grid[i2][j2];
        }
        
        int up_up = solve(i1-1,j1,i2-1,j2,grid,dp);
        int up_left = solve(i1-1,j1,i2,j2-1,grid,dp);
        int left_up = solve(i1,j1-1,i2-1,j2,grid,dp);
        int left_left = solve(i1,j1-1,i2,j2-1,grid,dp);
        
        cherries += max(max(up_up,up_left),max(left_up,left_left));
        return dp[i1][j1][i2][j2] = cherries;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        return max(0,solve(n-1,n-1,n-1,n-1,grid,dp));
    }
};