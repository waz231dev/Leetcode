class Solution {
        int solve(int i, int j, int k,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,vector<vector<int>>& visited){
        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || j >= n || i < 0 || j < 0 || visited[i][j]){
            return 1e9;
        }
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        if(i == 0 && j == 0){
            return dp[i][j][k] = 0;
        }
        
        if(grid[i][j]){
            if(k == 0){
                return dp[i][j][k] = 1e9;
            }
            else{
                k--;
            }
        }
        visited[i][j] = true;
        
        int up = 1 + solve(i-1,j,k,grid,dp,visited);
        int left = 1 + solve(i,j-1,k,grid,dp,visited);
        int right = 1 + solve(i,j+1,k,grid,dp,visited);
        int down = 1 + solve(i+1,j,k,grid,dp,visited);
        
        visited[i][j] = false;
        
        return dp[i][j][k] = min(min(left,up),min(right,down));
    }
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans = solve(m-1,n-1,k,grid,dp,vis);
        return ans >= 1e9 ? -1 : ans;
    }
};