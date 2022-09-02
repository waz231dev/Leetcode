class Solution {
    int del[5] = {-1,0,1,0,-1};
    int m,n;
    void dfs(vector<vector<int>>& grid,int x,int y){
        grid[x][y] = 0;
        
        for(int i = 0 ; i < 4 ; i++){
            int newx = x + del[i];
            int newy = y + del[i+1];
            if(newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == 1){
                dfs(grid,newx,newy);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        for(int i = 0 ; i < m ; i++){
            if(grid[i][0])
                dfs(grid,i,0);
            if(grid[i][n-1])
                dfs(grid,i,n-1);
        }
        
        for(int i = 0 ; i < n ; i++){
            if(grid[0][i])
                dfs(grid,0,i);
            if(grid[m-1][i])
                dfs(grid,m-1,i);
        }
        int cnt = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j])
                    cnt++;
            }
        }
        return cnt;
    }
};