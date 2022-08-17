class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                    break;
                }
            }
        }
        int dir[] = {-1,0,1,0,-1};
        int ans = 0;
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            int curr = 4;
            for(int i = 0 ; i < 4 ; i++){
                int dr = r + dir[i];
                int dc = c + dir[i+1];
                if(dr<0 || dc<0 || dr>=m || dc>=n){
                    continue;
                }
                if(grid[dr][dc] == 1){
                    curr--;
                    if(!vis[dr][dc]){
                        q.push({dr,dc});
                        vis[dr][dc] = 1;
                    }
                }
            }
            
            ans += curr;
        }
        
        return ans;
    }
};