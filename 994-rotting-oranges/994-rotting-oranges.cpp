class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        queue<vector<int>> q;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    q.push({i,j,0});
            }
        }
        int ans = 0;
        int d[] = {-1,0,1,0,-1};
        while(!q.empty()){
            auto front = q.front();
            int x = front[0];
            int y = front[1];
            int minute = front[2];
            q.pop();
            ans = max(ans,minute);
            for(int i = 0 ; i < 4 ; i++){
                int dx = x + d[i];
                int dy = y + d[i+1];
                if(dx<0||dy<0||dx>=m||dy>=n){
                    continue;
                }
                
                if(grid[dx][dy] == 1){
                    fresh--;
                    grid[dx][dy] = 2;
                    q.push({dx,dy,minute+1});
                }
            }
        }
        return fresh>0 ? -1 : ans;
    }
};