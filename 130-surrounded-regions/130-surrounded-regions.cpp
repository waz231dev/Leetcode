class Solution {
public:
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    if(board[i][j] == 'O'){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        int del[5] = {-1,0,1,0,-1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int newx = x + del[i];
                int newy = y + del[i+1];
                if(newx >= 0 && newx < m && newy >= 0 && newy < n && !vis[newx][newy] && board[newx][newy] == 'O'){
                    q.push({newx,newy});
                    vis[newx][newy] = 1;
                }
            }
        }
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(!vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};