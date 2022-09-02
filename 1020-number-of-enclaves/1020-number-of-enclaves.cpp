class Solution {
    int del[5] = {-1,0,1,0,-1};
    int m,n;
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int x,int y){
        vis[x][y] = 1;
        
        for(int i = 0 ; i < 4 ; i++){
            int newx = x + del[i];
            int newy = y + del[i+1];
            if(newx >= 0 && newx < m && newy >= 0 && newy < n && !vis[newx][newy] && grid[newx][newy] == 1){
                dfs(grid,vis,newx,newy);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(int i = 0 ; i < m ; i++){
            if(grid[i][0] && !vis[i][0])
                dfs(grid,vis,i,0);
            if(grid[i][n-1] && !vis[i][n-1])
                dfs(grid,vis,i,n-1);
        }
        
        for(int i = 0 ; i < n ; i++){
            if(grid[0][i] && !vis[0][i]){
                // cout<<i<<endl;
                dfs(grid,vis,0,i);
            }
            if(grid[m-1][i] && !vis[m-1][i])
                dfs(grid,vis,m-1,i);
        }
        int cnt = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                // if(!vis[i][j])
                // cout<<grid[i][j]<<" ";
                if(!vis[i][j] && grid[i][j])
                    cnt++;
            }
            // cout<<endl;
        }
        return cnt;
    }
};