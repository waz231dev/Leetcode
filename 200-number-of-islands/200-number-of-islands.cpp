class Solution {
public:
    void bfs(vector<vector<char>>& grid,int i,int j){
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = '0';
        
        int del[] = {-1,0,1,0,-1};
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            
            for(int it = 0 ; it < 4 ; it++){
                int ni = i + del[it];
                int nj = j + del[it+1];
                if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '1'){
                    q.push({ni,nj});
                    grid[ni][nj] = '0';
                }
            }
        }
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == '1'){
                    bfs(grid,i,j);
                    cnt++;                        
                }
            }
        }
        return cnt;
    }
};