class Solution {
    int solve(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()){
            return -1e8;
        }
        
        if(i == grid.size()-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxim = -1e8;
        for(int p = -1 ; p <= 1 ; p++){
            for(int q = -1 ; q <= 1 ; q++){
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += solve(i+1,j1+p,j2+q,grid,dp);
                maxim = max(maxim,value);
            }
        }
        return dp[i][j1][j2] = maxim;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,0,m-1,grid,dp);
    }
};